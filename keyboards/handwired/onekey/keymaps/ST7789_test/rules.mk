QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

BACKLIGHT_ENABLE = yes

BACKLIGHT_DRIVER = pwm

SRC += users/kweboakye/quantumpainter/ST7789/ST7789_logic.c
SRC += users/kweboakye/quantumpainter/graphics/rotating_hand.qgf.c
