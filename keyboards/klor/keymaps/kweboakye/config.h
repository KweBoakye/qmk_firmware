#pragma once
#define MASTER_LEFT
//#define EE_HANDS
//#undef USE_SERIAL
//#undef SOFT_SERIAL_PIN
//#define SERIAL_USART_FULL_DUPLEX
//#define SERIAL_USART_TX_PIN D2
//#define SERIAL_USART_RX_PIN D4
//#define SERIAL_USART_PIN_SWAP

// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN C7//GP14
// #define SPI_MISO_PIN NO_PIN //B7 //GP12
// #define SPI_MOSI_PIN F1//GP15

// #ifdef QUANTUM_PAINTER_ENABLE 
//     #define LCD_CS_PIN D5 //GP13
//     #define LCD_DC_PIN F4 //GP28 ENCB
//     #define LCD_RST_PIN F5 //GP29 ENCA
//     #define LCD_DC_PIN_RIGHT F4 //GP29 ENCA
//     #define LCD_RST_PIN_RIGHT F5 //GP28 ENCB
//     #undef ENCODERS_PAD_A     
//     #undef ENCODERS_PAD_B     
//     #undef ENCODERS_PAD_A_RIGHT
//     #undef ENCODERS_PAD_B_RIGHT 
//     #define QP_LVGL_TASK_PERIOD 50
//     #define LCD_DISPLAY_ROTATION QP_ROTATION_90
//     #define ST7789_NUM_DEVICES 2
//     #define QUANTUM_PAINTER_DEBUG true
//     //#define QUANTUM_PAINTER_DEBUG_ENABLE_FLUSH_TASK_OUTPUT true
//     #define ST7789_135
// #endif

// #ifdef BACKLIGHT_ENABLE
//     #define BACKLIGHT_PIN B7  // GP12 
//     #define BACKLIGHT_PWM_DRIVER PWMD6
//     #define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A
//     //#define BACKLIGHT_PAL_MODE 4
//     //#define BACKLIGHT_GPT_DRIVER GPTD4
//     #define BACKLIGHT_LEVELS 5
// #endif

#define AZOTEQ_IQS5XX_TPS43
#define AZOTEQ_IQS5XX_TAP_ENABLE true
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
#define AZOTEQ_IQS5XX_SWIPE_X_ENABLE true
#define AZOTEQ_IQS5XX_ZOOM_ENABLE true
#define AZOTEQ_IQS5XX_SCROLL_ENABLE true
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 25
#define AZOTEQ_IQS5XX_ROTATION_270   
#define POINTING_DEVICE_DEBUG true
// #define IQS55XX_RDY_PIN  F0 // GP16

#define SPLIT_POINTING_ENABLE 
#define POINTING_DEVICE_COMBINED
#define MOUSE_EXTENDED_REPORT

//#define EE_HANDS

// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 1
// #define BOOTMAGIC_LITE_ROW_RIGHT 4
// #define BOOTMAGIC_LITE_COLUMN_RIGHT 4

// ┌─────────────────────────────────────────────────┐
// │ a u d i o                                       │
// └─────────────────────────────────────────────────┘
#ifdef AUDIO_ENABLE
    #define AUDIO_PWM_DRIVER PWMD4
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
    #define AUDIO_STATE_TIMER GPTD4
#endif

#ifdef RGB_MATRIX_ENABLE
#    undef RGB_MATRIX_STARTUP_HUE
#    define RGB_MATRIX_STARTUP_HUE 120
#    undef RGB_MATRIX_STARTUP_VAL
#    define RGB_MATRIX_STARTUP_VAL 80
#    define ENABLE_RGB_MATRIX_SOLID_COLOR
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#endif 