# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no   # Mouse keys
CONSOLE_ENABLE   = no   # Console for debug
COMMAND_ENABLE   = no   # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE      = no   # USB Nkey Rollover - not yet supported in LUFA
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

SRC = matrix.c adb.c led.c

# ADB_MOUSE_ENABLE
# OPT_DEFS += -DADB_MOUSE_ENABLE -DMOUSE_ENABLE
