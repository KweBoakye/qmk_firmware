#include "cirque_trackpad_logic.h"
#include "pointing_utils.h"
#include "i2c_master.h"
//#include <quantum.h>

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

void cirque_trackpad__mode_set(cirque_trackpad_mode_t mode) { cirque_trackpad_mode = mode; }

cirque_trackpad_mode_t cirque_trackpad_mode_get(void) { return cirque_trackpad_mode; }



bool is_strong_touch(uint16_t zValue){
     //xprintf("%s", "z value is");
 //xprintf("%u", zValue);
  //xprintf("%s", "\n");
    if(zValue > 60){
        return true;
    } else {
        return false;
    }
}

bool drag_down = false;

uint32_t derigister_cirque_click_callback(uint32_t trigger_time, void *cb_arg) {
   report_mouse_t mouse_report = pointing_device_get_report();
    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
    return  0;
}



/* bool is_right_click(void){
    pinnacle_data_t touchData = cirque_pinnacle_read_data();
      //xprintf("%s", " is_right_click x is ");
      //xprintf("%u", x);
      //xprintf("%s", " , ");
      //xprintf("%s", " is_right_click y is ");
      //xprintf("%u", y);
      // xprintf("%s", " is_right_click y is ");
      //xprintf("%u", y);
      //xprintf("%s", "\n");
//
    if((CIRQUE_PINNACLE_Y_LOWER < touchData.yValu)e && (touchData.yValue < CIRQUE_TRACKPAD_RIGHT_CLICK_Y_AXIS_BOUNDARY)){
   // if(is_keyboard_left()){
        if( (CIRQUE_PINNACLE_X_LOWER < touchData.xValue) && (touchData.xValue < CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_LEFT)){
            return true;
        }
   //} else {
   //    if(x > CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_RIGHT){
   //        return true ;
   //    }
   //}
    }
    return false;


} */
uint16_t last_x = 0, last_y = 0, last_z = 0;

bool off_hand_tapped = false;
bool off_hand_tap_processed = false;

    bool is_right_click(uint16_t x, uint16_t y){
      //xprintf("%s", " is_right_click x is ");
      //xprintf("%u", x);
      //xprintf("%s", " , ");
      //xprintf("%s", " is_right_click y is ");
      //xprintf("%u", y);
      // xprintf("%s", " is_right_click y is ");
      //xprintf("%u", y);
      //xprintf("%s", "\n");
//
    if((CIRQUE_PINNACLE_X_LOWER < x) && (x < CIRQUE_TRACKPAD_X_AXIS_LOWER_BOUNDARY)){
    if(is_keyboard_left()){
        if((CIRQUE_PINNACLE_Y_LOWER < y) && (y < CIRQUE_TRACKPAD_Y_AXIS_LOWER_BOUNDARY)){
            return true;
        }
   } else {
     if((y > CIRQUE_TRACKPAD_Y_AXIS_UPPER_BOUNDARY)  && (y < CIRQUE_PINNACLE_Y_UPPER) ){
         return true ;
     }
   }
    }
    return false;
}

bool is_mousewheel_click(uint16_t x, uint16_t y){
    if((CIRQUE_PINNACLE_X_UPPER > x) && (CIRQUE_TRACKPAD_X_AXIS_UPPER_BOUNDARY < x)){
        if(is_keyboard_left()){
         if((y > CIRQUE_TRACKPAD_Y_AXIS_UPPER_BOUNDARY)  && (y < CIRQUE_PINNACLE_Y_UPPER) ){
         return true ;
     }
   } else {
     if((CIRQUE_PINNACLE_Y_LOWER < y) && (y < CIRQUE_TRACKPAD_Y_AXIS_LOWER_BOUNDARY)){
            return true;
        }
   }
    }
    return false;
}

report_mouse_t cirque_pinnacle_get_report(report_mouse_t mouse_report) {


//uint16_t x_boundary = is_keyboard_left() ? CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_LEFT : CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_RIGHT;

    pinnacle_data_t touchData = cirque_pinnacle_read_data();
    static uint16_t x = 0, y = 0, cirque_mouse_timer = 0;
     static uint16_t raw_x = 0, raw_y = 0, raw_z = 0;

    int8_t          report_x = 0, report_y = 0;
    static bool     is_z_down = false;
  // xprintf("%s", "x is ");
  // xprintf("%u", raw_x);
  // xprintf("%s", " , ");
  // xprintf("%s", "y is ");
  // xprintf("%u", raw_y);
  // xprintf("%s", "\n");
 //  xprintf("%s", "drag_down is ");
 // xprintf("%s", drag_down ? "true" : "false");
 // xprintf("%s", "\n");
//

    raw_x = touchData.xValue;
    raw_y = touchData.yValue;
    raw_z = touchData.zValue;



    cirque_pinnacle_scale_data(&touchData, cirque_pinnacle_get_scale(), cirque_pinnacle_get_scale());  // Scale coordinates to arbitrary X, Y resolution

    if (x && y && touchData.xValue && touchData.yValue) {
        report_x = (int8_t)(touchData.xValue - x);
        report_y = (int8_t)(touchData.yValue - y);
    }
    x = touchData.xValue;
    y = touchData.yValue;

    //


    if ((bool)touchData.zValue != is_z_down) {
        bool check_r_click = is_right_click(last_x,last_y);
        bool check_mouse_wheel_click = is_mousewheel_click(last_x,last_y);
        is_z_down = (bool)touchData.zValue;
        if (!touchData.zValue) {
            if (timer_elapsed(cirque_mouse_timer) < CIRQUE_PINNACLE_TAPPING_TERM && cirque_mouse_timer != 0) {
                if(drag_down){
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
                 drag_down = false;
                 xprintf("%s", "check_r_click drag");
                } else {

                  xprintf("%s", "check_r_click is ");
                  xprintf("%s", check_r_click ? "true" : "false");
                  xprintf("%s", "\n");
                   xprintf("%s", "CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_LEFT is ");
                    xprintf("%u", CIRQUE_TRACKPAD_RIGHT_CLICK_X_AXIS_BOUNDARY_LEFT);
                    xprintf("%s", " , ");
                    xprintf("%s", "CIRQUE_TRACKPAD_RIGHT_CLICK_Y_AXIS_BOUNDARY is ");
                    xprintf("%u", CIRQUE_TRACKPAD_RIGHT_CLICK_Y_AXIS_BOUNDARY);
                    xprintf("%s", "\n");
                     xprintf("%s", "x is ");
                     xprintf("%u", last_x);
                     xprintf("%s", " , ");
                     xprintf("%s", "y is ");
                     xprintf("%u", last_y);
                     xprintf("%s", "\n");

                if(check_r_click){
                    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON2);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
                xprintf("%s", "pressed right click");
                xprintf("%s", "\n");

                #ifdef HAPTIC_ENABLE
                    DRV_pulse(sharp_click);
               #endif
 #    if TAP_CODE_DELAY > 0
                wait_ms(TAP_CODE_DELAY);
#    endif
             mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON2);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
                } else if(check_mouse_wheel_click){
                    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON3);
                pointing_device_set_report(mouse_report);
                pointing_device_send();
                } else {

                    if(is_keyboard_master()){
                    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();

                 #    if TAP_CODE_DELAY > 0
                wait_ms(TAP_CODE_DELAY);
                #    endif
             mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();


                } else {
                    //tap_code16(KC_MS_BTN1);
                    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
                    //pointing_device_set_shared_report(mouse_report);
                    defer_exec(300,derigister_cirque_click_callback, NULL)
;

             //        #    if TAP_CODE_DELAY > 0
             //  wait_ms(TAP_CODE_DELAY);
             //  #    endif

             //       mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
             //       pointing_device_set_shared_report(mouse_report);
                }

                #ifdef HAPTIC_ENABLE
                    DRV_pulse(strong_click);
               #endif
                }
                }
            }

        }
        cirque_mouse_timer = timer_read();
    }

    if (is_strong_touch(touchData.zValue && drag_down == false)) {
                 mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
                pointing_device_set_report(mouse_report);
                pointing_device_send();



                #ifdef HAPTIC_ENABLE
                    DRV_pulse(pulsing_strong);
               #endif

               drag_down = true;
            }
    if (timer_elapsed(cirque_mouse_timer) > (CIRQUE_PINNACLE_TOUCH_DEBOUNCE)) {
        cirque_mouse_timer = 0;
    }
    mouse_report.x = report_x;
    mouse_report.y = report_y;
    last_x = raw_x;
    last_y = raw_y;
    last_z = raw_z;

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
          #ifdef CIRQUE_TRACKPAD_ROTATE_CLOCKWISE_90
          tap_tb(KC_UP, KC_DOWN, KC_RIGHT, KC_LEFT, mouse_report);
          # else
          tap_tb(KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP, mouse_report);
          #endif

        cirque_report.x = 0;
        cirque_report.y = 0;
        cirque_report.h = 0;
        cirque_report.v = 0;
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
    if(is_keyboard_master()){}
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
           cirque_trackpad__mode_set(CIRQUE_TRACKPAD_SCROLLING_MODE);
            mouse_timer = timer_read();
           return PROCESS_RECORD_RETURN_FALSE;
           }
             case CARET:
             if (record->event.pressed){ //is_caret ^= 1;
             cirque_trackpad__mode_set(CIRQUE_TRACKPAD_CARET_MODE);
             return PROCESS_RECORD_RETURN_FALSE;
             }
            case DRAG_MOM:
           if (record->event.pressed){ //is_drag_mom ^= 1;
            cirque_trackpad__mode_set(CIRQUE_TRACKPAD_DRAG_MOM_MODE);
            return PROCESS_RECORD_RETURN_FALSE;
            }
            case TRCKPD:
           if (record->event.pressed){
            cirque_trackpad__mode_set(CIRQUE_TRACKPAD_TRACKPAD_MODE);
            return PROCESS_RECORD_RETURN_FALSE;
            }


    }
return PROCESS_RECORD_CONTINUE;
 }
