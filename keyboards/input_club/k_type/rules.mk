# MCU name
MCU = MK20DX256

# Bootloader selection
BOOTLOADER = kiibohd

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
# This board was copied from PJRC_TEENSY_3_1. The only difference should be a
# hack to ensure the watchdog has started before trying to disable it, and an
# override to disable restart of USB driver after returning from suspend.
BOARD = IC_TEENSY_3_1

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/input_club/k_type/rules.mk
=======
<<<<<<< HEAD
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
<<<<<<< HEAD
=======
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/k_type/rules.mk
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# RGB options
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = custom

# Additional files for RGB lighting
SRC += k_type-rgbdriver.c
QUANTUM_LIB_SRC += i2c_master.c is31fl3733-dual.c

LAYOUTS = tkl_ansi

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
