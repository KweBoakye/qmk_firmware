# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes  # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
CONSOLE_ENABLE = yes   # Console for debug
COMMAND_ENABLE = yes   # Commands for debug and configuration
CUSTOM_MATRIX = yes    # Custom matrix file for the HHKB
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# NKRO_ENABLE = yes       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
# NKRO_ENABLE = yes       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
# BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality

# HHKB_RN42_ENABLE = yes  # Enable support for hasu's BT alt controller -- code borrowed from tmk source tree.

# Either uncomment the HHKB_RN42_ENABLE line above, or run make enabling the
# feature. Be sure to clean any existing build before trying to enable rn42
# support. For example:
#
# make hhkb-keymap-clean
# make hhkb-keymap-dfu HHKB_RN42_ENABLE=yes

# project specific files
SRC = matrix.c

# debug-on: EXTRAFLAGS += -DDEBUG -DDEBUG_ACTION
# debug-on: all

# debug-off: EXTRAFLAGS += -DNO_DEBUG -DNO_PRINT
# debug-off: OPT_DEFS := $(filter-out -DCONSOLE_ENABLE,$(OPT_DEFS))
# debug-off: all
