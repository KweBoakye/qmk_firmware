#pragma once
#include "quantum.h"
#include "qp.h"

//#ifdef ST7789_240 

#ifdef ST7789_135
    #define ST7789_height 135
    #define ST7789_NO_AUTOMATIC_OFFSETS
    #define X_VIEWPORT_OFFSET 40
    #define y_VIEWPORT_OFFSET 53
#else 
    #define ST7789_height 240 
#endif

#define ST7789_width 240


painter_device_t init_display(void);