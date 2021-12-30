# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD

# Build Options
#   change yes to no to disable
#
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
BACKLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes                 # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = yes            # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3731
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in
