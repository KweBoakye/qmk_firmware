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

#include "tractyl_frankenform.h"
#include QMK_KEYBOARD_H
#ifdef RGB_MATRIX_ENABLE
#include "drivers/led/issi/is31fl3731.h"
#endif
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif
#include <quantum.h>
#include "analog.h"
/*
#    include "pointing_device.h"
 */
#include "spi_master.h"
#include "i2c_master.h"
//#include "pointing_device_drivers.c"
//#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#include "drivers/sensors/pmw3360.h"
#ifdef CIRQUE_ENABLED
#include "drivers/sensors/cirque_pinnacle.h"
#include "pointing/cirque_trackpad_logic.h"
#endif
#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
#include "pointing/analog_joystick_logic.h"
//#include "drivers/sensors/analog_joystick.h"
#endif



/* keyboard_config_t keyboard_config;

 void eeconfig_init_kb(void) {  // EEPROM is getting reset!
  keyboard_config.raw = 0;
  keyboard_config.eeprom_works = true; // We want this enabled by default
  eeconfig_update_user(keyboard_config.raw); // Write default value to EEPROM now

}

void keyboard_post_init_kb(void) {
    keyboard_config.raw = eeconfig_read_kb();
    if (is_keyboard_left()){

    if(keyboard_config.eeprom_works){
        uprintf("eeprom works");
    } else {
        uprintf("eeprom fail");
    }
     }
} */

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0, C1_1,  C2_1,  C3_1},
    {0, C1_2,  C2_2,  C3_2},
    {0, C1_3,  C2_3,  C3_3},
    {0, C1_4,  C2_4,  C3_4},
    {0, C1_5,  C2_5,  C3_5},
    {0, C1_6,  C2_6,  C3_6},
    {0, C1_7,  C2_7,  C3_7},
    {0, C1_8,  C2_8,  C3_8},
    {0, C4_1,  C5_1,  C6_1},
    {0, C4_2,  C5_2,  C6_2},
    {0, C4_3,  C5_3,  C6_3},
    {0, C4_4,  C5_4,  C6_4},
    {0, C4_5,  C5_5,  C6_5},
    {0, C4_6,  C5_6,  C6_6},
    {0, C4_7,  C5_7,  C6_7},
    {0, C4_8,  C5_8,  C6_8},
    {0, C7_1,  C8_1,  C9_1},
    {0, C7_2,  C8_2,  C9_2},
    {0, C7_3,  C8_3,  C9_3},
    {0, C7_4,  C8_4,  C9_4},
    {0, C7_5,  C8_5,  C9_5},
    {0, C7_6,  C8_6,  C9_6},
    {0, C7_7,  C8_7,  C9_7},
    {0, C7_8,  C8_8,  C9_8},

    {0, C1_16,  C2_16,  C3_16},
    {0, C1_15,  C2_15,  C3_15},
    {0, C1_14,  C2_14,  C3_14},
    {0, C1_13,  C2_13,  C3_13},
    {0, C1_12,  C2_12,  C3_12},
    {0, C9_13,  C8_13,  C7_13},
    {0, C9_12,  C8_12,  C7_12},
    {0, C9_11,  C8_11,  C7_11},
    {0, C9_10,  C8_10,  C7_10},
   //S {0, C9_9,   C8_9,   C7_9},



};
// from https://github.com/tzarc/qmk_firmware/blob/djinn/keyboards/tzarc/djinn/rev2/rev2.c
// clang-format off
#define RLO 33 //33 not 32 to accunt for 0
#define LLI(x) (x)
#define LLP(x,y) {(x),(y)}
#define RLI(x) (RLO+(x))
#define RLP(x,y) {(224-(x)),((y))}
led_config_t g_led_config  = { {
    {  6,  5,  4,  3,  2, 1, 0 },
    {  7,  13,  12,  11, 10, 9, 8 },
    {  15,  14, 20,  19,  18, 17, 16 },
    {  23,  22, 21,  25,  30, 26, NO_LED },
    {  NO_LED,  NO_LED, 24,  29,  NO_LED, 31, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  32, 28, 27, NO_LED },
    {  RLI(0),       RLI(1),      RLI(2),       RLI(3),      RLI(4),      RLI(5),      RLI(6 )    },
    {  RLI(8),       RLI(9),      RLI(10),      RLI( 11),    RLI(12),     RLI(13),     RLI(7 )    },
    {  RLI(16),      RLI(17),     RLI(18),      RLI( 19),    RLI(20),     RLI(14),     RLI(15)     },
    {  NO_LED,   RLI(26),   RLI(30),  RLI(25),     RLI(21),    RLI(22),      RLI(23) },
    {  NO_LED,   RLI(31), NO_LED,  RLI(29),  RLI(24), NO_LED, NO_LED },
    {  NO_LED, RLI(27), RLI(28), RLI(32), NO_LED, NO_LED, NO_LED }
}, {

    LLP( 0,   0 ), LLP( 38,  0 ), LLP( 75,   0  ), LLP( 112,   0  ) ,LLP( 149,  0), LLP(187,  0 ), LLP(224,  0 ),
    LLP(224,  13 ), LLP( 0,  13 ), LLP( 38,  13 ), LLP( 75,  13 ) ,LLP(112,  13 ),LLP(149,  13 ), LLP(187,  13 ),
    LLP(187,  26 ), LLP( 224,  26 ), LLP( 0,  26 ), LLP( 38,  26 ) ,LLP(75,  26 ),LLP(112,  26 ), LLP(224,  149 ),
    LLP(112,  38 ), LLP( 149,  38 ), LLP( 187,  38 ), LLP( 149,  51 ) ,LLP(112,  38 ),LLP(38,  38 ), LLP(75,  51 ),
    LLP(38,  64 ), LLP( 112,  51 ), LLP( 75,  38 ), LLP( 38,  51 ),



    RLP( 0,   0 ), RLP( 38,  0 ), RLP( 75,   0  ), RLP( 112,   0  ) ,RLP( 149,  0), RLP(187,  0 ), RLP(224,  0 ),
    RLP(224,  13 ), RLP( 0,  13 ), RLP( 38,  13 ), RLP( 75,  13 ) ,RLP(112,  13 ),RLP(149,  13 ), RLP(187,  13 ),
    RLP(187,  26 ), RLP( 224,  26 ), RLP( 0,  26 ), RLP( 38,  26 ) ,RLP(75,  26 ),RLP(112,  26 ), RLP(224,  149 ),
    RLP(112,  38 ), RLP( 149,  38 ), RLP( 187,  38 ), RLP( 149,  51 ) ,RLP(112,  38 ),RLP(38,  38 ), RLP(75,  51 ),
    RLP(38,  64 ), RLP( 112,  51 ), RLP( 75,  38 ), RLP( 38,  51 ),
}, {
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
} };
// clang-format on
#endif

void keyboard_pre_init_kb(void) {
#ifdef BOOTMAGIC_ENABLE
     setPinInputHigh(A0);
#endif

    }




void matrix_scan_kb(void) {
#ifdef BOOTMAGIC_ENABLE
    if (!readPin(A0)) {
        reset_keyboard();
   }
#endif

    /* uint16_t x_val = analogReadPin(B1);
    uint16_t y_val = analogReadPin(B2);
    xprintf("%6d, %6d", x_val, y_val);
    xprintf("\n"); */

}

void keyboard_post_init_kb(void){
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);


    // Customise these values to desired behaviour

  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;

//     bool init_success = pmw3360_check_signature();
//#ifdef CONSOLE_ENABLE
//    if (init_success) {
//        dprintf("pmw3360 signature verified");
//    } else {
//        dprintf("pmw3360 signature verification failed!");
//    }
//#endif
keyboard_post_init_user();
}

 void eeconfig_init_kb(void){
    keymap_config.raw = 0;
    keymap_config.swap_control_capslock = false;
    keymap_config.capslock_to_control = false;
    keymap_config.swap_lalt_lgui = false;
    keymap_config.swap_ralt_rgui = false;
    keymap_config.no_gui = false;
    keymap_config.swap_grave_esc = false;
    keymap_config.swap_backslash_backspace = false;
    keymap_config.nkro = false;
    keymap_config.swap_lctl_lgui = false;
    keymap_config.swap_rctl_rgui = false;
    keymap_config.oneshot_enable  = false;
    eeconfig_update_kb(keymap_config.raw);

    eeconfig_init_user();
}



/* uint8_t prng(void) {
    static uint8_t s = 0xAA, a = 0;
    s ^= s << 3;
    s ^= s >> 5;
    s ^= a++ >> 2;
    return s;
}

void keyboard_post_init_user(void) {
    debug_enable = true;
}

void matrix_scan_user(void) {
    static uint32_t last_eeprom_access = 0;
    uint32_t        now                = timer_read32();
    if (now - last_eeprom_access > 5000) {
        dprint("reading eeprom\n");
        last_eeprom_access = now;

        union {
            uint8_t  bytes[4];
            uint32_t raw;
        } tmp;
        tmp.bytes[0] = prng();
        tmp.bytes[1] = prng();
        tmp.bytes[2] = prng();
        tmp.bytes[3] = prng();

        eeconfig_update_user(tmp.raw);
        uint32_t value = eeconfig_read_user();
        if (value != tmp.raw) {
            dprint("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            dprint("!! EEPROM readback mismatch!\n");
            dprint("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
    }
}
 */
#ifdef BOOTMAGIC_ENABLE
void bootmagic_lite(void) {
    // We need multiple scans because debouncing can't be turned off.
    matrix_scan();
#if defined(DEBOUNCE) && DEBOUNCE > 0
    wait_ms(DEBOUNCE * 2);
#else
    wait_ms(30);
#endif
    matrix_scan();

    uint8_t row = BOOTMAGIC_LITE_ROW;
    uint8_t col = BOOTMAGIC_LITE_COLUMN;

#if defined(SPLIT_KEYBOARD) && defined(BOOTMAGIC_LITE_ROW_RIGHT) && defined(BOOTMAGIC_LITE_COLUMN_RIGHT)
    if (!is_keyboard_left()) {
        row = BOOTMAGIC_LITE_ROW_RIGHT;
        col = BOOTMAGIC_LITE_COLUMN_RIGHT;
    }
#endif

    if (matrix_get_row(row) & (1 << col) || !readPin(A0)) {
        eeconfig_disable();
        bootloader_jump();
    }
}
#endif

/* void eeconfig_init_kb(void) {  // EEPROM is getting reset!
    keyboard_config.raw = 0;
    keyboard_config.rgb_matrix_enable = true;
    keyboard_config.led_level = true;
    keyboard_config.led_level_res = 0b11;
    keyboard_config.dpi_config = 2;
    eeconfig_update_kb(keyboard_config.raw);
    eeconfig_init_user();
}
 */

#define MUSIC_MAP

const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT (
    52, 53, 54, 55, 56, 57, 58,              59, 60, 61, 62, 63, 64, 65, \
    38, 39, 40, 41, 42, 43, 44,              45, 46, 47, 48, 49, 50, 51, \
    24, 25, 26, 27, 28, 29, 30,              31, 32, 33, 34, 35, 36, 37, \
    12, 13, 14, 15, 16, 17,                        18, 19, 20, 21, 22, 23, \
              8, 9,                                            10, 1, \
                             6,                        7,  \
                                  4,              5, \
                                  0, 1,     2, 3 \
);


//#ifdef POINTING_DEVICE_ENABLE
#define constrain_hid(amt) ((amt) < -127 ? -127 : ((amt) > 127 ? 127 : (amt)))


deferred_token derigister_cirque_click_token;
 bool init_success;

void  pointing_device_driver_init(void) {

 #    ifdef CONSOLE_ENABLE
            if (debug_mouse) dprintf("pointing_device_driver_init .\n");
#    endif
     cirque_trackpad_logic_init();
     if (is_keyboard_left()) {
        analog_joystick_logic_init();
 } else {
       init_success = pmw3360_init(0);
     //pmw3360_check_signature(0);
 }
 }

  report_mouse_t pmw3360_get_report(report_mouse_t mouse_report) {
    report_pmw3360_t data        = pmw3360_read_burst(0);
    static uint16_t  MotionStart = 0;  // Timer for accel, 0 is resting state

    if (data.isOnSurface && data.isMotion) {
        // Reset timer if stopped moving
        if (!data.isMotion) {
            if (MotionStart != 0) MotionStart = 0;
            return mouse_report;
        }

        // Set timer if new motion
        if ((MotionStart == 0) && data.isMotion) {
#    ifdef CONSOLE_ENABLE
            if (debug_mouse) dprintf("Starting motion.\n");
#    endif
            MotionStart = timer_read();
        }
        mouse_report.x = constrain_hid(data.dx);
        mouse_report.y = constrain_hid(data.dy);
    }

    return mouse_report;
}

static inline int8_t pointing_device_movement_clamp(int16_t value) {
    if (value < INT8_MIN) {
        return INT8_MIN;
    } else if (value > INT8_MAX) {
        return INT8_MAX;
    } else {
        return value;
    }
}

/*  #    ifndef CIRQUE_PINNACLE_TAPPING_TERM
#        ifdef TAPPING_TERM_PER_KEY
#            include "action.h"
#            include "action_tapping.h"
#            define CIRQUE_PINNACLE_TAPPING_TERM get_tapping_term(KC_BTN1, NULL)
#        else
#            ifdef TAPPING_TERM
#                define CIRQUE_PINNACLE_TAPPING_TERM TAPPING_TERM
#            else
#                define CIRQUE_PINNACLE_TAPPING_TERM 200
#            endif
#        endif
#    endif
#    ifndef CIRQUE_PINNACLE_TOUCH_DEBOUNCE
#        define CIRQUE_PINNACLE_TOUCH_DEBOUNCE (CIRQUE_PINNACLE_TAPPING_TERM * 8)
#    endif  */

// report_mouse_t rotate_cirque(report_mouse_t mouse_report){
//      int8_t x = mouse_report.x, y = mouse_report.y;
//        mouse_report.x = y;
//        mouse_report.y = -x;
//     return mouse_report;
// }




/* report_mouse_t analog_joystick_get_report(report_mouse_t mouse_report) {
    report_analog_joystick_t data = analog_joystick_read();

    mouse_report.x = data.x;
    mouse_report.y = data.y;

    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, data.button, POINTING_DEVICE_BUTTON1);

    return mouse_report;
}
 */

 report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
if (is_keyboard_left()) {
    report_mouse_t  cirque_pinnacle_report, analog_joystick_report;
      //pmw3360_report =  pmw3360_get_report(mouse_report);
    analog_joystick_report = analog_joystick_pointing_device_task(mouse_report);
     cirque_pinnacle_report = cirque_trackpad_pointing_device_task(mouse_report);
     // mouse_report.x = pointing_device_movement_clamp((int16_t) -pmw3360_report.x + cirque_pinnacle_report.y);
     // mouse_report.y = pointing_device_movement_clamp((int16_t) -pmw3360_report.y + -cirque_pinnacle_report.x);

      mouse_report.x = pointing_device_movement_clamp((int16_t) analog_joystick_report.x + cirque_pinnacle_report.y);
      mouse_report.y = pointing_device_movement_clamp((int16_t) analog_joystick_report.y + -cirque_pinnacle_report.x);
       mouse_report.h = pointing_device_movement_clamp((int16_t) analog_joystick_report.h + cirque_pinnacle_report.v);
      mouse_report.v = pointing_device_movement_clamp((int16_t) analog_joystick_report.v + -cirque_pinnacle_report.h);

     //cirque_pinnacle_report.buttons |= analog_joystick_report.buttons;
    // mouse_report.buttons = cirque_pinnacle_report.buttons |= analog_joystick_report.buttons;


     mouse_report.buttons = analog_joystick_report.buttons  | cirque_pinnacle_report.buttons;

} else {
    report_mouse_t  cirque_pinnacle_report;
     cirque_pinnacle_report = cirque_trackpad_pointing_device_task(mouse_report);

     if(init_success){

     report_mouse_t pmw3360_report =  pmw3360_get_report(mouse_report);

     mouse_report.x = pointing_device_movement_clamp((int16_t) -pmw3360_report.x + cirque_pinnacle_report.y);
     mouse_report.y = pointing_device_movement_clamp((int16_t) pmw3360_report.y + -cirque_pinnacle_report.x);
     mouse_report.h = pointing_device_movement_clamp((int16_t) -pmw3360_report.h + cirque_pinnacle_report.v);
     mouse_report.v = pointing_device_movement_clamp((int16_t) pmw3360_report.v + -cirque_pinnacle_report.h);
     } else {
     mouse_report.x =  cirque_pinnacle_report.y;
     mouse_report.y = -cirque_pinnacle_report.x;
     mouse_report.h =  cirque_pinnacle_report.v;
     mouse_report.v = -cirque_pinnacle_report.h;
     }
     mouse_report.buttons = cirque_pinnacle_report.buttons;
}


    return mouse_report; }
uint16_t       pointing_device_driver_get_cpi(void) { return cirque_pinnacle_get_scale();}



void           pointing_device_driver_set_cpi(uint16_t cpi) {
    if(is_keyboard_left()){
        cirque_pinnacle_set_scale(cpi);
    } else {
        pmw3360_set_cpi(cpi);
 cirque_pinnacle_set_scale(cpi);
    }

    }


 void pointing_device_init_kb(void) {
    if (!is_keyboard_left()) {

       // pmw3360_set_cpi(200);
    }
}

  report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {


     /*if (!is_keyboard_left()) {
         report_mouse_t pmw3360_report;

   //if(right_report.x == 0 && right_report.y== 0){
pmw3360_report = pmw3360_get_report(pmw3360_report);

//right_report.x = pmw3360_report.x;
//right_report.y = pmw3360_report.y;
   // }

   right_report.x = pointing_device_movement_clamp((int16_t)(-pmw3360_report.x) + (-pmw3360_report.x));
   right_report.y = 0;
    //right_report = pointing_device_combine_reports(pmw3360_report, right_report) ;

     } */
      return pointing_device_task_combined_user(left_report, right_report);
      }
//#endif

