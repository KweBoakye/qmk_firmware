#include QMK_KEYBOARD_H
#include "dilemma.h"
#include "kweboakye.h"
#include "users/kweboakye/keyrecords/os_toggle.h"
#if defined(UNICODEMAP_ENABLE) 
#    include "keyrecords/user_unicode.h"
#endif
#ifdef CIRQUE_ENABLED
#include "drivers/sensors/cirque_pinnacle.h"
#include "pointing/cirque_trackpad_logic.h"

#endif
#ifdef IQS5XX_ENABLED
#include "pointing/tps65/IQS5xx.h"
#endif
#include "drivers/sensors/azoteq_iqs5xx.h"
 #ifdef QUANTUM_PAINTER_ENABLE 
#include "users/kweboakye/quantumpainter/qp_display.h"
#endif

#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_MOD_DH] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       ______________COLEMAK_MOD_DH_L1____________ ,    ______________COLEMAK_MOD_DH_R1____________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____,    _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ______________COLEMAK_MOD_DH_L3____________,    ______________COLEMAK_MOD_DH_R3____________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    OSM(MOD_LSFT),  NAV_SPC,  SH_DEL, NAV_ENT, SYM_BSPC, OSL(_UNICODE)
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
  [_QWERTY_GAMING] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _____________QWERTY_GAMING_LEFT_1__________ ,    _____________QWERTY_GAMING_RIGHT_1_________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _____________QWERTY_GAMING_LEFT_2__________,    _____________QWERTY_GAMING_RIGHT_2_________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _____________QWERTY_GAMING_LEFT_3__________,    _____________QWERTY_GAMING_RIGHT_3_________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        MO(_GAMING_NUM_LAYER) ,  KC_SPC,  KC_LSFT, _______, _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
[_SYM] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    ___________________SYM_LEFT_1___________________ ,    ___________________SYM_RIGHT_1___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________________SYM_LEFT_2___________________,    ___________________SYM_RIGHT_2___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________________SYM_LEFT_3___________________,    ___________________SYM_RIGHT_3___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______,  MO(_FN),  _______, _______, _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

[_NAV] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    ___________________NAV_LEFT_1___________________ ,    ___________________NAV_RIGHT_1___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________________NAV_LEFT_2___________________,    ___________________NAV_RIGHT_2___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________________NAV_LEFT_3___________________,   ___________________NAV_RIGHT_3___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______, _______,  _______,       _______, MO(_FN), _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
  [_FN] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    _________________FUNC_LEFT_________________    , _________________FUNC_RIGHT________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ________________NUMBER_LEFT________________,    ________________NUMBER_RIGHT_______________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______ , KC_MINS , KC_ASTR , KC_PLUS ,  KC_SPC,   ___________________BLANK___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______, _______,  _______,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
   [_MOUSE] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    ___________________BLANK___________________    , ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     ___________________NAV_LEFT_2___________________,    ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      _______, KC_WH_U, KC_WH_D, _______, _______,   ___________________BLANK___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    KC_BTN3, KC_BTN1,  KC_BTN2,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
    [_MAINTENANCE] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    ________________MAINTANENCE_LEFT_1_______________, ________________MAINTANENCE_RIGHT_1______________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ________________MAINTANENCE_LEFT_2_______________, ________________MAINTANENCE_RIGHT_2______________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    ________________MAINTANENCE_LEFT_3_______________, ________________MAINTANENCE_RIGHT_3______________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______, _______,  _______,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
   [_UNICODE] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    ___________________BLANK___________________,      ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     ___________________BLANK___________________,    UM(BANG), UM(IRONY), OPEN_E, UM(SNEK), OPEN_O ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    ___________________BLANK___________________,      ___________________BLANK___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______, _______,  _______,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
   [_GAMING_NUM_LAYER] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     KC_ESC, _____NUMPAD_LEFT_1_3_KEY______,KC_LALT,      ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________NUMPAD_LEFT_2_4_KEY_____,KC_M,       ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     KC_LCTL, _____NUMPAD_LEFT_3_3_KEY______ ,KC_I,    ___________________BLANK___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    _______, KC_SPC,  KC_LSFT,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
    [_NUMPAD] = LAYOUT_split_3x5_3_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     KC_ESC, _____NUMPAD_LEFT_1_3_KEY______,KC_MINS,      ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ___________NUMPAD_LEFT_2_4_KEY_____,KC_PLUS,      ___________________BLANK___________________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     KC_SLASH, _____NUMPAD_LEFT_3_3_KEY______, KC_ASTR ,    ___________________BLANK___________________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    TG(_NUMPAD), KC_SPC,  KC_LSFT,       _______,_______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  )
};

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,4}, {1,4}, {2,4},{3,4} , {4,4}},
    {{0,5}, {1,5}, {2,5},{3,5} , {4,5}},
    {{0,6}, {1,6}, {2,6},{3,6} , {4,6}},
    {{0,7}, {1,7}, {2,7},{3,7} , {4,7}},
    /* Right hand, matrix positions */
    {{0,0}, {1,0}, {2,0},{3,0} ,{4,0}},
    {{0,1}, {1,1}, {2,1},{3,1} ,{4,1}},
    {{0,2}, {1,2}, {2,2},{3,2} ,{4,2}},
    {{0,3}, {1,3}, {2,3},{3,3} ,{4,3}},
};
#endif
#ifdef POINTING_DEVICE_COMBINED

#define CONSTRAIN_HID(amt) ((amt) < INT8_MIN ? INT8_MIN : ((amt) > INT8_MAX ? INT8_MAX : (amt)))
#define CONSTRAIN_HID_XY(amt) ((amt) < XY_REPORT_MIN ? XY_REPORT_MIN : ((amt) > XY_REPORT_MAX ? XY_REPORT_MAX : (amt)))

static i2c_status_t azoteq_iqs5xx_init_status = 1;

void azoteq_iqs5xx_init(void) {
    i2c_init();
    azoteq_iqs5xx_wake();
    azoteq_iqs5xx_reset_suspend(true, false, true);
    wait_ms(100);
    azoteq_iqs5xx_wake();
    if (azoteq_iqs5xx_get_product() != AZOTEQ_IQS5XX_UNKNOWN) {
        azoteq_iqs5xx_setup_resolution();
        azoteq_iqs5xx_init_status = azoteq_iqs5xx_set_report_rate(AZOTEQ_IQS5XX_REPORT_RATE, AZOTEQ_IQS5XX_ACTIVE, false);
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_event_mode(false, false);
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_reati(true, false);
#    if defined(AZOTEQ_IQS5XX_ROTATION_90)
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_xy_config(false, true, true, true, false);
#    elif defined(AZOTEQ_IQS5XX_ROTATION_180)
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_xy_config(true, true, false, true, false);
#    elif defined(AZOTEQ_IQS5XX_ROTATION_270)
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_xy_config(true, false, true, true, false);
#    else
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_xy_config(false, false, false, true, false);
#    endif
        azoteq_iqs5xx_init_status |= azoteq_iqs5xx_set_gesture_config(true);
        wait_ms(AZOTEQ_IQS5XX_REPORT_RATE + 1);
    }
};

report_mouse_t azoteq_iqs5xx_get_report(report_mouse_t mouse_report) {
    report_mouse_t temp_report           = {0};
    static uint8_t previous_button_state = 0;
    static uint8_t read_error_count      = 0;

    if (azoteq_iqs5xx_init_status == I2C_STATUS_SUCCESS) {
        azoteq_iqs5xx_base_data_t base_data = {0};
#    if !defined(POINTING_DEVICE_MOTION_PIN)
        azoteq_iqs5xx_wake();
#    endif
        i2c_status_t status          = azoteq_iqs5xx_get_base_data(&base_data);
        bool         ignore_movement = false;

        if (status == I2C_STATUS_SUCCESS) {
           //  pd_dprintf("IQS5XX - previous cycle time: %d \n", base_data.previous_cycle_time);
            read_error_count = 0;
            if (base_data.gesture_events_0.single_tap || base_data.gesture_events_0.press_and_hold) {
                pd_dprintf("IQS5XX - Single tap/hold.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON1);
            } else if (base_data.gesture_events_1.two_finger_tap) {
                pd_dprintf("IQS5XX - Two finger tap.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON2);
            } else if (base_data.gesture_events_0.swipe_x_neg) {
                pd_dprintf("IQS5XX - X-.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON4);
                ignore_movement     = true;
            } else if (base_data.gesture_events_0.swipe_x_pos) {
                pd_dprintf("IQS5XX - X+.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON5);
                ignore_movement     = true;
            } else if (base_data.gesture_events_0.swipe_y_neg) {
                pd_dprintf("IQS5XX - Y-.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON6);
                ignore_movement     = true;
            } else if (base_data.gesture_events_0.swipe_y_pos) {
                pd_dprintf("IQS5XX - Y+.\n");
                temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON3);
                ignore_movement     = true;
            } else if (base_data.gesture_events_1.zoom) {
                if (AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.x.h, base_data.x.l) < 0) {
                    pd_dprintf("IQS5XX - Zoom out.\n");
                    temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON7);
                } else if (AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.x.h, base_data.x.l) > 0) {
                    pd_dprintf("IQS5XX - Zoom in.\n");
                    temp_report.buttons = pointing_device_handle_buttons(temp_report.buttons, true, POINTING_DEVICE_BUTTON8);
                }
            } else if (base_data.gesture_events_1.scroll) {
                pd_dprintf("IQS5XX - Scroll.\n");
                temp_report.h = CONSTRAIN_HID(AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.x.h, base_data.x.l));
                temp_report.v = CONSTRAIN_HID(AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.y.h, base_data.y.l));
            }
            if (base_data.number_of_fingers == 1 && !ignore_movement) {
                temp_report.x = CONSTRAIN_HID_XY(AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.x.h, base_data.x.l));
                temp_report.y = CONSTRAIN_HID_XY(AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.y.h, base_data.y.l));
            }

            previous_button_state = temp_report.buttons;

        } else {
            if (read_error_count > 10) {
                read_error_count      = 0;
                previous_button_state = 0;
            } else {
                read_error_count++;
            }
            temp_report.buttons = previous_button_state;
            pd_dprintf("IQS5XX - get report failed: %d \n", status);
        }
    } else {
        pd_dprintf("IQS5XX - Init failed: %d \n", azoteq_iqs5xx_init_status);
    }

    return temp_report;
}

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report){
     if (is_keyboard_left()){
         // uprintf("rdy pin %d \n", (int) readPin(IQS55XX_RDY_PIN));
          report_mouse_t  iqs5xx_report;
          iqs5xx_report = azoteq_iqs5xx_get_report(mouse_report);
         
           mouse_report.x = iqs5xx_report.x;
           mouse_report.y = iqs5xx_report.y;
           if(os.type == OS_MACOS){
            mouse_report.h = iqs5xx_report.v / 16;
           mouse_report.v = iqs5xx_report.h / 16;
           } else {
             mouse_report.h = iqs5xx_report.v / 4;
           mouse_report.v = -iqs5xx_report.h / 4;
           }
           

           mouse_report.buttons = iqs5xx_report.buttons;
     } else {
          report_mouse_t  cirque_pinnacle_report;
     cirque_pinnacle_report = cirque_trackpad_pointing_device_task(mouse_report);
     mouse_report.x = cirque_pinnacle_report.y;
     mouse_report.y = -cirque_pinnacle_report.x;
     mouse_report.h = cirque_pinnacle_report.v;
     mouse_report.v = -cirque_pinnacle_report.h;
     mouse_report.buttons = cirque_pinnacle_report.buttons;
    // uprintf("touchpad_init: %s", touchpad_init ? "true" : "false");
     }
if(mouse_report.x != 0 && mouse_report.y != 0){
    uprintf("mouse_report.x %d  mouse_report.y %d\n", mouse_report.x,  mouse_report.y);
}
     return mouse_report;
}

void pointing_device_driver_init(void) {
    if (is_keyboard_left()) {
     
     azoteq_iqs5xx_init();
    } else {
     cirque_trackpad_logic_init();
    }
}

void           pointing_device_driver_set_cpi(uint16_t cpi) {
    if(is_keyboard_left()){
     azoteq_iqs5xx_set_cpi(cpi);
    } else {
 cirque_pinnacle_set_scale(cpi);
    }

    }

    uint16_t       pointing_device_driver_get_cpi(void) { 
     if(is_keyboard_left()){
          return azoteq_iqs5xx_get_cpi();
     } else {
          return cirque_pinnacle_get_scale();
     }
    }
    
#endif

    void keyboard_post_init_keymap(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
   #ifdef QUANTUM_PAINTER_ENABLE 
 keyboard_post_init_kb_display();
#endif
 

}

