# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> c0de397925 (merge bedore pointerwork)
=======

=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
NKRO_ENABLE = yes
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
CUSTOM_MATRIX = lite

SRC += matrix.c
