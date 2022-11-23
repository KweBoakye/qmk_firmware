# MCU name
MCU = STM32F072
BOARD = GENERIC_STM32_F072XB

# Bootloader selection
BOOTLOADER = stm32-dfu

# Do not put the microcontroller into power saving mode
# when we get USB suspend event. We want it to keep updating
# backlight effects.
OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

# Build Options
#   change yes to no to disable
#
BACKLIGHT_ENABLE = no              # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/spaceholdings/nebula12/rules.mk
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes                  # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/nebula12/rules.mk
=======
<<<<<<< HEAD
NKRO_ENABLE = yes                  # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
AUDIO_ENABLE = no                  # Audio output
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in
RGBLIGHT_ENABLE = yes              # Underglow RGB
WS2812_DRIVER = spi                # Underglow RGB Driver

CIE1931_CURVE = yes

# project specific files
SRC +=  keyboards/wilba_tech/wt_main.c \
        keyboards/wilba_tech/wt_rgb_backlight.c \
        drivers/led/issi/is31fl3731.c \
        quantum/color.c
QUANTUM_LIB_SRC += i2c_master.c
