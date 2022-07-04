#include "user_haptic.h"
#include "definitions/keycodes.h"
#include "DRV2605L.h"
#//include "transport_sync.h"
#include "transactions.h"

bool check_is_both_hand_combo(uint16_t keycode){
    switch(keycode){
        case MO(_MAINTENANCE):
        case MO(_FN):
        return true;
        default:
        return false;
    }
}

 bool  get_haptic_enabled_key_custom(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case NAV_SPC:
    case SYM_BSPC:
    case NAV_ENT:
    case SYM_DEL:
        if (record->tap.count == 0){
        return true;
        } else {
            return false;
        }
        break;
    case KC_WH_U:
    case KC_WH_D:
         return false;
#ifdef NO_HAPTIC_MOD
       /*   case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0) return false;
            break; */
        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            if (record->tap.count != TAPPING_TOGGLE) return false;
            break;
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) return false;
            break;
        case KC_LEFT_CTRL ... KC_RIGHT_GUI:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
#endif
#ifdef NO_HAPTIC_ALPHA
        case KC_A ... KC_Z:
#endif
#ifdef NO_HAPTIC_PUNCTUATION
        case KC_ENTER:
        case KC_ESCAPE:
        case KC_BACKSPACE:
        case KC_SPACE:
        case KC_MINUS:
        case KC_EQUAL:
        case KC_LEFT_BRACKET:
        case KC_RIGHT_BRACKET:
        case KC_BACKSLASH:
        case KC_NONUS_HASH:
        case KC_SEMICOLON:
        case KC_QUOTE:
        case KC_GRAVE:
        case KC_COMMA:
        case KC_SLASH:
        case KC_DOT:
        case KC_NONUS_BACKSLASH:
#endif
#ifdef NO_HAPTIC_LOCKKEYS
        case KC_CAPS_LOCK:
        case KC_SCROLL_LOCK:
        case KC_NUM_LOCK:
#endif
#ifdef NO_HAPTIC_NAV
        case KC_PRINT_SCREEN:
        case KC_PAUSE:
        case KC_INSERT:
        case KC_DELETE:
        case KC_PAGE_DOWN:
        case KC_PAGE_UP:
        case KC_LEFT:
        case KC_UP:
        case KC_RIGHT:
        case KC_DOWN:
        case KC_END:
        case KC_HOME:
#endif
#ifdef NO_HAPTIC_NUMERIC
        case KC_1 ... KC_0:
#endif
            return false;
    }
    return true;
}

/* void handle_split_haptic(uint16_t keycode, keyrecord_t *record, uint8_t haptic_feedback){



        if (record->event.pressed) {
            // keypress
            if (haptic_feedback < 2 ) {
                //haptic_play();
                DRV_pulse(soft_bump_60);
            }
        } else {
            // keyrelease
            if (haptic_feedback > 0 ) {
                //haptic_play();
                 DRV_pulse(soft_bump_60);
            }
        }

} */



bool is_keypress_on_secondary(uint16_t keycode, keyrecord_t *record){
 if(is_keyboard_left()){
    if(record->event.key.row > (MATRIX_ROWS / 2)){
       return true;
    } else {
        return false;
    }
    } else {
        if(record->event.key.row <= (MATRIX_ROWS / 2)){
        return true;
        } else {
        return false;
    }
    }
}

bool should_secondary_haptic_actuate(keyrecord_t *record){
    if(record->event.pressed){
    if(haptic_get_feedback() < 2) return true;
    } else {
        if(haptic_get_feedback() > 0) return true;
    }
    return false;
}

bool should_primary_send_haptic(uint16_t keycode, keyrecord_t *record){
     return (is_keypress_on_secondary(keycode, record) && should_secondary_haptic_actuate(record));
}

void user_haptic_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(uint8_t)) {
       uint8_t drv_effect;
        memcpy(&drv_effect, initiator2target_buffer, initiator2target_buffer_size);
       DRV_pulse(drv_effect);
    }
}


void send_haptic(uint8_t drv_effect){

      bool haptic_sent = transaction_rpc_send(RPC_ID_HAPTIC_SYNC, sizeof(uint8_t), &drv_effect);
      dprintf("haptic sent  = ");
      printf(haptic_sent ? "true \n" : "false \n");
}
