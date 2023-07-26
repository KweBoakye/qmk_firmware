#include "IQS5xx.h"


//uint8_t 	Data_Buff[44];
uint16_t	ui16SnapStatus[15], ui16PrevSnap[15];
uint8_t		stop = 1;


///*****************************************************************************
//
//! Acknowledge the reset flag
//!
//! This function simply sets the ACK_RESET bit found in the SYSTEM_CONTROL_0
//! register.  By setting this bit the SHOW_RESET flag is cleared in the
//! SYSTEM_INFO_0 register.  During normal operation, the SHOW_RESET bit can be
//! monitored and if it becomes set, then an unexpected reset has occurred.
//! If any device configuration is needed, it must then be repeated.
//!
//! \param None
//!
//! \return None
//
//*****************************************************************************
void IQS5xx_AcknowledgeReset(void)
{
    static  uint8_t System_ctrl_0 = ACK_RESET;

	i2c_writeReg16(IQS5xx_ADDR<<1,SystemControl0_adr, &System_ctrl_0, 1, 4);
}


//*****************************************************************************
//
//! Terminate communication window
//!
//! The IQS5xx B000 does not close the communication window on the reception of
//!	the STOP bit; therefore this function sends the END COMMUNICATION WINDOW
//!	COMMAND (Please see datasheet for more information). RDY will go low after
//!	receiving any write to 0xEEEE followed by a STOP.
//!
//! \param None
//!
//! \return None
//
//*****************************************************************************
void Close_Comms(void)
{
  //uint8_t ui8DataBuffer[1];

  i2c_writeReg16(IQS5xx_ADDR<<1,END_WINDOW, &stop, 1, 1);
}

 void set_xy_config_0(void){

    static uint8_t XY_config_0 = FLIP_Y  ;
    i2c_writeReg16(IQS5xx_ADDR<<1 ,XYConfig0_adr, &XY_config_0, sizeof(XY_config_0), 4);
}

void set_GestureEvents0(void){
    static uint8_t GestureEvents0 = SINGLE_TAP | TAP_AND_HOLD;
     i2c_writeReg16(IQS5xx_ADDR<<1 ,GestureEvents0_adr, &GestureEvents0, sizeof(GestureEvents0), 4);
}

void set_TapTime(void){
    static uint16_t TapTime = 150;
    uint8_t wbuff[16];
     *((uint16_t*)wbuff) = SWPEND16(TapTime);
    i2c_writeReg16(IQS5xx_ADDR<<1 ,TapTime_adr, wbuff, sizeof(uint16_t), 4);

}

void set_distance(void){
    static uint16_t tap_distance = 50;
    uint8_t wbuff[16];
     *((uint16_t*)wbuff) = SWPEND16(tap_distance);
    i2c_writeReg16(IQS5xx_ADDR<<1 ,TapDistance_adr, wbuff, sizeof(uint16_t), 4);

}

// void enble_noise_detection(void){
//     static uint8_t noise_detect = ND_ENABLE;
//     i2c_writeReg16(IQS5xx_ADDR<<1 ,TapTime_adr, noise_detect, sizeof(uint8_t), 4);
// }

// void set_GestureEvents1(void){
//     static uint8_t GestureEvents1 = (TWO_FINGER_TAP | SCROLL | ZOOM)
//      i2c_writeReg16(IQS5xx_ADDR<<1 ,GestureEvents1_adr, &GestureEvents1, sizeof(GestureEvents1), 4);
// }

void setting_config(void){
set_xy_config_0();
    //set_GestureEvents0();
    set_TapTime();
    set_distance();
}

void init_iqs5xx(void) {
    setPinInput(IQS55XX_RDY_PIN);
    i2c_init();
    //IQS5xx_AcknowledgeReset();
//Close_Comms();
    setting_config();
    Close_Comms();
}



i2c_status_t  read_iqs5xx(azoteq_iqs5xx_base_data_t *base_data) {
 	



 uint8_t buffer[44];
   i2c_status_t status = i2c_readReg16(IQS5xx_ADDR<<1, GestureEvents0_adr, buffer, sizeof(buffer), 10);

    Close_Comms();
    if(status < 0){
        return status;
    } 
      
    base_data->gesture_events_0 = buffer[0];
    base_data->gesture_events_1 = buffer[1];
    base_data->system_info_0 = buffer[2];
    base_data->system_info_1 = buffer[3];
    base_data->number_of_fingers = buffer[4];
    base_data->relative_x.h = buffer[5];
    base_data->relative_x.l = buffer[6];
    base_data->relative_y.h = buffer[7]; 
    base_data->relative_y.l = buffer[8];
    for(int i = 0; i < 5;i++) {
        const int p = 9 + (7 * i);
        base_data->finger_data.ax.h = buffer[p];
        base_data->finger_data.ax.l = buffer[p + 1];
         base_data->finger_data.ay.h = buffer[p + 2];
        base_data->finger_data.ay.l = buffer[p + 3];
        base_data->finger_data.strength = buffer[p + 4] << 8 | buffer [p + 5];
        base_data->finger_data.area = buffer[p + 5];
    }

    return status;
}

/* __attribute__((weak)) iqs55xx_handle_swipe_y_neg(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) iqs55xx_handle_swipe_y_pos(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) iqs55xx_handle_swipe_x_neg(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) iqs55xx_handle_swipe_x_pos(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) iqs55xx_handle_tap_and_hold(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) uint8_t iqs55xx_handle_single_tap(uint8_t buttons, uint16_t ui16AbsX, uint16_t ui16AbsY){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON1)
}

__attribute__((weak)) iqs55xx_handle_zoom(uint8_t buttons, int16_t i16RelX1){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) iqs55xx_handle_scroll(uint8_t buttons, int16_t i16RelY1, int16_t i16RelY1 ){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON)
}

__attribute__((weak)) uint8_t iqs55xx_handle_two_finger_tap(uint8_t buttons){
    return pointing_device_handle_buttons(buttons, true, POINTING_DEVICE_BUTTON3)
} */


uint16_t timeout = 0.15;
//static uint32_t timer = 0;
bool mouse_held = false;
bool left_clicked = false;
bool right_clicked = false;

void send_mouse_button(report_mouse_t mouse_report, bool pressed, pointing_device_buttons_t button){
 mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, pressed, button);
   pointing_device_set_report(mouse_report);
                    pointing_device_send();
}

void send_left_click(report_mouse_t mouse_report){
    send_mouse_button(mouse_report, true, POINTING_DEVICE_BUTTON1);
}

void send_left_click_deregister(report_mouse_t mouse_report){
    send_mouse_button(mouse_report, false, POINTING_DEVICE_BUTTON1);
}
uint32_t derigister_left_click_callback(uint32_t trigger_time, void *cb_arg) {
   report_mouse_t mouse_report = pointing_device_get_report();
     send_mouse_button(mouse_report, false, POINTING_DEVICE_BUTTON1);
                return  0;
}


void send_right_click(report_mouse_t mouse_report){
     send_mouse_button(mouse_report, true, POINTING_DEVICE_BUTTON2);

}


void send_right_click_deregister(report_mouse_t mouse_report){
     send_mouse_button(mouse_report, false, POINTING_DEVICE_BUTTON2);

}
uint32_t derigister_right_click_callback(uint32_t trigger_time, void *cb_arg) {
   report_mouse_t mouse_report = pointing_device_get_report();
     send_mouse_button(mouse_report, false, POINTING_DEVICE_BUTTON2);
                return  0;
}

bool zooming = false;
bool ctrl_for_zoom_held = false;
bool three_fingers_down = false;
bool middle_held = false;
uint16_t three_finger_click_length = 100;
uint16_t three_fingers_down_timer = 0;

report_mouse_t iqs5xx_get_report(report_mouse_t mouse_report){




/* while(!readPin(IQS55XX_RDY_PIN)){
  printf("%s", "IQS55XX_RDY_PIN is low \n");
} */
  //if(readPin(IQS55XX_RDY_PIN)){
     //  printf("%s", "IQS55XX_RDY_PIN is high \n");
if(!mouse_held){
 mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
}
if(right_clicked){
mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON2);
}

int pin_val = readPin(IQS55XX_RDY_PIN);
    //uprintf("rdy is %d",pin_val);
    if(pin_val){
      //  uprintf("in cond");
    // if(timer_elapsed(timer) >= timeout) {
			//RDY_wait();
	//		timer = timer_read32();
   
    azoteq_iqs5xx_base_data_t base_data = {0};
   read_iqs5xx(&base_data);
    bool has_gesture = false;

     if(base_data.number_of_fingers == 3){
        
         uprintf("three_fingers_down");
         if(three_fingers_down && three_fingers_down_timer > three_finger_click_length){
          mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON3);  
          middle_held = true;
         }
         three_fingers_down = true;
         three_fingers_down_timer =  timer_read();
     } 
      if(base_data.number_of_fingers == 0 && three_fingers_down && three_fingers_down_timer < three_finger_click_length){
        uprintf("three click");
        if(middle_held){
            mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON3);
        } else {
          mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON3);
          three_fingers_down = false;
          has_gesture = true;   

        }
      } else if(three_fingers_down && base_data.number_of_fingers != 3) {
          mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON3);
          three_fingers_down = false;
          uprintf("three unclick");
      }

    if((base_data.gesture_events_0 || base_data.gesture_events_1) && !three_fingers_down){
        switch(base_data.gesture_events_1){
            case TWO_FINGER_TAP:  mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON2);
            has_gesture = true;
            break;
            case SCROLL:
            #if defined(MOUSE_EXTENDED_REPORT)
            mouse_report.h = (int16_t)AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.relative_x.h, base_data.relative_x.l);
            mouse_report.v = (int16_t)AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.relative_y.h, base_data.relative_y.l);
            #else
            mouse_report.h = (int8_t)base_data.relative_x.l;
            mouse_report.v = (int8_t)base_data.relative_y.l;
            #endif  
            has_gesture = true;
           break;
           case ZOOM:
            if(!zooming){
                zooming = true;
                register_code(KC_LCTL);
                ctrl_for_zoom_held = true;
                 
            }
           #if defined(MOUSE_EXTENDED_REPORT)
            mouse_report.v = (int16_t)AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.relative_y.h, base_data.relative_x.l);
            #else
            mouse_report.v = (int8_t)base_data.relative_x.l;
            #endif  
            has_gesture = true;
            
            break;
        }
        switch(base_data.gesture_events_0){
            case SINGLE_TAP: 
            if(mouse_held){
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
                mouse_held = false;
            } else {
                mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
            }
            has_gesture = true;
             break;
            case TAP_AND_HOLD:
            mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
            mouse_held = true; 
            uprintf("tap and hold");  
            break;
            case SWIPE_X_NEG:
            tap_code(KC_LEFT);
            has_gesture = true;
            break;
            case SWIPE_X_POS:
            tap_code(KC_RIGHT);
            has_gesture = true;
            break;
            case SWIPE_Y_NEG:
            tap_code(KC_UP);
            has_gesture = true;
            break;
            case SWIPE_Y_POS:
            tap_code(KC_DOWN);
            has_gesture = true;
            break;
        }
    } else {
        if(zooming && !has_gesture){
        uprintf("in not zoom");
        zooming = false;
        if(ctrl_for_zoom_held){
            unregister_code(KC_LCTL);
        }
        }
    }

      if(!has_gesture){
        #if defined(MOUSE_EXTENDED_REPORT)
    mouse_report.x = (int16_t)AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.relative_x.h, base_data.relative_x.l);
    mouse_report.y = (int16_t)AZOTEQ_IQS5XX_COMBINE_H_L_BYTES(base_data.relative_y.h, base_data.relative_y.l);
#else
    mouse_report.x = (int8_t)base_data.relative_x.l;
    mouse_report.y = (int8_t)base_data.relative_y.l;
#endif
   uprintf("mouse_report.x %d  mouse_report.y %d\n", mouse_report.x,  mouse_report.y);
    }
        uprintf("number of fingers %d\n",base_data.number_of_fingers);

    }
    //uprintf("button %d\n", (int)mouse_report.buttons);
   return mouse_report;
}

