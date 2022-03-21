#include "cirque_trackpad_logic.h"
#include "pointing_utils.h"
#include "i2c_master.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif
#include "drivers/sensors/cirque_pinnacle.h"

uint8_t	carret_threshold = 5;
int16_t cur_factor;
uint8_t	scroll_threshold = 1;
int8_t last_v = 0;
bool scrolling_mode = false, is_caret = false, is_drag_mom = false;


int max(int num1, int num2) { return (num1 > num2 ) ? num1 : num2; }
int min(int num1, int num2) { return (num1 > num2 ) ? num2 : num1; }
int8_t sign(int x) { return (x > 0) - (x < 0); }

void cirque_trackpad_logic_init (void) {
     i2c_init();
    cirque_pinnacle_init();
     cirque_trackpad_mode = CIRQUE_TRACKPAD_TRACKPAD_MODE;

}


report_mouse_t cirque_pinnacle_get_report(report_mouse_t mouse_report) {
    pinnacle_data_t touchData = cirque_pinnacle_read_data();
    static uint16_t x = 0, y = 0, cirque_mouse_timer = 0;
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
            if (timer_elapsed(cirque_mouse_timer) < CIRQUE_PINNACLE_TAPPING_TERM && cirque_mouse_timer != 0) {
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();

                #ifdef HAPTIC_ENABLE
                    DRV_pulse(strong_click);
               #endif
 #    if TAP_CODE_DELAY > 0
                wait_ms(TAP_CODE_DELAY);
#    endif
   mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();


            }
        }
        cirque_mouse_timer = timer_read();
    }
    if (timer_elapsed(cirque_mouse_timer) > (CIRQUE_PINNACLE_TOUCH_DEBOUNCE)) {
        cirque_mouse_timer = 0;
    }
    mouse_report.x = report_x;
    mouse_report.y = report_y;

    return mouse_report;
}


void tap_tb(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, report_mouse_t mouse_report) {
        if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor){
            if(abs(mouse_report.x) > abs(mouse_report.y)) {
                if(mouse_report.x > 0) {
                    for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
                        tap_code(keycode0);
                        mouse_report.x = max(mouse_report.x - cur_factor, 0);
                    }
                    mouse_report.y = 0;
                } else {
                    for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
                        tap_code(keycode1);
                        mouse_report.x = min(mouse_report.x + cur_factor, 0);
                    }
                    mouse_report.y = 0;
                }
            } else {
                if(mouse_report.y > 0) {
                    for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
                        tap_code(keycode2);
                        mouse_report.y = max(mouse_report.y - cur_factor, 0);
                        }
                    mouse_report.x = 0;
                } else {
                    for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
                        tap_code(keycode3);
                        mouse_report.y = min(mouse_report.y + cur_factor, 0);
                    }
                    mouse_report.x = 0;
                }
            }
        }
    }

report_mouse_t cirque_trackpad_pointing_device_adjust_by_mode(report_mouse_t mouse_report){
report_mouse_t cirque_report;

    switch (cirque_trackpad_mode){
        case CIRQUE_TRACKPAD_TRACKPAD_MODE:
        cirque_report = mouse_report;
        break;

        case CIRQUE_TRACKPAD_SCROLLING_MODE:
        cirque_report.h = mouse_report.x;
        cirque_report.v = mouse_report.y;
        cirque_report.x = mouse_report.y = 0;
         break;

         case CIRQUE_TRACKPAD_CARET_MODE:
          cur_factor = carret_threshold;
        tap_tb(KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP, mouse_report);
        cirque_report.x = 0;
        cirque_report.y = 0;
         break;
         case CIRQUE_TRACKPAD_DRAG_MOM_MODE:

         cur_factor = scroll_threshold;
        if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor) {
            if(abs(mouse_report.x) > abs(mouse_report.y)) {
                cirque_report.h = sign(mouse_report.x) * (abs(mouse_report.x) + abs(mouse_report.y)) / 2;
            } else {
                cirque_report.v = sign(mouse_report.y) * (abs(mouse_report.x) + abs(mouse_report.y)) / 4; //* (sign(mouse_report.y)>0 ? 5 : 1) + (sign(mouse_report.y)==sign(last_v) ? last_v / 8 : 0);
            }
            last_v = cirque_report.v;
            cirque_report.x = 0;
            cirque_report.y = 0;
        } else {
            cirque_report.v = 0;
            cirque_report.h = 0;
        }
         break;
         default:
         cirque_report = mouse_report;
         break;

    }

/* if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.y = 0;
    }
    if (is_caret) {
        cur_factor = carret_threshold;
        tap_tb(KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP, mouse_report);
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (is_drag_mom) {
        cur_factor = scroll_threshold;
        if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor) {
            if(abs(mouse_report.x) > abs(mouse_report.y)) {
                mouse_report.h = sign(mouse_report.x) * (abs(mouse_report.x) + abs(mouse_report.y)) / 2;
            } else {
                mouse_report.v = sign(mouse_report.y) * (abs(mouse_report.x) + abs(mouse_report.y)) / 4; // (sign(mouse_report.y)>0 ? 5 : 1) + (sign(mouse_report.y)==sign(last_v) ? last_v / 8 : 0);
            }
            last_v = mouse_report.v;
            mouse_report.x = 0;
            mouse_report.y = 0;
        } else {
            mouse_report.v = 0;
            mouse_report.h = 0;
        }
    } */


    return cirque_report;

}

report_mouse_t cirque_trackpad_pointing_device_task(report_mouse_t mouse_report){
  report_mouse_t cirque_pinnacle_report = cirque_pinnacle_get_report(mouse_report);
  mouse_report = cirque_trackpad_pointing_device_adjust_by_mode(cirque_pinnacle_report);
  return mouse_report;
};



process_record_result_t process_record_trackpad(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {


          /*  case CIRQUE_TRACKPAD_TRACKPAD_MODE:
           cirque_trackpad_mode = CIRQUE_TRACKPAD_TRACKPAD_MODE */

           case DRAG_SCROLL:
           if (record->event.pressed){
           //scrolling_mode = record->event.pressed;
           //record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
           cirque_trackpad_mode = CIRQUE_TRACKPAD_SCROLLING_MODE;
            mouse_timer = timer_read();
           return PROCESS_RECORD_CONTINUE;
           }
             case CARET:
             if (record->event.pressed){ //is_caret ^= 1;
             cirque_trackpad_mode = CIRQUE_TRACKPAD_CARET_MODE;
             return PROCESS_RECORD_CONTINUE;
             }
            case DRAG_MOM:
           if (record->event.pressed){ //is_drag_mom ^= 1;
            cirque_trackpad_mode = CIRQUE_TRACKPAD_DRAG_MOM_MODE;
            return PROCESS_RECORD_CONTINUE;
            }

    }
return PROCESS_RECORD_CONTINUE;
 }
