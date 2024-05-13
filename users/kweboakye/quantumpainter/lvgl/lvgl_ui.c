#include "lvgl_ui.h"
#include "lvgl.h"

#include "layer_indicators/layer_indicators.h"
#include "state_indicators/state_indicators.h"
#include "events/custom_events.h"

static lv_obj_t *main_screen;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Image1;

void init_main_screen(void){
   
   main_screen = lv_scr_act();
   lv_obj_set_style_bg_color(main_screen, lv_color_black(), LV_PART_MAIN);
  lv_obj_clear_flag(main_screen, LV_OBJ_FLAG_SCROLLABLE);
     init_layer_indicators(main_screen);
   init_layers();   
  draw_layer_indicators(0);
  init_layer_name(main_screen);

  
  
  
   flex_indicator_container(main_screen);
}
void init_secondary_screen(void){
    ui_Screen2 = lv_obj_create(NULL);
    ui_Image1 = lv_img_create(ui_Screen2);
    lv_img_set_src(ui_Image1, &cowboy_bebop); // set image on startup
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 81
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 55
    lv_obj_set_x(ui_Image1, 25);
    lv_obj_set_align(ui_Image1, LV_ALIGN_LEFT_MID);
}

void init_lvgl_ui(painter_device_t display){
     if (qp_lvgl_attach(display)) {   
      printf("lvgl attatched");
 lv_disp_t * lvgl_display = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(lvgl_display, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    lv_disp_set_theme(lvgl_display, theme);
register_event_ids();
      

  init_main_screen();
  init_secondary_screen();
  if(is_keyboard_left()){
   lv_disp_load_scr(main_screen);
  } else {
   lv_disp_load_scr(ui_Screen2);
  }
     } else{
      printf("lvgl attach failed");
     }
}



