#include "tap_dance.h"

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
         if (!state->pressed) return TD_DOUBLE_TAP;
         else return TD_DOUBLE_HOLD;
         }
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t nl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void nl_finished(qk_tap_dance_state_t *state, void *user_data) {
    nl_tap_state.state = cur_dance(state);
    switch (nl_tap_state.state) {
        case TD_SINGLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
           register_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_NUMPAD)) {
                // If already set, then switch it off
                layer_off(_NUMPAD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NUMPAD);
            }
            break;
        case TD_DOUBLE_HOLD:
                layer_on(_NUMPAD);
        default:
            break;
    }
}

void nl_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer

    switch(nl_tap_state.state){
        case TD_SINGLE_HOLD:
        unregister_mods(MOD_BIT(KC_LSFT));
        break;
        case  TD_DOUBLE_HOLD:
             layer_off(_NUMPAD);
             break;
        default: break;
    }

    nl_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [NUMPAD_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nl_finished, nl_reset)
};
