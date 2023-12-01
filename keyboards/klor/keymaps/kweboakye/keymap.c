#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "klor.h"
#include "kweboakye.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif //HAPTIC ENABLE

#define LAYOUT_polydactyl_wrapper(...) LAYOUT_polydactyl(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌───────────────────────────────────────────────────────────┐
   │ c o l e m a k                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    F    │    P    │    G    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    J    │    L    │    U    │    Y    │    ;    │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   TAB   │    A    │    R    │    S    │    T    │    D    ├─╯                ╰─┤    H    │    N    │    E    │    I    │    O    │    "    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   DEL   │    Z    │    X    │    C    │    V    │    B    ││ SHIFT  ││PLY/PSE ││    K    │    M    │    ,    │    .    │    /    │  SHIFT  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  CTRL   │  LOWER  │  SPACE  │   ALT   ││ CMD/WIN │  ENTER  │  RAISE  │  BSPCE  │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_COLEMAK_MOD_DH] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ______________COLEMAK_MOD_DH_L1____________,                          ______________COLEMAK_MOD_DH_R1____________,  
    KC_TAB,   _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____,                          _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____,    KC_QUOT,
    KC_BTN4,     ______________COLEMAK_MOD_DH_L3____________,     KC_LSFT,   KC_MPLY,  ______________COLEMAK_MOD_DH_R3____________,  KC_BTN5,
                                  NAV_SPC,  SH_DEL, OSM(MOD_LSFT),OSM(MOD_LCTL), OSL(_UNICODE),  KC_LGUI,  NAV_ENT,    SYM_BSPC
 ),
 [_SYM] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ___________________SYM_LEFT_1___________________,                          ___________________SYM_RIGHT_1___________________,  
    KC_TAB,   ___________________SYM_LEFT_2___________________,                          ___________________SYM_RIGHT_2___________________,    KC_QUOT,
    _______,   ___________________SYM_LEFT_3___________________, KC_LSFT,   KC_MPLY,  ___________________SYM_RIGHT_3___________________,  _______,
                                  MO(_FN),  _______, _______,_______, _______, _______,  _______,    _______
 ),
 [_NAV] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ___________________SYM_LEFT_1___________________,                          ___________________SYM_RIGHT_1___________________,  
    KC_TAB,   ___________________SYM_LEFT_2___________________,                          ___________________SYM_RIGHT_2___________________,    KC_QUOT,
    _______,   ___________________SYM_LEFT_3___________________,     KC_LSFT,   KC_MPLY,  ___________________SYM_RIGHT_3___________________,  _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    MO(_FN)
 ),
 [_NAV] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              _________________FUNC_LEFT_________________,                          _________________FUNC_RIGHT________________,  
    KC_TAB,   ________________NUMBER_LEFT________________,                          ________________NUMBER_RIGHT_______________,    KC_QUOT,
    _______,   _______ , KC_MINS , KC_ASTR , KC_PLUS ,  KC_SPC,     KC_LSFT,   KC_MPLY,   _______, _______ , _______, _______, _______,  _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    _______
 ),
  [_MAINTENANCE] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ________________MAINTANENCE_LEFT_1_______________,                          ________________MAINTANENCE_RIGHT_1______________,  
    KC_TAB,   ________________MAINTANENCE_LEFT_2_______________,                          ________________MAINTANENCE_RIGHT_2______________,    KC_QUOT,
    _______,   ________________MAINTANENCE_LEFT_3_______________,     KC_LSFT,   KC_MPLY,  ________________MAINTANENCE_RIGHT_3______________, _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    _______
 ),

};

painter_device_t display;
void keyboard_post_init_keymap(void) {
display = qp_st7789_make_spi_device(240, 135, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 0);  
qp_init(display,QP_ROTATION_0);
}

