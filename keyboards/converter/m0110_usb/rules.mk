# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no   # Mouse keys
CONSOLE_ENABLE   = yes  # Console for debug
COMMAND_ENABLE   = no   # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
NKRO_ENABLE      = no   # USB Nkey Rollover - not yet supported in LUFA
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
NKRO_ENABLE      = no   # USB Nkey Rollover - not yet supported in LUFA
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

SRC = matrix.c m0110.c
