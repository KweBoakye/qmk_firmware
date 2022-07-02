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

#define PRODUCT Onekey Blackpill STM32F411

#define MATRIX_COL_PINS { B0 }
#define MATRIX_ROW_PINS { B1 }
#define UNUSED_PINS

#define BACKLIGHT_PIN         A0
#define BACKLIGHT_PWM_DRIVER  PWMD5
#define BACKLIGHT_PWM_CHANNEL 1
#define BACKLIGHT_LEVELS 4

#define RGB_DI_PIN A1

#define ADC_PIN A0

#define I2C_DRIVER        I2CD1
#define I2C1_SCL_PIN      B8
#define I2C1_SCL_PAL_MODE 4
#define  I2C1_SDA_PIN     B9
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         A7
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         A6
#define SPI_MISO_PAL_MODE                    5


//#define I2C1_CLOCK_SPEED  400000
//#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#define SOLENOID_PIN B12
#define SOLENOID_PINS { B12, B13, B14, B15 }
#define SOLENOID_PINS_ACTIVE_STATE { high, high, low }
