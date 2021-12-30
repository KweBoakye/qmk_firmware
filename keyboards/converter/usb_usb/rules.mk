# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE  = yes  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
#CONSOLE_ENABLE   = yes  # Console for debug
#COMMAND_ENABLE   = yes  # Commands for debug and configuration
<<<<<<< HEAD
#NKRO_ENABLE      = yes  # USB Nkey Rollover - not yet supported in LUFA
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
#BACKLIGHT_ENABLE = yes
USB_HID_ENABLE   = yes
CUSTOM_MATRIX    = yes

SRC = custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu
