/* Copyright 2020
   Sergi Meseguer <zigotica@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "zigotica.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======

// Custom Keycodes
#define MODE_1 TO(_TERMINAL)
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
#include "raw_hid.h"

#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t* data, uint8_t length) {
    layer_clear();
    if (data[0] == 99) {
        layer_on(_BASE);
    }
    else {
        layer_on(data[0]);
    }
}
#endif

// Custom Keycodes
#define MODE_1 TO(_BASE)
<<<<<<< HEAD
=======

// Custom Keycodes
#define MODE_1 TO(_TERMINAL)
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
#define MODE_2 TO(_FIGMA)
#define MODE_3 TO(_BROWSER)
#define MODE_4 TO(_VIM)

enum custom_keycodes {
<<<<<<< HEAD
<<<<<<< HEAD
=======
    VIM_SIP = SAFE_RANGE
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
    VIM_SIF = SAFE_RANGE,
    VIM_SIP,
    VIM_RIF,
    VIM_RIP,
    VIM_NEW
<<<<<<< HEAD
=======
    VIM_SIP = SAFE_RANGE
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
        case VIM_SIP:
            if (record->event.pressed) {
                register_code(KC_ESC);
                SEND_STRING(":Ag ");
            } else {
                // released
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
        case VIM_SIF:// Search in File
            if (record->event.pressed) {
                register_code(KC_ESC);
                tap_code(KC_SLASH);
            } else { // released
                unregister_code(KC_ESC);
            }
        break;
        case VIM_SIP:// Search in Project
            if (record->event.pressed) {
                register_code(KC_ESC);
                SEND_STRING(":Ag ");
            } else { // released
                unregister_code(KC_ESC);
            }
        break;
        case VIM_RIF:// Replace in File
            if (record->event.pressed) {
                register_code(KC_ESC);
                SEND_STRING(":%s/a/b/g");
            } else { // released
                unregister_code(KC_ESC);
            }
        break;
        case VIM_RIP:// Replace in Project
            if (record->event.pressed) {
                register_code(KC_ESC);
                SEND_STRING(":cdo %s/a/b/g");
            } else { // released
                unregister_code(KC_ESC);
            }
        break;
        case VIM_NEW:// New buffer
            if (record->event.pressed) {
                SEND_STRING("\e:vnew\n");
            } else { // released
                unregister_code(KC_ENT);
<<<<<<< HEAD
=======
        case VIM_SIP:
            if (record->event.pressed) {
                register_code(KC_ESC);
                SEND_STRING(":Ag ");
            } else {
                // released
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
                unregister_code(KC_ESC);
            }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
<<<<<<< HEAD
<<<<<<< HEAD
=======
 * TERMINAL Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  VOL  | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    | MEDIA |   o   |   o   |
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
 * BASE Layer
 *
 * ,-----------------------------.
 * |       | BASE | FIGM |       |
 * |-------+------+------+-------|
 * |VOL/PLY| BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
<<<<<<< HEAD
=======
 * TERMINAL Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  VOL  | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    | MEDIA |   o   |   o   |
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
<<<<<<< HEAD
<<<<<<< HEAD
    [_BASE] = LAYOUT(
=======
    [_TERMINAL] = LAYOUT(
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
    [_TERMINAL] = LAYOUT(
=======
    [_BASE] = LAYOUT(
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
               MODE_1, MODE_2,
    ZK_MEDIA,  MODE_3, MODE_4,  _______,
    _______,      _______,      _______,
    _______,      _______,      _______
    ),
/*
<<<<<<< HEAD
<<<<<<< HEAD
=======
 * VIM Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |BUFFER | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SEARCH |   o   |   o   |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_VIM] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    VIM_SIP,      _______,      _______,
    _______,      _______,      _______
    ),
/*
 * FIGMA Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  VOL  | BROW |  VIM | ZOOM  |
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    | ZOOM  | GRIDS |  FULL |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_FIGMA] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    LSFT(KC_1), LCTL(KC_G), LGUI(KC_BSLS),
    _______,      _______,      _______
    ),
/*
 * BROWSER Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  TABS | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SEARCH | BOOKM | DEVTL |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_BROWSER] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    G(KC_F),      G(KC_D),   G(A(KC_I)),
    _______,      _______,      _______
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
 * FIGMA Layer
 *
 * ,-----------------------------.
 * |       | BASE | FIGM |       |
 * |-------+------+------+-------|
 * |  TABS | BROW |  VIM | ZOOM  |
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |ZOOMFIT| GRIDS |  FULL |
 *    |-------+-------+-------|
 *    |ZOOM100|  NEXT | COLOR |
 *    |-------+-------+-------|
 */
    [_FIGMA] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    LSFT(KC_1), LCTL(KC_G), LGUI(KC_BSLS),
    LSFT(KC_0), KC_N,       LCTL(KC_C)
    ),
/*
 * BROWSER Layer
 *
 * ,-----------------------------.
 * |       | BASE | FIGM |       |
 * |-------+------+------+-------|
 * |  TABS | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SEARCH | BOOKM | DEVTL |
 *    |-------+-------+-------|
 *    |ZOOM100| MUTE  | READ  |
 *    |-------+-------+-------|
 */
    [_BROWSER] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    G(KC_F),   G(KC_D),   G(A(KC_I)),
    G(KC_0),   C(KC_M),   G(A(KC_R))
    ),
/*
 * VIM Layer
 *
 * ,-----------------------------.
 * |       | BASE | FIGM |       |
 * |-------+------+------+-------|
 * |BUFFER | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SRCH FL|REPL FL|NEW BUF|
 *    |-------+-------+-------|
 *    |SRCH PR|REPL PR|   o   |
 *    |-------+-------+-------|
 */
    [_VIM] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    VIM_SIF,      VIM_RIF,      VIM_NEW,
    VIM_SIP,      VIM_RIP,      _______
<<<<<<< HEAD
=======
 * VIM Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |BUFFER | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SEARCH |   o   |   o   |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_VIM] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    VIM_SIP,      _______,      _______,
    _______,      _______,      _______
    ),
/*
 * FIGMA Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  VOL  | BROW |  VIM | ZOOM  |
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    | ZOOM  | GRIDS |  FULL |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_FIGMA] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    LSFT(KC_1), LCTL(KC_G), LGUI(KC_BSLS),
    _______,      _______,      _______
    ),
/*
 * BROWSER Layer
 *
 * ,-----------------------------.
 * |       | TERM | FIGM |       |
 * |-------+------+------+-------|
 * |  TABS | BROW |  VIM | SCROLL|
 * |-------+------+------+-------|
 *    |-------+-------+-------|
 *    |SEARCH | BOOKM | DEVTL |
 *    |-------+-------+-------|
 *    |   o   |   o   |   o   |
 *    |-------+-------+-------|
 */
    [_BROWSER] = LAYOUT(
             _______, _______,
    _______, _______, _______,  _______,
    G(KC_F),      G(KC_D),   G(A(KC_I)),
    _______,      _______,      _______
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
    ),
};
