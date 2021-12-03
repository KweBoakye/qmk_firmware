/* Copyright 2021 KweBoakye
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

#include "tractyl_frankenform.h"
#include "drivers/led/issi/is31fl3731.h"

#include <quantum.h>
#include "analog.h"
#ifdef POINTING_DEVICE_ENABLE
#    include "pointing_device.h"
#    include "cirque_tm040040.h"
#endif



keyboard_config_t keyboard_config;

const is31_led __flash g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0, C1_1,  C2_1,  C3_1},
    {0, C1_2,  C2_2,  C3_2},
    {0, C1_3,  C2_3,  C3_3},
    {0, C1_4,  C2_4,  C3_4},
    {0, C1_5,  C2_5,  C3_5},
    {0, C1_6,  C2_6,  C3_6},
    {0, C1_7,  C2_7,  C3_7},
    {0, C1_8,  C2_8,  C3_8},
    {0, C4_1,  C5_1,  C6_1},
    {0, C4_2,  C5_2,  C6_2},
    {0, C4_3,  C5_3,  C6_3},
    {0, C4_4,  C5_4,  C6_4},
    {0, C4_5,  C5_5,  C6_5},
    {0, C4_6,  C5_6,  C6_6},
    {0, C4_7,  C5_7,  C6_7},
    {0, C4_8,  C5_8,  C6_8},
    {0, C7_1,  C8_1,  C9_1},
    {0, C7_2,  C8_2,  C9_2},
    {0, C7_3,  C8_3,  C9_3},
    {0, C7_4,  C8_4,  C9_4},
    {0, C7_5,  C8_5,  C9_5},
    {0, C7_6,  C8_6,  C9_6},
    {0, C7_7,  C8_7,  C9_7},
    {0, C7_8,  C8_8,  C9_8},

    {0, C7_14,  C8_14,  C9_14},
};


led_config_t g_led_config  = { {
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED },
    {   0,   1, 2,  3, 4, 5, 6 },
    {   8,   9, 10,  11,  12, 13, 7 },
    {   16,   17, 18,  19,  20, 14, 15 },
    {   NO_LED,   24, NO_LED,  NO_LED,  21, 22, 23 },
    {   NO_LED,   NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    { 0,   0 }, { 38,  0 }, { 75,   0  }, { 112,   0  }, {    187,  0 }, { 224,  0 },
    {0,  12 }, { 38,  12 }, { 75,  12 }, { 112,  12 },{150,  25 },{187,  25 }, { 224,  25 },
    {0,  25 }, { 38,  25 }, { 75,  25 }, { 112,  38 },{150,  38 },{187,  38 }, { 224,  38 },
    /*{0,  38 },*/ { 38,  38 },/* { 75,  51 }, { 112,  51 },*/{150,  51 },{187,  51 }, { 224,  51 }//,
    /*{0,  50 }, { 38,  50 }, { 75,  50 }, { 112,  50 },{150,  50 },{187,  50 }, { 224,  50 },*/
    /*{0,  63 }, { 38,  63 }, { 75,  63 }, { 112,  63 },{150,  63 },{187,  63 }, { 224,  63 }*/
}, {
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
        4,        4, 4, 4
} };

void matrix_init_kb(void) {
#if BOOTMAGIC_ENABLE
     setPinInputHigh(A0);
#endif
    // setPinInputHigh(B12);
    keyboard_config.raw = eeconfig_read_kb();

    if (!keyboard_config.dpi_config) {
        keyboard_config.dpi_config = 2;
        eeconfig_update_kb(keyboard_config.raw);
    }
    matrix_init_user();
}



void matrix_scan_kb(void) {
#if BOOTMAGIC_ENABLE
    if (!readPin(A0)) {
        reset_keyboard();
   }
#endif

    /* uint16_t x_val = analogReadPin(B1);
    uint16_t y_val = analogReadPin(B2);
    xprintf("%6d, %6d", x_val, y_val);
    xprintf("\n"); */
    matrix_scan_user();

}


void eeconfig_init_kb(void) {  // EEPROM is getting reset!
    keyboard_config.raw = 0;
    keyboard_config.rgb_matrix_enable = true;
    keyboard_config.led_level = true;
    keyboard_config.led_level_res = 0b11;
    keyboard_config.dpi_config = 2;
    eeconfig_update_kb(keyboard_config.raw);
    eeconfig_init_user();
}
