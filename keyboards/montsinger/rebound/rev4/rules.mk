# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

<<<<<<< HEAD
# Build Options
#   change yes to no to disable
#
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes

LAYOUTS = ortho_4x12
LAYOUTS_HAS_RGB = no

# Disable unsupported hardware
RGBLIGHT_SUPPORTED = yes
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
