/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

<<<<<<< HEAD:keyboards/ploopyco/trackball_thumb/rev1_001/config.h
// These pins are not broken out, and cannot be used normally.
// They are set as output and pulled high, by default
#define UNUSED_PINS \
    { D1, D3, B4, B7, D6, C7, F6, F5, F3, F7 }
=======
#include "drashna.h"

typedef union {
    uint32_t raw;
    struct {
        bool audio_enable         :1;
        bool audio_clicky_enable  :1;
        bool tap_toggling         :1;
        bool unicode_mode         :1;
        bool swap_hands           :1;
        bool host_driver_disabled :1;
    };
} user_runtime_config_t;

extern user_runtime_config_t user_state;

void keyboard_post_init_transport_sync(void);
>>>>>>> c0de397925 (merge bedore pointerwork):users/drashna/transport_sync.h
