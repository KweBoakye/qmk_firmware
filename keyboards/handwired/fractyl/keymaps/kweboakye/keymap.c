// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
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


#define TIMEOUT 50

// TODO: remove patch
#ifdef PROTOCOL_CHIBIOS
#    pragma message("ChibiOS is currently 'best effort' and might not report accurate results")

i2c_status_t i2c_start_bodge(uint8_t address, uint16_t timeout) {
    i2c_start(address);

    // except on ChibiOS where the only way is do do "something"
    uint8_t data = 0;
    return i2c_readReg(address, 0, &data, sizeof(data), TIMEOUT);
}

#    define i2c_start i2c_start_bodge
#endif



void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_start to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_start(address << 1, TIMEOUT);
        if (error == I2C_STATUS_SUCCESS) {
            i2c_stop();
            dprintf("  I2C device found at address 0x%02X\n", address);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        dprintf("No I2C devices found\n");
    else
        dprintf("done\n");
}

uint16_t scan_timer = 0;

void matrix_scan_keymap(void) {
    if (timer_elapsed(scan_timer) > 5000) {
        do_scan();
        scan_timer = timer_read();
    }
}
void keyboard_post_init_keymap(void){
     debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
 #if RGB_MATRIX_ENABLE
    rgb_matrix_enable();
     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR );
    rgb_matrix_sethsv_noeeprom(170, 255, 255); // set default RGB color to yellow
  #endif //RGB_MATRIX_ENABLE
    #ifdef QUANTUM_PAINTER_ENABLE 
 keyboard_post_init_kb_display();
#endif 
    i2c_init();
    scan_timer = timer_read();
}
