# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE = yes	# Mouse keys
POINTING_DEVICE_ENABLE = yes # Generic Pointer, not as big as mouse keys hopefully.
POINTING_DEVICE_DRIVER = custom
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes   # Commands for debug and configuration
CUSTOM_MATRIX = yes    # Remote matrix from the wireless bridge
<<<<<<< HEAD:keyboards/keyhive/honeycomb/rules.mk
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes		# USB Nkey Rollover - not yet supported in LUFA
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/honeycomb/rules.mk
# BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality

# # project specific files
SRC += matrix.c
QUANTUM_LIB_SRC += uart.c
