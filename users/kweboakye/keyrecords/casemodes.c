/* Copyright 2021 Andrew Rae ajrae.nv@gmail.com @andrewjrae
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "casemodes.h"
#include "caps_word.h"
#include "../definitions/keycodes.h"

/* The caps word concept started with me @iaap on splitkb.com discord.
 * However it has been implemented and extended by many splitkb.com users:
 * - @theol0403 made many improvements to initial implementation
 * - @precondition used caps lock rather than shifting
 * - @dnaq his own implementation which also used caps lock
 * - @sevanteri added underscores on spaces
 * - @metheon extended on @sevanteri's work and added specific modes for
 *   snake_case and SCREAMING_SNAKE_CASE
 * - @baffalop came up with the idea for xcase, which he implements in his own
 *   repo, however this is implemented by @iaap with support also for one-shot-shift.
 * - @sevanteri
 *     - fixed xcase waiting mode to allow more modified keys and keys from other layers.
 *     - Added @baffalop's separator defaulting on first keypress, with a
 *       configurable default separator and overrideable function to determine
 *       if the default should be used.
 */


#ifndef DEFAULT_XCASE_SEPARATOR
#define DEFAULT_XCASE_SEPARATOR KC_UNDS
#endif

#define IS_OSM(keycode) (keycode >= QK_ONE_SHOT_MOD && keycode <= QK_ONE_SHOT_MOD_MAX)

// bool to keep track of the caps word state
//static bool caps_word_on = false;

// enum to keep track of the xcase state
static enum xcase_state xcase_state = XCASE_OFF;
// the keycode of the xcase delimiter
static uint16_t xcase_delimiter;
// the number of keys to the last delimiter
static int8_t distance_to_last_delim = -1;

static bool snake_case_active = false;
static bool kebab_case_active =  false;
static bool camel_case_active = false;
static bool screaming_snake_case_active = false;

// Get xcase state
enum xcase_state get_xcase_state(void) {
    return xcase_state;
}

// Enable xcase and pickup the next keystroke as the delimiter
void enable_xcase(void) {
    xcase_state = XCASE_WAIT;
}

// Enable xcase with the specified delimiter
void enable_xcase_with(uint16_t delimiter) {
    xcase_state = XCASE_ON;
    xcase_delimiter = delimiter;
    distance_to_last_delim = -1;
}

// Disable xcase
void disable_xcase(void) {
    xcase_state = XCASE_OFF;
    snake_case_active = false;
    kebab_case_active =  false;
    camel_case_active = false;
    screaming_snake_case_active = false;
}

// Place the current xcase delimiter
static void place_delimiter(void) {
    if (IS_OSM(xcase_delimiter)) {
        // apparently set_oneshot_mods() is dumb and doesn't deal with handedness for you
        uint8_t mods = xcase_delimiter & 0x10 ? (xcase_delimiter & 0x0F) << 4 : xcase_delimiter & 0xFF;
        set_oneshot_mods(mods);
    } else {
        tap_code16(xcase_delimiter);
    }
}

// Removes a delimiter, used for double tap space exit
static void remove_delimiter(void) {
    if (IS_OSM(xcase_delimiter)) {
        clear_oneshot_mods();
    } else {
        tap_code(KC_BSPC);
    }
}

// overrideable function to determine whether the case mode should stop
__attribute__ ((weak))
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
        switch (keycode) {
            // Keycodes to ignore (don't disable caps word)
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
                // If mod chording disable the mods
                if (record->event.pressed && (get_mods() != 0)) {
                    return true;
                }
                break;
            default:
                if (record->event.pressed) {
                    return true;
                }
                break;
        }
        return false;
}

/* overrideable function to determine whether to use the default separator on
 * first keypress when waiting for the separator. */
__attribute__ ((weak))
bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    // for example:
    /* switch (keycode) { */
    /*     case KC_A ... KC_Z: */
    /*     case KC_1 ... KC_0: */
    /*         return true; */
    /* } */
    return false;
}

bool process_case_modes(uint16_t keycode, const keyrecord_t *record) {
    if (is_caps_word_on() || xcase_state) {
        if ((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX)
            || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) {
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
        }

        if (keycode >= QK_LAYER_TAP && keycode <= QK_ONE_SHOT_LAYER_MAX) {
            // let special keys and normal modifiers go through
            return true;
        }

        if (xcase_state == XCASE_WAIT) {
            // grab the next input to be the delimiter
            if (use_default_xcase_separator(keycode, record)) {
                enable_xcase_with(DEFAULT_XCASE_SEPARATOR);
            }
            else if (record->event.pressed) {
                // factor in mods
                if (get_mods() & MOD_MASK_SHIFT) {
                    keycode = LSFT(keycode);
                }
                else if (get_mods() & MOD_BIT(KC_RALT)) {
                    keycode = RALT(keycode);
                }
                enable_xcase_with(keycode);
                return false;
            }
            else {
                if (IS_OSM(keycode)) {
                    // this catches the OSM release if no other key was pressed
                    set_oneshot_mods(0);
                    enable_xcase_with(keycode);
                    return false;
                }
                // let other special keys go through
                return true;
            }
        }

        if (record->event.pressed) {
            // handle xcase mode
            if (xcase_state == XCASE_ON) {
                // place the delimiter if space is tapped
                if (keycode == KC_SPACE) {
                    if (distance_to_last_delim != 0) {
                        place_delimiter();
                        distance_to_last_delim = 0;
                        return false;
                    }
                    // remove the delimiter and disable modes
                    else {
                        remove_delimiter();
                        disable_xcase();
                        caps_word_on();
                        return true;
                    }
                }
                // decrement distance to delimiter on back space
                else if (keycode == KC_BSPC) {
                    --distance_to_last_delim;
                }
                // don't increment distance to last delim if negative
                else if (distance_to_last_delim >= 0) {
                    // puts back a one shot delimiter if you we're back to the delimiter pos
                    if (distance_to_last_delim == 0 && (IS_OSM(xcase_delimiter))) {
                        place_delimiter();
                    }
                    ++distance_to_last_delim;
                }

            } // end XCASE_ON

            // check if the case modes have been terminated
            if (terminate_case_modes(keycode, record)) {
                caps_word_on();
                disable_xcase();
            }

#ifdef CAPSWORD_USE_SHIFT
            else if (is_caps_word_on() && keycode >= KC_A && keycode <= KC_Z){
                tap_code16(LSFT(keycode));
                return false;
            }
#endif

        } // end if event.pressed

        return true;
    }
    return true;
}

void enable_snake_case(void){
enable_xcase_with(KC_UNDS);
 snake_case_active = true;
}

void enable_camel_case(void){
    enable_xcase_with(OSM(MOD_LSFT));
    camel_case_active = true;
}

void enable_kebab_case(void){
                 enable_xcase_with(KC_MINS);
                 kebab_case_active = true;
}

void enable_screaming_snake_case(void){
                 if (!is_caps_word_on()){
                     caps_word_on();
                 }
                 enable_xcase_with(KC_UNDS);
                 screaming_snake_case_active = true;
}

process_record_result_t process_case_mode_keycodes(uint16_t keycode, const keyrecord_t *record){
    switch (keycode) {
        case SNAKECASE:
             if (record->event.pressed) {
                 enable_snake_case();
             }
             return PROCESS_RECORD_RETURN_FALSE;
        case CAMELCASE:
             if (record->event.pressed){
                 enable_xcase_with(OSM(MOD_LSFT));
             }
             return PROCESS_RECORD_RETURN_FALSE;
        case KEBABCASE:
             if (record->event.pressed){
                 enable_xcase_with(KC_MINS);
             }
             return PROCESS_RECORD_RETURN_FALSE;
        case SCREAMINGSNAKECASE:
             if (record->event.pressed){
                 if (!is_caps_word_on()){
                     caps_word_on();
                 }
                 enable_snake_case();
             }
             return PROCESS_RECORD_RETURN_FALSE;
    }
     return PROCESS_RECORD_CONTINUE;
}

bool is_snake_case_active  (void){
    return snake_case_active ;
}
bool is_kebab_case_active  (void){
    return kebab_case_active ;
}
bool is_camel_case_active  (void){
    return camel_case_active ;
}
bool is_screaming_snake_case_active (void){
    return screaming_snake_case_active ;
}
