# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

<<<<<<< HEAD
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
CUSTOM_MATRIX = yes
=======
CUSTOM_MATRIX    = yes
MOUSEKEY_ENABLE  = yes  # Mouse keys
COMBO_ENABLE     = yes
EXTRAKEY_ENABLE  = yes
CONSOLE_ENABLE   = no
NKRO_ENABLE      = yes  # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
COMMAND_ENABLE   = yes
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
>>>>>>> c0de397925 (merge bedore pointerwork)

LAYOUTS = split_3x5_3

DEBOUNCE_TYPE = sym_eager_pr
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
