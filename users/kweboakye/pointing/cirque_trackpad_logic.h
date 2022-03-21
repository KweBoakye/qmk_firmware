#pragma once

#include "quantum.h"
#include "pointing_device.h"
#include "kweboakye.h"

typedef enum {
    CIRQUE_TRACKPAD_TRACKPAD_MODE = 0,
    CIRQUE_TRACKPAD_SCROLLING_MODE,
    CIRQUE_TRACKPAD_CARET_MODE,
    CIRQUE_TRACKPAD_DRAG_MOM_MODE,
    CIRQUE_TRACKPAD_MODE_LAST  // Do not use, except for looping through enum values
} cirque_trackpad_mode_t;

cirque_trackpad_mode_t cirque_trackpad_mode;

void cirque_trackpad_logic_init (void);


report_mouse_t cirque_trackpad_pointing_device_task(report_mouse_t mouse_report);
process_record_result_t process_record_trackpad(uint16_t keycode, keyrecord_t* record);
