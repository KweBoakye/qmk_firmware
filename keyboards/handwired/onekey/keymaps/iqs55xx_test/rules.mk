# MCU name
MCU = STM32F411

# Bootloader selection
BOOTLOADER = stm32-dfu
BOARD = BLACKPILL_STM32_F411

CONSOLE_ENABLE = yes

QUANTUM_LIB_SRC += i2c_master.c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
SRC += users/kweboakye/pointing/tps65/IQS5xx.c
DEFERRED_EXEC_ENABLE = yes
