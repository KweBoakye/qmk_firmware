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
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD
<<<<<<< HEAD
NKRO_ENABLE = yes           # Enable N-Key Rollover
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
>>>>>>> c0de397925 (merge bedore pointerwork)
=======
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 4d393d88652f8c755427f162c27746e1a4eb59ea
>>>>>>> 312f511fa7db3bb9b38cbb44cf2c00ad935e3e1c
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
ENCODER_ENABLE = yes        # Enable rotary encoder support
AUDIO_ENABLE = no           # Audio output
KEYBOARD_SHARED_EP = yes    # Free up some extra endpoints - needed if console+mouse+extra

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WS2812_DRIVER = pwm
OPT_DEFS += -DSTM32_DMA_REQUIRED=TRUE

DEFAULT_FOLDER = tkw/grandiceps/rev1
