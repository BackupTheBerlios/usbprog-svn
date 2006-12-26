/*
 * avrdude - A Downloader/Uploader for AVR device programmers
 * Copyright (C) 2005,2006 Joerg Wunsch
 * Copyright (C) 2006 David Moore
 * Copyright (C) 2006 Benedikt Sauter (based on usb_libusb.c)
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
 */

/* $Id: usb_libusb.c,v 1.10 2006/12/11 12:47:35 joerg_wunsch Exp $ */

#include "ac_cfg.h"
#if defined(HAVE_LIBUSB)


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>

#include <usb.h>

#include "serial.h"
#include "usbprog.h"

extern char *progname;
extern int verbose;

static char usbbuf[USBPROG_MAX_XFER];
static int buflen = -1, bufptr;

static int usb_interface;

/********** serial device emulation *********************/

/*
 * Device descriptor for the usbprog
 */

struct serial_device usb_serdev_usbprog =
{
  .open = usbprog_open,
  .close = usbprog_close,
  .send = usbprog_send,
  .recv = usbprog_recv_frame,
  .drain = usbprog_drain,
  .flags = SERDEV_FL_NONE,
};

/*
 * The "baud" parameter is meaningless for USB devices, so we reuse it
 * to pass the desired USB device ID.
 */
static void usbprog_open(char * port, long baud, union filedescriptor *fd)
{
  char string[256];
  char product[256];
  struct usb_bus *bus;
  struct usb_device *dev;
  usb_dev_handle *udev;
  char *serno, *cp2;
  size_t x;

  usb_init();

  usb_find_busses();
  usb_find_devices();

  for (bus = usb_get_busses(); bus; bus = bus->next){
		for (dev = bus->devices; dev; dev = dev->next){
	  	udev = usb_open(dev);
	  	if (udev){
	    	if (dev->descriptor.idVendor == USBPROG_VID &&
		  		dev->descriptor.idProduct == USBPROG_PID){
		  			/* yeah, we found something */
		  
		
					/* check if device has an configuration like AVR069 */
		  		if (dev->config == NULL){
		      	fprintf(stderr,
			      	"%s: usbprog_open(): USB device has no configuration\n",
			      	progname);
		      	goto trynext;
		    	}

					/* select first configuation */
		  		if (usb_set_configuration(udev, dev->config[0].bConfigurationValue)){
		      	fprintf(stderr,
			      	"%s: usbprog_open(): error setting configuration %d: %s\n",
			      	progname, dev->config[0].bConfigurationValue,
			      	usb_strerror());
		      	goto trynext;
		    	}

		 
		 			/* specify interface */
					usb_interface = dev->config[0].interface[0].altsetting[0].bInterfaceNumber;
		  		if (usb_claim_interface(udev, usb_interface)) {
		      	fprintf(stderr,
			      	"%s: usbprog_open(): error claiming interface %d: %s\n",
			      	progname, usb_interface, usb_strerror());
		      	goto trynext;
		    	}

		  		fd->pfd = udev;
          return;
				}
	      trynext:
	      usb_close(udev);
	    }
		}
  }

  fprintf(stderr, "%s: usbprog_open(): did not find any USB device\n",
	  progname);
  exit(1);
}

static void usbprog_close(union filedescriptor *fd)
{
  usb_dev_handle *udev = (usb_dev_handle *)fd->pfd;

  (void)usb_release_interface(udev, usb_interface);

  /*
   * Without this reset, the AVRISP mkII seems to stall the second
   * time we try to connect to it.
   */
  usb_reset(udev);

  usb_close(udev);
}


static int usbprog_send(union filedescriptor *fd, unsigned char *bp, size_t mlen)
{
  usb_dev_handle *udev = (usb_dev_handle *)fd->pfd;
  int rv;
  int i = mlen;
  unsigned char * p = bp;
  int tx_size;

  /*
   * Split the frame into multiple packets.  It's important to make
   * sure we finish with a short packet, or else the device won't know
   * the frame is finished.  For example, if we need to send 64 bytes,
   * we must send a packet of length 64 followed by a packet of length
   * 0.
   */
  do {
    tx_size = (mlen < USBPROG_MAX_XFER)? mlen: USBPROG_MAX_XFER;
    rv = usb_bulk_write(udev, USBPROG_BULK_EP_WRITE, (char *)bp, tx_size, 5000);
    if (rv != tx_size)
    {
        fprintf(stderr, "%s: usbprog_send(): wrote %d out of %d bytes, err = %s\n",
                progname, rv, tx_size, usb_strerror());
        return -1;
    }
    bp += tx_size;
    mlen -= tx_size;
  } while (tx_size == USBPROG_MAX_XFER);

  if (verbose > 3)
  {
      fprintf(stderr, "%s: Sent: ", progname);

      while (i) {
        unsigned char c = *p;
        if (isprint(c)) {
          fprintf(stderr, "%c ", c);
        }
        else {
          fprintf(stderr, ". ");
        }
        fprintf(stderr, "[%02x] ", c);

        p++;
        i--;
      }
      fprintf(stderr, "\n");
  }
  return 0;
}

/*
 * As calls to usb_bulk_read() result in exactly one USB request, we
 * have to buffer the read results ourselves, so the single-char read
 * requests performed by the upper layers will be handled.  In order
 * to do this, we maintain a private buffer of what we've got so far,
 * and transparently issue another USB read request if the buffer is
 * empty and more data are requested.
 */
static int
usb_fill_buf(usb_dev_handle *udev)
{
  int rv;

  rv = usb_bulk_read(udev, USBPROG_BULK_EP_READ, usbbuf, USBPROG_MAX_XFER, 5000);
  if (rv < 0)
    {
      if (verbose > 1)
	fprintf(stderr, "%s: usb_fill_buf(): usb_bulk_read() error %s\n",
		progname, usb_strerror());
      return -1;
    }

  buflen = rv;
  bufptr = 0;

  return 0;
}

static int usbprog_recv(union filedescriptor *fd, unsigned char *buf, size_t nbytes)
{
  usb_dev_handle *udev = (usb_dev_handle *)fd->pfd;
  int i, amnt;
  unsigned char * p = buf;

  for (i = 0; nbytes > 0;)
    {
      if (buflen <= bufptr)
	{
	  if (usb_fill_buf(udev) < 0)
	    return -1;
	}
      amnt = buflen - bufptr > nbytes? nbytes: buflen - bufptr;
      memcpy(buf + i, usbbuf + bufptr, amnt);
      bufptr += amnt;
      nbytes -= amnt;
      i += amnt;
    }

  if (verbose > 3)
  {
      fprintf(stderr, "%s: Recv: ", progname);

      while (i) {
        unsigned char c = *p;
        if (isprint(c)) {
          fprintf(stderr, "%c ", c);
        }
        else {
          fprintf(stderr, ". ");
        }
        fprintf(stderr, "[%02x] ", c);

        p++;
        i--;
      }
      fprintf(stderr, "\n");
  }

  return 0;
}

/*
 * This version of recv keeps reading packets until we receive a short
 * packet.  Then, the entire frame is assembled and returned to the
 * user.  The length will be unknown in advance, so we return the
 * length as the return value of this function, or -1 in case of an
 * error.
 *
 * This is used for the AVRISP mkII device.
 */
static int usbprog_recv_frame(union filedescriptor *fd, unsigned char *buf, size_t nbytes)
{
  usb_dev_handle *udev = (usb_dev_handle *)fd->pfd;
  int rv, n;
  int i;
  unsigned char * p = buf;

  n = 0;
  do
    {
      rv = usb_bulk_read(udev, USBPROG_BULK_EP_READ, usbbuf,
			 USBPROG_MAX_XFER, 10000);
      if (rv < 0)
	{
	  if (verbose > 1)
	    fprintf(stderr, "%s: usbprog_recv_frame(): usb_bulk_read(): %s\n",
		    progname, usb_strerror());
	  return -1;
	}

      if (rv <= nbytes)
	{
	  memcpy (buf, usbbuf, rv);
	  buf += rv;
	}

      n += rv;
      nbytes -= rv;
    }
  while (rv == USBPROG_MAX_XFER);

  if (nbytes < 0)
    return -1;

  if (verbose > 3)
  {
      i = n;
      fprintf(stderr, "%s: Recv: ", progname);

      while (i) {
        unsigned char c = *p;
        if (isprint(c)) {
          fprintf(stderr, "%c ", c);
        }
        else {
          fprintf(stderr, ". ");
        }
        fprintf(stderr, "[%02x] ", c);

        p++;
        i--;
      }
      fprintf(stderr, "\n");
  }
  return n;
}

static int usbprog_drain(union filedescriptor *fd, int display)
{
  usb_dev_handle *udev = (usb_dev_handle *)fd->pfd;
  int rv;

  do {
    rv = usb_bulk_read(udev, USBPROG_BULK_EP_READ, usbbuf, USBPROG_MAX_XFER, 100);
    if (rv > 0 && verbose >= 4)
      fprintf(stderr, "%s: usbprog_drain(): flushed %d characters\n",
	      progname, rv);
  } while (rv > 0);

  return 0;
}
#endif  /* HAVE_LIBUSB */
