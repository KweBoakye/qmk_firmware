#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    //rgb_matrix_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGB_MATRIX_RAINBOW_PINWHEELS);
}
