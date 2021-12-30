# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD:keyboards/keyprez/unicorn/rules.mk
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
=======
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/ajisai74/rules.mk
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD:keyboards/keyprez/unicorn/rules.mk
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/ajisai74/rules.mk
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = yes
