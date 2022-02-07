#include QMK_KEYBOARD_H
#include "haptic.h"

enum custom_keycodes {
    KC_HAPTIC = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_HAPTIC)
};

void keyboard_post_init_user(void){
haptic_toggle_continuous();
}
