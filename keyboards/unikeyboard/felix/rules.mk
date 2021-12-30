# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD:keyboards/unikeyboard/felix/rules.mk
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes           # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/felix/rules.mk
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

LAYOUTS = ortho_5x4
