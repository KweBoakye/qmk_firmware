<<<<<<< HEAD
<<<<<<< HEAD:keyboards/takashicompany/dogtag/dogtag.c
/* Copyright 2021 takashicompany
=======
/* Copyright 2021 paprikman
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/paprikman/albacore/albacore.c
=======
/* Copyright 2021 takashicompany
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
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

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD:keyboards/takashicompany/dogtag/dogtag.c
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
#include "dogtag.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    keypos_t key;
    if (index == 0) {
        if (clockwise) {
            key.row = 2;
            key.col = 1;
        } else {
            key.row = 2;
            key.col = 0;
        }
        uint8_t layer = layer_switch_get_layer(key);
        uint16_t keycode = keymap_key_to_keycode(layer, key);

        tap_code16(keycode);
    } else {
        if (clockwise) {
            key.row = 5;
            key.col = 0;
        } else {
            key.row = 5;
            key.col = 1;
        }
        uint8_t  layer   = layer_switch_get_layer(key);
        uint16_t keycode = keymap_key_to_keycode(layer, key);

        tap_code16(keycode);
=======
<<<<<<< HEAD:keyboards/takashicompany/compacx/compacx.c
#include "compacx.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (!clockwise) {
        tap_code(KC_MS_WH_UP);
    } else {
        tap_code(KC_MS_WH_DOWN);
=======
#include "dogtag.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
    } else {
        tap_code(KC_MS_WH_UP);
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/takashicompany/dogtag/dogtag.c
>>>>>>> c0de397925 (merge bedore pointerwork)
    }

    return true;
}
<<<<<<< HEAD
=======
#include "albacore.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  { 0, 1, 2, 3 },
  { 7, 6, 5, 4 }
}, {
  { 56, 16 }, { 112, 16 }, { 168, 16 }, { 224, 16 },
  { 56, 24 }, { 112, 24 }, { 168, 24 }, { 224, 24 }
}, {
    1, 1, 1, 1,
    1, 1, 1, 1
} };
#endif
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/paprikman/albacore/albacore.c
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
