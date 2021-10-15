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
#include <rgb_matrix.h>
#include "color.h"
#include "cirque_tm040040.h"


// Defines the keycodes used by our macros in process_record_user


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUMPAD 2

float my_song[][2] = SONG(QWERTY_SOUND);

// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // left hand
        KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   TAB_RO,
        OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                                  TAB_L,   TAB_R,
                                                 KC_SPC,
                                                  KC_HOME,
                                                 KC_PSCR, TASK,
        // right hand
                          KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
                          KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                      TG(_NUMPAD), KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                                   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_RSFT),
                                            KC_LEFT, KC_UP,
                      KC_ENT,
                      KC_PGDN,
             KC_LCTL, KC_LALT
    ),

    [_FN] = LAYOUT(
        // left hand
        _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    KC_F6,
        _______,   _______,   _______,    KC_UP,    _______,   _______,  _______,
        _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   _______,  RESET,
        _______,   _______,   _______,   _______,   _______,   _______,
                                KC_MPRV,   KC_MNXT,
                                    _______,
                                    _______,
                                    _______, _______,
        // right hand
                          KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    _______,
                          _______,   _______,   _______,   _______,   _______,   _______,   _______,
                          _______,   _______,   _______,   _______,   _______,   _______,   _______,
                                     _______,   _______,   _______,   _______,   _______,   _______,
                                                           _______,   _______,
                     _______,
                      _______,
             _______, _______
    ),

    [_NUMPAD] = LAYOUT(
        // left hand
        _______,   _______,   _______,   _______,   _______,   _______,  _______,
        _______,   _______,   _______,   _______,   _______,   _______,  _______,
        _______,   _______,   _______,   _______,   _______,   _______,  _______,
        _______,   _______,   _______,   _______,   _______,   _______,
           _______,   _______,
                                    _______,
                                    _______,
                                    _______, _______,
        // right hand
                          _______,   _______,   KC_NLCK,   _______,   KC_PMNS,   KC_PPLS,   _______,
                          _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
                          _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
                                     _______,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
                                                           KC_P0,     KC_PDOT,
                     KC_PENT,
                    _______,
             _______, _______
    ),
};

enum {
    TEST_NEXT_LED = SAFE_RANGE,
};

//static uint8_t test_led_index, test_color;

/* void rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(test_led_index, (test_color == 0) * 255, (test_color == 1) * 255, (test_color == 2) * 255);
} */

void keyboard_post_init_user(void){
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    PLAY_SONG(my_song);
    }
   /*  switch (keycode) {
        case TEST_NEXT_LED:
            if (++test_color > 2) {
                test_color = 0;
                if (++test_led_index >= DRIVER_LED_TOTAL) {
                    test_led_index = 0;
                }
            }
            break;
    } */


    return true;
}

#ifdef OLED_ENABLE
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
} */

void oled_task_user(void) {

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

}
#endif

