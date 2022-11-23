# MCU name
MCU = atmega32a

# Bootloader selection
BOOTLOADER = bootloadhid

<<<<<<< HEAD
<<<<<<< HEAD
=======
# build options
=======
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
# Build Options
#   change yes to no to disable
#
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
WS2812_DRIVER = i2c         # This driver powers the RGB Lighting and RGB Matrix features
LTO_ENABLE = yes            # Enable link time optimization
=======
# build options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no    # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = no     # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
NKRO_ENABLE = no        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes   # Enable keyboard underlight functionality
WS2812_DRIVER = i2c     # This driver powers the RGB Lighting and RGB Matrix features
LTO_ENABLE = yes        # Enable link time optimization
>>>>>>> c0de397925 (merge bedore pointerwork)

LAYOUTS = ortho_5x12
