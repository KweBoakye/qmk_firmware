#include <quantum.h>
#include "blackpill_f411.h"

void matrix_init_kb(void) {
#if BOOTMAGIC_ENABLE
     setPinInputHigh(A0);
#endif
    // setPinInputHigh(B12);
   /*  keyboard_config.raw = eeconfig_read_kb();

    if (!keyboard_config.dpi_config) {
        keyboard_config.dpi_config = 2;
        eeconfig_update_kb(keyboard_config.raw);
    } */
    matrix_init_user();
}

void matrix_scan_kb(void) {
#if BOOTMAGIC_ENABLE
    if (!readPin(A0)) {
        reset_keyboard();
   }
#endif
}
