# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = no	    # Console for debug
COMMAND_ENABLE = no      # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD:keyboards/rainkeebs/rainkeeb/rules.mk
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/rainkeeb/rules.mk
=======
<<<<<<< HEAD
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no

# OLED enable
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Encoder enable
ENCODER_ENABLE = yes

# WPM counter enable
WPM_ENABLE = yes
