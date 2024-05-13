#include "styles.h"
#include "../lvgl_fonts/fonts.h"

// const lv_style_t main_draw_line_style;

//  const lv_style_const_prop_t main_draw_line_style_props[] = {
//    LV_STYLE_CONST_LINE_COLOR(LV_COLOR_MAKE32(0xFF, 0xCD,0xD2)),
//    LV_STYLE_CONST_WIDTH(2),
//    LV_STYLE_CONST_LINE_ROUNDED(0),
//    LV_STYLE_CONST_LINE_OPA(LV_OPA_60),
//    LV_STYLE_CONST_BLEND_MODE(LV_BLEND_MODE_ADDITIVE),

//  };
 
//  LV_STYLE_CONST_INIT(main_draw_line_style, main_draw_line_style_props);

void set_main_draw_line_style(lv_draw_line_dsc_t *draw_line_dsc)
{
  draw_line_dsc->color = lv_color_change_lightness(lv_palette_lighten(LV_PALETTE_RED, 1), LV_OPA_60);
  draw_line_dsc->width = 2;
  draw_line_dsc->opa = LV_OPA_80;
  draw_line_dsc->round_end = 0;
  draw_line_dsc->round_start = 0; 
  draw_line_dsc->blend_mode = LV_BLEND_MODE_ADDITIVE;
  draw_line_dsc->raw_end = 0;
}

void set_offset_draw_line_style(lv_draw_line_dsc_t *draw_line_dsc)
{
  draw_line_dsc->color = lv_palette_lighten(LV_PALETTE_RED, 3);
  draw_line_dsc->width = 0.75;
  draw_line_dsc->round_end = 0;
  draw_line_dsc->opa = LV_OPA_60;
  draw_line_dsc->round_start = 0;
  draw_line_dsc->blend_mode = LV_BLEND_MODE_ADDITIVE;
  draw_line_dsc->raw_end = 0;
}

void set_current_layer_indicator_draw_rect_style(lv_draw_rect_dsc_t * draw_rect_dsc){
draw_rect_dsc->bg_color =   lv_palette_lighten(LV_PALETTE_RED, 1);
draw_rect_dsc->bg_opa = LV_OPA_60;
draw_rect_dsc->blend_mode = LV_BLEND_MODE_ADDITIVE;
draw_rect_dsc->border_color = lv_palette_darken(LV_PALETTE_AMBER,1);
draw_rect_dsc->border_opa = LV_OPA_100;
}

lv_style_const_prop_t layer_name_style_props[] = {
  LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0xEF, 0x53, 0x50)),
};

 lv_style_const_prop_t indicator_box_default_style_props[] = {   
  LV_STYLE_CONST_BORDER_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)),
  LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0x00,0x00, 0x00)),
  //LV_STYLE_CONST_TEXT_FONT(&BalaCynwydNF_14),
  LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)),
  LV_STYLE_CONST_OUTLINE_COLOR(LV_COLOR_MAKE(0x00,0x00, 0x00)),
  LV_STYLE_CONST_OUTLINE_WIDTH(1),
  LV_STYLE_CONST_OUTLINE_PAD(2),
};

const lv_style_const_prop_t  indicator_box_pressed_style_props[] = {
  LV_STYLE_CONST_BORDER_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  LV_STYLE_CONST_OUTLINE_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  
};

const lv_style_const_prop_t indicator_box_checked_style_props[] = {
  LV_STYLE_CONST_BORDER_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  LV_STYLE_CONST_OUTLINE_COLOR(LV_COLOR_MAKE(0xFF,0xBF, 0x00)),
  
  LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0x00,0x00, 0x00)),

};

LV_STYLE_CONST_INIT(indicator_box_default_style ,indicator_box_default_style_props);
LV_STYLE_CONST_INIT(indicator_box_pressed_style, indicator_box_pressed_style_props);
LV_STYLE_CONST_INIT(indicator_box_checked_style, indicator_box_checked_style_props);
LV_STYLE_CONST_INIT(layer_name_style, layer_name_style_props);






