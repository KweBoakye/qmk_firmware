// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
};

#define KC_CTES CTL_T(KC_ESC)
#define KC_SFSP SFT_T(KC_SPC)
#define KC_ALBS ALT_T(KC_BSPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                      KC_H,   KC_J,   KC_K,   KC_L, KC_ENT,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_SPC,KC_LALT,KC_LGUI,  LOWER,KC_CTES,   KC_SFSP,  RAISE,KC_ALBS,KC_RCTL,KC_LGUI,XXXXXXX
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_TAB,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT, KC_ENT,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_LCTL, KC_SPC,KC_LSFT,KC_LALT, KC_DEL,                   KC_BSPC,KC_HOME, KC_END,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
     KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                   KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_TAB,KC_UNDS,KC_PLUS,KC_PIPE,KC_TILD,                   KC_COLN,KC_DQUO,  KC_GT,KC_LCBR,KC_RCBR,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_LCTL,KC_MINS, KC_EQL,KC_BSLS, KC_GRV,                   KC_SCLN,KC_QUOT,  KC_LT,KC_LBRC,KC_RBRC,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                     KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_F11, KC_F12,  QK_BOOT,KC_PSCR, KC_INS,                   RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,XXXXXXX,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGBRST,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

<<<<<<< HEAD
=======
const char *read_logo(void) {
  static char logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  return logo;
}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

>>>>>>> c0de397925 (merge bedore pointerwork)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
#endif
            break;
    }
    return true;
}
