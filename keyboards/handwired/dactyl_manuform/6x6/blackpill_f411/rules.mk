# Copyright 2021 Bartosz Nowak (@dumam)
# SPDX-License-Identifier: GPL-2.0-or-later

# MCU name
MCU = STM32F411
BOARD = BLACKPILL_STM32_F411

# Bootloader selection
BOOTLOADER = stm32-dfu
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD:keyboards/handwired/dactyl_manuform/6x6/blackpill_f411/rules.mk
NKRO_ENABLE = no            # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork):keyboards/hecomi/rules.mk
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output


# Build Options
#   change yes to no to disable
#
SPLIT_KEYBOARD = yes
# split settings
# https://beta.docs.qmk.fm/developing-qmk/c-development/hardware_drivers/serial_driver
SERIAL_DRIVER = usart
