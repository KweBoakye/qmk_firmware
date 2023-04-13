#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"

//extern uint16_t COMBO_LEN;

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record);