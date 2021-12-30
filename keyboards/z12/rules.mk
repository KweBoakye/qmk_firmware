# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
<<<<<<< HEAD
#   change yes to no to disable
#
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
ENCODER_ENABLE = yes       # Enables the use of encoders
<<<<<<< HEAD
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no           # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no          # Audio output
LTO_ENABLE = yes           # Enables Link Time Optimization (LTO) which reduces the compiled size
OLED_ENABLE = yes          # Enables the use of OLED displays
OLED_DRIVER = SSD1306      # Enables the use of OLED displays

