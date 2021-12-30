# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
<<<<<<< HEAD
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
USB_HID_ENABLE = yes
CUSTOM_MATRIX = yes
=======
#MOUSEKEY_ENABLE  = yes  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
#CONSOLE_ENABLE   = yes  # Console for debug
#COMMAND_ENABLE   = yes  # Commands for debug and configuration
#NKRO_ENABLE      = yes  # USB Nkey Rollover - not yet supported in LUFA
#BACKLIGHT_ENABLE = yes
USB_HID_ENABLE   = yes
CUSTOM_MATRIX    = yes
>>>>>>> c0de397925 (merge bedore pointerwork)

SRC += custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu

LAYOUTS = fullsize_ansi fullsize_iso
