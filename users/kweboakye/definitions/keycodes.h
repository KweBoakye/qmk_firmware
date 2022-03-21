#pragma once

#include "layers.h"

// Custom keycodes
enum custom_keycodes {
    KC_AUDIO = SAFE_RANGE,
    KC_ACCEL,
    DPI_CONFIG,
    SCOPE,
    UPDIR,
    EQ3X,
    ARROW,
    SS_SELW,
    SS_SWIN,
    DF_CDH,
    DF_QWE,

    GAME,
    CUSTOM_KEYCODES_SAFE_RANGE,

    TRACKBALL_KEYCODES_SAFE_RANGE,
    ANALOG_JOYSTICK_KEYCODES_SAFE_RANGE
};

enum cirque_trackpad_keycodes {
    DRAG_SCROLL = CUSTOM_KEYCODES_SAFE_RANGE ,
    DRAG_MOM,
    CARET,
    CIRQUE_TRACKPAD_KEYCODES_SAFE_RANGE,
};

enum charybdis_keycodes {
    POINTER_DEFAULT_DPI_FORWARD = CIRQUE_TRACKPAD_KEYCODES_SAFE_RANGE,
    POINTER_DEFAULT_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD,
    POINTER_SNIPING_DPI_REVERSE,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
    CHARYBDIS_SAFE_RANGE,
};

enum  analog_joystick_pointing_keycodes{
    AJS_MODE = CHARYBDIS_SAFE_RANGE,
    NEW_SAFE_RANGE
};

#define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#define SNIPING SNIPING_MODE
#define SNP_TOG SNIPING_MODE_TOGGLE
#define DRGSCRL DRAGSCROLL_MODE
#define DRG_TOG DRAGSCROLL_MODE_TOGGLE

// One-shot mods
#define OS_RALT OSM(MOD_RALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LGUI OSM(MOD_LGUI)

// Left-hand Colemak home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)

// Right-hand Colemak home row mods
#define CTRL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

uint16_t extract_base_tapping_keycode(uint16_t keycode);
