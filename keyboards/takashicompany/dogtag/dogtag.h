<<<<<<< HEAD
/* Copyright 2021 takashicompany
=======
<<<<<<< HEAD:keyboards/dailycraft/stickey4/stickey4.h
/* Copyright 2021 yfuku
=======
/* Copyright 2021 takashicompany
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/takashicompany/dogtag/dogtag.h
>>>>>>> c0de397925 (merge bedore pointerwork)
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
<<<<<<< HEAD
#define LAYOUT( \
    l01, l02, l03, l04,           r01, r02, r03, r04,   \
    l05, l06, l07, l08, l09, r05, r06, r07, r08, r09,   \
                   l10, l11, r10, r11                   \
) { \
    { l01, l02, l03, l04, KC_NO },      \
    { l05, l06, l07, l08, l09 },        \
    { l10, l11, KC_NO, KC_NO, KC_NO },   \
    { KC_NO, r01, r02, r03, r04},      \
    { r05, r06, r07, r08, r09 },        \
    { r10, r11, KC_NO, KC_NO, KC_NO }    \
=======

#define LAYOUT( \
<<<<<<< HEAD:keyboards/dailycraft/stickey4/stickey4.h
    k00, k01, k02, k03, \
    k04, k05, k06, k07 \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07 } \
=======
    l01, l02, l03, l04,           r01, r02, r03, r04,\
    l05, l06, l07, l08, l09, r05, r06, r07, r08, r09 \
) { \
    { l01, l02, l03, l04, KC_NO }, \
    { l05, l06, l07, l08, l09 },   \
    { KC_NO, r01, r02, r03, r04,}, \
    { r05, r06, r07, r08, r09 }    \
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/takashicompany/dogtag/dogtag.h
>>>>>>> c0de397925 (merge bedore pointerwork)
}
