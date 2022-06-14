#include QMK_KEYBOARD_H

#include "combos.h"
#include "process_combo.h"


enum combos {
  MAINTENENCE_LAYER,
  FUNCTION_LAYER,
  COMBO_LENGTH
};

const uint16_t PROGMEM nav_sym_combo[] = {NAV_ENT, SYM_DEL, COMBO_END};
const uint16_t PROGMEM space_bckspc_combo[] = {NAV_SPC, SYM_BSPC, COMBO_END};
combo_t key_combos[] = {
    [MAINTENENCE_LAYER] = COMBO(nav_sym_combo, MO(_MAINTENANCE)),
    [FUNCTION_LAYER] = COMBO(space_bckspc_combo, MO(_FN)),
};

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    return PROCESS_RECORD_CONTINUE;
}

uint16_t COMBO_LEN = COMBO_LENGTH;
