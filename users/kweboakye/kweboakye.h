#pragma once
#include QMK_KEYBOARD_H

#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/wrappers.h"
#include "keyrecords/process_records.h"
#include "keyrecords/process_record_result.h"
#include "keyrecords/os_toggle.h"
#include "keyrecords/combos.h"
#include "keyrecords/taphold.h"
#include "keyrecords/caps_word.h"
#include "keyrecords/achordion.h"
#include "keyrecords/select_word.h"
#include "keyrecords/casemodes.h"
//#include "keyrecords/default_mod_key.h"
#include "eeprom.h"
#include "callbacks.h"

#if defined(OLED_ENABLE)
#    include "oled/oled.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
#    include "pointing/pointing.h"
#endif

#ifdef SPLIT_KEYBOARD
#    include "split/transport_sync.h"
#endif


typedef union {
    uint32_t raw;
    struct {
        bool    rgb_layer_change     :1;
        bool    is_overwatch         :1;
        bool    nuke_switch          :1;
        bool    swapped_numbers      :1;
        bool    rgb_matrix_idle_anim :1;
        bool    autocorrection       :1;
        bool    anim_displaying :1;
    };
} userspace_config_t;
// clang-format on

extern userspace_config_t userspace_config;
