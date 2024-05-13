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
//#define SPLIT_TRANSPORT_MIRROR

#define SPI_DRIVER                           SPID0
#define SPI_SCK_PIN                          GP2
#define SPI_MOSI_PIN                         GP3
#define SPI_MISO_PIN                         GP4

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

#ifdef QUANTUM_PAINTER_ENABLE
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 30000
    /* right */
    #define LCD_CS_PIN_RIGHT GP5
    #define LCD_RST_PIN_RIGHT GP8
    #define LCD_DC_PIN_RIGHT GP9

    /*  left */
    #define LCD_CS_PIN GP5
    #define LCD_RST_PIN GP8
    #define LCD_DC_PIN GP9

    
    //#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
    #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
    //#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (96U * 1024U) //1024
    #define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
    //#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
   #define ST7789_NUM_DEVICES 2
   #define LCD_DISPLAY_ROTATION QP_ROTATION_90
#endif //QUANTUM_PAINTER_ENABLE

/* Backlight configuration for TFT Screen */
#ifdef BACKLIGHT_ENABLE
    #define BACKLIGHT_PIN GP22
    #define BACKLIGHT_LEVELS 8
    #define BACKLIGHT_DEFAULT_LEVEL 6
    #define BACKLIGHT_PWM_DRIVER PWMD3
    #define BACKLIGHT_PWM_CHANNEL 1
#endif //BACKLIGHT_ENABLE

#ifdef PS2_ENABLE
    #define PS2_PIO_USE_PIO1 
    #define PS2_CLOCK_PIN   GP20
    #define PS2_DATA_PIN    GP19
#endif

/* Audio configuration */
#ifdef AUDIO_ENABLE
    #define AUDIO_PIN GP28
    #define AUDIO_PWM_DRIVER PWMD6
    #define AUDIO_PWM_CHANNEL 1
#endif //AUDIO_ENABLE

#ifdef RGB_MATRIX_ENABLE
    #define __flash
    #define DRIVER_ADDR_2  DRIVER_ADDR_1  
    #define DRIVER_1_LED_TOTAL 18
    #define DRIVER_2_LED_TOTAL 18
    #define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    //#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #define RGB_MATRIX_SPLIT { 18, 18}
//    #define RGB_MATRIX_DEFAULT_HUE 132
  //  #define RGB_MATRIX_DEFAULT_SAT 102

    //#define RGB_MATRIX_SOLID_COLOR,     // Static single hue, no speed support
    #define RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
    #define RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
    #define RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
    #define RGB_MATRIX_BREATHING          // Single hue brightness cycling animation
    #define RGB_MATRIX_BAND_SAT       // Single hue band fading saturation scrolling left to right
    #define RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
    #define RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
    #define RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
    #define RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
    #define RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
    #define RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
    #define RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
    #define RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
    #define RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
    #define RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
    #define RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
    #define RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
    #define RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
    #define RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
    #define RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
    #define RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halfs of keyboard
    #define RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
    #define RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
    #define RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight ammount at the same time, then shifts back
    #define RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight ammount in a wave to the right, then back to the left
    #define RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight ammount and then back down in a wave to the right
    #define RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
    #define RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
    #define RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues

#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
    #define RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
    #define RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
#endif
#if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
    #define RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
    #define RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    #define RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    #define RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
    #define RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
    #define RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
    #define RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
#endif
#endif

#define SPLIT_POINTING_ENABLE 
#define POINTING_DEVICE_COMBINED
#define MOUSE_EXTENDED_REPORT
#define AZOTEQ_IQS5XX_TPS65
#define AZOTEQ_IQS5XX_TAP_ENABLE true
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
#define AZOTEQ_IQS5XX_ZOOM_ENABLE true
#define AZOTEQ_IQS5XX_SWIPE_X_ENABLE true
#define AZOTEQ_IQS5XX_TWO_FINGER_TAP_ENABLE true
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 25
#define AZOTEQ_IQS5XX_SCROLL_ENABLE true
#define AZOTEQ_IQS5XX_ROTATION_270