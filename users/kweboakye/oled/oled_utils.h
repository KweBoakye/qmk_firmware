#pragma once

#include "oled_driver.h"

void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame);
