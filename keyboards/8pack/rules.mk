# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no  # Mouse keys
EXTRAKEY_ENABLE  = no  # Audio control and System control
CONSOLE_ENABLE   = yes # Console for debug
COMMAND_ENABLE   = yes # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
NKRO_ENABLE      = no  # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = yes # Enable keyboard backlight functionality
AUDIO_ENABLE     = no
RGBLIGHT_ENABLE  = yes
OLED_ENABLE = no

DEFAULT_FOLDER = 8pack/rev12
