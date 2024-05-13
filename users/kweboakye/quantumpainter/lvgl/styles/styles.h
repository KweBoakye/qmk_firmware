
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "lib/lvgl/lvgl.h"

//#include "lib/lvgl/lvgl.h"

//#define LV_STYLE_INIT(var_name, prop_array) lv_style_t var_name = { .v_p = { .const_props = prop_array }, .has_group = 0xFF, .is_const = 1 }
//#define C_LV_STYLE_PROP_INV { .prop = LV_STYLE_PROP_INV, .value = {0} }

void set_main_draw_line_style(lv_draw_line_dsc_t *draw_line_dsc);
void set_offset_draw_line_style(lv_draw_line_dsc_t *draw_line_dsc);
void set_current_layer_indicator_draw_rect_style(lv_draw_rect_dsc_t * draw_rect_dsc);

const lv_style_t indicator_box_default_style;
const lv_style_t indicator_box_pressed_style;
const lv_style_t indicator_box_checked_style;
const lv_style_t current_layer_indicator_style;
const lv_style_t layer_name_style;

#ifdef __cplusplus
} /*extern "C"*/
#endif
