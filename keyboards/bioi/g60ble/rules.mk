# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = qmk-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = yes       # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes          # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BACKLIGHT_ENABLE = yes     # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes
LTO_ENABLE = yes

LAYOUTS = 60_ansi 60_iso 60_hhkb 60_ansi_split_bs_rshift 60_tsangan_hhkb
