# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no	# Mouse keys
EXTRAKEY_ENABLE = no	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
<<<<<<< HEAD
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
BACKLIGHT_ENABLE = no  # [Crawlpad] Custom backlighting code is used, so this should not be enabled
AUDIO_ENABLE = no # [Crawlpad] This can be enabled if a speaker is connected to the expansion port. Not compatible with RGBLIGHT below
RGBLIGHT_ENABLE = yes # [Crawlpad] This can be enabled if a ws2812 strip is connected to the expansion port.
ENCODER_ENABLE = yes # [2Key2crawl] Make the knobs turn
