#include "process_records.h"
#include "pointing/pointing.h"
#include "taphold.h"
#include QMK_KEYBOARD_H

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_achordion(keycode, record)) { return false; }

    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
#ifdef OLED_ENABLE
    process_record_user_oled(keycode, record);
#endif
if (!process_caps_word_custom(keycode, record)) { return false; }

 // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

if (!process_record_keymap(keycode, record)) { return false; }

const uint8_t mods = get_mods();
const uint8_t oneshot_mods = get_oneshot_mods();

    switch (process_persistent_layers(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };


    switch (process_combos(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };


    switch (process_record_pointing(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    switch (proccess_record_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

     // Process OS toggle
    switch (process_os_toggle(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

 // Process select word
    switch (process_select_word(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    switch (process_case_mode_keycodes(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
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



    switch (keycode) {

        case KC_BTN1:
           if (record->event.pressed) {

#ifdef HAPTIC_ENABLE
               DRV_pulse(strong_click);
#endif
         break;
}

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
