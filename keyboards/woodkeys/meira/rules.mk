# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality, also set ISSI_ENABLE below for Meira
BACKLIGHT_DRIVER = custom
ISSI_ENABLE = yes           # If the I2C pullup resistors aren't install this must be disabled
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

CUSTOM_MATRIX = yes

#ifeq ($(strip $(ISSI_ENABLE)), yes)
#    TMK_COMMON_DEFS += -DISSI_ENABLE
#endif

#ifeq ($(strip $(WATCHDOG_ENABLE)), yes)
#    TMK_COMMON_DEFS += -DWATCHDOG_ENABLE
#endif
SRC += matrix.c TWIlib.c issi.c lighting.c

DEFAULT_FOLDER = woodkeys/meira/promicro
LAYOUTS = ortho_4x12
