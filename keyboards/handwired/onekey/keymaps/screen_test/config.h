#pragma once

// #define LCD_DC_PIN B12
// #define LCD_CS_PIN B13
// #define LCD_RST_PIN B10

/* SPI pins */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP8

/* LCD Configuration */
#define LCD_RST_PIN GP0
#define LCD_DC_PIN GP1
#define LCD_CS_PIN GP4

#ifdef BACKLIGHT_ENABLE
#undef BACKLIGHT_PIN
#define BACKLIGHT_PIN GP5
#define BACKLIGHT_LEVELS 5
#endif
#define LCD_BACKLIGHT_PIN GP5


#define ST7789_135
#define QUANTUM_PAINTER_DEBUG true

#define LCD_DISPLAY_ROTATION QP_ROTATION_90
//#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF