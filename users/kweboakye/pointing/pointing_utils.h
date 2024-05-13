#pragma once

#include "pointing_device.h"


#define CONSTRAIN_HID(amt) ((amt) < INT8_MIN ? INT8_MIN : ((amt) > INT8_MAX ? INT8_MAX : (amt)))
#define CONSTRAIN_HID_XY(amt) ((amt) < XY_REPORT_MIN ? XY_REPORT_MIN : ((amt) > XY_REPORT_MAX ? XY_REPORT_MAX : (amt)))
//extern uint16_t mouse_timer;

int8_t pointing_device_hv_clamp(int16_t value);
mouse_xy_report_t pointing_device_xy_clamp(clamp_range_t value);
