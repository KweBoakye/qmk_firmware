# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
MOUSEKEY_ENABLE 	= yes		# Mouse keys
EXTRAKEY_ENABLE 	= yes       # Audio control and System control
CONSOLE_ENABLE 		= yes       # Console for debug
COMMAND_ENABLE 		= no		# Commands for debug and configuration
<<<<<<< HEAD:keyboards/gboards/butterstick/rules.mk
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
NKRO_ENABLE 		= yes       # USB Nkey Rollover
STENO_ENABLE		= yes 		# Needed for chording

OPT_DEFS += -DONLYQWERTY -DDEBUG_MATRIX
SRC += sten.c
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/butterstick/rules.mk
LTO_ENABLE = yes
