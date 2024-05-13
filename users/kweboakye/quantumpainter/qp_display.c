#include "qp_display.h"
#include "print.h"
#include "color.h"



#ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE
#include "lvgl/lvgl_ui.h"
#include "lvgl.h"
#include "lvgl/state_indicators/state_indicators.h"
#include "lvgl/layer_indicators/layer_indicators.h"
#endif

static painter_device_t display;
__attribute__((weak)) painter_device_t init_display(void){
    return display;
}

void keyboard_post_init_kb_display(void) {
 #ifdef LCD_BACKLIGHT_PIN
 setPinOutput(LCD_BACKLIGHT_PIN);
 writePinHigh(LCD_BACKLIGHT_PIN);
 #elif BACKLIGHT_ENABLE
backlight_enable();
backlight_level(BACKLIGHT_LEVELS);
 #endif
//#endif    

   display = init_display();
qp_power(display, true);   
qp_rect(display, 0, 0, 239, 239, HSV_BLACK, true);
//qp_rect(display, 0, 0, 239, 239, HSV_RED, true);
   #ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE 
   init_lvgl_ui(display);
   #endif
    

}

// #if defined BACKLIGHT_ENABLE
//     static uint8_t last_backlight = 255;
// #endif
void suspend_power_down_user_display(void) {
   
    
    #ifdef LCD_BACKLIGHT_PIN 
    writePinLow(LCD_BACKLIGHT_PIN);
#elif defined(BACKLIGHT_ENABLE) 
  
    // if (last_backlight == 255) {
    //     last_backlight = get_backlight_level();
    // }
    backlight_level(0);
#endif    
qp_power(display, false);
}

void suspend_wakeup_init_user_display(void) {
    
#ifdef LCD_BACKLIGHT_PIN 
    writePinHigh(LCD_BACKLIGHT_PIN);
#elif defined(BACKLIGHT_ENABLE) 
//   if (last_backlight != 255) {
//     backlight_level(last_backlight);
//     }
//     last_backlight = 255;
  backlight_level(BACKLIGHT_LEVELS);
#endif
qp_power(display, true);
}

 layer_state_t last_layer_state;
void housekeeping_task_display(void) {
    #ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE
  // process_state_indicators(get_mods());
  // process_case_indicators();
  // #ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE
    
    
    if(layer_state != last_layer_state){
    uprintf("before set_screen_layer \n");
        set_screen_layer(get_highest_layer(layer_state));
        set_screen_layer_name(layer_state);
        last_layer_state = layer_state;
    }
    

//#endif
#endif
 /*    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw a 240px high vertical rainbow line on X=0:
        for (int i = 0; i < 239; ++i) {
            qp_setpixel(display, 0, i, i, 255, 255);
        }
        qp_flush(display);
    } */
    
 
}