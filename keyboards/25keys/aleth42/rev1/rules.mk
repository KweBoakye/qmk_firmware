# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/25keys/aleth42/rev1/rules.mk
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/aleth42/rev1/rules.mk
=======
<<<<<<< HEAD
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
ENCODER_ENABLE = yes
