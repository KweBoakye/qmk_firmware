/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once
#include "config_common.h"

<<<<<<< HEAD
=======
/* USB Device descriptor parameter */
#define VENDOR_ID       0xC88B
#define PRODUCT_ID      0x3388
#define DEVICE_VER      0x0003
#define MANUFACTURER    DPB
#define PRODUCT         Macro3

>>>>>>> c0de397925 (merge bedore pointerwork)
/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4

/* key matrix pins */
<<<<<<< HEAD
#define DIRECT_PINS {   \
=======
#define DIRECT_PINS { \
>>>>>>> c0de397925 (merge bedore pointerwork)
    { D7, C6, D4, D1 }, \
    { B1, B4, B5, B3 }  \
}

#define ENCODERS_PAD_A { D2, F7 }
#define ENCODERS_PAD_B { D3, F6 }

<<<<<<< HEAD
=======
#define UNUSED_PINS
>>>>>>> c0de397925 (merge bedore pointerwork)

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

<<<<<<< HEAD
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
