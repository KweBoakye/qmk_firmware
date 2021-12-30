# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD
# LTO_ENABLE = yes
=======
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
LTO_ENABLE = yes
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
CONSOLE_ENABLE = no  # Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes     # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no


# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
