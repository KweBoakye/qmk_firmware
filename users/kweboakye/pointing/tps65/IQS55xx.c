#include "IQS55xx.h"
#include "i2c_master.h"

uint8_t 	Data_Buff[44];
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

/* void set_xy_config_0(void){

    static uint8_t XY_config_0 = (FLIP_X | FLIP_Y | SWITCH_XY_AXIS | PALM_REJECT );
    i2c_writeReg16(IQS5xx_ADDR<<1 ,XYConfig0_adr, &XY_config_0, sizeof(XY_config_0), 4);
} */

void init_iqs55xx(void) {
    //setPinInputHigh(IQS55XX_RDY_PIN);
    i2c_init();
//set_xy_config_0();
    IQS5xx_AcknowledgeReset();
    Close_Comms();
}

iqs55xx_data_t Process_XY(void){

    iqs55xx_data_t iqs55xx_data = {0};
	uint8_t 	i;
	//static uint8_t ui8FirstTouch = 0;
	//uint8_t 	ui8NoOfFingers;
	//uint8_t 	ui8SystemFlags[2];
	//int16_t 	i16RelX[6];
	//int16_t 	i16RelY[6];
	//uint16_t 	ui16AbsX[6];
	//uint16_t 	ui16AbsY[6];
	//uint16_t 	ui16TouchStrength[6];
	//uint8_t  	ui8Area[6];

	iqs55xx_data.ui8SystemFlags[0] = Data_Buff[2];
	iqs55xx_data.ui8SystemFlags[1] = Data_Buff[3];
	iqs55xx_data.ui8NoOfFingers = Data_Buff[4];
	//
	// Re-initialize the device if unexpected RESET detected
	//
	if((iqs55xx_data.ui8SystemFlags[0] & SHOW_RESET) != 0)
	{
		// Serial.println("RESET DETECTED");
		IQS5xx_AcknowledgeReset();
		//return iqs55xx_data_t;
	}

	if((iqs55xx_data.ui8SystemFlags[1] & SNAP_TOGGLE) != 0)
	{
		// A snap state has changed, thus indicate which channel
		//
		//DisplaySnap();
		//return iqs55xx_data_t;
	}

	if((Data_Buff[0]) == SINGLE_TAP)
	{
        iqs55xx_data.single_tap = true;
		// Serial.println("Single Tap  ");
	}
	else if((Data_Buff[1]) == TWO_FINGER_TAP)
	{
        iqs55xx_data.two_finger_tap = true;
		// Serial.println("2 Finger Tap");
	}

	if(iqs55xx_data.ui8NoOfFingers != 0)
	{
		if (!(iqs55xx_data.ui8FirstTouch))
		{
			// Serial.print("Gestures:    ");
			// Serial.print(" RelX: ");
			// Serial.print("RelY: ");
			// Serial.print("Fig: ");
			// Serial.print("X1:  "); Serial.print("Y1:  "); Serial.print("TS1: "); Serial.print("TA1: ");
			// Serial.print("X2:  "); Serial.print("Y2:  "); Serial.print("TS2: "); Serial.print("TA2: ");
			// Serial.print("X3:  "); Serial.print("Y3:  "); Serial.print("TS3: "); Serial.print("TA3: ");
			// Serial.print("X4:  "); Serial.print("Y4:  "); Serial.print("TS4: "); Serial.print("TA4: ");
			// Serial.print("X5:  "); Serial.print("Y5:  "); Serial.print("TS5: "); Serial.println("TA5: ");
			iqs55xx_data.ui8FirstTouch = 1;
		}

		switch (Data_Buff[0])
		{
			case SINGLE_TAP		:  	// Serial.print("Single Tap  ");
                                    iqs55xx_data.single_tap = true;
									break;
			case TAP_AND_HOLD	:  	// Serial.print("Tap & Hold  ");
                                    iqs55xx_data.tap_and_hold = true;
									break;
			case SWIPE_X_NEG	:  	// Serial.print("Swipe X-    ");
                                    iqs55xx_data.swipe_x_neg = true;
									break;
			case SWIPE_X_POS	:  	// Serial.print("Swipe X+    ");
                                    iqs55xx_data.swipe_x_pos = true;
									break;
			case SWIPE_Y_POS	:  	// Serial.print("Swipe Y+    ");
                                    iqs55xx_data.swipe_y_pos = true;
									break;
			case SWIPE_Y_NEG	:  	// Serial.print("Swipe Y-    ");
                                    iqs55xx_data.swipe_y_neg = true;
									break;
		}

		switch (Data_Buff[1])
		{
			case TWO_FINGER_TAP	:  	// Serial.print("2 Finger Tap");
                                    iqs55xx_data.two_finger_tap = true;
									break;
			case SCROLL			:  	// Serial.print("Scroll      ");
                                    iqs55xx_data.scroll = true;
									break;
			case ZOOM			:  	// Serial.print("Zoom        ");
                                    iqs55xx_data.zoom = true;
									break;
		}
		if((Data_Buff[0] | Data_Buff[1]) == 0)
		{
			// Serial.print("            ");
		}

		iqs55xx_data.i16RelX[1] = ((Data_Buff[5] << 8) | (Data_Buff[6]));
		iqs55xx_data.i16RelY[1] = ((Data_Buff[7] << 8) | (Data_Buff[8]));
		//Print_signed(iqs55xx_data.i16RelX[1]);
		//Print_signed(iqs55xx_data.i16RelY[1]);
		//Print_unsigned(ui8NoOfFingers);

           uprintf("x %d y %d\n", iqs55xx_data.i16RelX[1], iqs55xx_data.i16RelY[1]);

		for (i = 0; i < 5; i++)
		{
			iqs55xx_data.ui16AbsX[i+1] = ((Data_Buff[(7*i)+9] << 8) | (Data_Buff[(7*i)+10])); //9-16-23-30-37//10-17-24-31-38
			iqs55xx_data.ui16AbsY[i+1] = ((Data_Buff[(7*i)+11] << 8) | (Data_Buff[(7*i)+12])); //11-18-25-32-39//12-19-26-33-40
			iqs55xx_data.ui16TouchStrength[i+1] = ((Data_Buff[(7*i)+13] << 8) | (Data_Buff[(7*i)+14])); //13-20-27-34-11/14-21-28-35-42
			iqs55xx_data.ui8Area[i+1] = (Data_Buff[7*i+15]); //15-22-29-36-43
			//Print_unsigned(iqs55xx_data.ui16AbsX[i+1]);
			//Print_unsigned(iqs55xx_data.ui16AbsY[i+1]);
			//Print_unsigned(iqs55xx_data.ui16TouchStrength[i+1]);
			//Print_unsigned(iqs55xx_data.ui8Area[i+1]);
		}
		// Serial.println("");
	}
	else
	{
		iqs55xx_data.ui8FirstTouch = 0;
	}

    return iqs55xx_data;
}


void read_iqs55xx(void) {
 	uint8_t		ui8TempData[30], i;



 i2c_readReg16(IQS5xx_ADDR<<1, GestureEvents0_adr, &Data_Buff[0], 44, 1);


	if((Data_Buff[3] & SNAP_TOGGLE) != 0)
	{
		// If there was a change in a snap status, then read the snap status
		// bytes additionally. Keep previous valus to identify a state change
		//
		i2c_readReg16(IQS5xx_ADDR<<1,SnapStatus_adr, &ui8TempData[0], 30, 7);
		for(i = 0; i < 15; i++)
		{
			ui16PrevSnap[i] = ui16SnapStatus[i];
			ui16SnapStatus[i] = ((uint16_t)(ui8TempData[2*i])<<8) +
								 (uint16_t)ui8TempData[(2*i)+1];
		}
	}

    Close_Comms();


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


uint16_t timeout = 2;
static uint16_t timer = 0;

report_mouse_t iqs55xx_get_report(report_mouse_t mouse_report){


/* while(!readPin(IQS55XX_RDY_PIN)){
  printf("%s", "IQS55XX_RDY_PIN is low \n");
} */
  //if(readPin(IQS55XX_RDY_PIN)){
     //  printf("%s", "IQS55XX_RDY_PIN is high \n");

     if(timer_elapsed(timer) >= timeout) {
			//RDY_wait();
			timer = timer_read();
    read_iqs55xx();
    iqs55xx_data_t iqs55xx_data = Process_XY();
    //int16_t x, y = 0;



/*     if(iqs55xx_data.scroll){

    }

    if(){

    }

    if(){

    }

    if(){

    }

    if(){

    }

    if(){

    }

    if(){

    } */

   mouse_report.x = (int16_t)iqs55xx_data.i16RelX[1] * -1;
   mouse_report.y= (int16_t)iqs55xx_data.i16RelY[1] * -1;
   uprintf("mouse_report.x %d  mouse_report.y %d\n", mouse_report.x,  mouse_report.y);
 // } else {
    //  printf("%s", "IQS55XX_RDY_PIN is low \n");
   //    mouse_report.x = 0;
   //    mouse_report.y= 0;
 // }


 }
   return mouse_report;
}
