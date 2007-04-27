/***************************************************************************
 *   Copyright (C) 2005 by Dominic Rath                                    *
 *   Dominic.Rath@gmx.de                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef BITBANG_H
#define BITBANG_H
#include "types.h"

#define USBPROG 1			//TODO

typedef struct bitbang_interface_s
{
	/* low level callbacks (for bitbang)
	 */
	int (*read)(void);
	void (*write)(int tck, int tms, int tdi);
	#if USBPROG
	void (*write_tdi)(u8 *buffer, int scan_size);
	void (*read_tdo)(u8 *buffer, int scan_size);
	#endif
	void (*reset)(int trst, int srst);
} bitbang_interface_t;

extern bitbang_interface_t *bitbang_interface;

extern int bitbang_execute_queue(void);

#endif /* BITBANG_H */
