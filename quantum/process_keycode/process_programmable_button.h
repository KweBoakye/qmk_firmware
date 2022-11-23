<<<<<<< HEAD
<<<<<<< HEAD:quantum/process_keycode/process_programmable_button.h
/*
<<<<<<< HEAD
Copyright 2021 Thomas Weißschuh <thomas@t-8ch.de>
=======
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/kapcave/arya/arya.c
Copyright 2021 KapCave
=======
Copyright 2021 Thomas Weißschuh <thomas@t-8ch.de>
>>>>>>> c0de397925 (merge bedore pointerwork):quantum/process_keycode/process_programmable_button.h
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/z34/keymaps/zigotica/config.h
=======
/*
Copyright 2021 Thomas Weißschuh <thomas@t-8ch.de>
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
<<<<<<< HEAD
=======
<<<<<<< HEAD:keyboards/kapcave/arya/arya.c
#include "arya.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
=======
>>>>>>> c0de397925 (merge bedore pointerwork)

#pragma once

<<<<<<< HEAD
<<<<<<< HEAD:quantum/process_keycode/process_programmable_button.h
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
#include <stdint.h>
#include "quantum.h"

bool process_programmable_button(uint16_t keycode, keyrecord_t *record);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c0de397925 (merge bedore pointerwork):quantum/process_keycode/process_programmable_button.h
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
#include "config_common.h"

#define MASTER_RIGHT

// these should work better for homerow modifiers
#define TAPPING_TERM 350
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/z34/keymaps/zigotica/config.h
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
