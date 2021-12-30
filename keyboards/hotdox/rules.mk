# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX           = yes # Custom matrix file for the ErgoDone
UNICODE_ENABLE          = yes # Unicode
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE         = yes  # Mouse keys
EXTRAKEY_ENABLE         = yes # Audio control and System control
CONSOLE_ENABLE          = yes # Console for debug
COMMAND_ENABLE          = no  # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE             = yes # USB Nkey Rollover - not yet supported in LUFA
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE        = yes # Enable keyboard backlight functionality
SWAP_HANDS_ENABLE       = no  # Disable Onehand
RGBLIGHT_ENABLE         = no

# project specific files
SRC =  matrix.c     \
	   i2c_master.c \
       left.c

LAYOUTS = ergodox
