#include QMK_KEYBOARD_H

#include "os_toggle.h"

os_t os = {
    .type = OS_WINDOWS
};

void apply_os_settings(os_variant_t  os_to_apply){
    switch(os_to_apply){
        case OS_MACOS:
        case OS_IOS:
                if (!keymap_config.swap_lctl_lgui) {
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                }
        break;
        case OS_WINDOWS:
               if  (keymap_config.swap_lctl_lgui) {
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
               }
        break;
        default:
        break;
    }
    os.type = os_to_apply;
}

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Change OS type

        case TG_MAC:
            if (record->event.pressed) {
                 apply_os_settings(OS_MACOS); 
            }
            return false;

        case TG_WIN:
            if (record->event.pressed) {
                apply_os_settings(OS_WINDOWS);
            }
            return false;

        case TG_LIN:
            if (record->event.pressed) {
                apply_os_settings(OS_LINUX);
            }
            return false;

    }

    return PROCESS_RECORD_CONTINUE;
}

uint32_t startup_exec(uint32_t trigger_time, void *cb_arg){
         os_variant_t os_type; 
         os_type = detected_host_os();
         apply_os_settings(os_type);
          return os_type ? 0 : 500;
}
