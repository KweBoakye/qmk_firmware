# MCU name
MCU = STM32F411

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no          # Audio control and System control
CONSOLE_ENABLE  = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = yes           # Audio output
AUDIO_DRIVER  = pwm_hardware
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = IS31FL3731
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
MIDI_ENABLE = no

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
EEPROM_DRIVER = spi
SRC += oled.c analog.c #cirque_tm040040.c
QUANTUM_LIB_SRC += spi_master.c #i2c_master.c i2c2_master.c

MOUSE_SHARED_EP = no
KEYBOARD_SHARED_EP = no
STENO_ENABLE = no
VIRTSER_ENABLE = no

POINTING_DEVICE_ENABLE = no
HAPTIC_ENABLE += DRV2605L
JOYSTICK_ENABLE = no
JOYSTICK_DRIVER = analog
