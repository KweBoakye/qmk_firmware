<<<<<<< HEAD
<<<<<<< HEAD:quantum/encoder/tests/mock_split.h
/* Copyright 2021 Balz Guenat
=======
/* Copyright 2020 QMK
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/yanghu/unicorne/f411/mcuconf.h
=======
/* Copyright 2021 Balz Guenat
>>>>>>> c0de397925 (merge bedore pointerwork)
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

<<<<<<< HEAD
<<<<<<< HEAD:quantum/encoder/tests/mock_split.h
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
#include <stdint.h>
#include <stdbool.h>

#define SPLIT_KEYBOARD
<<<<<<< HEAD
typedef uint8_t pin_t;

void encoder_state_raw(uint8_t* slave_state);
void encoder_update_raw(uint8_t* slave_state);
=======
/* Here, "pins" from 0 to 31 are allowed. */
#define ENCODERS_PAD_A \
    { 0 }
#define ENCODERS_PAD_B \
    { 1 }
#define ENCODERS_PAD_A_RIGHT \
    { 2 }
#define ENCODERS_PAD_B_RIGHT \
    { 3 }

typedef uint8_t pin_t;
extern bool     isLeftHand;
void            encoder_state_raw(uint8_t* slave_state);
void            encoder_update_raw(uint8_t* slave_state);
>>>>>>> c0de397925 (merge bedore pointerwork)

extern bool pins[];
extern bool pinIsInputHigh[];

#define setPinInputHigh(pin) (mockSetPinInputHigh(pin))
#define readPin(pin) (mockReadPin(pin))

uint8_t mockSetPinInputHigh(pin_t pin);

bool mockReadPin(pin_t pin);

bool setPin(pin_t pin, bool val);
<<<<<<< HEAD
=======
#include_next <mcuconf.h>

/* TIM1 PWM used for audio driver */
#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE
/* TIM5 GPT used for audio driver */
#undef STM32_GPT_USE_TIM4
#define STM32_GPT_USE_TIM4 TRUE

/* TIM3 used for WS2812 driver */
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE

/* I2C used for OLED display */
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/yanghu/unicorne/f411/mcuconf.h
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
