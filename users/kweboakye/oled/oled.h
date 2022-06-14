#pragma once

#include "quantum.h"
#include "oled_driver.h"

#    define OLED_RENDER_LAYOUT_QWERTY     "Qwerty"
#    define OLED_RENDER_LAYOUT_COLEMAK_DH "Clmk DH"

#    define OLED_RENDER_LAYOUT_COLEMAK    "Colemak"
#    define OLED_RENDER_LAYOUT_COLEMAK_DH_GAMING "CMK DH GM"


bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
bool oled_task_user(void);
oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
extern uint32_t oled_timer;

