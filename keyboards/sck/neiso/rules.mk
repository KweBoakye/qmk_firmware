# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
