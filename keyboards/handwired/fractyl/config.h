// Copyright 2023 kweboakye (@kweboakye)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_ROWS 8
#define MATRIX_COLS 5 

#define SPLIT_HAND_PIN GP21

#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN     GP0
#define SERIAL_USART_RX_PIN     GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT    100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED      806400 //460800
#define SERIAL_USART_PIN_SWAP

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_HAPTIC_ENABLE

#define SPI_DRIVER                           SPID0
#define SPI_SCK_PIN                          GP2
#define SPI_MOSI_PIN                         GP3
#define SPI_MISO_PIN                         GP4

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP4
#define I2C1_SCL_PIN GP5

#ifdef QUANTUM_PAINTER_ENABLE
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 30000
    /* right */
    #define DISPLAY_CS_PIN_RIGHT GP5
    #define DISPLAY_RST_PIN_RIGHT GP6
    #define DISPLAY_DC_PIN_RIGHT GP7

    /*  left */
    #define DISPLAY_CS_PIN GP4
    #define DISPLAY_RST_PIN GP6
    #define DISPLAY_DC_PIN GP7

    
    //#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
    #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
    //#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (96U * 1024U) //1024
    #define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
    //#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
   #define ST7789_NUM_DEVICES 2
#endif //QUANTUM_PAINTER_ENABLE

/* Backlight configuration for TFT Screen */
#ifdef BACKLIGHT_ENABLE
    #define BACKLIGHT_PIN GP22
    #define BACKLIGHT_LEVELS 8
    #define BACKLIGHT_DEFAULT_LEVEL 6
    #define BACKLIGHT_PWM_DRIVER PWMD3
    #define BACKLIGHT_PWM_CHANNEL 1
#endif //BACKLIGHT_ENABLE

/* Audio configuration */
#ifdef AUDIO_ENABLE
    #define AUDIO_PIN GP28
    #define AUDIO_PWM_DRIVER PWMD6
    #define AUDIO_PWM_CHANNEL 1
#endif //AUDIO_ENABLE

//#ifdef RGB_MATRIX_ENABLE
    #define __flash
    #define DRIVER_ADDR_1  0b0100000
    #define DRIVER_COUNT 2
    #define DRIVER_1_LED_TOTAL 1
    #define DRIVER_2_LED_TOTAL 1
    #define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
//#endif