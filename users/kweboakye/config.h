/* Copyright 2022 KweBoakye
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


// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

#define TAPPING_TOGGLE 2
//#define PERMISSIVE_HOLD


//#define TAPPING_FORCE_HOLD
#define QUICK_TAP_TERM_PER_KEY
#define TAPPING_TERM_PER_KEY
//#define RETRO_TAPPING
//#define RETRO_TAPPING_PER_KEY

/* Set Polling rate to 1000Hz */


#ifdef SPLIT_KEYBOARD
#    define SPLIT_TRANSPORT_MIRROR
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_ACTIVITY_ENABLE
#    ifdef WPM_ENABLE
#        define SPLIT_WPM_ENABLE
#    endif
#    ifdef OLED_ENABLE
#        define SPLIT_OLED_ENABLE
#    endif
#    if defined(__AVR__) && !defined(SELECT_SOFT_SERIAL_SPEED)
#        define SELECT_SOFT_SERIAL_SPEED 1
#    endif
#    ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
//#    define SPLIT_WATCHDOG_TIMEOUT
#        define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_STATE_SYNC, RPC_ID_USER_KEYMAP_SYNC, RPC_ID_USER_CONFIG_SYNC, RPC_ID_HAPTIC_SYNC, RPC_ID_HAPTIC_SEND, RPC_ID_USER_WATCHDOG_SYNC  //, RPC_ID_USER_WATCHDOG_SYNC, RPC_ID_USER_KEYLOG_STR
    #endif
#endif


#ifdef HAPTIC_ENABLE
#define NO_HAPTIC_ALPHA
#define NO_HAPTIC_PUNCTUATION
#define NO_HAPTIC_NAV
#define NO_HAPTIC_NUMERIC
#endif

#if RGB_MATRIX_ENABLE

#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000  // Turn off Caps Word after 5 seconds.

#undef COMBO_COUNT
//#define COMBO_REF_LAYER(_QWERTY_GAMING, _COLEMAK_MOD_DH)


#ifdef drv2605l
#define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_SOFT_BUMP_60
#endif

#ifdef POINTING_DEVICE_ENABLE
    #define MOUSE_EXTENDED_REPORT
    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#endif

#ifdef UNICODEMAP_ENABLE
    #define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
    #define UNICODE_KEY_WINC KC_RIGHT_ALT
#endif    

#define ENABLE_COMPILE_KEYCODE

#ifdef HAPTIC_ENABLE
#define DRV2605L_FB_ERM_LRA 1
#define DRV2605L_FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define DRV2605L_FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

#ifdef ELV1411A
/* Please refer to your datasheet for the optimal setting for your specific motor. */
    #define DRV2605L_RATED_VOLTAGE 2
    #define DRV2605L_V_PEAK 2.8
    #define DRV2605L_V_RMS 2.0
    #define DRV2605L_F_LRA 150 /* resonance freq */
#elif VL91022
 #define DRV2605L_RATED_VOLTAGE 3.0
    #define DRV2605L_V_PEAK 3.3
    #define DRV2605L_V_RMS 3.0
    #define DRV2605L_F_LRA 160 /* resonance freq */
#endif
#define DRV2605L_GREETING DRV2605L_EFFECT_TRANSITION_RAMP_UP_LONG_SMOOTH_1_100
#define DRV2605L_DEFAULT_MODE 8	//soft_bump_60
//#define SPLIT_HAPTIC_ENABLE
//#define NO_HAPTIC_ALPHA
//#define NO_HAPTIC_PUNCTUATION
//#define NO_HAPTIC_NAV
//#define NO_HAPTIC_NUMERIC
#endif

#ifdef MOUSEKEY_ENABLE 
#define MOUSEKEY_WHEEL_DELAY 4
#endif
