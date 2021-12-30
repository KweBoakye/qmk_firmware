/* Copyright 2021 MTBKeys
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

#include "quantum.h"

<<<<<<< HEAD
#define ___ KC_NO

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │11   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
 * ├───┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┬───┤
 * │30 │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c │3d │3e │
 * ├───┴┬──┴─┬─┴──┬┴───┴───┼───┴┬──┴───┴───┼───┼───┼───┼───┼───┤
 * │40  │41  │42  │44      │46  │48        │4a │4b │4c │4d │4e │
 * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
 */

#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
         k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,      \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, \
    k40, k41,      k43, k44,      k46,      k48,      k4a, k4b, k4c, k4d, k4e  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e }, \
    { ___, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e }, \
    { k20, ___, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, ___ }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e }, \
    { k40, k41, ___, k43, k44, ___, k46, ___, k48, ___, k4a, k4b, k4c, k4d, k4e }  \
=======
#define LAYOUT( \
    k00, k10, k20, k30, k40, k50, k60, k70, k80, k90, ka0, kb0, kc0, kd0, ke0, \
         k11, k21, k31, k41, k51, k61, k71, k81, k91, ka1, kb1, kc1, kd1, ke1, \
    k02,      k22, k32, k42, k52, k62, k72, k82, k92, ka2, kb2, kc2, kd2,      \
    k03, k13, k23, k33, k43, k53, k63, k73, k83, k93, ka3, kb3, kc3, kd3, ke3, \
    k04, k14,      k34, k44,      k64,      k84,      ka4, kb4, kc4, kd4, ke4  \
) { \
    { k00,   k10,   k20,   k30, k40, k50,   k60, k70,   k80, k90,   ka0, kb0, kc0, kd0, ke0   }, \
    { KC_NO, k11,   k21,   k31, k41, k51,   k61, k71,   k81, k91,   ka1, kb1, kc1, kd1, ke1   }, \
    { k02,   KC_NO, k22,   k32, k42, k52,   k62, k72,   k82, k92,   ka2, kb2, kc2, kd2, KC_NO }, \
    { k03,   k13,   k23,   k33, k43, k53,   k63, k73,   k83, k93,   ka3, kb3, kc3, kd3, ke3   }, \
    { k04,   k14,   KC_NO, k34, k44, KC_NO, k64, KC_NO, k84, KC_NO, ka4, kb4, kc4, kd4, ke4   }  \
>>>>>>> c0de397925 (merge bedore pointerwork)
}
