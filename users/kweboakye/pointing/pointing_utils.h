#pragma once

#define CONSTRAIN_HID(value) ((value) < -127 ? -127 : ((value) > 127 ? 127 : (value)))

extern bool mouse_timer;
