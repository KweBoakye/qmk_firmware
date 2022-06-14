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

#include QMK_KEYBOARD_H
#ifdef RGB_MATRIX_ENABLE
#include <rgb_matrix.h>
#include "color.h"
#endif
#ifdef POINTING_DEVICE_ENABLE
#     include "pointing_device.h"
#endif
//#ifdef JOYSTICK_ENABLE
#include "joystick.h"
//#endif
#include "analog.h"
#include "print.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "kweboakye.h"

#include "song_list.h"
#include "dip_switch.h"

#ifdef AUDIO_ENABLE
float my_song[][2] = SONG(QWERTY_SOUND);
#endif

extern keymap_config_t keymap_config;

/* void matrix_scan_user() {
    int16_t val = (((uint32_t)timer_read() % 5000 - 2500) * 255) / 5000;

    if (val != joystick_status.axes[1]) {
        joystick_status.axes[1] = val;
        joystick_status.status |= JS_UPDATED;
    }
} */

/* #ifdef JOYSTICK_ENABLE
//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
   [0] = JOYSTICK_AXIS_IN(B0, 141, 490, 810),
    [1] = JOYSTICK_AXIS_IN(B1, 224, 534, 811)
};
#endif */

// Defines the keycodes used by our macros in process_record_user

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper ( \
        KC_ESC,  ________________NUMBER_LEFT________________,  KC_GRV,                                ________________NUMBER_RIGHT_______________,     KC_MINS,  KC_EQL, \
        KC_TAB,      K01,    K02,      K03,     K04,     K05,   KC_LBRC,                                KC_RBRC,    K06,     K07,     K08,     K09,      K0A,      KC_DELETE,     \
        TT(_MOUSE),   K11,    K12,      K13,     K14,     K15,   TAB_RO,                                KC_LEFT,     K16,     K17,     K18,     K19,      K1A,      K1B,   \
        KC_LGUI,     K21,     K22,      K23,     K24,     K25,                                                      K26,     K27,     K28,     K29,      K2A,      KC_NUBS, \
                                  LALT_T(TAB_L),   TAB_R,                                                                    KC_BTN4, KC_BTN5, \
                                                 NAV_SPC,                                            SYM_BSPC,       \
                                                 SYM_DEL,                                           NAV_ENT, \
                                                  OSM(MOD_LCTL) , OSM(MOD_LSFT),                                  KC_ENT,  KC_LALT \
    )
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)



//http://www.keyboard-layout-editor.com/##@@_x:3.5%3B&=%23%0A3&_x:10.5%3B&=*%0A8%3B&@_y:-0.875&x:2.5%3B&=%2F@%0A2&_x:1%3B&=$%0A4&_x:8.5%3B&=%2F&%0A7&_x:1%3B&=(%0A9%3B&@_y:-0.875&x:5.5%3B&=%25%0A5&_a:7%3B&=&_x:4.5%3B&=&_a:4%3B&=%5E%0A6%3B&@_y:-0.875&x:1.5%3B&=!%0A1&_x:14.5%3B&=)%0A0&_a:7%3B&=%3B&@_y:-0.995&x:0.5%3B&=ESC%3B&@_y:-0.3799999999999999&x:3.5&a:4%3B&=E&_x:10.5%3B&=I%3B&@_y:-0.875&x:2.5%3B&=W&_x:1%3B&=R&_x:8.5%3B&=U&_x:1%3B&=O%3B&@_y:-0.875&x:5.5%3B&=T&_a:7%3B&=&_x:4.5%3B&=&_a:4%3B&=Y%3B&@_y:-0.875&x:1.5%3B&=Q&_x:14.5%3B&=P&_a:7%3B&=%3B&@_y:-0.9950000000000001&x:0.5%3B&=%3Ci%20class%2F='kb%20kb-Line-End'%3E%3C%2F%2Fi%3E%3B&@_y:-0.3799999999999999&x:3.5&a:4%3B&=D&_x:10.5%3B&=K%3B&@_y:-0.875&x:2.5%3B&=S&_x:1%3B&=F&_x:8.5%3B&=J&_x:1%3B&=L%3B&@_y:-0.875&x:5.5%3B&=G&_a:7%3B&=&_x:4.5%3B&=&_a:4%3B&=H%3B&@_y:-0.875&x:1.5%3B&=A&_x:14.5%3B&=%2F:%0A%2F%3B&_a:7%3B&=%3B&@_y:-0.9950000000000001&x:0.5&f:1%3B&=TT(%2F_MOUSE)%3B&@_y:-0.3799999999999999&x:3.5&a:4&f:3%3B&=C&_x:10.5%3B&=%3C%0A,%3B&@_y:-0.875&x:2.5%3B&=X&_x:1%3B&=V&_x:8.5%3B&=M&_x:1%3B&=%3E%0A.%3B&@_y:-0.875&x:5.5%3B&=B&_x:6.5%3B&=N%3B&@_y:-0.875&x:1.5%3B&=Z&_x:14.5%3B&=%3F%0A%2F%2F&_a:7%3B&=%3B&@_y:-0.9950000000000001&x:0.5%3B&=LGUI%3B&@_y:-0.3799999999999999&x:3.5&a:6%3B&=TABR&_x:10.5&a:7%3B&=,%3B&@_y:-0.875&x:2.5%3B&=LALT&_x:12.5%3B&=.%3B&@_r:30&rx:6.5&ry:4.25&y:-1&a:6%3B&=SPC%3B&@_x:1%3B&=LFST%3B&@=LFCTL&_f:1%3B&=MT(%2F_NAV)%3B&@_r:-30&rx:13&y:-1&x:-1.25&a:7&f:3%3B&=%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%3B&@_x:-1.75&a:6%3B&=ENT%3B&@_x:-2&f:1%3B&=MO(SYM)&_f:3%3B&=LALT



// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))

#define TAB_RO LCTL(LSFT(KC_T))

//TD_MACR removed from nav see https://github.com/rafaelromao/keyboards/blob/main/docs/navigation.md

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]  = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),
      [_COLEMAK_MOD_DH]  = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____, _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),
     [_COLEMAK_DH_GAMING]  = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),
      [_SYM] = LAYOUT_wrapper(
        _______, _________________FUNC_LEFT_________________ , _______,             _______,  _________________FUNC_RIGHT________________, _______,
        _______, KC_QUOT,  KC_DQUO, KC_MINS, KC_PLUS, KC_DOT , _______,            _______,    EQ3X,KC_LCBR , KC_RCBR, SCOPE, KC_PERC,    KC_AMPR,
        _______, KC_EXLM,  KC_NUBS,  KC_LABK, KC_RABK, KC_NUHS ,  _______,            _______,   ARROW, KC_LPRN, KC_RPRN, KC_COLN, KC_QUES,   KC_NUBS,
        _______, KC_CIRC,  KC_EQL,  KC_SLSH, KC_ASTR, UPDIR,                                    KC_QUES,KC_LBRC  , KC_RBRC, KC_DLR, KC_AT  ,  KC_TILD,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),
     [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______, KC_ESC , KC_LEAD, SS_SELW, OS_RALT, _______,  _______,            _______, _______, KC_APP,  KC_PGUP , KC_PGDN, _______, _______,
        _______, SS_SWIN, KC_LALT ,KC_LSFT, OS_LCTL, KC_ENT,  _______,            _______, _______, KC_LEFT, KC_UP,KC_DOWN , KC_RIGHT, _______,
        _______, KC_TAB , XXXXXXX , _______ , OS_LGUI ,  _______,                              _______, KC_HOME, KC_WH_U ,KC_WH_D, KC_END, KC_DEL  ,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),
    [_FN] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______,_________________FUNC_LEFT_________________,  _______,            _______, _________________FUNC_RIGHT________________, _______,
        _______, ________________NUMBER_LEFT________________,  _______,            _______, ________________NUMBER_RIGHT_______________, _______,
        _______, _______ , _______ , _______ , KC_SPC ,  _______,                              _______, KC_BSPC, _______ , _______, _______, _______  ,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),

 [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        DPI_MOD, DPI_RMOD, S_D_MOD, S_D_RMOD, SNP_TOG, DRG_TOG,  _______,            _______, KC_WH_U, _______, _______, _______, _______, _______,
        _______, _______, CARET, DRAG_MOM, DRAG_SCROLL, TRCKPD,  _______,            _______, KC_WH_D, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN6, DPI_CONFIG,
        _______, _______, _______, _______, _______, AJS_MODE,                              KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),
[_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,            _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______,
        _______, _______, _______, _______, _______, _______,                              _______, KC_MRWD, _______, KC_MFFD, _______, _______,
                          _______, _______,                                                                  KC_BRID, KC_BRIU,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),


    [_MAINTENANCE] = LAYOUT(
        RESET, _______, _______, _______, _______, _______,  _______,            _______,   _______, _______, _______, _______, _______, EE_CLR,
        AU_ON, AU_OFF, CLICKY_TOGGLE, MU_ON, MU_OFF,  MU_MOD, _______,            _______, _______, _______, DF_CMG  , DF_CDH, DF_QWE, _______,
        _______, SC_SNK_CS, SNK_CS, KB_CS, CML_CS, _______,  _______,            _______, HPT_TOG, HPT_MODD, HPT_MODI, _______, _______, _______,
        QK_BOOT, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, DM_RSTP,                              _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                                  _______, _______,
                                                     _______,                               _______,
                                                     _______,                              _______,
                                                     _______, _______,            _______, _______
    ),
};





//static uint8_t test_led_index, test_color;

/* void rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(test_led_index, (test_color == 0) * 255, (test_color == 1) * 255, (test_color == 2) * 255);
} */



bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { audio_on(); } else { audio_off(); }
            break;
        /* case 1:
            if(active) { clicky_on(); } else { clicky_off(); }
            break; */
    /*     case 2:
             if (active) {
                set_single_persistent_default_layer(_COLEMAK_MOD_DH);
            } else {
                set_single_persistent_default_layer(_QWERTY);
            }
            break; */
        /* case 3:

            break; */
    }
    return true;
}




#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {


        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
             tap_code_delay(KC_VOLU, 10);
        }

    return false;
}
#endif



/* #ifdef OLED_ENABLE

bool oled_task_user(void) {

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
return false;
}
#endif */

 /*void matrix_init_user(void) {
    // init pin? Is needed?
 #ifdef POINTING_DEVICE_ENABLE
    setPinInputHigh(B12);
    // Account for drift
    xOrigin = analogReadPin(B0);
    yOrigin = analogReadPin(B1);
#endif
} */

