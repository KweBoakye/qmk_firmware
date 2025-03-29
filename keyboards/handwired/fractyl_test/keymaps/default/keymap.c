// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
   [0] = LAYOUT(
 // ╷╷         ╷         ╷         ╷         ╷         ╷         ╷ 
                KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  
                KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
      KC_LGUI,  KC_ENT,   KC_BSPC
 ),
};

void keyboard_post_init_keyboard(void){
     debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;

  #if RGB_MATRIX_ENABLE
    rgb_matrix_enable();
     rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR );
    rgb_matrix_sethsv(170, 255, 255); // set default RGB color to yellow
  #endif //RGB_MATRIX_ENABLE
}