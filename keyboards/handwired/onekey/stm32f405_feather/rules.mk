<<<<<<< HEAD
=======
# MCU name
MCU = STM32F405

# Bootloader selection
BOOTLOADER = stm32-dfu

>>>>>>> c0de397925 (merge bedore pointerwork)
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
