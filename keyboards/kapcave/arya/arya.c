/*
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/kapcave/arya/arya.c
Copyright 2021 KapCave
=======
Copyright 2021 Thomas Weißschuh <thomas@t-8ch.de>
>>>>>>> c0de397925 (merge bedore pointerwork):quantum/process_keycode/process_programmable_button.h
=======
Copyright 2021 KapCave
>>>>>>> c0de397925 (merge bedore pointerwork)

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
<<<<<<< HEAD:keyboards/kapcave/arya/arya.c
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
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
<<<<<<< HEAD
=======

#pragma once

#include <stdint.h>
#include "quantum.h"

bool process_programmable_button(uint16_t keycode, keyrecord_t *record);
>>>>>>> c0de397925 (merge bedore pointerwork):quantum/process_keycode/process_programmable_button.h
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
