#include QMK_KEYBOARD_H

#include "combos.h"
#include "process_combo.h"


enum combos {
  MAINTENENCE_LAYER,
  ACTIVATE_NUM_WORD,
  ACTIVATE_NAV_MODE,
  COMBO_LENGTH
};

const uint16_t PROGMEM nav_sym_combo[] = {NAV_ENT, SYM_DEL, COMBO_END};
const uint16_t PROGMEM swap_hands_del_combo[] = {NAV_ENT, SH_DEL, COMBO_END};
const uint16_t PROGMEM space_bckspc_combo[] = {NAV_SPC, SYM_BSPC, COMBO_END};
const uint16_t PROGMEM space_enter_combo[] = {LT(_NAV, KC_SPC), LT(_NAV, KC_ENT), COMBO_END};
combo_t key_combos[] = {
    [MAINTENENCE_LAYER] = COMBO(nav_sym_combo, MO(_MAINTENANCE)),
    [MAINTENENCE_LAYER] = COMBO(swap_hands_del_combo, MO(_MAINTENANCE)),
    [ACTIVATE_NUM_WORD] = COMBO(space_bckspc_combo, NUM_WORD),
    [ACTIVATE_NAV_MODE] = COMBO(space_enter_combo, NAV_MODE),
};

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    return PROCESS_RECORD_CONTINUE;
}

uint16_t COMBO_LEN = COMBO_LENGTH;
