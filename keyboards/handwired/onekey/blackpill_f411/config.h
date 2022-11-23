/* Copyright 2019
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

#pragma once

#include "config_common.h"

#define BACKLIGHT_PWM_DRIVER  PWMD5
#define BACKLIGHT_PWM_CHANNEL 1

#define ADC_PIN A0

#define I2C_DRIVER        I2CD1
#define I2C1_SCL_BANK     GPIOB
#define I2C1_SDA_BANK     GPIOB
#define I2C1_SCL          8
#define I2C1_SDA          9
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
//#define I2C1_CLOCK_SPEED  400000
//#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
