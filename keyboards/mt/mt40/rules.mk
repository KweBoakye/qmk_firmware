# MCU name
MCU = atmega32a

# Bootloader selection
BOOTLOADER = bootloadhid

<<<<<<< HEAD
<<<<<<< HEAD:keyboards/mt/mt40/rules.mk
# Build Options
#   change yes to no to disable
#
=======
# build options
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/mt40/rules.mk
=======
<<<<<<< HEAD
# build options
=======
# Build Options
#   change yes to no to disable
#
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no   # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
CONSOLE_ENABLE = no    # Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes # Enable keyboard backlight functionality
AUDIO_ENABLE = no      # Audio output
RGBLIGHT_ENABLE = yes  # Enable WS2812 RGB underlight. 
WS2812_DRIVER = i2c

LAYOUTS = planck_mit
LAYOUTS_HAS_RGB = no
