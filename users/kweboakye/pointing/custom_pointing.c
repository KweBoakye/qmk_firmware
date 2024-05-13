//#include "pointing.h"
#include "custom_pointing.h"

#ifdef CIRQUE_ENABLED
#include "cirque_trackpad_logic.h"
#endif
#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
#include "analog_joystick_logic.h"
#endif

#include <math.h>


//static uint16_t mouse_debounce_timer  = 0;
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

#ifdef POINTING_DEVICE_COMBINED
__attribute__((weak))  report_mouse_t pointing_device_task_combined_keymap(report_mouse_t left_report, report_mouse_t right_report){
    return pointing_device_combine_reports(left_report, right_report);
}

#endif

void pointing_device_init_user(void){
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    

    if (mouse_report.x != 0 && mouse_report.y != 0) {
        
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
      
    } 

    return pointing_device_task_keymap(mouse_report);
}




#ifdef POINTING_DEVICE_COMBINED
 report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    
    if ((left_report.x != 0 && left_report.y != 0) ||( right_report.x != 0 && right_report.y != 0)) {
        
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
    }     
    return pointing_device_task_combined_keymap(left_report, right_report);
 }
 #endif


 process_record_result_t process_record_pointing(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
           case MO(_MOUSE):
            record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
        
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

//  bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record){
//     switch(keycode){
//         case KC_BTN4:
//         case KC_BTN5:
//             return false;
//         default:
//          return false;
//     }
//  }

// layer_state_t layer_state_set_pointing(layer_state_t state) {
//     if (layer_state_cmp(state, _GAME)) {
//         state |= ((layer_state_t)1 << _MOUSE);
//     }
//     return state;
// }