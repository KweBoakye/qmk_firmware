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

    bool  get_haptic_enabled_key_custom(uint16_t keycode, keyrecord_t *record);
    void user_haptic_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer);
    bool should_primary_send_haptic(uint16_t keycode, keyrecord_t *record);
    void send_haptic(uint8_t drv_effect);
    bool check_is_combo(uint16_t keycode);
