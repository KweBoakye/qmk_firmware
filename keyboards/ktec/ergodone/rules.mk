# custom matrix setup
CUSTOM_MATRIX = lite

<<<<<<< HEAD
VPATH += drivers/gpio
SRC += mcp23018.c matrix.c
=======
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   comment out to disable the options.
#
CUSTOM_MATRIX           = yes # Custom matrix file for the ErgoDone
UNICODE_ENABLE          = yes # Unicode
BOOTMAGIC_ENABLE        = yes # Enable Bootmagic Lite
MOUSEKEY_ENABLE         = yes # Mouse keys
EXTRAKEY_ENABLE         = yes # Audio control and System control
CONSOLE_ENABLE          = no  # Console for debug
COMMAND_ENABLE          = no  # Commands for debug and configuration
NKRO_ENABLE             = yes # USB Nkey Rollover - not yet supported in LUFA
BACKLIGHT_ENABLE        = no  # Enable keyboard backlight functionality
SWAP_HANDS_ENABLE       = no  # Disable Onehand
RGBLIGHT_ENABLE         = no

# project specific files
>>>>>>> c0de397925 (merge bedore pointerwork)
QUANTUM_LIB_SRC += i2c_master.c
