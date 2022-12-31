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

#include QMK_KEYBOARD_H
#ifdef RGB_MATRIX_ENABLEkkkkk
#include <rgb_matrix.h>
#include "color.h"
#endif
#ifdef POINTING_DEVICE_ENABLE
#     include "pointing_device.h"
#endif
//#ifdef JOYSTICK_ENABLE
#include "joystick.h"
//#endif
#include "analog.h"
#include "print.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

#include "song_list.h"

#ifdef AUDIO_ENABLE
float my_song[][2] = SONG(QWERTY_SOUND);
#endif

// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

//TD_MACR removed from nav see https://github.com/rafaelromao/keyboards/blob/main/docs/navigation.md

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]  = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_GRV,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,                   KC_RBRC,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_DELETE,     \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   TAB_RO,                    KC_LEFT,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
        OSM(MOD_LSFT),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      KC_BSLS, \
                          KC_LALT,   TAB_R,                                                                    KC_COMMA, KC_DOT, \
                                         KC_SPC,                                            MO(_SYM),       \
                                          KC_LSFT,                                         KC_ENT, \
                                         KC_LCTL, MO(_NAV),                                    KC_BSPC, KC_LALT \
    ),
      [_SYM] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5 , _______,             _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
        _______, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_DOT ,  _______,            _______, _______,KC_AMPR, SCOPE  , KC_LBRC, KC_RBRC, KC_PERC,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,  _______,            _______, _______, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES,
        _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR,                                  _______, KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT  ,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     KC_ACCEL,                              _______,
                                                     _______, _______,            _______, _______
    ),
     [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______, KC_ESC , KC_LEAD, SS_SELW, OS_RALT, _______,  _______,            _______, _______, KC_APP,  KC_PGUP , KC_LBRC, KC_RBRC, KC_PERC,
        _______, SS_SWIN, KC_LALT, OS_LCTL, KC_LSFT, _______,  _______,            _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUES,
        _______, KC_TAB , XXXXXXX , _______ , OS_LGUI ,  UPDIR,                              _______, KC_INS, KC_HOME , KC_END, KC_RCBR, KC_DEL  ,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     KC_ACCEL,                              _______,
                                                     _______, _______,            _______, _______
    ),

 [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, KC_WH_U, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, KC_WH_D, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN6, DPI_CONFIG,
        _______, _______, _______, _______, _______, _______,                              KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               KC_BTN3,
                                                     KC_ACCEL,                              _______,
                                                     _______, _______,            _______, _______
    ),
    [_MAINTENANCE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, KC_WH_U, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, KC_WH_D, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN6, DPI_CONFIG,
        _______, _______, _______, _______, _______, _______,                              KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               KC_BTN3,
                                                     KC_ACCEL,                              _______,
                                                     _______, _______,            _______, _______
    ),
};

