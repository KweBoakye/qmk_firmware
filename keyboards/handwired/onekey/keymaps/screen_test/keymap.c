#include QMK_KEYBOARD_H
#include "qp.h"
#include "users/kweboakye/quantumpainter/qp_display.h"
#include "print.h"
#include "color.h"
//#include "lvgl.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};
 painter_device_t display;
void keyboard_post_init_user(void) {
  // keyboard_post_init_kb_display();
  //backlight_enable();
 // backlight_level(0);
//  #ifdef LCD_BACKLIGHT_PIN
//  setPinOutput(LCD_BACKLIGHT_PIN);
//  writePinHigh(LCD_BACKLIGHT_PIN);
//  #elif BACKLIGHT_ENABLE
// backlight_enable();
//  #endif
//  display = qp_st7789_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 3); 
//   qp_init(display,QP_ROTATION_90);
//   #ifdef ST7789_135 
//     qp_set_viewport_offsets(display, 40, 53);
// #endif
//   qp_power(display, true);
//     qp_rect(display, 0, 0, 239, 239, HSV_RED, true);
keyboard_post_init_kb_display();
}

/**
 * Create an arc which acts as a loader.
 */
