#include "process_records.h"
#ifdef POINTING_DEVICE_ENABLE
#include "pointing/custom_pointing.h"
#endif
#include "taphold.h"
#include "os_toggle.h"
#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE
    #include "../quantumpainter/lvgl/state_indicators/state_indicators.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//uprintf("in process record user \n");
mod_state = get_mods(); 
    if (!process_achordion(keycode, record)) { return false; }

 /*    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif */

#ifdef OLED_ENABLE
    process_record_user_oled(keycode, record);
#endif

//uprintf("before process record taphold \n");

   switch (proccess_record_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };


//uprintf("before process case modes  \n");

 // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

//uprintf("before process record keymap \n");
if (!process_record_keymap(keycode, record)) { return false; }

const uint8_t mods = get_mods();
const uint8_t oneshot_mods = get_oneshot_mods();

//uprintf("before process_persistent_layers \n");
    switch (process_persistent_layers(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

//uprintf("before process_combos  \n");
    switch (process_combos(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

//uprintf("before process_record_pointing \n");
   #ifdef POINTING_DEVICE_ENABLE
    switch (process_record_pointing(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
    #endif

 
//uprintf("before process_os_toggle\n");
     // Process OS toggle
    switch (process_os_toggle(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

//uprintf("before process_select_word \n");
 // Process select word
    switch (process_select_word(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

//uprintf("before process_case_mode_keycodes  \n");
    switch (process_case_mode_keycodes(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

//uprintf("before process_record_num_word \n");
       switch (process_record_num_word(keycode, record)){
            case PROCESS_RECORD_RETURN_TRUE:
  //          uprintf("process_record_num_word true \n");
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
    //    uprintf("process_record_num_word false\n");
            return false;
        default:
      //  uprintf("process_record_num_word default \n");
            break;
    };

//uprintf("before process_record_nav_mode \n");
          switch (process_record_nav_mode(keycode, record)){
            case PROCESS_RECORD_RETURN_TRUE:
  //          uprintf("process_record_nav_mode true \n");
            return true;
        case PROCESS_RECORD_RETURN_FALSE: 
    //    uprintf("process_record_nav_mode false\n");
            return false;
        default:
      //  uprintf("process_record_nav_mode default \n");
            break;
    };


//     #ifdef QUANTUM_PAINTER_LVGL_INTEGRATION_ENABLE
//     if (record->event.pressed) {
//    process_state_indicators(mod_state);
//     }
// #endif



    //return true;

  //      // Process default modifier key
  //  switch (process_default_mod_key(keycode, record)) {
  //      case PROCESS_RECORD_RETURN_TRUE:
  //          return true;
  //      case PROCESS_RECORD_RETURN_FALSE:
  //          return false;
  //      default:
  //          break;
  //  };


//uprintf("before keycode switch \n");
    switch (keycode) {
        
        case KC_BTN1:
           if (record->event.pressed) {

#ifdef HAPTIC_ENABLE
               drv2605l_pulse(DRV2605L_EFFECT_STRONG_CLICK_100);
#endif
         break;
}
case SCRLL_UP:
uprintf("SCRLL_UP \n");
uint16_t upcode;
if(os.type == OS_MACOS){
    uprintf("os.type == OS_MACOS \n");
    upcode = KC_WH_D;  
}else {
    uprintf("os.type != OS_MACOS \n");
    upcode = KC_WH_U;
}
if (record->event.pressed){
register_code16(upcode);
} else {
    unregister_code16(upcode);
}
return false;
case SCRLL_DN:
uprintf("SCRLL_DN \n");
uint16_t downcode;
if(os.type == OS_MACOS){
  //      uprintf("os.type == OS_MACOS \n");
        downcode = KC_WH_U;
    } else {
    //    uprintf("os.type != OS_MACOS \n");
        downcode = KC_WH_D;
    }
if (record->event.pressed){
register_code16(downcode);
    } else {
        unregister_code16(downcode);
    }
    return false;
  case SCOPE:

 if(record->event.pressed){
     SEND_STRING("::");
 }
  break;

case UPDIR:
if(record->event.pressed){
  SEND_STRING("../");
  break;
}

 case EQ3X:  // Types triple equal ===
if(record->event.pressed){
   SEND_STRING("===");

 break;
}
  case ARROW:  // Arrow macro, types -> or =>.
if(record->event.pressed){
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Is shift held?
        del_mods(MOD_MASK_SHIFT);  // Temporarily delete shift.
        del_oneshot_mods(MOD_MASK_SHIFT);
        SEND_STRING("=>");
        set_mods(mods);            // Restore mods.
      } else {
        SEND_STRING("->");
      }
    break;
}


    }
    return true;
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) { post_process_record_keymap(keycode, record); }
