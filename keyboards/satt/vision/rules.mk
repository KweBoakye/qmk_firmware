# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes           # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
NKRO_ENABLE = yes           # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
