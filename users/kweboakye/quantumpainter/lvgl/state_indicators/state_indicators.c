#include "state_indicators.h"
#include "../layer_indicators/layer_indicators.h"
#include "../styles/styles.h"
#include "../lvgl_fonts/fonts.h"
#include "../../qp_display.h"
#include "../events/custom_events.h"
#include <stdio.h>
#include <inttypes.h>
#include "caps_word.h"
#include "../../../keyrecords/casemodes.h"

char ctrl_string[5] = "CTRL";
char shift_string[5] = "SHFT";
char alt_string[4] = "ALT";
char gui_string[4] = "GUI";
char caps_string[5] = "CAPS";
char caps_word_string[3] = "CW"; 
char snake_case_string[6] = "SNKCS";
char camel_case_string[6] = "CMLCS";
char kebab_case_string[6] = "KBBCS";
char screaming_snake_case_string[5] = "SSCS";


lv_obj_t * ctrl_indicator;
lv_obj_t * shift_indicator;
lv_obj_t * alt_indicator;
lv_obj_t * gui_indicator;
lv_obj_t * caps_indicator;
lv_obj_t * caps_word_indicator;
lv_obj_t * snake_case_indicator;
lv_obj_t * camel_case_indicator;
lv_obj_t * kebab_case_indicator;
lv_obj_t * screaming_snake_case_indicator;
lv_obj_t * num_lock_indicator;
lv_obj_t * scroll_lock_indicator;
lv_obj_t * haptic_indicator;
lv_obj_t * audio_indicator;




void set_indicator_state(lv_obj_t * indicator, lv_state_t state){
   //uprintf("state is %" PRIu16 "\n" ,state);
  switch (state)
  {
  case LV_STATE_DEFAULT:
  
  lv_obj_clear_state(indicator ,LV_STATE_CHECKED);
  lv_obj_clear_state(indicator ,LV_STATE_PRESSED);
  
  case LV_STATE_PRESSED:
  lv_obj_clear_state(indicator ,LV_STATE_CHECKED);
  lv_obj_clear_state(indicator ,LV_STATE_DEFAULT);
  

  case LV_STATE_CHECKED:
  lv_obj_clear_state(indicator ,LV_STATE_DEFAULT);
  lv_obj_clear_state(indicator ,LV_STATE_PRESSED);

  }
  lv_obj_add_state(indicator, state);
}
//const uint16_t offset = 4;
 const lv_point_t top_left = {8, 5};
const lv_point_t top_right = {44 , 5};
const lv_point_t bottom_right = {40, 20};
const lv_point_t bottom_left = {4, 20};
const lv_point_t line_points[5] = { top_left, top_right, bottom_right ,bottom_left , top_left };
lv_obj_t * parrallelogram_indicator(lv_obj_t * parent, char text[]){
    
  
  /*Create style*/
    // static lv_style_t style_line;
    // lv_style_init(&style_line);
    // lv_style_set_line_width(&style_line,4);
    // lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    // lv_style_set_line_rounded(&style_line, true);
    

    /*Create a line and apply the new style*/
    //lv_obj_t * line1;
    //line1 = lv_line_create(lv_scr_act());
    //lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    //lv_obj_add_style(line1, &style_line, 0);
   //lv_obj_center(line1);
   
 //   lv_obj_clear_flag(line1, LV_OBJ_FLAG_SCROLLABLE);
  

     
 lv_obj_t *canvas = lv_canvas_create(parent);
  static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(indicator_widget_width, 24)];
  lv_canvas_set_buffer(canvas, cbuf_tmp, indicator_widget_width, 24, LV_IMG_CF_TRUE_COLOR_ALPHA);
  lv_canvas_fill_bg(canvas, lv_palette_darken(LV_PALETTE_GREY, 1), LV_OPA_0);
  lv_obj_set_style_bg_opa(canvas,LV_OPA_0,0);
  lv_obj_t * label;
  label = lv_label_create(canvas);
 lv_draw_line_dsc_t line_dsc;
 lv_draw_line_dsc_init(&line_dsc);
 set_main_draw_line_style(&line_dsc);
  lv_canvas_draw_line(canvas, line_points, 5, &line_dsc);
  lv_label_set_text(label, text);
  lv_obj_center(label);
  lv_obj_add_flag(canvas, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_add_style(canvas, (lv_style_t *) &indicator_box_default_style, LV_STATE_DEFAULT);
  lv_obj_add_style(canvas, (lv_style_t *) &indicator_box_checked_style, LV_STATE_CHECKED);
    return canvas;
}

// static void set_indicator_state_cb(lv_event_t * event){
//   uint32_t* event_code_pointer = (uint32_t* ) lv_event_get_code(event);
//   uint32_t event_code = *event_code_pointer;
//   //lv_obj_t * indicator = (lv_obj_t *) lv_event_get_current_target(event);
//   lv_state_t * state_pointer = (lv_state_t *) lv_event_get_param(event);
//   lv_state_t  state = *state_pointer;
//   uprintf("state is %" PRIu16 "\n" ,state);
//   uprintf("event is %" PRIu32 "\n" ,event_code);
//   //set_indicator_state(indicator, state, event_code);
// }

lv_state_t mod_state_to_lv_state(mod_state_t mod_state){
  switch (mod_state)
  {
  case INACTIVE:
    return LV_STATE_DEFAULT;
  case ONESHOT:
    return LV_STATE_PRESSED;
  case ACTIVE:
    return LV_STATE_CHECKED;  
  }
  return INACTIVE;
}



void set_lv_state_from_mod_state(lv_obj_t * indicator,uint32_t event_code, mod_state_t mod_state){
  // lv_event_send(indicator, event_code, &mod_state);
set_indicator_state(indicator, mod_state_to_lv_state(mod_state));
}

void set_ctrl_indicator_state(mod_state_t mod_state){
  set_lv_state_from_mod_state(ctrl_indicator, CUSTOM_EVENT_MOD_STATE_CHANGE_CTRL, mod_state);
}
void set_shift_indicator_state(mod_state_t mod_state){
  set_lv_state_from_mod_state(shift_indicator, CUSTOM_EVENT_MOD_STATE_CHANGE_SHIFT, mod_state);
}
void set_alt_indicator_state(mod_state_t mod_state){
  set_lv_state_from_mod_state(alt_indicator, CUSTOM_EVENT_MOD_STATE_CHANGE_ALT, mod_state);
}
void set_gui_indicator_state(mod_state_t mod_state){
  set_lv_state_from_mod_state(gui_indicator, CUSTOM_EVENT_MOD_STATE_CHANGE_GUI, mod_state);
}
// void set_caps_indicator_state(mod_state_t mod_state){
//   set_lv_state_from_mod_state(caps_indicator,mod_state);
// }
// void set_caps_word_indicator_state(mod_state_t mod_state){
//   set_lv_state_from_mod_state(caps_word_indicator,mod_state);
// }

void process_state_indicators(uint8_t mods){

  if(mods & MOD_MASK_CTRL){
    set_ctrl_indicator_state(ACTIVE);
  } else {
    set_ctrl_indicator_state(INACTIVE);
  }

  if(mods & MOD_MASK_SHIFT){
    set_shift_indicator_state(ACTIVE);
  } else {
    set_shift_indicator_state(INACTIVE);
  }

  if(mods & MOD_MASK_ALT){
    set_alt_indicator_state(ACTIVE);
  } else {
    set_alt_indicator_state(INACTIVE);
  }

  if(mods & MOD_MASK_GUI){
    set_gui_indicator_state(ACTIVE);
  } else {
    set_gui_indicator_state(INACTIVE);
  }
}
void set_case_indicator_state(lv_obj_t * case_indicator,bool set_active){
  if(set_active){
    set_indicator_state(case_indicator, LV_STATE_CHECKED);
  } else {
    set_indicator_state(case_indicator, LV_STATE_DEFAULT);
  }
}
void process_case_indicators(void){
  set_case_indicator_state(caps_word_indicator, is_caps_word_on());
  set_case_indicator_state(snake_case_indicator, is_snake_case_active());
  set_case_indicator_state(kebab_case_indicator, is_kebab_case_active());
  set_case_indicator_state(camel_case_indicator, is_camel_case_active());
  set_case_indicator_state(screaming_snake_case_indicator, is_screaming_snake_case_active());
}

lv_obj_t *indicator_box(lv_obj_t *parent, char text[])
{
    uint16_t offset = 4;
lv_obj_t *  indicator_button;

  indicator_button = lv_obj_create(parent);
  lv_obj_set_size(indicator_button, indicator_widget_width - (2 * offset), indicator_widget_height - (2 * offset));

  lv_obj_clear_flag(indicator_button, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_add_flag(indicator_button, LV_OBJ_FLAG_CHECKABLE);

  
  
  
  lv_obj_t * label;
  label = lv_label_create(indicator_button);
 
  lv_label_set_text(label, text);
  lv_obj_center(label);

 lv_obj_add_style(indicator_button, (lv_style_t *) &indicator_box_default_style, LV_STATE_DEFAULT);
lv_obj_add_style(indicator_button, (lv_style_t *) &indicator_box_checked_style, LV_STATE_CHECKED);
//lv_obj_add_event_cb(indicator_button , set_indicator_state_cb, LV_EVENT_ALL, NULL);
  return indicator_button;
}

void flex_indicator_container(lv_obj_t *parent){
  int temp_height = (indicator_container_row_height * row_count) + vertical_distance_between_indicator_widgets;
  int indicator_container_height;
  if(temp_height >= DISPLAY_HEIGHT){
    indicator_container_height = DISPLAY_HEIGHT - 4;
  } else {
    indicator_container_height = temp_height;

  }
  lv_obj_t *indicator_container = lv_obj_create(parent);
  lv_obj_set_style_bg_color(indicator_container, lv_color_black(), 0);
  lv_obj_set_layout(indicator_container, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(indicator_container, LV_FLEX_FLOW_COLUMN_WRAP);
  lv_obj_set_flex_align(indicator_container, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_obj_set_size(indicator_container, (indicator_container_column_width * col_count) + horizontal_distance_between_indicator_widgets,indicator_container_height); 
  lv_obj_clear_flag(indicator_container, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_set_style_border_width(indicator_container, 1, 0);
  lv_obj_set_style_pad_hor(indicator_container, horizontal_distance_between_indicator_widgets / 4, 0);
  lv_obj_set_style_pad_ver(indicator_container, vertical_distance_between_indicator_widgets / 4, 0);
  lv_obj_set_style_pad_row(indicator_container, vertical_distance_between_indicator_widgets / 4, 0);

//ctrl_indicator = indicator_box(indicator_container, ctrl_string);
//shift_indicator = indicator_box(indicator_container, shift_string);
//alt_indicator = indicator_box(indicator_container, alt_string);
//gui_indicator = indicator_box(indicator_container, gui_string);
//parrallelogram_indicator(indicator_container);
//caps_indicator = indicator_box(indicator_container, caps_string);
caps_word_indicator = indicator_box(indicator_container, caps_word_string);
//snake_case_indicator = indicator_box(indicator_container, snake_case_string);
//camel_case_indicator = indicator_box(indicator_container, camel_case_string);
//kebab_case_indicator = indicator_box(indicator_container, kebab_case_string);
//screaming_snake_case_indicator = indicator_box(indicator_container, screaming_snake_case_string);
//lv_obj_add_event_cb(ctrl_indicator , set_indicator_state_cb, CUSTOM_EVENT_MOD_STATE_CHANGE_CTRL, NULL);
// lv_obj_add_event_cb(ctrl_indicator , set_indicator_state_cb, LV_EVENT_ALL, NULL);
// lv_obj_add_event_cb(shift_indicator , set_indicator_state_cb, LV_EVENT_ALL, NULL);
// lv_obj_add_event_cb(alt_indicator , set_indicator_state_cb, LV_EVENT_ALL, NULL);
// lv_obj_add_event_cb( gui_indicator, set_indicator_state_cb, LV_EVENT_ALL, NULL);
lv_obj_align_to(indicator_container, layer_indicators, LV_ALIGN_OUT_RIGHT_MID, 4, 24);

}