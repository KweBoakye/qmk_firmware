# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
ENCODER_ENABLE = yes
MOUSEKEY_ENABLE  = no       # Mouse keys
EXTRAKEY_ENABLE  = no       # Audio control and System control
CONSOLE_ENABLE  = yes       # Console for debug
COMMAND_ENABLE  = yes       # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE  = yes          # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
NKRO_ENABLE  = yes          # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE  = no
AUDIO_ENABLE  = no          # This can be enabled if a speaker is connected to the expansion port. Not compatible with RGBLIGHT below
RGBLIGHT_ENABLE  = no       # This can be enabled if a ws2812 strip is connected to the expansion port.

BLUETOOTH_ENABLE = yes
<<<<<<< HEAD
BLUETOOTH_DRIVER = BluefruitLE
=======
BLUETOOTH_DRIVER = AdafruitBLE
>>>>>>> c0de397925 (merge bedore pointerwork)
