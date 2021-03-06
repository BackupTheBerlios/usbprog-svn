/* usbn2mc.h
* Copyright (C) 2005  Benedikt Sauter
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* @brief Architecture and connection dependent access to the USBN device.
*/
#ifndef _MCIFACE_H_
#define _MCIFACE_H_

#include <avr/interrupt.h>
#include "usbn2mc/tiny/usbnapi.h"

#define MIN(a,b)		(((a)>=(b))?(a):(b))

void USBNInitMC(void);

// print debug messages
#ifdef DEBUG
void USBNDebug(char *msg);
#else
#define USBNDebug(x)
#endif

void USBNDecodeVendorRequest(DeviceRequest_t *req);

#define USBNInterrupt()		ISR(SIG_INTERRUPT0)

/// The Atmega register used to send data/address to the USBN9604
#define USB_DATA_OUT		PORTC

/// The Atmega register used to receive data from the USBN9604
#define USB_DATA_IN			PINC

/// The Atmega register that controls the i/o direction of the USB_DATA_OUT
#define USB_DATA_DDR		DDRC

/// The Atmega port used to send control signals to the USBN9604
#define USB_CTRL_PORT		PORTD

/// The Atmega register that controls the i/o direction of USB_CTRL_PORT
#define USB_CTRL_DDR		DDRD

/// The pin address of the chip select signal
#define  PF_CS    0x08

/// The pin address of the Address enable signal
#define  PF_A0    0x40

/// The pin address of the write strobe signal
#define  PF_WR    0x20

/// The pin address of the read strobe signal
#define  PF_RD    0x10

//#define  PF_RESET    0x10

#endif /* _MCIFACE_H_ */
