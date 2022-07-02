CONSOLE_ENABLE = yes

QUANTUM_LIB_SRC += i2c_master.c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
SRC += users/kweboakye/pointing/tps65/IQS55xx.c
DEFERRED_EXEC_ENABLE = yes
