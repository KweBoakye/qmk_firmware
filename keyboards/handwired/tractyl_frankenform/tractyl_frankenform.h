/* Copyright 2021 KweBoakye
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

#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// clang-format off
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, \
    L10, L11, L12, L13, L14, L15, L16, \
    L20, L21, L22, L23, L24, L25, L26, \
    L30, L31, L32, L33, L34, L35, \
              L42, L43, \
                             L45, \
                                  L55, \
                                  L53, L54, \
         R00, R01, R02, R03, R04, R05, R06, \
         R10, R11, R12, R13, R14, R15, R16, \
         R20, R21, R22, R23, R24, R25, R26, \
              R31, R32, R33, R34, R35, R36, \
                        R43, R44, \
              R41,  \
         R51, \
    R52, R53 \
) { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, L26 }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { KC_NO, KC_NO, L42, L43, KC_NO, L45, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, L53, L54, L55, KC_NO }, \
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, R26 }, \
    { KC_NO, R31, R32, R33, R34, R35, R36 }, \
    { KC_NO, R41, KC_NO, R43, R44, KC_NO, KC_NO }, \
    { KC_NO, R51, R52, R53, KC_NO, KC_NO, KC_NO } \
}
// clang-format on

/* typedef union {
  uint32_t raw;
  struct {
      bool    disable_layer_led :1;
      bool    rgb_matrix_enable :1;
      bool    led_level         :1;
      uint8_t led_level_res     :2; // DO NOT REMOVE
      uint8_t dpi_config        :3;
  };
} keyboard_config_t; */

//extern keyboard_config_t keyboard_config;
