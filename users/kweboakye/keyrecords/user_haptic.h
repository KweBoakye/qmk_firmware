#pragma once
#include "quantum.h"
#include "haptic.h"

typedef union {
    uint32_t raw;
    struct {
        uint16_t keycode;
        keyrecord_t *record;
        uint8_t haptic_feedback;
    };
    } haptic_sync_t;
