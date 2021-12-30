# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD
=======

# Build Options
#   change yes to no to disable
#
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
BACKLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes                 # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = yes            # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3731
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in
