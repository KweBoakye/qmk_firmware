#pragma once
#include "quantum.h"
#include "qp.h"

extern painter_device_t display;

void keyboard_post_init_kb_display(void);

void suspend_power_down_user_display(void);

void suspend_wakeup_init_user_display(void);

void housekeeping_task_display(void);
