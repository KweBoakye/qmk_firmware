<<<<<<< HEAD
<<<<<<< HEAD:keyboards/handwired/onekey/sipeed_longan_nano/chconf.h
/* Copyright 2021 QMK
=======
/* Copyright 2021
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/40percentclub/polyandry/polyandry.h
=======
/* Copyright 2021 QMK
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
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
<<<<<<< HEAD
#pragma once

<<<<<<< HEAD:keyboards/handwired/onekey/sipeed_longan_nano/chconf.h
=======

#pragma once

>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
#define CH_CFG_ST_RESOLUTION 16

#define CH_CFG_ST_FREQUENCY 10000

#include_next <chconf.h>
<<<<<<< HEAD
=======
#include "quantum.h"

#ifdef KEYBOARD_40percentclub_polyandry_promicro
    #include "promicro.h"
#elif KEYBOARD_40percentclub_polyandry_teensy2
    #include "teensy2.h"
#endif
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/40percentclub/polyandry/polyandry.h
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
