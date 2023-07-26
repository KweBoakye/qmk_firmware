// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    keyboard_post_init_user();
}

#if RGB_MATRIX_ENABLE
const is31_led __flash g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |        G location
 *   |  |        |        B location
 *   |  |        |        | */
    {0, CS18_SW1, CS17_SW1, CS16_SW1},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
 {0}
}, {
  // LED Index to Physical Position
  {112, 32}
}, {
  // LED Index to Flag
  4
} };
#endif