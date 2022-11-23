/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>

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

#include "zigotica.h"

static void render_status(void) {
    oled_write_P(PSTR("z12 v1.0\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _VIM:
<<<<<<< HEAD
<<<<<<< HEAD
=======
            oled_write_P(PSTR("VIM\n\nBUFFER       SCROLL"), false);
            break;
        case _FIGMA:
            oled_write_P(PSTR("FIGMA\n\nVOLUME         ZOOM"), false);
            break;
        case _BROWSER:
            oled_write_P(PSTR("BROWSER\n\nTABS         SCROLL"), false);
            break;
        case _TERMINAL:
            oled_write_P(PSTR("TERMINAL\n\nVOLUME       SCROLL"), false);
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
            oled_write_P(PSTR("VIM      \n\nBUFFER         SCROLL"), false);
            break;
        case _FIGMA:
            oled_write_P(PSTR("FIGMA    \n\nTABS             ZOOM"), false);
            break;
        case _BROWSER:
            oled_write_P(PSTR("BROWSER  \n\nTABS           SCROLL"), false);
            break;
        case _BASE:
            oled_write_P(PSTR("BASE     \n\nVOLUME         SCROLL"), false);
<<<<<<< HEAD
=======
            oled_write_P(PSTR("VIM\n\nBUFFER       SCROLL"), false);
            break;
        case _FIGMA:
            oled_write_P(PSTR("FIGMA\n\nVOLUME         ZOOM"), false);
            break;
        case _BROWSER:
            oled_write_P(PSTR("BROWSER\n\nTABS         SCROLL"), false);
            break;
        case _TERMINAL:
            oled_write_P(PSTR("TERMINAL\n\nVOLUME       SCROLL"), false);
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
}

bool oled_task_user(void) {
    render_status();
    return false;
}
