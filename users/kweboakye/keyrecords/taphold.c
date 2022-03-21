#include "taphold.h"


bool get_tapping_force_hold_result(uint16_t keycode) {
   switch (keycode) {
        case QK_MOD_TAP...QK_MOD_TAP_MAX:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term_result(uint16_t keycode) {
    switch (keycode) {
        case GUI_A:
        case GUI_O:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping_result(uint16_t keycode){
    switch (keycode) {
        case GUI_A:
        case ALT_R:
        case SFT_S:
        case CTRL_T:
        case CTRL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
            return true;
        default:
            return false;
    }
}

process_record_result_t proccess_record_taphold(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {

    case RCTL_T(KC_N):
        /*
        This piece of code nullifies the effect of Right Shift when tapping
        the RCTL_T(KC_N) key.
        This helps rolling over RSFT_T(KC_E) and RCTL_T(KC_N)
        to obtain the intended "en" instead of "N".
        Consequently, capital N can only be obtained by tapping RCTL_T(KC_N)
        and holding LSFT_T(KC_S) (which is the left Shift mod tap).
        */

        /*
        Detect the tap.
        We're only interested in overriding the tap behaviour
        in a certain cicumstance. The hold behaviour can stay the same.
        */
        if (record->event.pressed && record->tap.count > 0) {
            // Detect right Shift
            if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                // temporarily disable right Shift
                // so that we can send KC_E and KC_N
                // without Shift on.
                unregister_mods(MOD_BIT(KC_RSHIFT));
                tap_code(KC_E);
                tap_code(KC_N);
                // restore the mod state
                add_mods(MOD_BIT(KC_RSHIFT));
                // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
                return PROCESS_RECORD_RETURN_FALSE;
            }
        }
         /*else process RCTL_T(KC_N) as usual.*/
        return PROCESS_RECORD_RETURN_TRUE;

    case LCTL_T(KC_T):
        /*
        This piece of code nullifies the effect of Left Shift when
        tapping the LCTL_T(KC_T) key.
        This helps rolling over LSFT_T(KC_S) and LCTL_T(KC_T)
        to obtain the intended "st" instead of "T".
        Consequently, capital T can only be obtained by tapping LCTL_T(KC_T)
        and holding RSFT_T(KC_E) (which is the right Shift mod tap).
        */

        if (record->event.pressed && record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                unregister_mods(MOD_BIT(KC_LSHIFT));
                tap_code(KC_S);
                tap_code(KC_T);
                add_mods(MOD_BIT(KC_LSHIFT));
                return PROCESS_RECORD_RETURN_FALSE;
            }
        }
         /*else process LCTL_T(KC_T) as usual.*/
        return PROCESS_RECORD_RETURN_TRUE;
    }
    return PROCESS_RECORD_CONTINUE;
}
