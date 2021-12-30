# MCU name
MCU = at90usb1286

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = yes # Mouse keys
EXTRAKEY_ENABLE  = yes # Audio control and System control
CONSOLE_ENABLE   = yes # Console for debug
COMMAND_ENABLE   = yes # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE      = no  # USB Nkey Rollover - not yet supported in LUFA
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
UNICODE_ENABLE   = yes # Enable support for arrow keys icon on the second layer.
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes
