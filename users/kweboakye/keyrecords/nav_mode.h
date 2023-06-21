#pragma once
#include QMK_KEYBOARD_H
#include "process_record_result.h"

bool nav_mode_enabled(void);

void enable_nav_mode(void);

// Turn nav mode off.
void disable_nav_mode(void);

// Handle each key for nav mode.
process_record_result_t process_record_nav_mode(uint16_t keycode, keyrecord_t *record);
