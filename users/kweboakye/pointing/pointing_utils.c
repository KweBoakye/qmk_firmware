
#include "pointing_utils.h"

int8_t pointing_device_hv_clamp(int16_t value) {
    if (value < INT8_MIN) {
        return INT8_MIN;
    } else if (value > INT8_MAX) {
        return INT8_MAX;
    } else {
        return value;
    }
}


mouse_xy_report_t pointing_device_xy_clamp(clamp_range_t value) {
    if (value < XY_REPORT_MIN) {
        return XY_REPORT_MIN;
    } else if (value > XY_REPORT_MAX) {
        return XY_REPORT_MAX;
    } else {
        return value;
    }
}
