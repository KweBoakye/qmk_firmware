#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_detection.h"

typedef struct {
    os_variant_t type;
} os_t;

bool                    is_macos(void);

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record);
