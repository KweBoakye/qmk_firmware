# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = yes # Mouse keys
EXTRAKEY_ENABLE  = yes # Audio control and System control
CONSOLE_ENABLE   = yes  # Console for debug
COMMAND_ENABLE   = yes # Commands for debug and configuration
CUSTOM_MATRIX    = yes # Custom matrix file (taken and adapted from the ErgoDox EZ to handle custom number of columns)
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no

# project specific files
SRC = i2c_master.c \
	  matrix.c
