/*
 * modified by Sven Luetkemeier sven@sl-ware.de, 2007
 *
 * Copyright (C) 2004 by egnite Software GmbH. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY EGNITE SOFTWARE GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL EGNITE
 * SOFTWARE GMBH OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * For additional information see http://www.ethernut.de/
 */

/*
 * $Log$
 */

#include "xsvfexec.h"
#include "xsvf.h"
#include "host.h"
#include "tapsm.h"
#include "avr/delay.h"

/*!
 * \file xsvfexec.c
 *
 * \brief Executor main file.
 */

/*!
 * \addtogroup xgBitString
 */
/*@{*/

/*!
 * \brief Compare two bit string using an optional bit mask.
 *
 * \param len  Number of bits in the bit strings.
 * \param op1  Pointer to the first bit string.
 * \param op2  Pointer to the second bit string.
 * \param mask Pointer to the mask. Bits are compared only if the corresponding
 *             bit in the mask is set. If this pointer is set to NULL, all
 *             bits will be compared.
 *
 * \return 0 if equal, 1 otherwise.
 */
static int BitStringCmp(int len, unsigned char *op1, unsigned char *op2, unsigned char *mask)
{
    int rc = 0;

#if !defined(_WIN32)
    int i;
    unsigned char diff;

    for (i = 0; i < len; i += 8) {
        diff = *op1++ ^ *op2++;
        if (mask) {
            diff &= *mask++;
        }
        if (diff) {
            rc = 1;
            break;
        }
    }
#endif

    return rc;
}

/*!
 * \brief Numeric addition of two bit string.
 *
 * \param len Number of bits in the bit strings.
 * \param op1 Pointer to the first bit string, which will also receive
 *            the final result.
 * \param op2 Pointer to the second bit string. Will be added to the first.
 */
static void BitStringAdd(int len, unsigned char *op1, unsigned char *op2)
{
    int i;
    unsigned short sum;
    unsigned char ovr = 0;

    i = (int)((len + 7UL) / 8UL);
    while (i--) {
        if((sum = (unsigned short)((unsigned short)op1[i] + (unsigned short)op2[i] + ovr)) > (unsigned short)255) {
            ovr = 1;
        }
        else {
            ovr = 0;
        }
        op1[i] = (unsigned char)sum;
    }
}

/*!
 * \brief Count the number of bits set to one in a bit string.
 *
 * \param len Number of bits in the bit string.
 * \param op  Pointer to the bit string.
 *
 * \return The number of bits set to one.
 */
static int BitStringOnes(int len, unsigned char *op)
{
    int rc = 0;
    unsigned char mask;
    int i = (int)((len + 7UL) / 8UL);

    while (i--) {
        for(mask = op[i]; mask; mask >>= 1) {
            rc += mask & 1;            
        }
    }
    return rc;
}

/*@}*/

/*!
 * \addtogroup xgXsvfExec
 */
/*@{*/


/*!
 * \brief Prepare the next TDI value for iterating XSDR.
 *
 * \param len       Number of bits in the first TDI value.
 * \param tdi_val   First TDI value, the one which will be updated.
 * \param len2      Number of bits in the second TDI value.
 * \param tdi_val2  Second TDI value.
 * \param data_mask The data mask used for the update.
 */
static void UpdateTdi(int len, unsigned char *tdi_val, int len2, unsigned char *tdi_val2, unsigned char *data_mask)
{
    unsigned char tdibit;
    unsigned char mask;
    int i;
    unsigned char d = 0;
    unsigned char m = 0;

    for (i = len - 1; i >= 0; --i) {
        mask = data_mask[i];
        if (mask) {
            tdibit = 1;
            while (mask) {
                if (mask & 1) {
                    if (m == 0) {
                        d = tdi_val2[--len2];
                        m = 1;
                    }
                    if (d & m) {
                        tdi_val[i] |= tdibit;
                    } else {
                        tdi_val[i] &= ~tdibit;
                    }
                    m <<= 1;
                }
                tdibit <<= 1;
                mask >>= 1;
            }
        }
    }
}


/*!
 * \brief Repeat shifting out a TDI value until an expected TDO value appears.
 *
 * \param len     Number of bits to shift.
 * \param tdi_val TDI value to shift out.
 * \param tdo_exp Expected TDO value. Set to NULL if not available.
 * \param tdo_msk Used to mask out don't care TDO values.
 * \param sState  TAP state during shift operation, either SHIFT-DR or SHIFT-IR. No
 *                retries are allowed with SHIFT-IR.
 * \param eState  TAP state after shift operation.
 * \param delay   Idle time (in microseconds) after each shift.
 * \param retries Maximum number of retries. Ignored if expected TDO value is not available.
 *
 * \return Zero on success, otherwise an error code is returned.
 */
static int ReShift(int len, unsigned char *tdi_val, unsigned char *tdo_exp, unsigned char *tdo_msk, 
                   unsigned char sState, unsigned char eState, long delay, unsigned char retries)
{
    int rc = 0;
    unsigned char tdo_val[MAX_BITVEC_BYTES];

    if (len == 0) {
        if (delay) {
            TapStateChange(RUN_TEST_IDLE);
            XsvfDelay(delay);
        }
    } else {
        int last_byte = (int)((len + 7UL) / 8UL - 1UL);

        /* 
         * Retry loop. 
         */
        do {
            unsigned char *tdi = &tdi_val[last_byte];
            unsigned char *tdo = &tdo_val[last_byte];
            int bitcnt;
            unsigned char bitmsk;

            TapStateChange(sState);

            /* 
             * Byte loop. 
             */
            for(bitcnt = len; bitcnt;) {
                *tdo = 0;

                /* 
                 * Bit loop. LSB is shifted first.
                 */
                for (bitmsk = 1; bitmsk && bitcnt; bitmsk <<= 1) {
                    if (sState != eState && bitcnt == 1) {
                        /* Exit Shift state with last bit. */
                        SET_TMS();
                        TapStateInc();
                    }

                    /* Shift TDI in and TDO out. */
                    if(*tdi & bitmsk) {
                        SET_TDI();
                    }
                    else {
                        CLR_TDI();
                    }
                    CLR_TCK();

                    /*
                     * This is time critical, because TDO may be delayed.
                     * The following decrement of our int value consumes
                     * some CPU cycles.
                     */
                    bitcnt--;
                    if(GET_TDO()) {
                        *tdo |= bitmsk;
                    }
                    SET_TCK();
                }
                tdi--;
                tdo--;
            }

            /*
             * Compare captured with expected TDO result.
             */
            if (tdo_exp) {
                if(BitStringCmp(len, tdo_exp, tdo_val, tdo_msk)) {
                    rc = XE_TDOMISMATCH;
                }
                else {
                    rc = 0;
                }
            }

            /*
             * Update TAP controller state.
             */
            if (sState != eState) {
                if (rc && delay && retries) {
                    /* The TDO value does not match the expected value. */
                    TapStateChange(PAUSE_DR);
                    TapStateChange(SHIFT_DR);
                } else {
                    TapStateChange(eState);
                }

                /*
                 * If the XRUNTEST time is non-zero, go to the Run-Test/Idle state 
                 * and wait for the specified number of microseconds.
                 */
                if (delay) {
                    PORTA ^= 0x10;
                    TapStateChange(RUN_TEST_IDLE);
                    //XsvfDelay(delay);
                    XsvfClockCycles(delay);
                    /* In case of another retry, increase idle time by 25%. */
                    //delay += (delay >> 2);
                }
            }
        } while (rc && retries--);
    }
    return rc;
}


/*!
 * \brief Shift next TDI value out and optionally capture TDO value.
 *
 * No delays and no retries are performed.
 *
 * \param len     Number of bits to shift.
 * \param tdi_val Pointer to TDI value buffer.
 * \param tdo_exp Pointer to expected TDO value buffer. If NULL, no TDO value will
 *                be read from the XSVF buffer and no comparision will take place.
 * \param sState  TAP state during shift operation, either SHIFT-DR or SHIFT-IR.
 * \param eState  TAP state after shift operation.
 *
 * \return Zero on success, otherwise an error code is returned.
 */
static int Shift(int len, unsigned char *tdi_val, unsigned char *tdo_exp, unsigned char sState, unsigned char eState)
{
    XsvfReadBitString(tdi_val, len);
    if(tdo_exp) {
        XsvfReadBitString(tdo_exp, len);
    }
    return ReShift(len, tdi_val, tdo_exp, 0, sState, eState, 0, 0);
}

/*!
 * \brief TDI value buffer.
 */
static unsigned char tdiVal[MAX_BITVEC_BYTES];

/*!
 * \brief TDI value 2 buffer.
 */
static unsigned char tdiVal2[MAX_BITVEC_BYTES];

/*!
 * \brief Expected TDO value buffer.
 */
static unsigned char tdoExp[MAX_BITVEC_BYTES];

/*!
 * \brief TDO mask buffer.
 */
static unsigned char tdoMask[MAX_BITVEC_BYTES];

/*!
 * \brief Data mask buffer.
 */
static unsigned char dataMask[MAX_BITVEC_BYTES];

/*!
 * \brief Address mask buffer.
 */
static unsigned char addrMask[MAX_BITVEC_BYTES];

static unsigned char endIr = RUN_TEST_IDLE;
static unsigned char endDr = RUN_TEST_IDLE;
static unsigned char retries = DEFAULT_REPEAT;
static long delay = 0;
static int drSize = 0;
static int drSize2 = 0;
static int irSize;

/*!
 * \brief Execute a single XSVF command stored in buf
 */
int XsvfExec(char *buf, int size) {
    int rc = 0;
    unsigned char cmd;

	XsvfSetBuf(buf, size);

    /* Process the XSVF command */
	cmd = XsvfGetCmd();
	switch(cmd) {
	
	case XCOMPLETE:
		/* 
			* Normal end of the XSVF buffer reached. 
			*/
		break;

	case XTDOMASK:
		/* 
			* Set the TDO mask. Length has been specified by the last XSDRSIZE command.
			*/
		XsvfReadBitString(tdoMask, drSize);
		break;

	case XRUNTEST:
		/*
			* Set the number of microseconds the device should stay in the Run-Test-Idle 
			* state after each visit to the SDR state.
			*/
		delay = XsvfGetLong();
		break;

	case XREPEAT:
		/*
			* Set the number of times that TDO is tested against the expected value before 
			* the programming operation is considered a failure.
			*/
		retries = XsvfGetByte();
		break;

	case XSDRSIZE:
		/*
			* Set the length of the next XSDR/XSDRTDO records that follow.
			*/
		drSize = (int)XsvfGetLong();
		if ((drSize + 7) / 8 > MAX_BITVEC_BYTES) {
			rc = XE_DATAOVERFLOW;
		}
		break;

	case XSIR:
	case XSIR2:
		/*
			* Go to the Shift-IR state and shift in the TDI value. XSIR uses
			* a single byte for the TDI size, while XSIR2 uses two bytes.
			*/
		if(cmd == XSIR) {
			irSize = XsvfGetByte();
		}
		else {
			irSize = XsvfGetShort();
		}
		XsvfReadBitString(tdiVal, irSize);
		rc = ReShift(irSize, tdiVal, 0, 0, SHIFT_IR, endIr, delay, 0);
		break;

	case XSDRTDO:
		/*
			* Go to the Shift-DR state and shift in the TDI value; compare the expected
			* value against the TDO value that was shifted out. Use the TDO mask which 
			* was generated by the last XTDOMASK command.
			*
			* The expected TDO value is re-used in successive XSDR commands.
			*/
		XsvfReadBitString(tdiVal, drSize);
		XsvfReadBitString(tdoExp, drSize);
		rc = ReShift(drSize, tdiVal, tdoExp, tdoMask, SHIFT_DR, endDr, delay, retries);
		break;

	case XSDR:
		/*
			* Go to the Shift-DR state and shift in the TDI value; compare the expected 
			* value from the last XSDRTDO command against the TDO value that was 
			* shifted out. Use the TDO mask which was generated by the last XTDOMASK 
			* instruction.
			*/
		XsvfReadBitString(tdiVal, drSize);
		rc = ReShift(drSize, tdiVal, tdoExp, tdoMask, SHIFT_DR, endDr, delay, retries);
		break;

	case XSDRB:
	case XSDRC:
		/*
			* Go to the Shift-DR state and shift in the TDI value. No comparison of TDO 
			* value with the last specified expected value is performed.
			*/
		rc = Shift(drSize, tdiVal, 0, SHIFT_DR, SHIFT_DR);
		break;

	case XSDRE:
		/*
			* Continue to stay in Shift-DR state and shift in the TDI value. At the end 
			* of the operation, go to the state specified in the last XENDDR command. No
			* comparison of TDO value with the last specified expected value is performed.
			*/
		rc = Shift(drSize, tdiVal, 0, SHIFT_DR, endDr);
		break;

	case XSDRTDOB:
	case XSDRTDOC:
		/*
			* Go to the Shift-DR state and shift in the TDI value. Compare all bits of the 
			* expected value against the TDO value that is shifted out. No retries are
			* performed.
			*/
		rc = Shift(drSize, tdiVal, tdoExp, SHIFT_DR, SHIFT_DR);
		break;

	case XSDRTDOE:
		/*
			* Continue to stay in Shift-DR state and shift in the TDI value. Compare all 
			* bits of the expected value against the TDO value that is shifted out. At the 
			* end of the operation, go to the state specified in the last XENDDR command.
			* No retries are performed.
			*/
		rc = Shift(drSize, tdiVal, tdoExp, SHIFT_DR, endDr);
		break;

	case XSTATE:
		/*
			* Immediately set the TAP controller to Test-Logic-Reset (0) or Run-Test_idle (1).
			*/
		rc = TapStateChange(XsvfGetState(TEST_LOGIC_RESET, RUN_TEST_IDLE));
		break;

	case XENDIR:
		/* 
			* Set the XSIR end state to Run-Test-Idle (0) or Pause-IR (1).
			*/
		endIr = XsvfGetState(RUN_TEST_IDLE, PAUSE_IR);
		break;

	case XENDDR:
		/*
			* Set the XSDR/XSDRTDO end state to Run-Test-Idle (0) or Pause-DR (1).
			*/
		endDr = XsvfGetState(RUN_TEST_IDLE, PAUSE_DR);
		break;

	case XSETSDRMASKS:
		/*
			* Set SDR address and data masks for interatin XSDR commands.
			*/
		XsvfReadBitString(addrMask, drSize);
		XsvfReadBitString(dataMask, drSize);
		drSize2 = BitStringOnes(drSize, dataMask);
		break;

	case XSDRINC:
		/*
			* Do iterating XSDR commands.
			*/
		XsvfReadBitString(tdiVal, drSize);
		rc = ReShift(drSize, tdiVal, tdoExp, tdoMask, SHIFT_DR, endDr, delay, retries);
		if (rc == 0) {
			int num = XsvfGetByte();

			while(num-- && rc == 0) {
				XsvfReadBitString(tdiVal2, drSize2);
				BitStringAdd(drSize, tdiVal, addrMask);
				UpdateTdi(drSize, tdiVal, drSize2, tdiVal2, dataMask);
				rc = ReShift(drSize, tdiVal, tdoExp, tdoMask, SHIFT_DR, endDr, delay, retries);
			}
		}
		break;

	case XCOMMENT:
		/*
			* Skip comment string.
			*/
		XsvfSkipComment();
		break;

	default:
		rc = XE_ILLEGALCMD;
		break;
	}

	/* Check for errors in the platform dependant interface. */
	if(rc == 0) {
		rc = XsvfGetError();
	}

    return rc;
}

/*!
 * \brief Initialize XSVF Execution
 *
 * To be called before the first XSVF instruction is executed.
 */
void XsvfInit(void)
{
	XsvfInitHost();
	TapStateInit();
}

/*!
 * \brief Close XSVF Execution
 *
 * To be called after the last XSVF instruction is executed.
 */
void XsvfClose(void) {
	XsvfCloseHost();
}

/*@}*/
