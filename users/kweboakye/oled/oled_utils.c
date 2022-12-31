#include "oled_utils.h"

// Loop to create line by line rendering for Horizontal display
// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
    void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
	for (uint8_t i = 0; i <= (lines-1); i++){
            oled_set_cursor(X_pos, Y_pos + i);
			oled_write_raw_P(render_line[i + frame], px);
		}
	}
