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
#ifdef POINTING_DEVICE_ENABLE
#     include "pointing_device.h"
#endif
//#ifdef JOYSTICK_ENABLE
#include "joystick.h"
//#endif
#include "analog.h"
#include "print.h"
#include "audio.h"
#include "song_list.h"
float my_song[][2] = SONG(QWERTY_SOUND);

void matrix_scan_user() {
    /* int16_t val = (((uint32_t)timer_read() % 5000 - 2500) * 255) / 5000;

    if (val != joystick_status.axes[1]) {
        joystick_status.axes[1] = val;
        joystick_status.status |= JS_UPDATED;
    } */
}

/* #ifdef JOYSTICK_ENABLE
//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
   [0] = JOYSTICK_AXIS_IN(B0, 141, 490, 810),
    [1] = JOYSTICK_AXIS_IN(B1, 224, 534, 811)
};
#endif */

// Defines the keycodes used by our macros in process_record_user


enum custom_keycodes {
    KC_AUDIO = SAFE_RANGE,
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUMPAD 2


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
                                  KC_LALT,   TAB_R,
                                                 KC_SPC,
                                                  KC_HOME,
                                                 KC_PSCR, TASK,
        // right hand
                          KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
                          KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                      KC_LEFT, KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                                   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_RSFT),
                                            KC_LEFT, KC_UP,
                      KC_ENT,
                      KC_PGDN,
             KC_LCTL, KC_LALT
    ),

    [_FN] = LAYOUT(
        // left hand
        _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    KC_F6,
        _______,   _______,   _______,    _______,    _______,   _______,  _______,
        _______,   KC_LEFT,   KC_DOWN,    KC_UP,  KC_RGHT,   _______,  RESET,
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





//static uint8_t test_led_index, test_color;

/* void rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(test_led_index, (test_color == 0) * 255, (test_color == 1) * 255, (test_color == 2) * 255);
} */

void keyboard_post_init_user(void){
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    if (is_keyboard_master()) {
		rgb_matrix_sethsv_noeeprom(HSV_GOLD);
	} else {
		rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
	}

    // Customise these values to desired behaviour

  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case KC_7:
            if (record->event.pressed) {
               PLAY_SONG(my_song);
            }
            return true;
    }
    return true;
}



/* #ifdef OLED_ENABLE

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
#endif */

void matrix_init_user(void) {
    // init pin? Is needed?
 /* #ifdef POINTING_DEVICE_ENABLE
    setPinInputHigh(B12);
    // Account for drift
    xOrigin = analogReadPin(B0);
    yOrigin = analogReadPin(B1);
#endif */
}

