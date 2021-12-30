<<<<<<< HEAD:keyboards/loki65/loki65.c
/* Copyright 2022 Yiancar-Designs
=======
/* Copyright 2019
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/handwired/onekey/stm32f405_feather/config.h
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 #include "loki65.h"

<<<<<<< HEAD:keyboards/loki65/loki65.c
void led_init_ports(void) {
    // Set our LED pins as open drain outputs
    palSetLineMode(LED_CAPS_LOCK_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
}
=======
#pragma once

#include "config_common.h"

#define PRODUCT Onekey Adafruit Feather STM32F405

#define MATRIX_COL_PINS { C2 }
#define MATRIX_ROW_PINS { C3 }
#define UNUSED_PINS
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/handwired/onekey/stm32f405_feather/config.h
