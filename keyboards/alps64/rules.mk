# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
NKRO_ENABLE = no	# USB Nkey Rollover - not yet supported in LUFA
>>>>>>> c0de397925 (merge bedore pointerwork)

LAYOUTS = 60_ansi
