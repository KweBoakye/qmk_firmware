<<<<<<< HEAD
<<<<<<< HEAD
/* Copyright 2021 Salmon Cat Studio
=======
/* Copyright 2021 bdtc123
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
/* Copyright 2021 bdtc123
=======
/* Copyright 2021 Salmon Cat Studio
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
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
<<<<<<< HEAD

=======
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
=======

>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
#pragma once

#include "quantum.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======
#define LAYOUT_60_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,        \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
    K20,    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D,          \
    K30,       K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,        K3D,     \
    K40,  K41,  K42,              K45,                 K49,  K4A,   K4B,  K4D    \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, KC_NO, K3D   }, \
    { K40,   K41,   K42,   KC_NO, KC_NO, K45,   KC_NO, KC_NO, KC_NO, K49,   K4A,   K4B,   KC_NO, K4D   }, \
}
<<<<<<< HEAD:keyboards/aozora/aozora.h
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,       K0E, K0F,  \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,     K1E, K1F,  \
    K20,    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D,                    \
    K30,       K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3D,           K3E, K3F,  \
    K40,  K41,  K42,              K44,                K48,  K49,  K4A,     K4D, K4E, K4F   \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   KC_NO, KC_NO }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, KC_NO, K3D,   K3E,   K3F   }, \
    { K40,   K41,   K42,   KC_NO, K44,   KC_NO, KC_NO, KC_NO, K48,   K49,   K4A,   KC_NO, KC_NO, K4D,   K4E,   K4F   }, \
}
<<<<<<< HEAD
=======
#define LAYOUT_60_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,        \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
    K20,    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D,          \
    K30,       K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,        K3D,     \
    K40,  K41,  K42,              K45,                 K49,  K4A,   K4B,  K4D    \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, KC_NO, K3D   }, \
    { K40,   K41,   K42,   KC_NO, KC_NO, K45,   KC_NO, KC_NO, KC_NO, K49,   K4A,   K4B,   KC_NO, K4D   }, \
}
<<<<<<< HEAD:keyboards/kprepublic/bm60hsrgb_poker/rev2/rev2.h
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c

#define LAYOUT_all( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0G, K0D,  K0E, K0F,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,       K1E, K1F,  \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,                  \
    K30, K3G, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3C, K3D,       K3E, K3F,  \
    K40,  K41,  K42,              K44,                K48,  K49,  K4A,    K4D,  K4E, K4F   \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F,     K0G  }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   KC_NO  }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, KC_NO, KC_NO  }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C,   K3D,   K3E,   K3F,     K3G  }, \
    { K40,   K41,   K42,   KC_NO, K44,   KC_NO, KC_NO, KC_NO, K48,   K49,   K4A,   KC_NO, KC_NO, K4D,   K4E,   K4F,   KC_NO  }, \
}
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/aozora/aozora.h
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/kprepublic/bm60hsrgb_poker/rev2/rev2.h
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
