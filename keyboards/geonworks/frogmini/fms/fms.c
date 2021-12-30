<<<<<<< HEAD:keyboards/geonworks/frogmini/fms/fms.c
/* Copyright 2022 Gondolindrim
=======
/*
 * Copyright 2021 foxx1337 at yahoo dot com
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/massdrop/ctrl/keymaps/foxx1337/hid_protocol.c
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

<<<<<<< HEAD:keyboards/geonworks/frogmini/fms/fms.c
#include "fms.h"

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) led_state.caps_lock ? backlight_enable() : backlight_disable() ;
    return res;
=======
#include QMK_KEYBOARD_H
#include "hid_protocol.h"

uint8_t raw_hid_buffer[RAW_EPSIZE];

void raw_hid_perform_send(void) {
    raw_hid_send(raw_hid_buffer, RAW_EPSIZE);
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/massdrop/ctrl/keymaps/foxx1337/hid_protocol.c
}
