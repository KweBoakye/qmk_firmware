# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
<<<<<<< HEAD:keyboards/novelkeys/novelpad/rules.mk
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
NKRO_ENABLE = no		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/novelpad/rules.mk
BACKLIGHT_ENABLE = yes  # In-switch LEDs
AUDIO_ENABLE = no      # There is no available timer or pin for audio on the NovelPad
RGBLIGHT_ENABLE = yes  # RGB LEDs for underglow, installed and enabled by default for the NovelPad

LAYOUTS = ortho_5x4
