# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
<<<<<<< HEAD
#   change yes to no to disable
#
=======
#   comment out to disable the options.
>>>>>>> c0de397925 (merge bedore pointerwork)
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes           # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = spi
