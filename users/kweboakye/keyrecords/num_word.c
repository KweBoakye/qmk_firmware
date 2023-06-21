#include "num_word.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

static uint16_t num_word_timer = 0;
static bool _num_word_enabled = false;
bool num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(_FN);
}
void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(_FN);
}

void process_num_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_FN);
        num_word_timer = timer_read();
    } else {
        if (timer_elapsed(num_word_timer) < TAPPING_TERM) {
            // Tapping enables NUMWORD
            _num_word_enabled = true;
        } else {
            // Holding turns off NUM when released
            layer_off(_FN);
        }
    }
}

bool should_terminate_num_word(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes which should not disable num word mode.
        // We could probably be more brief with these definitions by using
        // a couple more ranges, but I believe "explicit is better than
        // implicit"
        case KC_F1 ... KC_F12:
        case KC_1 ... KC_0:
        case KC_LCBR:
        case KC_RCBR:
        case KC_LPRN:
        case KC_RPRN:
        case KC_LBRC:
        case KC_RBRC:
        case KC_CIRC:
        case KC_MINS:
        case KC_ASTR:
        case KC_PLUS:
        case KC_LABK:
        case KC_RABK:
        case KC_EQL:
        case KC_AMPR:
        case UK_DQUO:
        case KC_NUBS:
        case KC_DLR:
        case KC_COLN:
        case KC_QUES:
        case NAV_SPC:
        case SYM_BSPC:
        case KC_SPC:
        case KC_BSPC:
        case KC_ENT:
        case KC_NO:
        case KC_DOT:
        case KC_SCLN:
        // Numpad keycodes
        case KC_P1 ... KC_P0:
        case KC_PSLS ... KC_PPLS:
        case KC_PDOT:
            // Don't disable for above keycodes
            return false;

        default:
            if (record->event.pressed) {
                return true;
            }
            return false;
    }

    // Should be unreachable
    return false;
}

process_record_result_t process_record_num_word(uint16_t keycode, const keyrecord_t *record) {
    // Handle the custom keycodes that go with this feature
    if (keycode == NUM_WORD) {
        if (record->event.pressed) {
            if (num_word_enabled()){
                disable_num_word();
            } else {
                enable_num_word();
            num_word_timer = timer_read();
            }

            return PROCESS_RECORD_RETURN_FALSE;
        }
        else {
            if (timer_elapsed(num_word_timer) > TAPPING_TERM) {
                // If the user held the key longer than TAPPING_TERM,
                // consider it a hold, and disable the behavior on
                // key release.
                disable_num_word();
                return PROCESS_RECORD_RETURN_FALSE;
            }
        }
    }

    // Other than the custom keycodes, nothing else in this feature will
    // activate if the behavior is not on, so allow QMK to handle the
    // event as usual
    if (!num_word_enabled()) return PROCESS_RECORD_RETURN_TRUE;

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

    if (should_terminate_num_word(keycode, record)) {
        disable_num_word();
    }

    return PROCESS_RECORD_RETURN_TRUE;
}
