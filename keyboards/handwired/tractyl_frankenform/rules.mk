# MCU name
MCU = STM32F411

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes          # Audio control and System control
CONSOLE_ENABLE  = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = yes           # Audio output
AUDIO_DRIVER  = pwm_hardware
RGB_MATRIX_ENABLE = no
#RGB_MATRIX_DRIVER = IS31FL3731
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
MIDI_ENABLE = no

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
EEPROM_DRIVER = spi

MOUSE_SHARED_EP = yes
KEYBOARD_SHARED_EP = yes
STENO_ENABLE = no
VIRTSER_ENABLE = no

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
HAPTIC_ENABLE = yes
HAPTIC_DRIVER += DRV2605L
JOYSTICK_ENABLE = no
JOYSTICK_DRIVER = analog
ENCODER_ENABLE = yes


DIP_SWITCH_ENABLE = yes

DEBOUNCE_TYPE = asym_eager_defer_pk

#OPT_DEFS += -DSTM32_I2C -DHAL_USE_I2C=TRUE  -DSTM32_SPI -DHAL_USE_SPI=TRUE -DSTM32_ADC -DHAL_USE_ADC=TRUE #-DPOINTING_DEVICE_DRIVER_cirque_pinnacle_i2c -DPOINTING_DEVICE_DRIVER_pmw3360
SRC += analog.c oled.c drivers/sensors/pmw3360.c drivers/sensors/cirque_pinnacle.c drivers/sensors/cirque_pinnacle_i2c.c  drivers/sensors/analog_joystick.c  # drivers/sensors/pmw3360.c   $(QUANTUM_DIR)/pointing_device_drivers.c $(QUANTUM_DIR)/pointing_device_drivers.c #pointing_logic.c
QUANTUM_LIB_SRC += spi_master.c i2c_master.c #pointing_device_drivers.c
