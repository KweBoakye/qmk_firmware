/* Copyright 2021 KweBoakye
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"
//#include "audio.c"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER KweBoakye
#define PRODUCT      tractyl_frankenform



/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define MATRIX_COL_PINS {A15, B3, B4, A3, A2, A1, C15}
#define MATRIX_ROW_PINS \
    { B12, B13, B14, B15, A8, A10 }

#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define  DIP_SWITCH_MATRIX_GRID { {4,6}, {5,6},{4,0}, {5,0}}


/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

//#define MASTER_RIGHT
#define SPLIT_HAND_PIN C14
#define SPLIT_MAX_CONNECTION_ERRORS 10

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin
#define SELECT_SOFT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
                                   //  0: 460800 baud
                                   //  1: 230400 baud (default)
                                   //  2: 115200 baud
                                   //  3: 57600 baud
                                   //  4: 38400 baud
                                   //  5: 19200 baud
#define SERIAL_USART_DRIVER SD1    // USART driver of TX and RX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 100   // USART driver timeout. default 20
//#undef SOFT_SERIAL_PIN

#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         A7
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         A6
#define SPI_MISO_PAL_MODE                    5

#define I2C_DRIVER        I2CD1
#define I2C1_SCL_PIN      B8
#define I2C1_SCL_PAL_MODE 4
#define  I2C1_SDA_PIN     B9
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
//#define I2C1_OPMODE OPMODE_I2C


#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4

#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    8
#define EXTERNAL_EEPROM_BYTE_COUNT           32000
#define EXTERNAL_EEPROM_PAGE_SIZE            64
//#define EXTERNAL_EEPROM_ADDRESS_SIZE

//#define LED_NUM_LOCK_PIN B0
//#define LED_CAPS_LOCK_PIN B1
//#define LED_SCROLL_LOCK_PIN B2
//#define LED_COMPOSE_PIN B3
//#define LED_KANA_PIN B4

//#define BACKLIGHT_PIN B7
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

//#define OLED_DRIVER = SSD1306
#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_FONT_H "keyboards/handwired/tractyl_frankenform/glcdfont.c"
#define OLED_FONT_END 255


#ifdef JOYSTICK_ENABLE
#define JOYSTICK_AXES_COUNT 2
#define JOYSTICK_BUTTON_COUNT 1
//#define JOYSTICK_AXES_RESOLUTION 10
#endif

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_COUNT 1
#define DRIVER_ADDR_1  0x74
#define DRIVER_1_LED_TOTAL 33
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_1_LED_TOTAL)
#define RGB_MATRIX_SPLIT { DRIVER_1_LED_TOTAL, DRIVER_1_LED_TOTAL }

// RGB Effects
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif


//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
//#define RGB_MATRIX_STARTUP_HUE 0
//#define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
//#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set

//#define RGB_DI_PIN E2
//#ifdef RGB_DI_PIN
//#    define RGBLED_NUM 16
//#    define RGBLIGHT_HUE_STEP 8
//#    define RGBLIGHT_SAT_STEP 8
//#    define RGBLIGHT_VAL_STEP 8
//#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
//#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
//#endif

#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define RATED_VOLTAGE 2
#define V_PEAK 2.8
#define V_RMS 2.0
#define F_LRA 150 /* resonance freq */
#define DRV_GREETING transition_rampup_long_smooth1

#ifdef AUDIO_ENABLE
/* Audio config */
#define AUDIO_PIN       B5
#define AUDIO_PWM_DRIVER   PWMD3
#define AUDIO_PWM_CHANNEL  2
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_STATE_TIMER  GPTD4
#define STARTUP_SONG SONG(STARTUP_SOUND)
#define AUDIO_INIT_DELAY 2000
#endif

/* encoder config */
#define ENCODERS_PAD_A \
    { A13 }
#define ENCODERS_PAD_B \
    { A14 }
#define ENCODER_DEFAULT_POS 0x3

#define ENCODER_RESOLUTION 2


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 45

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

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

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT    0
#define BOOTMAGIC_LITE_COLUMN_RIGHT 6

/* pmw3360 config  */
#define PMW3360_CS_PIN   B0
#define PMW3360_SPI_MODE                     3
#define PMW3360_SPI_DIVISOR                  64
//#define POINTING_DEVICE_INVERT_X_RIGHT
//#define POINTING_DEVICE_ROTATION_90_RIGHT
//#define ROTATIONAL_TRANSFORM_ANGLE  -25
#define PMW3360_LIFTOFF_DISTANCE 0x04


#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_TAPPING_TERM 200
#define CIRQUE_PINNACLE_TOUCH_DEBOUNCE (CIRQUE_PINNACLE_TAPPING_TERM * 8)
#define CIRQUE_PINNACLE_TIMEOUT 200

#define ANALOG_JOYSTICK_X_AXIS_PIN B0
#define ANALOG_JOYSTICK_Y_AXIS_PIN B1
#define ANALOG_JOYSTICK_AXIS_MIN 230
#define ANALOG_JOYSTICK_AXIS_MAX 800
#define ANALOG_JOYSTICK_CLICK_PIN B10
