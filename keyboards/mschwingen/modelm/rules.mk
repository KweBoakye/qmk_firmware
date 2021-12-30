# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = lufa-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

CUSTOM_MATRIX = lite
KEY_LOCK_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes

UART_DEBUG = no

SRC += matrix.c
QUANTUM_LIB_SRC += uart.c \
                   spi_master.c

OPT_DEFS += -DSLEEP_LED_ENABLE # we need our own sleep callbacks to turn of WS2812 LEDs

LTO_ENABLE = yes

DEFAULT_FOLDER = mschwingen/modelm/led_wired
