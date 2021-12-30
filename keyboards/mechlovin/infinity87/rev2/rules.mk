# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD
=======

>>>>>>> c0de397925 (merge bedore pointerwork)

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
CUSTOM_MATRIX = lite

SRC += matrix.c
