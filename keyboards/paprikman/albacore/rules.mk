# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
<<<<<<< HEAD:keyboards/kprepublic/bm60hsrgb_iso/rev1/rules.mk
MOUSEKEY_ENABLE = yes       # Mouse keys
=======
MOUSEKEY_ENABLE = no        # Mouse keys
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/paprikman/albacore/rules.mk
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

LTO_ENABLE = yes
