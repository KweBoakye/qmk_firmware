#include QMK_KEYBOARD_H

float my_song[][2] = SONG(QWERTY_SOUND);

enum custom_keycodes {
    KC_AUDIO = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_AUDIO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_AUDIO:
            if (record->event.pressed) {
               PLAY_SONG(my_song);
            }
            return false;
    }
    return true;
}
