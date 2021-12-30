# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = lufa-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
BLUETOOTH_ENABLE = yes      # Enable Bluetooth
<<<<<<< HEAD
BLUETOOTH_DRIVER = BluefruitLE
=======
BLUETOOTH_DRIVER = AdafruitBLE
>>>>>>> c0de397925 (merge bedore pointerwork)
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

LTO_ENABLE = yes
