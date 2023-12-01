#pragma once
//#include QMK_KEYBOARD_H

// #if defined(UNICODEMAP_ENABLE) 
// #    include "keyrecords/user_unicode.h"
// #endif


#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____       GUI_A,    ALT_R,  SFT_S,   CTRL_T,   KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____       KC_M,    CTRL_N,   SFT_E,   ALT_I,   GUI_O    
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________HALMAK_L1_________________       KC_W,    KC_L,    KC_R,    KC_B,    KC_Z
#define _________________HALMAK_L2_________________       KC_S,    KC_H,    KC_N,    KC_T,    KC_COMM
#define _________________HALMAK_L3_________________       KC_F,    KC_M,    KC_V,    KC_V,    KC_SLASH

#define _________________HALMAK_R1_________________       KC_SCLN, KC_Q,    KC_U,    KC_D,    KC_J
#define _________________HALMAK_R2_________________       KC_DOT,  KC_A,    KC_E,    KC_O,    KC_I,    KC_QUOTE
#define _________________HALMAK_R3_________________       KC_G,    KC_P,    KC_X,    KC_K,    KC_Y

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define ___________________SYM_LEFT_1___________________ KC_QUOT,  UK_AT   , KC_MINS, KC_EQL, KC_DOT
#define ___________________SYM_LEFT_2___________________ KC_EXLM,  UK_PERC,  KC_LABK, KC_RABK, KC_NUHS
#define ___________________SYM_LEFT_3___________________ KC_CIRC,  KC_MINS,  KC_ASTR, KC_PLUS, KC_TILD

#define ___________________SYM_RIGHT_1___________________ UK_PND ,KC_LCBR , KC_RCBR, UK_DQUO, KC_GRV
#define ___________________SYM_RIGHT_2___________________  KC_NUBS, KC_LPRN, KC_RPRN, KC_COLN, KC_QUES
#define ___________________SYM_RIGHT_3___________________ KC_AMPR,KC_LBRC  , KC_RBRC, KC_DLR, KC_NUBS

#define ___________________NAV_LEFT_1___________________ KC_ESC , KC_TAB, SS_SELW, OS_RALT, _______ 
#define ___________________NAV_LEFT_2___________________ OS_LGUI, OS_LALT ,KC_LSFT, KC_LCTL, OS_RALT
#define ___________________NAV_LEFT_3___________________ LCTL(KC_Z) , LCTL(KC_X) ,  LCTL(KC_C), _______ ,  LCTL(KC_V)

#define ___________________NAV_RIGHT_1___________________ _______, KC_APP,  KC_PGUP , KC_PGDN, _______
#define ___________________NAV_RIGHT_2___________________ _______, KC_LEFT, KC_UP,KC_DOWN , KC_RIGHT, _______
#define ___________________NAV_RIGHT_3___________________ _______, KC_HOME, KC_WH_U ,KC_WH_D, KC_END, KC_DEL

#define ________________MAINTANENCE_LEFT_1_______________ QK_BOOT, QK_REBOOT, QK_MAKE ,_______,_______ 
#define ________________MAINTANENCE_LEFT_2_______________ SC_SNK_CS, SNK_CS, KB_CS, CML_CS, _______
#define ________________MAINTANENCE_LEFT_3_______________ DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, DM_RSTP

#define ________________MAINTANENCE_RIGHT_1______________  _______, _______, _______, _______, EE_CLR
#define ________________MAINTANENCE_RIGHT_2______________  _______, _______, DF_CMG  , DF_CDH, DF_QWE
#define ________________MAINTANENCE_RIGHT_3______________ HF_TOGG, HF_PREV, HF_NEXT, TG_WIN, TG_MAC
                                                            
#define _____________QWERTY_GAMING_LEFT_1__________ KC_Q,    KC_F,    KC_E,    KC_R,    KC_T
#define _____________QWERTY_GAMING_LEFT_2__________ KC_A   ,  KC_S , KC_W    ,KC_D ,KC_G
#define _____________QWERTY_GAMING_LEFT_3__________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _____________QWERTY_GAMING_RIGHT_1_________  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _____________QWERTY_GAMING_RIGHT_2_________  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _____________QWERTY_GAMING_RIGHT_3_________  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// #if defined(UNICODEMAP_ENABLE)
// #define ________________UNICODE_R2_________________       _______, _______, OPEN_E, _______, OPEN_O 
// #endif