#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "klor.h"
#include "kweboakye.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif //HAPTIC ENABLE
#ifdef QUANTUM_PAINTER_ENABLE 
#include "users/kweboakye/quantumpainter/qp_display.h"
#endif
#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#define LAYOUT_polydactyl_wrapper(...) LAYOUT_polydactyl(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌───────────────────────────────────────────────────────────┐
   │ c o l e m a k                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    F    │    P    │    G    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    J    │    L    │    U    │    Y    │    ;    │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   TAB   │    A    │    R    │    S    │    T    │    D    ├─╯                ╰─┤    H    │    N    │    E    │    I    │    O    │    "    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   DEL   │    Z    │    X    │    C    │    V    │    B    ││ SHIFT  ││PLY/PSE ││    K    │    M    │    ,    │    .    │    /    │  SHIFT  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  CTRL   │  LOWER  │  SPACE  │   ALT   ││ CMD/WIN │  ENTER  │  RAISE  │  BSPCE  │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_COLEMAK_MOD_DH] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ______________COLEMAK_MOD_DH_L1____________,                          ______________COLEMAK_MOD_DH_R1____________,  
    KC_TAB,   _______COLEMAK_MOD_DH_L2_HOME_ROW_MODS_____,                          _______COLEMAK_MOD_DH_R2_HOME_ROW_MODS_____,    KC_QUOT,
    KC_BTN4,     ______________COLEMAK_MOD_DH_L3____________,     KC_LSFT,   KC_MPLY,  ______________COLEMAK_MOD_DH_R3____________,  KC_BTN5,
                                  NAV_SPC,  SH_DEL, OSM(MOD_LSFT),OSM(MOD_LCTL), OSL(_UNICODE),  KC_LGUI,  NAV_ENT,    SYM_BSPC
 ),
 [_SYM] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ___________________SYM_LEFT_1___________________,                          ___________________SYM_RIGHT_1___________________,  
    KC_TAB,   ___________________SYM_LEFT_2___________________,                          ___________________SYM_RIGHT_2___________________,    KC_QUOT,
    _______,   ___________________SYM_LEFT_3___________________, KC_LSFT,   KC_MPLY,  ___________________SYM_RIGHT_3___________________,  _______,
                                  MO(_FN),  _______, _______,_______, _______, _______,  _______,    _______
 ),
 [_NAV] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ___________________NAV_LEFT_1___________________,                          ___________________NAV_RIGHT_1___________________,  
    KC_TAB,   ___________________NAV_LEFT_2___________________,                          ___________________NAV_RIGHT_2___________________,    KC_QUOT,
    _______,   ___________________NAV_LEFT_3___________________,     KC_LSFT,   KC_MPLY,  ___________________NAV_RIGHT_3___________________,  _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    MO(_FN)
 ),
 [_FN] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              _________________FUNC_LEFT_________________,                          _________________FUNC_RIGHT________________,  
    KC_TAB,   ________________NUMBER_LEFT________________,                          ________________NUMBER_RIGHT_______________,    KC_QUOT,
    _______,   _______ , KC_MINS , KC_ASTR , KC_PLUS ,  KC_SPC,     KC_LSFT,   KC_MPLY,   _______, _______ , _______, _______, _______,  _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    _______
 ),
  [_MAINTENANCE] = LAYOUT_polydactyl_wrapper(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              ________________MAINTANENCE_LEFT_1_______________,                          ________________MAINTANENCE_RIGHT_1______________,  
    KC_TAB,   ________________MAINTANENCE_LEFT_2_______________,                          ________________MAINTANENCE_RIGHT_2______________,    KC_QUOT,
    _______,   ________________MAINTANENCE_LEFT_3_______________,     KC_LSFT,   KC_MPLY,  ________________MAINTANENCE_RIGHT_3______________, _______,
                                  _______,  _______, _______,_______,   _______, _______,  _______,    _______
 ),

};

// void keyboard_pre_init_kb(void) {
//     // Ensures that GP26 through GP29 are initialized as digital inputs (as
//     // opposed to analog inputs).  These GPIOs are shared with A0 through A3,
//     // respectively.  On RP2040-B2 and later, the digital inputs are disabled by
//     // default (see RP2040-E6).
//     gpio_init(F4);
//     gpio_init(F5);
//     gpio_init(F6);
//     gpio_init(F7);

//     keyboard_pre_init_user();
// }

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
    void keyboard_post_init_keymap(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
   #ifdef QUANTUM_PAINTER_ENABLE 
 keyboard_post_init_kb_display();
#endif
 
    i2c_init();
    scan_timer = timer_read();

printf("keyboard_post_init_keymap");
backlight_level(BACKLIGHT_LEVELS);

#if RGB_MATRIX_ENABLE
    //rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(35, 255, 100); // set default RGB color to yellow
  #endif //RGB_MATRIX_ENABLE
}

