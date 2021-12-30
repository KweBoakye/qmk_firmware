/* Copyright 2021 Cutie Club
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
 *              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐      ┌───────┐
 *              │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D │0E │0F │      │0E     │ 2u Backspace
 *              ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤      └─┬─────┤
 *              │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │1F │        │     │
 *  2.25u       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤     ┌──┴┐2D  │ ISO Enter
 *  LShift      │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2D      │2F │     │2C │    │
 * ┌────────┐   ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤   ┌─┴───┴────┤
 * │30      │   │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C    │3D │3F │   │3C        │ 2.75u RShift
 * └────────┘   ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤   └──────────┘
 *              │40  │41  │42  │44      │46  │48        │49 │4A │4B │4C │4D │4F │
 *              └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┴───┘
 *              ┌────┬────┬────┬────────────────────────┬───┬───┬───┐
 *              │40  │41  │42  │46                      │49 │4A │4B │ Standard
 *              └────┴────┴────┴────────────────────────┴───┴───┴───┘
 *              ┌─────┬─────┬───────────────────────────┬─────┬─────┐
 *              │40   │41   │46                         │49   │4A   │ WKL
 *              └─────┴─────┴───────────────────────────┴─────┴─────┘
 *              ┌─────┬───┬─────┬───────────────────────────┬─────┐
 *              │40   │41 │42   │46                         │4A   │ Tsangan
 *              └─────┴───┴─────┴───────────────────────────┴─────┘
 */

#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D,      k1F, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D,      k2F, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C,      k3D, k3F, \
    k40, k41, k42,      k44,      k46,      k48, k49, k4A, k4B,      k4C, k4D, k4F  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, ___, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, ___, k2F }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, ___, k3F }, \
    { k40, k41, k42, ___, k44, ___, k46, ___, k48, k49, k4A, k4B, k4C, k4D, ___, k4F }  \
}

#define LAYOUT_65_ansi( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1F, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k2D, k2F, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3F, \
    k40, k41, k42,                k46,           k49, k4A, k4B, k4C, k4D, k4F  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, ___, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, ___, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, ___, k2D, ___, k2F }, \
    { k30, ___, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, ___, k3F }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, k49, k4A, k4B, k4C, k4D, ___, k4F }  \
}

#define LAYOUT_65_iso( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C,      k1F, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2F, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3F, \
    k40, k41, k42,                k46,           k49, k4A, k4B, k4C, k4D, k4F  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, ___, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, ___, ___, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, ___, k2F }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, ___, k3F }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, k49, k4A, k4B, k4C, k4D, ___, k4F }  \
=======
#define LAYOUT_all( \
    k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15, \
    k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13,         k01_15, \
    k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13,         k02_15, \
    k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12,         k03_13, k03_15, \
    k04_00, k04_01, k04_02,         k04_04,         k04_06,         k04_08, k04_09, k04_10, k04_11,         k04_12, k04_13, k04_15  \
) \
{ \
    { k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15 }, \
    { k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13, KC_NO,  k01_15 }, \
    { k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13, KC_NO,  k02_15 }, \
    { k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12, k03_13, KC_NO,  k03_15 }, \
    { k04_00, k04_01, k04_02, KC_NO,  k04_04, KC_NO,  k04_06, KC_NO,  k04_08, k04_09, k04_10, k04_11, k04_12, k04_13, KC_NO,  k04_15 }  \
>>>>>>> c0de397925 (merge bedore pointerwork)
}
