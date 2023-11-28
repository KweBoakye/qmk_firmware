// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


#include "kweboakye.h"
 #ifdef QUANTUM_PAINTER_ENABLE 
#include "users/kweboakye/quantumpainter/qp_display.h"
#endif


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_MOD_DH] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       ______________COLEMAK_MOD_DH_L1____________ ,    ______________COLEMAK_MOD_DH_R1____________,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____,    _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       ______________COLEMAK_MOD_DH_L3____________,    ______________COLEMAK_MOD_DH_R3____________,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                    OSM(MOD_LSFT),  NAV_SPC,  SH_DEL, NAV_ENT, SYM_BSPC, OSL(_UNICODE)
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  )
};





void keyboard_post_init_keymap(void){
     debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
 
    #ifdef QUANTUM_PAINTER_ENABLE 
 keyboard_post_init_kb_display();
#endif 
    i2c_init();


// #if RGB_MATRIX_ENABLE
//     rgb_matrix_enable();
//      rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR );
//     rgb_matrix_sethsv(170, 255, 255); // set default RGB color to yellow
//   #endif //RGB_MATRIX_ENABLE
    if(is_keyboard_left()){
        printf(" left side");
    } else {
                printf("right side");
    }
    
}
