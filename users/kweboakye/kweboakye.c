#include "kweboakye.h"
#include "haptic.h"
#include "transactions.h"

userspace_config_t userspace_config;
extern os_t os;
#ifdef DRV2605L
extern haptic_config_t haptic_config;
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_force_hold_result(keycode);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_term_result(keycode);
}



/* bool get_retro_tapping(uint16_t keycode, keyrecord_t *record){
    return get_retro_tapping_result(keycode);
} */




/* bool check_side_to_buzz(uint16_t keycode, keyrecord_t *record){
    if(is_keyboard_left()){
    if(record->event.key.row > (MATRIX_ROWS / 2)){
        send_haptic(keycode, record);
       return false;
    } else {
        return true;
    }
    } else {
        if(record->event.key.row <= (MATRIX_ROWS / 2)){
        send_haptic(keycode, record);
        return false;
        } else {
        return true;
    }
    }
} */

bool  get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record){

 #ifdef DRV2605L
  if(get_haptic_enabled_key_custom(keycode, record)){
    if(check_is_combo(keycode)){
        send_haptic(haptic_config.mode);
        return true;
    }
    if(should_primary_send_haptic(keycode, record)){
      send_haptic(haptic_config.mode);
    } else {
        return true;
    }
  }
  return false;
  #else

return get_haptic_enabled_key_custom(keycode, record);
  #endif
}
