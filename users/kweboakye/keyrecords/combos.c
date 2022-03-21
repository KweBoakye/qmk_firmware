#include QMK_KEYBOARD_H

#include "combos.h"


enum combos {
  MAINTENENCE_LAYER,
};

const uint16_t PROGMEM nav_sym_combo[] = {MO(_NAV), MO(_SYM), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [MAINTENENCE_LAYER] = COMBO(nav_sym_combo, MO(_MAINTENANCE)),
};

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    return PROCESS_RECORD_CONTINUE;
}