#include "pointing.h"
#ifdef CIRQUE_ENABLED
#include "cirque_trackpad_logic.h"
#endif
#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
#include "analog_joystick_logic.h"
#endif

#include <math.h>

uint16_t mouse_timer           = 0;
static uint16_t mouse_debounce_timer  = 0;
 uint8_t  mouse_keycode_tracker = 0;
bool            tap_toggling = false, enable_acceleration = false;

#ifdef TAPPING_TERM_PER_KEY
#    define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#else
#    ifndef TAPPING_TERM
#        define TAPPING_TERM 200
#    endif
#    define TAP_CHECK TAPPING_TERM
#endif

__attribute__((weak)) report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report) {
    return mouse_report;
}

__attribute__((weak))  report_mouse_t pointing_device_task_combined_keymap(report_mouse_t left_report, report_mouse_t right_report){
    return pointing_device_combine_reports(left_report, right_report);
}






report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int8_t x = mouse_report.x, y = mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;

    if (x != 0 && y != 0) {
        mouse_timer = timer_read();
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
        if (timer_elapsed(mouse_debounce_timer) > TAP_CHECK) {
            if (enable_acceleration) {
                x = (x > 0 ? x * x / 16 + x : -x * x / 16 + x);
                y = (y > 0 ? y * y / 16 + y : -y * y / 16 + y);
            }
            mouse_report.x = x;
            mouse_report.y = y;
            if (!layer_state_is(_MOUSE)) {
                layer_on(_MOUSE);
            }
        }
    } else if (timer_elapsed(mouse_timer) > 650 && layer_state_is(_MOUSE) && !mouse_keycode_tracker && !tap_toggling) {
        layer_off(_MOUSE);
    } else if (tap_toggling) {
        if (!layer_state_is(_MOUSE)) {
            layer_on(_MOUSE);
        }
    }

    return pointing_device_task_keymap(mouse_report);
}





 report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
      int8_t left_x = left_report.x, left_y = left_report.y, right_x = right_report.x, right_y = right_report.y;
  //    left_report.x = 0;
  //  left_report.y = 0;
  //   right_report.x = 0;
  //  right_report.y = 0;

    if ((left_x != 0 && left_y != 0) ||( right_x != 0 && right_y != 0)) {
        mouse_timer = timer_read();
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
        if (timer_elapsed(mouse_debounce_timer) > TAP_CHECK) {
            if (enable_acceleration) {
                left_x = (left_x > 0 ? left_x * left_x / 16 + left_x : -left_x * left_x / 16 + left_x);
                left_y = (left_y > 0 ? left_y * left_y / 16 + left_y : -left_y * left_y / 16 + left_y);
                right_x = (right_x > 0 ? right_x * right_x / 16 + right_x : -right_x * right_x / 16 + right_x);
                right_y = (right_y > 0 ? right_y * right_y / 16 + right_y : -right_y * right_y / 16 + right_y);
            }
            left_report.x = left_x;
            left_report.y = left_y;
            right_report.x = right_x;
            right_report.y = right_y;
            if (!layer_state_is(_MOUSE)) {
                layer_on(_MOUSE);
            }
        }
    } else if (timer_elapsed(mouse_timer) > 650 && layer_state_is(_MOUSE) && !mouse_keycode_tracker && !tap_toggling) {
        layer_off(_MOUSE);
    } else if (tap_toggling) {
        if (!layer_state_is(_MOUSE)) {
            layer_on(_MOUSE);
        }
    }



    return pointing_device_task_combined_keymap(left_report, right_report);
 }


 process_record_result_t process_record_pointing(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
           case MO(_MOUSE):
            record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
            mouse_timer = timer_read();
           return PROCESS_RECORD_CONTINUE;
           case TT(_MOUSE):
            if (record->event.pressed) {
                mouse_keycode_tracker++;
            } else {
#if TAPPING_TOGGLE != 0
                if (record->tap.count == TAPPING_TOGGLE) {
                    tap_toggling ^= 1;
#    if TAPPING_TOGGLE == 1
                    if (!tap_toggling) mouse_keycode_tracker -= record->tap.count + 1;
#    else
                    if (!tap_toggling) mouse_keycode_tracker -= record->tap.count;
#    endif
                } else {
                    mouse_keycode_tracker--;
                }
#endif
            }
            mouse_timer = timer_read();
            return PROCESS_RECORD_CONTINUE;

    }

    #ifdef CIRQUE_ENABLED
     switch (process_record_trackpad(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
    #endif

#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
     switch (process_record_analog_joystick(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
    #endif
return PROCESS_RECORD_CONTINUE;

 }

layer_state_t layer_state_set_pointing(layer_state_t state) {
    if (layer_state_cmp(state, _GAME)) {
        state |= ((layer_state_t)1 << _MOUSE);
    }
    return state;
}