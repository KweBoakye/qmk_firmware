#pragma once

#include "quantum.h"
#include <qp.h>
#ifdef QUANTUM_PAINTER_ST7789_SPI_ENABLE
#include "ST7789/ST7789_logic.h"
#endif

#ifndef LCD_CS_PIN_RIGHT
    #define LCD_CS_PIN_RIGHT LCD_CS_PIN
#endif
#ifndef LCD_DC_PIN_RIGHT
    #define LCD_DC_PIN_RIGHT LCD_DC_PIN
#endif
#ifndef LCD_RST_PIN_RIGHT
    #define LCD_RST_PIN_RIGHT LCD_RST_PIN
#endif

#ifndef LCD_DISPLAY_ROTATION
    #define LCD_DISPLAY_ROTATION QP_ROTATION_0
#endif

#ifndef LCD_DISPLAY_ROTATION_RIGHT
    #define LCD_DISPLAY_ROTATION_RIGHT LCD_DISPLAY_ROTATION
#endif 

#ifdef QUANTUM_PAINTER_ST7789_SPI_ENABLE
    #define DISPLAY_HEIGHT ST7789_height
#endif

// typedef union {
//     uint32_t raw;
//     struct {
//         int layer;

//     };
// } display_state_t    

//static extern painter_device_t display;

void keyboard_post_init_kb_display(void);

void suspend_power_down_user_display(void);

void suspend_wakeup_init_user_display(void);

void housekeeping_task_display(void);

painter_device_t init_display(void);
