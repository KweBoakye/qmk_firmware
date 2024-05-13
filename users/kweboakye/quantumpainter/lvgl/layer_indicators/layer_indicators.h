#pragma once

#include "qp.h"
#include "lvgl.h"

#define LAYER_SHAPE_WIDTH 60
#define LAYER_SHAPE_HEIGHT 30
#define LAYER_COUNT 5
#define LAYER_Y_SHIFT 10
#define CANVAS_WIDTH (LAYER_SHAPE_WIDTH + 10)
#define CANVAS_HEIGHT (LAYER_SHAPE_HEIGHT + (LAYER_COUNT * LAYER_Y_SHIFT))
#define LINE_OFFSET 1.5

lv_obj_t * layer_indicators;
lv_obj_t * layer_name;

void  init_layer_indicators(lv_obj_t *parent);
void init_layers(void);
void draw_layer_indicators(int layer);
void set_screen_layer(layer_state_t layer_state);
void init_layer_name(lv_obj_t *parent);
void set_screen_layer_name(layer_state_t layer_state);