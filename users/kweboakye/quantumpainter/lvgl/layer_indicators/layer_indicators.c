#include "layer_indicators.h"
#include "../styles/styles.h"
#include "quantum.h"
#include "../../../definitions/layers.h"
#include "../events/custom_events.h"

//lv_obj_t * layer_indicators;
//lv_obj_t * layer_name;
lv_coord_t layer_y_positions[5];
lv_img_dsc_t * layers[5];
static void redraw_layer_indicators(lv_event_t * event);
static void layer_name_callback(lv_event_t * event);

static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(CANVAS_WIDTH, LAYER_SHAPE_HEIGHT + 5)];
static lv_color_t cbuf_layer_bg[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(CANVAS_WIDTH, LAYER_SHAPE_HEIGHT + 5)];
static lv_color_t cbuf_layer_fg[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(CANVAS_WIDTH, LAYER_SHAPE_HEIGHT + 5)];
lv_point_t translate_point(lv_point_t point, int16_t x, int16_t y){
  lv_point_t final_point = {point.x + x, point.y + y};
  return final_point;
  
}

lv_coord_t initial_layer_y_pos = CANVAS_HEIGHT - (LAYER_SHAPE_HEIGHT / 2) - 2.5;
  lv_point_t left = {5, (LAYER_SHAPE_HEIGHT / 2) + 2.5};
  lv_point_t top = {(LAYER_SHAPE_WIDTH / 2) + 5, 2.5};
  lv_point_t right = {LAYER_SHAPE_WIDTH + 5, (LAYER_SHAPE_HEIGHT / 2) + 2.5};
  lv_point_t bottom = {(LAYER_SHAPE_WIDTH / 2) + 5, LAYER_SHAPE_HEIGHT + 2.5};

static lv_color_t layer_indicators_cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(CANVAS_WIDTH, CANVAS_HEIGHT)];

void  init_layer_indicators(lv_obj_t *parent){


  layer_indicators = lv_canvas_create(parent);

  lv_canvas_set_buffer(layer_indicators, layer_indicators_cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR_ALPHA);
  lv_canvas_fill_bg(layer_indicators, lv_color_black(), LV_OPA_100);

  lv_obj_align(layer_indicators, LV_ALIGN_TOP_LEFT, 4, 4);
  lv_obj_add_event_cb(layer_indicators,redraw_layer_indicators,CUSTOM_EVENT_LAYER_CHANGE, NULL);
} 



void init_layer_name(lv_obj_t * parent){
  layer_name = lv_label_create(parent);
  lv_obj_add_style(layer_name, (lv_style_t *) &layer_name_style,0);
  lv_obj_align_to(layer_name, layer_indicators, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
  layer_state_t current_layer = get_highest_layer(layer_state);
  lv_label_set_text(layer_name, layer_to_string(current_layer));
  lv_obj_set_width(layer_name, CANVAS_WIDTH);
  lv_obj_set_style_text_align(layer_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
  lv_obj_add_event_cb(layer_name,layer_name_callback,CUSTOM_EVENT_LAYER_CHANGE, NULL);
}

lv_obj_t *layer_shape(lv_obj_t *parent)
{

  lv_draw_rect_dsc_t rect_dsc;
  lv_draw_rect_dsc_init(&rect_dsc);

  rect_dsc.bg_opa = LV_OPA_60;
  rect_dsc.bg_color = lv_color_black(); // lv_palette_lighten(LV_PALETTE_RED, 4);
  rect_dsc.blend_mode = LV_BLEND_MODE_NORMAL;

  lv_draw_line_dsc_t draw_dsc_main, draw_dsc_outer, draw_dsc_inner;
  lv_draw_line_dsc_init(&draw_dsc_main);
  lv_draw_line_dsc_init(&draw_dsc_outer);
  lv_draw_line_dsc_init(&draw_dsc_inner);

  set_main_draw_line_style(&draw_dsc_main);
  set_offset_draw_line_style(&draw_dsc_outer);
  set_offset_draw_line_style(&draw_dsc_inner);

  lv_obj_t *canvas = lv_canvas_create(parent);
  
  lv_canvas_set_buffer(canvas, cbuf_layer_bg, CANVAS_WIDTH, LAYER_SHAPE_HEIGHT + 5, LV_IMG_CF_TRUE_COLOR_ALPHA);
  lv_canvas_fill_bg(canvas, lv_palette_darken(LV_PALETTE_GREY, 1), LV_OPA_0);
  lv_obj_set_style_bg_opa(canvas,LV_OPA_0,0);

  const lv_point_t points[4] = {left, top, right, bottom};
  lv_canvas_draw_polygon(canvas, points, 4, &rect_dsc);
  const lv_point_t main_line_points[5] = {left, top, right, bottom, left};
  const lv_point_t outer_line_points[5] = {{left.x - LINE_OFFSET, left.y}, translate_point(top, 0, -LINE_OFFSET), translate_point(right, LINE_OFFSET, 0), translate_point(bottom, 0, LINE_OFFSET), {left.x - LINE_OFFSET, left.y}};
  const lv_point_t inner_line_points[5] = {translate_point(left, LINE_OFFSET, 0), translate_point(top, 0, LINE_OFFSET), translate_point(right, -LINE_OFFSET, 0),
                                           translate_point(bottom, 0, -LINE_OFFSET), translate_point(left, LINE_OFFSET, 0)};

  lv_canvas_draw_line(canvas, outer_line_points, 5, &draw_dsc_outer);
  lv_canvas_draw_line(canvas, inner_line_points, 5, &draw_dsc_inner);
  lv_canvas_draw_line(canvas, main_line_points, 5, &draw_dsc_main);
  lv_area_t blur_area = {
      4, 1, LAYER_SHAPE_WIDTH + 6, LAYER_SHAPE_HEIGHT + 4};

  lv_canvas_blur_hor(canvas, &blur_area, 1.5);
  lv_canvas_blur_ver(canvas, &blur_area, 1.5);

      lv_obj_add_flag(canvas, LV_OBJ_FLAG_EVENT_BUBBLE);
  return canvas;
}

 lv_obj_t * create_current_layer_indicator(lv_obj_t *parent){


  lv_draw_rect_dsc_t rect_dsc;
  lv_draw_rect_dsc_init(&rect_dsc);
  const lv_point_t points[4] =   {translate_point(left, LINE_OFFSET +1, 0), translate_point(top, 0, LINE_OFFSET ), 
  translate_point(right, -LINE_OFFSET - 1,0),
      translate_point(bottom, 0, -LINE_OFFSET )};
 
  lv_obj_t * current_layer_indicator;
   current_layer_indicator = lv_canvas_create(parent);

  lv_canvas_set_buffer(current_layer_indicator, cbuf_layer_fg, CANVAS_WIDTH, LAYER_SHAPE_HEIGHT + 5, LV_IMG_CF_TRUE_COLOR_ALPHA);
  lv_canvas_fill_bg(current_layer_indicator, lv_palette_darken(LV_PALETTE_GREY, 1), LV_OPA_0);
  
  set_current_layer_indicator_draw_rect_style(&rect_dsc);
 
 lv_canvas_draw_polygon(current_layer_indicator, points, 4, &rect_dsc);
  lv_obj_align(current_layer_indicator, LV_ALIGN_TOP_LEFT, 4, 4);
lv_obj_add_flag(current_layer_indicator, LV_OBJ_FLAG_HIDDEN );
return current_layer_indicator;
}

void set_screen_layer(layer_state_t layer_state){
  int real_layer_index =  (int) get_layer_real_index(layer_state);
  if(is_keyboard_left()){
    uprintf("left real_layer_index is %d \n", real_layer_index);
  } else {
    uprintf("right left real_layer_index is %d \n", real_layer_index);
  }
  
  lv_event_send(layer_indicators, CUSTOM_EVENT_LAYER_CHANGE, &real_layer_index);

}

void set_screen_layer_name(layer_state_t layer_state){
  const char * layer_name_char = layer_to_string(layer_state);
  uprintf("layer_name_char is %s \n",layer_name_char);
  char * ll = (char*) layer_name_char;
  lv_event_send(layer_name, CUSTOM_EVENT_LAYER_CHANGE, ll);
}

static void layer_name_callback(lv_event_t * event){
const  char* layer_name_char_pointer = (char*) lv_event_get_param(event);
uprintf("layer_name_char_pointer is %s \n",layer_name_char_pointer);
  lv_label_set_text(layer_name, layer_name_char_pointer);
}
static void redraw_layer_indicators(lv_event_t * event){
   int* layer_to_indicate_pointer =  (int*)lv_event_get_param(event);
  int layer_to_indicate =  *layer_to_indicate_pointer;
  uprintf("layer_to_indicate is %d \n", layer_to_indicate);
 draw_layer_indicators(layer_to_indicate);
}
    
void init_img_array(void){
  for(int i = 0; i < 5; i++){
   lv_obj_t * l_shape;
   l_shape = layer_shape(layer_indicators);
   lv_obj_set_pos(l_shape, 0, layer_y_positions[i]);
    
       
  }
}
lv_img_dsc_t layer_img_dsc;
lv_obj_t * layer_img;
void init_layer_img(void){
  memcpy(cbuf_tmp, cbuf_layer_fg, sizeof(cbuf_tmp));
         
         layer_img_dsc.data = (void *)cbuf_tmp;
         layer_img_dsc.header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
         layer_img_dsc.header.w = CANVAS_WIDTH;
         layer_img_dsc.header.h = LAYER_SHAPE_HEIGHT + 5;
         layer_img = lv_img_create(layer_indicators);
         lv_img_set_src(layer_img, &layer_img_dsc);
         lv_obj_align(layer_img, LV_ALIGN_TOP_LEFT, 0,0);
};   
void draw_layer_indicators(int layer){
   lv_obj_set_pos(layer_img, 0, layer_y_positions[layer]); 
}



void init_layers(){

 for (int i = 0; i < 5; i++){
  layer_y_positions[i] = (4 * 10) - (i * 10);
  printf("init layer %d \n", layer_y_positions[i]);
  }
  init_img_array();
  
 create_current_layer_indicator(layer_indicators);
init_layer_img();


  
}
