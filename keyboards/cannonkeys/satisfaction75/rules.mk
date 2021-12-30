# MCU name
MCU = STM32F072
BOARD = GENERIC_STM32_F072XB

# Bootloader selection
BOOTLOADER = stm32-dfu

# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -v FFFF -p FFFF

SRC += led.c \
      satisfaction_encoder.c \
      satisfaction_oled.c

<<<<<<< HEAD
=======
# Build Options
#   change yes to no to disable
#
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes	    # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
ENCODER_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
#BACKLIGHT_ENABLE = yes

DEFAULT_FOLDER = cannonkeys/satisfaction75/rev1

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
