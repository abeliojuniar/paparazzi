/*
 * $Id$
 *  
 * Copyright (C) 2009 Antoine Drouin <poinix@gmail.com>
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA. 
 */

#include <stm32/rcc.h>
#include <stm32/gpio.h>

#include <stm32/flash.h>
#include <stm32/misc.h>

#include BOARD_CONFIG
#include "init_hw.h"
#include "sys_time.h"

static inline void main_init( void );
static inline void main_periodic( void );

int main(void) {

  main_init();

  while (1) {
    if (sys_time_periodic())
      main_periodic();
  }
  return 0;
}

static inline void main_init( void ) {
  hw_init();
  sys_time_init();
}

static inline void main_periodic( void ) {
  uart1_transmit('a');
  uart1_transmit('b');
  uart1_transmit('c');
  uart1_transmit('\r');
  uart1_transmit('\n');
  uart2_transmit('d');
  uart2_transmit('e');
  uart2_transmit('f');
  uart2_transmit('\r');
  uart2_transmit('\n');
  uart3_transmit('g');
  uart3_transmit('h');
  uart3_transmit('i');
  uart3_transmit('\r');
  uart3_transmit('\n');
}



