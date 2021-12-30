<<<<<<< HEAD
/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>
=======
<<<<<<< HEAD:quantum/process_keycode/process_programmable_button.h
/*
Copyright 2021 Thomas Weißschuh <thomas@t-8ch.de>
=======
/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/z34/keymaps/zigotica/config.h
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea

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

#pragma once

<<<<<<< HEAD
=======
<<<<<<< HEAD:quantum/process_keycode/process_programmable_button.h
#include <stdint.h>
#include "quantum.h"

bool process_programmable_button(uint16_t keycode, keyrecord_t *record);
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
#include "config_common.h"

#define MASTER_RIGHT

// these should work better for homerow modifiers
#define TAPPING_TERM 350
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

<<<<<<< HEAD
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/z34/keymaps/zigotica/config.h
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
