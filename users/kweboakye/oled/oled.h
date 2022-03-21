#pragma once

#include "quantum.h"
#include "oled_driver.h"


bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
bool oled_task_user(void);
oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
extern uint32_t oled_timer;

