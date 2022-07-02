#include QMK_KEYBOARD_H

#include "users/kweboakye/quantumpainter/ST7789/ST7789_logic.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};

void keyboard_post_init_kb(void) {
keyboard_post_init_kb_display();
}


void housekeeping_task_user(void) {
housekeeping_task_display();
}

void suspend_power_down_user(void){
   suspend_power_down_user_display();
}

void suspend_wakeup_init_user(void){
    suspend_wakeup_init_user_display();
}
