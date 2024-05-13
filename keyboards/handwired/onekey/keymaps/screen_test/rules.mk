QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
#OPT_DEFS += -DST7789_135
CONSOLE_ENABLE=yes

BACKLIGHT_ENABLE = no

BACKLIGHT_DRIVER = pwm
#QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes



SRC += users/kweboakye/quantumpainter/qp_display.c
SRC += users/kweboakye/quantumpainter/ST7789/ST7789_logic.c
SRC += users/kweboakye/quantumpainter/lvgl/events/custom_events.c
SRC += users/kweboakye/quantumpainter/lvgl/layer_indicators/layer_indicators.c
SRC += users/kweboakye/quantumpainter/lvgl/lvgl_fonts/BalaCynwydNF_14.c
SRC += users/kweboakye/quantumpainter/lvgl/lvgl_fonts/BalaCynwydNF.c
SRC += users/kweboakye/quantumpainter/lvgl/state_indicators/state_indicators.c
SRC += users/kweboakye/quantumpainter/lvgl/styles/styles.c
SRC += users/kweboakye/quantumpainter/lvgl/lvgl_ui.c

SRC += users/kweboakye/quantumpainter/graphics/rotating_hand.qgf.c
SRC += users/kweboakye/quantumpainter/fonts/Microgramma_Normal.qff.c