# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD

=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
<<<<<<< HEAD
NKRO_ENABLE = yes
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
CUSTOM_MATRIX = lite

SRC += matrix.c
