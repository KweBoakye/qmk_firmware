#include "quantum.h"
#include "../qp_display.h"
#include <qp.h>
#include "ST7789_logic.h"
#include "quantum/color.h"


painter_device_t create_display_left(void){
    return  qp_st7789_make_spi_device(ST7789_width, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 3);      // Create the display 
}

painter_device_t create_display_right(void){
    #if defined(SPLIT_KEYBOARD)
    return qp_st7789_make_spi_device(ST7789_width, 240, LCD_CS_PIN_RIGHT, LCD_DC_PIN_RIGHT, LCD_RST_PIN_RIGHT, 4, 3);      // Create the  display
    #else
    return create_display_left();
    #endif 
}

// painter_rotation_t display_rotation_left(void){
//     return LCD_DISPLAY_ROTATION;
// }

// painter_rotation_t display_rotation_right(void){
//     #if defined(SPLIT_KEYBOARD)
//     return LCD_DISPLAY_ROTATION_RIGHT;
//     #else
//     return display_rotation_left();
//     #endif
// }


painter_device_t init_display(void) {
     painter_device_t temp_display;
    //temp_display = qp_st7789_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 3); 
    if(is_keyboard_left()){
        temp_display = create_display_left();
    } else {
        temp_display = create_display_right();
    }
    qp_init(temp_display,LCD_DISPLAY_ROTATION);
 #ifdef ST7789_135 
    qp_set_viewport_offsets(temp_display, 40, 52);
#endif
// if(is_keyboard_left()){
// qp_init(display, display_rotation_left());   // Initialise the display
// } else {
//     qp_init(display, display_rotation_right());
// }
    
     //qp_rect(display, 0, 0, 239, 239, HSV_BLACK, true);
   //  qp_rect(temp_display, 0, 0, 239, 239, HSV_RED, true);
      //qp_rect(display, 40, 53, (239 + 40), (239 + 53), HSV_RED, true);
    return temp_display;
}



