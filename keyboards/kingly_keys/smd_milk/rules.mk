# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no	# Mouse keys
EXTRAKEY_ENABLE  = no	# Audio control and System control
CONSOLE_ENABLE  = yes	# Console for debug
COMMAND_ENABLE  = yes    # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE  = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork)
BACKLIGHT_ENABLE  = no  # Custom backlighting code is used, so this should not be enabled
AUDIO_ENABLE  = no # This can be enabled if a speaker is connected to the expansion port. Not compatible with RGBLIGHT below
RGBLIGHT_ENABLE  = yes # This can be enabled if a ws2812 strip is connected to the expansion port.
