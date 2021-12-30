# MCU name
MCU = STM32L422

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD:keyboards/xelus/pachi/rgb/rev1/rules.mk
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea:keyboards/xelus/pachi/rgb/rules.mk
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches

EEPROM_DRIVER = i2c

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom

COMMON_VPATH += $(DRIVER_PATH)/issi
SRC += drivers/led/issi/is31fl3741.c

LTO_ENABLE = yes
OPT = 2
