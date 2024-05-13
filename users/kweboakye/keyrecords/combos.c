#include QMK_KEYBOARD_H

#include "combos.h"
#include "process_combo.h"


enum combos {
  MAINTENENCE_LAYER,
  ACTIVATE_NUM_WORD,
  ACTIVATE_NAV_MODE,
  Q_W_TAB_COMBO,
  COMMA_DOT_BACK_COMBO,
  COMMA_SLASH_FORWARD_COMBO,
  NAV_SPC_SH_DEL_NUMPAD_COMBO,
  SPC_LSFT_NUMPAD_TOGGLE_COMBO,
  E_COMMA_SCROLL_UP_COMBO,
  I_DOT_SCROLL_DOWN_COMBO,
  COMBO_LENGTH
};

const uint16_t PROGMEM nav_sym_combo[] = {NAV_ENT, SYM_DEL, COMBO_END};
const uint16_t PROGMEM swap_hands_del_combo[] = {NAV_ENT, SH_DEL, COMBO_END};
const uint16_t PROGMEM space_bckspc_combo[] = {NAV_SPC, SYM_BSPC, COMBO_END};
const uint16_t PROGMEM space_enter_combo[] = {LT(_NAV, KC_SPC), LT(_NAV, KC_ENT), COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_slash_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM nav_spc_swap_hands_del_combo[] = {NAV_SPC,  SH_DEL, COMBO_END};
const uint16_t PROGMEM spc_lsft_combo[] = {KC_SPC,  KC_LSFT, COMBO_END};
const uint16_t PROGMEM e_comma_combo[] = {RSFT_T(KC_E),KC_COMMA, COMBO_END};
const uint16_t PROGMEM i_dot_combo[] = {LALT_T(KC_I), KC_DOT, COMBO_END};
//const uint16_t PROGMEM h_comma_combo[] = {KC_H,KC_COMMA, COMBO_END};
//const uint16_t PROGMEM shift_nav_ent_combo[] = {KC_LSFT, NAV_ENT,COMBO_END};
combo_t key_combos[] = {
    [MAINTENENCE_LAYER] = COMBO(nav_sym_combo, MO(_MAINTENANCE)),
    [MAINTENENCE_LAYER] = COMBO(swap_hands_del_combo, MO(_MAINTENANCE)),
  //  [MAINTENENCE_LAYER] = COMBO(shift_nav_ent_combo, MO(_MAINTENANCE)),
    [ACTIVATE_NUM_WORD] = COMBO(space_bckspc_combo, NUM_WORD),
    [ACTIVATE_NAV_MODE] = COMBO(space_enter_combo, NAV_MODE),
    [Q_W_TAB_COMBO] = COMBO(q_w_combo, KC_TAB),
    [COMMA_DOT_BACK_COMBO] = COMBO(comma_dot_combo, KC_BTN4),
    [COMMA_SLASH_FORWARD_COMBO] = COMBO(dot_slash_combo, KC_BTN5),
    [NAV_SPC_SH_DEL_NUMPAD_COMBO] = COMBO(nav_spc_swap_hands_del_combo, TT(_NUMPAD)),
    [SPC_LSFT_NUMPAD_TOGGLE_COMBO] = COMBO(spc_lsft_combo, TG(_NUMPAD)),
    [E_COMMA_SCROLL_UP_COMBO] = COMBO(e_comma_combo, SCRLL_UP),
    [I_DOT_SCROLL_DOWN_COMBO] = COMBO(i_dot_combo, SCRLL_DN)
};

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    return PROCESS_RECORD_CONTINUE;
}

uint16_t COMBO_LEN = COMBO_LENGTH;

