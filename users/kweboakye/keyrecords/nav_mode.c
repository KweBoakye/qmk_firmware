#include "nav_mode.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

static bool _nav_mode_active  = false;
static uint16_t nav_mode_timer = 0;

bool nav_mode_enabled(void){
    return _nav_mode_active ;
}

void enable_nav_mode(void) {
    _nav_mode_active = true;
    layer_on(_NAV);
}

void disable_nav_mode(void) {
    _nav_mode_active = false;
    layer_off(_NAV);
}


void process_nav_mod_activation(const keyrecord_t *record){
if (record->event.pressed) {
        layer_on(_NAV);
        nav_mode_timer = timer_read();
    } else {
        if (timer_elapsed(nav_mode_timer) < TAPPING_TERM) {
            // Tapping enables layer mode
            _nav_mode_active = true;
        } else {
            // Holding treats as a normal LT
            layer_off(_NAV);
        }
    }
}

bool should_terminate_nav_mode(uint16_t keycode, const keyrecord_t *record){
    switch (keycode)
    {
        case KC_HOME ... KC_UP:
        case KC_MS_U ... KC_ACL2:
        case KC_LEFT_CTRL ... KC_RIGHT_GUI:
        case NAV_SPC:
        case SYM_BSPC:
        case NAV_ENT:
        case SH_DEL:
        case KC_SPC:
        case KC_BSPC:
        case KC_ENT:
        return false;

    default:
            if (record->event.pressed) {
                return true;
            }
            return false;
    }
}

process_record_result_t process_record_nav_mode(uint16_t keycode, keyrecord_t *record){
  if (keycode == NAV_MODE) {
    printf("%s","NAV_MODE");
        if (record->event.pressed) {
            if (nav_mode_enabled()){
                disable_nav_mode();
            } else {
                enable_nav_mode();
            nav_mode_timer = timer_read();
            }

            return PROCESS_RECORD_RETURN_FALSE;
        }
        else {
            if (timer_elapsed(nav_mode_timer) > TAPPING_TERM) {
                // If the user held the key longer than TAPPING_TERM,
                // consider it a hold, and disable the behavior on
                // key release.
                disable_nav_mode();
                return PROCESS_RECORD_RETURN_FALSE;
            }
        }
    }
    // Other than the custom keycodes, nothing else in this feature will
    // activate if the behavior is not on, so allow QMK to handle the
    // event as usual
    if (!nav_mode_enabled()) return PROCESS_RECORD_RETURN_TRUE;

    // Nothing else acts on key release, either
    if (!record->event.pressed) {
        return PROCESS_RECORD_RETURN_TRUE;
    }

    // Get the base keycode of a mod or layer tap key
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0)
                return PROCESS_RECORD_RETURN_TRUE;
            keycode = keycode & 0xFF;
            break;
        default:
            break;
    }

    if (should_terminate_nav_mode(keycode, record)) {
        disable_nav_mode();
    }

    return PROCESS_RECORD_RETURN_TRUE;
}



