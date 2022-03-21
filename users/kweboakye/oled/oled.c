/* Copyright 2021 John Ezra
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//Sets up what the OLED screens display.

#include QMK_KEYBOARD_H
#include <time.h>
#include <stdlib.h>
#include "helix.h"
#include "smiley.h"
#include "roving_eye.h"
#include "star.h"
#include "rotating_hand.h"
#include "qmk_logo.h"
#include "luna.h"
#include "ocean_dream.h"
#include "oled_utils.h"
#include "print.h"

#ifdef PMW3360_ENABLE
#include "drivers/sensors/pmw3360.h"
#endif

#ifdef CIRQUE_ENABLED
#include "drivers/sensors/cirque_pinnacle.h"
#include "pointing/cirque_trackpad_logic.h"
#endif

#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
#include "drivers/sensors/analog_joystick.h"
#include "pointing/analog_joystick_logic.h"
#endif

int timer = 0;
char wpm_counter[5];
int x = 31;
int currwpm = 0;
int vert_count = 0;

//=============  USER CONFIG PARAMS  ===============
float max_wpm = 150.0f; //WPM value at the top of the graph window
int graph_refresh_interval = 100; //in milliseconds
int graph_area_fill_interval = 3; //determines how dense the horizontal lines under the graph line are; lower = more dense
int vert_interval = 3; //determines frequency of vertical lines under the graph line
bool vert_line = false; //determines whether to draw vertical lines
int graph_line_thickness = 2; //determines thickness of graph line in pixels
//=============  END USER PARAMS  ===============



#define ANIM_SIZE 1024           // number of bytes in array, minimize for adequate firmware size, max is 1024
#define ROVING_EYE_ANIM_SIZE 1040
#define ROTATING_HAND_ANIM_SIZE 1040
#define ANIM_FRAMES 50           // Number of frames
#define STAR_ANIM_FRAMES 23           // Number of frames
#define SMILEY_ANIM_FRAMES 11           // Number of frames
#define ROVING_EYE_ANIM_FRAMES 43         // Number of frames
#define ROVING_EYE_FRAME_DURATION 60
#define ROTATING_HAND_ANIM_FRAMES 31         // Number of frames
#define ANIM_FRAME_DURATION 160  // How long each frame lasts in ms
#define ROTATING_HAND_DURATION 60  // How long each frame lasts in ms
#define NUMBER_OF_ANIMATIONS 5


typedef enum {
    smiley = 0,
    star = 1,
    helix = 2,
	roving_eye = 3,
    rotating_hand = 4
} animation_type;

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint8_t  current_total_frame = 0;
uint8_t  max_frame = SMILEY_ANIM_FRAMES * 5;
uint8_t current_anim_frame_duration = ANIM_FRAME_DURATION;
animation_type current_animation = smiley;

#ifdef OLED_ENABLE

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) { return rotation; }

	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return oled_init_keymap(rotation);
}

void process_current_idle_frame(int anim_frames){
current_idle_frame = (current_idle_frame + 1) % anim_frames;
current_total_frame++;
}

static void render_anim(void) {
    // assumes 1 frame prep stage
    void animation_phase(animation_type animation) {

		switch(animation){
				case smiley:
                process_current_idle_frame(SMILEY_ANIM_FRAMES);
				oled_write_raw_P(smiley_animation[abs((SMILEY_ANIM_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
				break;
				case star:
                 process_current_idle_frame(STAR_ANIM_FRAMES);
				oled_write_raw_P(star_animation[abs((STAR_ANIM_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
				break;
				case helix:
                 process_current_idle_frame(ANIM_FRAMES);
				oled_write_raw_P(helix_animation[abs((ANIM_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
				break;
                case roving_eye:
                process_current_idle_frame(ROVING_EYE_ANIM_FRAMES);
				oled_write_raw_P(roving_eye_animation[abs((ROVING_EYE_ANIM_FRAMES - 1) - current_idle_frame)], ROVING_EYE_ANIM_SIZE);
				break;

                 case rotating_hand:
                process_current_idle_frame(ROVING_EYE_ANIM_FRAMES);
				oled_write_raw_P(rotating_hand_animation[abs((ROTATING_HAND_ANIM_FRAMES - 1) - current_idle_frame)], ROTATING_HAND_ANIM_SIZE);
				break;

			}

    }

     if (timer_elapsed32(anim_timer) > current_anim_frame_duration) {
       if(current_total_frame >= max_frame){
		   current_total_frame = 0;
		    anim_timer = timer_read32();
		   srand(timer_read());

		   current_animation = (animation_type)(rand() % NUMBER_OF_ANIMATIONS);
		   switch(current_animation){
				case smiley:
                current_anim_frame_duration = ANIM_FRAME_DURATION ;
				max_frame = SMILEY_ANIM_FRAMES * 5;
				break;
				case star:
                current_anim_frame_duration = ANIM_FRAME_DURATION ;
				max_frame = STAR_ANIM_FRAMES *6;
				break;
				case helix:
                current_anim_frame_duration = ANIM_FRAME_DURATION ;
				max_frame = ANIM_FRAMES * 3 ;
				break;
                case roving_eye:
                current_anim_frame_duration =  ROVING_EYE_FRAME_DURATION ;
				max_frame = ROVING_EYE_ANIM_FRAMES * 3 ;
				break;
                case rotating_hand:
                current_anim_frame_duration =  ROTATING_HAND_DURATION ;
				max_frame = ROTATING_HAND_ANIM_FRAMES * 3 ;
				break;

			}
		   animation_phase(current_animation);
	} else {
		anim_timer = timer_read32();
		animation_phase(current_animation);
	}
}


}


static void render_qmk_logo(void) {
oled_set_cursor(0, 0);
    oled_write_raw_P(qmk_logo_r1, sizeof(qmk_logo_r1));
oled_set_cursor(0, 1);
    oled_write_raw_P(qmk_logo_r2, sizeof(qmk_logo_r2));
oled_set_cursor(0, 2);
    oled_write_raw_P(qmk_logo_r3, sizeof(qmk_logo_r3));
oled_set_cursor(0, 3);
    oled_write_raw_P(qmk_logo_r4, sizeof(qmk_logo_r4));
		//oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
}



static void render_layers(void) {
	static const char PROGMEM layer_background_r1[1][38] = {
		{0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x42,
		0x42, 0x42, 0x22, 0x22, 0x22, 0x42, 0x42, 0x42, 0x82, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0xfe}
		};
	static const char PROGMEM layer_background_r2[1][38] = {
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xaa, 0xaa, 0xaa, 0x11, 0x11, 0x11, 0x20, 0x20, 0x20, 0x40,
		0x40, 0x40, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x11, 0x11, 0x11, 0xaa, 0xaa,
		0xaa, 0x44, 0x44, 0x44, 0x00, 0xff}
		};
	static const char PROGMEM layer_background_r3[1][38] = {
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xaa, 0xaa, 0xaa, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x44,
		0x44, 0x44, 0x88, 0x88, 0x88, 0x44, 0x44, 0x44, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0xaa, 0xaa,
		0xaa, 0x44, 0x44, 0x44, 0x00, 0xff}
		};
	static const char PROGMEM layer_background_r4[1][38] = {
		{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x42, 0x42, 0x42, 0x44,
		0x44, 0x44, 0x48, 0x48, 0x48, 0x44, 0x44, 0x44, 0x42, 0x42, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40,
		0x40, 0x40, 0x40, 0x40, 0x40, 0x7f}
		};
	static const char PROGMEM base[1][38] = {
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xae, 0xae, 0xae, 0x1f, 0x1f, 0x1f, 0x3e, 0x3e, 0x3e, 0x7c,
		0x7c, 0x7c, 0xf8, 0xf8, 0xf8, 0x7c, 0x7c, 0x7c, 0x3e, 0x3e, 0x3e, 0x1f, 0x1f, 0x1f, 0xae, 0xae,
		0xae, 0x44, 0x44, 0x44, 0x00, 0xff}
		};
	static const char PROGMEM lower[2][38] = {
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xea, 0xea, 0xea, 0xf1, 0xf1, 0xf1, 0xe2, 0xe2, 0xe2, 0xc4,
		0xc4, 0xc4, 0x88, 0x88, 0x88, 0xc4, 0xc4, 0xc4, 0xe2, 0xe2, 0xe2, 0xf1, 0xf1, 0xf1, 0xea, 0xea,
		0xea, 0x44, 0x44, 0x44, 0x00, 0xff},
		{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x43, 0x43, 0x43, 0x47,
		0x47, 0x47, 0x4f, 0x4f, 0x4f, 0x47, 0x47, 0x47, 0x43, 0x43, 0x43, 0x41, 0x41, 0x41, 0x40, 0x40,
		0x40, 0x40, 0x40, 0x40, 0x40, 0x7f}
		};
	static const char PROGMEM raise[][38] = {
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xea, 0xea, 0xea, 0xf1, 0xf1, 0xf1, 0xe0, 0xe0, 0xe0, 0xc0,
		0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf1, 0xf1, 0xf1, 0xea, 0xea,
		0xea, 0x44, 0x44, 0x44, 0x00, 0xff},
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xaa, 0xaa, 0xaa, 0x11, 0x11, 0x11, 0x23, 0x23, 0x23, 0x47,
		0x47, 0x47, 0x8f, 0x8f, 0x8f, 0x47, 0x47, 0x47, 0x23, 0x23, 0x23, 0x11, 0x11, 0x11, 0xaa, 0xaa,
		0xaa, 0x44, 0x44, 0x44, 0x00, 0xff}
		};
	static const char PROGMEM adjust[][38] = {
		{0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0xc2,
		0xc2, 0xc2, 0xe2, 0xe2, 0xe2, 0xc2, 0xc2, 0xc2, 0x82, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0xfe},
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xae, 0xae, 0xae, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f,
		0x7f, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0xae, 0xae,
		0xae, 0x44, 0x44, 0x44, 0x00, 0xff}
		};
	static const char PROGMEM custom[][38] = {
		{0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x42,
		0xc2, 0x42, 0xa2, 0x62, 0xa2, 0x42, 0xc2, 0x42, 0x82, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0xfe},
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xaa, 0xee, 0xaa, 0x55, 0xbb, 0x55, 0xaa, 0x75, 0xaa, 0x55,
		0xea, 0x55, 0xaa, 0xd5, 0xaa, 0x55, 0xea, 0x55, 0xaa, 0x75, 0xaa, 0x55, 0xbb, 0x55, 0xaa, 0xee,
		0xaa, 0x44, 0x44, 0x44, 0x00, 0xff},
		{0x00, 0xff, 0x00, 0x44, 0x44, 0x44, 0xaa, 0xee, 0xaa, 0x55, 0xbb, 0x55, 0xaa, 0x77, 0xaa, 0x55,
		0xee, 0x55, 0xaa, 0xdd, 0xaa, 0x55, 0xee, 0x55, 0xaa, 0x77, 0xaa, 0x55, 0xbb, 0x55, 0xaa, 0xee,
		0xaa, 0x44, 0x44, 0x44, 0x00, 0xff},
		{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x42, 0x43, 0x42, 0x45,
		0x46, 0x45, 0x4a, 0x4d, 0x4a, 0x45, 0x46, 0x45, 0x42, 0x43, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40,
		0x40, 0x40, 0x40, 0x40, 0x40, 0x7f}
		};

	switch (get_highest_layer(layer_state)) {
		case 0:
		oled_render_image(1, 38, layer_background_r1, 15, 4, 0);
			oled_render_image(1, 38, layer_background_r2, 15, 5, 0);
		    oled_render_image(2, 38, lower, 15, 6, 0);
			
		break;
		case 1:
			oled_render_image(1, 38, layer_background_r1, 15, 4, 0);
			oled_render_image(1, 38, layer_background_r2, 15, 5, 0);
			oled_render_image(1, 38, base, 15, 6, 0);
			oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
		break;
		case 2:
			oled_render_image(1, 38, layer_background_r1, 15, 4, 0);
			oled_render_image(2, 38, raise, 15, 5, 0);
			oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
		break;
		case 3:
			oled_render_image(2, 38, adjust, 15, 4, 0);
			oled_render_image(1, 38, layer_background_r3, 15, 6, 0);
			oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
		break;
		default:
			oled_render_image(4, 38, custom, 15, 4, 0);
		break;
	}
}

void render_mod_state(uint8_t modifiers) {
	static const char PROGMEM gui_off [][3]= {{0x80, 0x81, 0}, {0xa0, 0xa1, 0}};
	static const char PROGMEM gui_on [][3]= {{0xc0, 0xc1, 0}, {0xe0, 0xe1, 0}};
	static const char PROGMEM alt_off [][3]= {{0x82, 0x83, 0}, {0xa2, 0xa3, 0}};
	static const char PROGMEM alt_on [][3]= {{0xc2, 0xc3, 0}, {0xe2, 0xe3, 0}};
	static const char PROGMEM ctrl_off [][3]= {{0x84, 0x85, 0}, {0xa4, 0xa5, 0}};
	static const char PROGMEM ctrl_on [][3]= {{0xc4, 0xc5, 0}, {0xe4, 0xe5, 0}};
	static const char PROGMEM shift_off [][3]= {{0x86, 0x87, 0}, {0xa6, 0xa7, 0}};
	static const char PROGMEM shift_on [][3]= {{0xc6, 0xc7, 0}, {0xe6, 0xe7, 0}};

	// fillers between the modifier icons bleed into the icon frames

	static const char PROGMEM off_off [][2]= {{0x9e, 0}, {0xbe, 0}};
	static const char PROGMEM on_on [][2]= {{0xdf, 0}, {0xff, 0}};
	static const char PROGMEM on_off [][2]= {{0xde, 0}, {0xfe, 0}};
	static const char PROGMEM off_on [][2]= {{0x9f, 0}, {0xbf, 0}};

	// render icons

	if(modifiers & MOD_MASK_GUI) {
		oled_set_cursor(0, 4);
		oled_write_P(gui_on[0], false);
		oled_set_cursor(0, 5);
		oled_write_P(gui_on[1], false);
	} else {
		oled_set_cursor(0, 4);
		oled_write_P(gui_off[0], false);
		oled_set_cursor(0, 5);
		oled_write_P(gui_off[1], false);
	}
	if(modifiers & MOD_MASK_ALT) {
		oled_set_cursor(3, 4);
		oled_write_P(alt_on[0], false);
		oled_set_cursor(3, 5);
		oled_write_P(alt_on[1], false);
	} else {
		oled_set_cursor(3, 4);
		oled_write_P(alt_off[0], false);
		oled_set_cursor(3, 5);
		oled_write_P(alt_off[1], false);
	}
	if(modifiers & MOD_MASK_CTRL) {
		oled_set_cursor(0, 6);
		oled_write_P(ctrl_on[0], false);
		oled_set_cursor(0, 7);
		oled_write_P(ctrl_on[1], false);
	} else {
		oled_set_cursor(0, 6);
		oled_write_P(ctrl_off[0], false);
		oled_set_cursor(0, 7);
		oled_write_P(ctrl_off[1], false);
	}
	if(modifiers & MOD_MASK_SHIFT) {
		oled_set_cursor(3, 6);
		oled_write_P(shift_on[0], false);
		oled_set_cursor(3, 7);
		oled_write_P(shift_on[1], false);
	} else {
		oled_set_cursor(3, 6);
		oled_write_P(shift_off[0], false);
		oled_set_cursor(3, 7);
		oled_write_P(shift_off[1], false);
	}

	// render fillers

	if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
		oled_set_cursor(2, 4);
		oled_write_P(on_on[0], false);
		oled_set_cursor(2, 5);
		oled_write_P(on_on[1], false);
	} else if(modifiers & MOD_MASK_GUI) {
		oled_set_cursor(2, 4);
		oled_write_P(on_off[0], false);
		oled_set_cursor(2, 5);
		oled_write_P(on_off[1], false);
	} else if(modifiers & MOD_MASK_ALT) {
		oled_set_cursor(2, 4);
		oled_write_P(off_on[0], false);
		oled_set_cursor(2, 5);
		oled_write_P(off_on[1], false);
	} else {
		oled_set_cursor(2, 4);
		oled_write_P(off_off[0], false);
		oled_set_cursor(2, 5);
		oled_write_P(off_off[1], false);
	}

	if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
		oled_set_cursor(2, 6);
		oled_write_P(on_on[0], false);
		oled_set_cursor(2, 7);
		oled_write_P(on_on[1], false);
	} else if(modifiers & MOD_MASK_CTRL) {
		oled_set_cursor(2, 6);
		oled_write_P(on_off[0], false);
		oled_set_cursor(2, 7);
		oled_write_P(on_off[1], false);
	} else if(modifiers & MOD_MASK_SHIFT) {
		oled_set_cursor(2, 6);
		oled_write_P(off_on[0], false);
		oled_set_cursor(2, 7);
		oled_write_P(off_on[1], false);
	} else {
		oled_set_cursor(2, 6);
		oled_write_P(off_off[0], false);
		oled_set_cursor(2, 7);
		oled_write_P(off_off[1], false);
	}
}

void render_bootmagic_status(void) {
	static const char PROGMEM nkro_off [][3]= {{0x88, 0x89, 0}, {0xa8, 0xa9, 0}};
	static const char PROGMEM nkro_on [][3]= {{0xc8, 0xc9, 0}, {0xe8, 0xe9, 0}};
	static const char PROGMEM mac_os_off [][6]= {{0x90, 0x91, 0x92, 0x93, 0x94, 0}, {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0}};
	static const char PROGMEM mac_os_on [][6]= {{0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0}, {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0}};
	static const char PROGMEM windows_off [][6]= {{0x95, 0x96, 0x97, 0x98, 0x99, 0}, {0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0}};
	static const char PROGMEM windows_on [][6]= {{0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0}, {0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0}};

	if (keymap_config.nkro) {
		oled_set_cursor(5, 4);
		oled_write_P(nkro_on[0], false);
		oled_set_cursor(5, 5);
		oled_write_P(nkro_on[1], false);
	}	else {
		oled_set_cursor(5, 4);
		oled_write_P(nkro_off[0], false);
		oled_set_cursor(5, 5);
		oled_write_P(nkro_off[1], false);
	}
	if (keymap_config.swap_lctl_lgui) {
		oled_set_cursor(10, 6);
		oled_write_P(windows_on[0], false);
		oled_set_cursor(10, 7);
		oled_write_P(windows_on[1], false);
		oled_set_cursor(10, 4);
		oled_write_P(mac_os_off[0], false);
		oled_set_cursor(10, 5);
		oled_write_P(mac_os_off[1], false);
	}	else {
		oled_set_cursor(10, 4);
		oled_write_P(mac_os_on[0], false);
		oled_set_cursor(10, 5);
		oled_write_P(mac_os_on[1], false);
		oled_set_cursor(10, 6);
		oled_write_P(windows_off[0], false);
		oled_set_cursor(10, 7);
		oled_write_P(windows_off[1], false);
	}
}

void render_lock_status(void) {
	static const char PROGMEM caps_off [][3]= {{0x8a, 0x8b, 0}, {0xaa, 0xab, 0}};
	static const char PROGMEM caps_on [][3]= {{0xca, 0xcb, 0}, {0xea, 0xeb, 0}};
	static const char PROGMEM num_off [][3]= {{0x8c, 0x8d, 0}, {0xac, 0xad, 0}};
	static const char PROGMEM num_on [][3]= {{0xcc, 0xcd, 0}, {0xec, 0xed, 0}};
	static const char PROGMEM scrl_off [][3]= {{0x8e, 0x8f, 0}, {0xae, 0xaf, 0}};
	static const char PROGMEM scrl_on [][3]= {{0xce, 0xcf, 0}, {0xee, 0xef, 0}};

	static const char PROGMEM off_off [][2]= {{0x9e, 0}, {0xbe, 0}};
	static const char PROGMEM on_on [][2]= {{0xdf, 0}, {0xff, 0}};
	static const char PROGMEM on_off [][2]= {{0xde, 0}, {0xfe, 0}};
	static const char PROGMEM off_on [][2]= {{0x9f, 0}, {0xbf, 0}};

	led_t led_usb_state = host_keyboard_led_state();
	if (led_usb_state.caps_lock) {
	oled_set_cursor(8, 4);
	oled_write_P(caps_on[0], false);
	oled_set_cursor(8, 5);
	oled_write_P(caps_on[1], false);
	}	else {
	oled_set_cursor(8, 4);
	oled_write_P(caps_off[0], false);
	oled_set_cursor(8, 5);
	oled_write_P(caps_off[1], false);
	}
	if (led_usb_state.num_lock) {
	oled_set_cursor(5, 6);
	oled_write_P(num_on[0], false);
	oled_set_cursor(5, 7);
	oled_write_P(num_on[1], false);
	}	else {
	oled_set_cursor(5, 6);
	oled_write_P(num_off[0], false);
	oled_set_cursor(5, 7);
	oled_write_P(num_off[1], false);
	}
	if (led_usb_state.scroll_lock) {
	oled_set_cursor(8, 6);
	oled_write_P(scrl_on[0], false);
	oled_set_cursor(8, 7);
	oled_write_P(scrl_on[1], false);
	}	else {
	oled_set_cursor(8, 6);
	oled_write_P(scrl_off[0], false);
	oled_set_cursor(8, 7);
	oled_write_P(scrl_off[1], false);
	}

	// render fillers

	if ((led_usb_state.caps_lock) && (keymap_config.nkro)) {
		oled_set_cursor(7, 4);
		oled_write_P(on_on[0], false);
		oled_set_cursor(7, 5);
		oled_write_P(on_on[1], false);
	} else if(keymap_config.nkro) {
		oled_set_cursor(7, 4);
		oled_write_P(on_off[0], false);
		oled_set_cursor(7, 5);
		oled_write_P(on_off[1], false);
	} else if(led_usb_state.caps_lock) {
		oled_set_cursor(7, 4);
		oled_write_P(off_on[0], false);
		oled_set_cursor(7, 5);
		oled_write_P(off_on[1], false);
	} else {
		oled_set_cursor(7, 4);
		oled_write_P(off_off[0], false);
		oled_set_cursor(7, 5);
		oled_write_P(off_off[1], false);
	}
	if ((led_usb_state.num_lock) && (led_usb_state.scroll_lock)) {
		oled_set_cursor(7, 6);
		oled_write_P(on_on[0], false);
		oled_set_cursor(7, 7);
		oled_write_P(on_on[1], false);
	} else if(led_usb_state.num_lock) {
		oled_set_cursor(7, 6);
		oled_write_P(on_off[0], false);
		oled_set_cursor(7, 7);
		oled_write_P(on_off[1], false);
	} else if(led_usb_state.scroll_lock) {
		oled_set_cursor(7, 6);
		oled_write_P(off_on[0], false);
		oled_set_cursor(7, 7);
		oled_write_P(off_on[1], false);
	} else {
		oled_set_cursor(7, 6);
		oled_write_P(off_off[0], false);
		oled_set_cursor(7, 7);
		oled_write_P(off_off[1], false);
	}
}



void render_wpm_graph(void) {
	currwpm = get_current_wpm();  //get current WPM value
	if(timer_elapsed(timer) > graph_refresh_interval){  //check if it's been long enough before refreshing graph
			x = 63 - ((currwpm / max_wpm) * 63);  // main calculation to plot graph line
			for(int i = 0; i <= graph_line_thickness - 1; i++){  //first draw actual value line
			oled_write_pixel(1, x + i, true);
			}
		if(vert_line){  //then fill in area below the value line
			if(vert_count == vert_interval){
				vert_count = 0;
				while(x <= 63){
					oled_write_pixel(1, x, true);
					x++;
					}
			} else {
				for(int i = 63; i > x; i--){
					if(i % graph_area_fill_interval == 0){
						oled_write_pixel(1, i, true);
					}
				}
			vert_count++;
			}
		} else {
			for(int i = 63; i > x; i--){
				if(i % graph_area_fill_interval == 0){
					oled_write_pixel(1, i, true);
				}
			}
		}
		oled_pan(false);  //then move the entire graph one pixel to the right
		timer = timer_read();  //refresh the timer for the next iteration
	}
	char buf[4];  //format current WPM value into a printable string
	oled_set_cursor(14, 0);
	oled_write("WPM:", false);
	buf[0] = currwpm >= 100 ? ((currwpm/100) + '0') : ' ';
	buf[1] = currwpm >= 10 ? (((currwpm/10) % 10) + '0') : ' ';
	buf[2] = (currwpm % 10) + '0';
	buf[3] = 0;
	oled_write(buf, false);
}

#ifdef POINTING_ANALOG_JOYSTICK_ENABLE
void render_analog_joystick(analog_joystick_mode_t mode) {
    switch (mode) {
        case ANALOG_JOYSTICK_MODE_MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case ANALOG_JOYSTICK_MODE_ARROWS:
            oled_write_P(PSTR("Arrows"), false);
            break;
        case ANALOG_JOYSTICK_MODE_SCROLL:
            oled_write_P(PSTR("Scroll"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}
#endif

void render_right_pointing_dpi(void){

    #ifdef CIRQUE_ENABLED
uint16_t cirque_cpi = cirque_pinnacle_get_scale();
oled_set_cursor(10, 0);
oled_write("TP CPI", false);
oled_write(get_u16_str(cirque_cpi, ' '), false);
oled_set_cursor(10, 2);
switch(cirque_trackpad_mode){
    case CIRQUE_TRACKPAD_TRACKPAD_MODE:
            oled_write_P(PSTR("Trckpd"), false);
            break;
        case CIRQUE_TRACKPAD_SCROLLING_MODE:
            oled_write_P(PSTR("Scroll"), false);
            break;
        case CIRQUE_TRACKPAD_CARET_MODE:
            oled_write_P(PSTR("Caret"), false);
            break;
            case CIRQUE_TRACKPAD_DRAG_MOM_MODE:
            oled_write_P(PSTR("Drag"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
#endif

#ifdef PMW3360_ENABLE
  uint16_t pmw3360_cpi = pmw3360_get_cpi();
 oled_set_cursor(10, 1);
 oled_write("TB CPI", false);
 oled_write(get_u16_str(pmw3360_cpi, ' '), false);
#endif



//#ifdef ANALOG_JOYSTICK_ENABLED
//#include "drivers/sensors/analog_joystick.h"
//#endif



}

void render_left_pointing_dpi(void){
#ifdef CIRQUE_ENABLED
uint16_t cirque_cpi = cirque_pinnacle_get_scale();
if(is_keyboard_master()){
oled_set_cursor(10, 0);
oled_write("TP CPI", false);
oled_write(get_u16_str(cirque_cpi, ' '), false);
} else {
    oled_set_cursor(5, 4);
oled_write("TP CPI", false);
oled_write(get_u16_str(cirque_cpi, ' '), false);
}
#endif

#ifdef ANALOG_JOYSTICK_ENABLED
  float joystick_speed_coeeficient = ANALOG_JOYSTICK_SPEED_MAX / ANALOG_JOYSTICK_SPEED_REGULATOR;
  char buffer[64];
   snprintf(buffer, sizeof buffer, "%2.2f", joystick_speed_coeeficient);
   if(is_keyboard_master()){
oled_set_cursor(10, 1);
oled_write("JS COEF", false);
oled_write(buffer, false);
oled_set_cursor(10, 2);
render_analog_joystick(analog_joystick_state.config.mode);
} else {
    oled_set_cursor(5, 5);
oled_write("JS COEF", false);
oled_write(buffer, false);
 oled_set_cursor(5, 6);
render_analog_joystick(analog_joystick_state.config.mode);
}
#endif
}

void render_box(void){
static const char PROGMEM box_top[72] = {
 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,

    };
    static const char PROGMEM box_bottom[72] = {
    0xFF, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0xFF,};

oled_set_cursor(ISLAND_COLUMN + 4, ISLAND_LINE);
oled_write_raw_P(box_top, 72);
oled_set_cursor(ISLAND_COLUMN + 4, ISLAND_LINE+ 1);
oled_write_raw_P(box_bottom, 72);
}

/* static const char PROGMEM windows_top[12] =
{0x7C, 0x7C, 0x7C, 0x7E, 0x00, 0x7E,
    0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x00,};



static const char PROGMEM windows_bottom[12] ={
     0x0F, 0x1F, 0x1F, 0x3F, 0x00, 0x3F,
    0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x00,
};

static const char PROGMEM mac_top[12] =
 {0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0xEC,
    0xEE, 0xF7, 0xF3, 0x70, 0x20, 0x00,};

static const char PROGMEM mac_bottom[12] ={
     0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x3F, 0x1E, 0x0C, 0x00,
}; */

void render_status_main(void) {
	render_qmk_logo();
    render_luna(5,0);
	render_layers();
	render_mod_state(get_mods());
	render_bootmagic_status();
	render_lock_status();

}

void render_status_secondary(void) {
	// render_anim();
    #    ifdef OCEAN_DREAM_ENABLE
        render_stars();
    #    endif
    //render_box();
    if(true){

    } else {
        render_anim();
    }
}

//__attribute__((weak)) bool oled_task_keymap(void) { return true; }

bool oled_task_user(void) {
	if (is_keyboard_master()) {
		render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
		render_status_secondary();
	}

     if(is_keyboard_left()){
         render_left_pointing_dpi();
     }else {
        render_right_pointing_dpi();
    }
     return false;
}



#endif
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
                is_calm = true;
            } else {
                isSneaking = false;
                is_calm = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
    }
    return true;
}
