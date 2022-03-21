#pragma once
#include QMK_KEYBOARD_H
#include "drivers/haptic/DRV2605L.h"
#include "../definitions/keycodes.h"
#include "../definitions/layers.h"
#include "persistent_layers.h"
#include "../kweboakye.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record);
 bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
