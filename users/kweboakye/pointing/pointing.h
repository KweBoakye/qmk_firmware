#include "kweboakye.h"


report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report);
report_mouse_t pointing_device_task_combined_keymap(report_mouse_t left_report, report_mouse_t right_report);
void           matrix_scan_pointing(void);
process_record_result_t           process_record_pointing(uint16_t keycode, keyrecord_t* record);
layer_state_t  layer_state_set_pointing(layer_state_t state);
extern bool    tap_toggling, enable_acceleration;
extern uint16_t mouse_timer;
uint8_t  mouse_keycode_tracker;






