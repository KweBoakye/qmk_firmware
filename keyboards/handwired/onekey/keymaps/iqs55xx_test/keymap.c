#include QMK_KEYBOARD_H

#include "users/kweboakye/pointing/tps65/IQS55xx.h"
#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};


void           pointing_device_driver_init(void) {
    init_iqs55xx();
}

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
    return iqs55xx_get_report(mouse_report);
    }

uint16_t       pointing_device_driver_get_cpi(void) { return 0; }
void           pointing_device_driver_set_cpi(uint16_t cpi) {}
