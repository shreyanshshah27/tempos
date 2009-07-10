/**
 * Copyright (C) 2009 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: timer.h
 *
 * This file is part of TempOS.
 *
 * TempOS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * TempOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef TIMER_H

	#define TIMER_H

	#include <unistd.h>

	/* System timer (Hz) */
	#define HZ	1000

	#define TIMER_IRQ	0


	/* Alarm struct */
	struct _alarm_t {
		uint32_t expires;
		void (*handler)(int);
		uint32_t arg; /* argument to handler */
	};

	typedef struct _alarm_t alarm_t;

	void init_timer(void);
	int new_alarm(uint32_t expires, void (*handler)(int), uint32_t arg);

#endif /* TIMER_H */

