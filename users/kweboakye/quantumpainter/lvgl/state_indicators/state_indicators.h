#include "lib/lvgl/lvgl.h"

#define indicator_widget_height 48
#define indicator_widget_width 48
#define horizontal_distance_between_indicator_widgets 1
#define vertical_distance_between_indicator_widgets 1
#define indicator_container_column_width horizontal_distance_between_indicator_widgets + indicator_widget_width
#define indicator_container_row_height vertical_distance_between_indicator_widgets + indicator_widget_height
#define row_count 3
#define col_count 3
extern lv_obj_t * indicator_container;

void flex_indicator_container(lv_obj_t *parent);
lv_obj_t *indicator_widget(lv_obj_t *parent);
lv_obj_t *text_indicator_widget(lv_obj_t *screen, char *text);
void process_state_indicators(uint8_t mods);
void process_case_indicators(void);
//void indicator_container(lv_obj_t *parent);

typedef enum  { INACTIVE, ONESHOT, ACTIVE} mod_state_t;