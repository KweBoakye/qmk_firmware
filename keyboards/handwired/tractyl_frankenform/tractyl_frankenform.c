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
#include "drivers/led/issi/is31fl3731.h"

#include <quantum.h>
#include "analog.h"
/* #ifdef POINTING_DEVICE_ENABLE
#    include "pointing_device.h"
#endif */
#include "pointing_device.h"
#include "spi_master.h"
#include "i2c_master.h"
//#include "pointing_device_drivers.c"
#include "drivers/sensors/pmw3360.h"
//#include "analog_joystick.h"
#include "drivers/sensors/cirque_pinnacle.h"



//keyboard_config_t keyboard_config;

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

    {0, C7_14,  C8_14,  C9_14},
};


led_config_t g_led_config  = { {
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    {  NO_LED,  NO_LED, NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED },
    {   0,   1, 2,  3, 4, 5, 6 },
    {   8,   9, 10,  11,  12, 13, 7 },
    {   16,   17, 18,  19,  20, 14, 15 },
    {   NO_LED,   24, NO_LED,  NO_LED,  21, 22, 23 },
    {   NO_LED,   NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    { 0,   0 }, { 38,  0 }, { 75,   0  }, { 112,   0  }, {    187,  0 }, { 224,  0 },
    {0,  12 }, { 38,  12 }, { 75,  12 }, { 112,  12 },{150,  25 },{187,  25 }, { 224,  25 },
    {0,  25 }, { 38,  25 }, { 75,  25 }, { 112,  38 },{150,  38 },{187,  38 }, { 224,  38 },
    /*{0,  38 },*/ { 38,  38 },/* { 75,  51 }, { 112,  51 },*/{150,  51 },{187,  51 }, { 224,  51 }//,
    /*{0,  50 }, { 38,  50 }, { 75,  50 }, { 112,  50 },{150,  50 },{187,  50 }, { 224,  50 },*/
    /*{0,  63 }, { 38,  63 }, { 75,  63 }, { 112,  63 },{150,  63 },{187,  63 }, { 224,  63 }*/
}, {
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
        4,        4, 4, 4
} };

void matrix_init_kb(void) {
#if BOOTMAGIC_ENABLE
     setPinInputHigh(A0);
#endif
    // setPinInputHigh(B12);
   /*  keyboard_config.raw = eeconfig_read_kb();

    if (!keyboard_config.dpi_config) {
        keyboard_config.dpi_config = 2;
        eeconfig_update_kb(keyboard_config.raw);
    } */
    matrix_init_user();
}



void matrix_scan_kb(void) {
#if BOOTMAGIC_ENABLE
    if (!readPin(A0)) {
        reset_keyboard();
   }
#endif

    /* uint16_t x_val = analogReadPin(B1);
    uint16_t y_val = analogReadPin(B2);
    xprintf("%6d, %6d", x_val, y_val);
    xprintf("\n"); */
    matrix_scan_user();

}


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


#define constrain_hid(amt) ((amt) < -127 ? -127 : ((amt) > 127 ? 127 : (amt)))

/*  void           pointing_device_driver_init(void) {
     if (!is_keyboard_left()) {
         pmw3360_init();
        i2c_init();
        cirque_pinnacle_init();
        analog_joystick_init
 }
 } */
/*
  report_mouse_t pmw3360_get_report(report_mouse_t mouse_report) {
    report_pmw3360_t data        = pmw3360_read_burst();
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
 */
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
/* // }
report_mouse_t cirque_pinnacle_get_report_custom(report_mouse_t mouse_report) {
    pinnacle_data_t touchData = cirque_pinnacle_read_data();
    static uint16_t x = 0, y = 0, mouse_timer = 0;
    int8_t          report_x = 0, report_y = 0;
    static bool     is_z_down = false;

    cirque_pinnacle_scale_data(&touchData, cirque_pinnacle_get_scale(), cirque_pinnacle_get_scale());  // Scale coordinates to arbitrary X, Y resolution

    if (x && y && touchData.xValue && touchData.yValue) {
        report_x = (int8_t)(touchData.xValue - x);
        report_y = (int8_t)(touchData.yValue - y);
    }
    x = touchData.xValue;
    y = touchData.yValue;

    if ((bool)touchData.zValue != is_z_down) {
        is_z_down = (bool)touchData.zValue;
        if (!touchData.zValue) {
            if (timer_elapsed(mouse_timer) < CIRQUE_PINNACLE_TAPPING_TERM && mouse_timer != 0) {
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
#    if TAP_CODE_DELAY > 0
                wait_ms(TAP_CODE_DELAY);
#    endif
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
            }
        }
        mouse_timer = timer_read();
    }
    if (timer_elapsed(mouse_timer) > (CIRQUE_PINNACLE_TOUCH_DEBOUNCE)) {
        mouse_timer = 0;
    }
    mouse_report.x = report_x;
    mouse_report.y = report_y;

    return mouse_report;
}

report_mouse_t analog_joystick_get_report(report_mouse_t mouse_report) {
    report_analog_joystick_t data = analog_joystick_read();

#    ifdef CONSOLE_ENABLE
    if (debug_mouse) dprintf("Raw ] X: %d, Y: %d\n", data.x, data.y);
#    endif

    mouse_report.x = data.x;
    mouse_report.y = data.y;

    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, data.button, POINTING_DEVICE_BUTTON1);

    return mouse_report;
}


 report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
if (!is_keyboard_left()) {
    report_mouse_t pmw3360_report, cirque_pinnacle_report, analog_joystick_report;
      pmw3360_report =  pmw3360_get_report(mouse_report);
    analog_joystick_report = analog_joystick_get_report;
     cirque_pinnacle_report = cirque_pinnacle_get_report_custom(mouse_report);
      mouse_report.x = pointing_device_movement_clamp((int16_t) -pmw3360_report.x + cirque_pinnacle_report.y);
      mouse_report.y = pointing_device_movement_clamp((int16_t) -pmw3360_report.y + -cirque_pinnacle_report.x);

      mouse_report.x = pointing_device_movement_clamp((int16_t) analog_joystick_report.x + cirque_pinnacle_report.y);
      mouse_report.y = pointing_device_movement_clamp((int16_t) analog_joystick_report.y + -cirque_pinnacle_report.x);
       mouse_report.buttons = cirque_pinnacle_report.buttons;

}
    return mouse_report; }
uint16_t       pointing_device_driver_get_cpi(void) { return cirque_pinnacle_get_scale(); }
void           pointing_device_driver_set_cpi(uint16_t cpi) {
    pmw3360_set_cpi(cpi);
    cirque_pinnacle_set_scale(cpi);
    }
 */

 void pointing_device_init_kb(void) {
    if (!is_keyboard_left()) {
        //pmw3360_init();
        pmw3360_set_cpi(200);
    }
}

  report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {
      dprintf("Raw ] X: %d, Y: %d\n", right_report.x, right_report.y);
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


