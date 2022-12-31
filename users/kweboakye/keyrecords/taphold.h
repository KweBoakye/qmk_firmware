#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../kweboakye.h"

bool get_tapping_force_hold_result(uint16_t keycode);

uint16_t get_tapping_term_result(uint16_t keycode);

bool get_retro_tapping_result(uint16_t keycode);

process_record_result_t proccess_record_taphold(uint16_t keycode, keyrecord_t *record);
