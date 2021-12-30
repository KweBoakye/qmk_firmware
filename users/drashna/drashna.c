// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "drashna.h"

userspace_config_t userspace_config;

/**
 * @brief Handle registering a keycode, with optional modifer based on timed event
 *
 * @param code keycode to send to host
 * @param mod_code modifier to send with code, if held for tapping term or longer
 * @param pressed the press/release event (can use "record->event.pressed" for this)
 * @return true exits function
 * @return false exits function
 */
bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    mod_key_press(code, mod_code, pressed, this_timer);
    return false;
}

/**
 * @brief Handle registation of keycode, with optional modifier based on custom timer
 *
 * @param code keycode to send to host
 * @param mod_code modifier keycode to send with code, if held for tapping term or longer
 * @param pressed the press/release event
 * @param this_timer custom timer to use
 * @return true
 * @return false
 */
bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

/**
 * @brief Performs exact match for modifier values
 *
 * @param value the modifer varible (get_mods/get_oneshot_mods/get_weak_mods)
 * @param mask the modifier mask to check for
 * @return true Has the exact modifiers specifed
 * @return false Does not have the exact modifiers specified
 */
bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}

/**
 * @brief Tap keycode, with no mods
 *
 * @param kc keycode to use
 */
void tap_code16_nomods(uint16_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

<<<<<<< HEAD
#ifdef I2C_SCANNER_ENABLE
#    include "i2c_master.h"
#    include "debug.h"

#    ifndef I2C_SCANNER_TIMEOUT
#        define I2C_SCANNER_TIMEOUT 50
#    endif
=======
#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_update_pwm_buffers(void);
#endif

__attribute__((weak)) void shutdown_keymap(void) {}
void                       shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
#endif  // RGB_MATRIX_ENABLE
#ifdef OLED_ENABLE
    oled_off();
#endif

    shutdown_keymap();
}
>>>>>>> c0de397925 (merge bedore pointerwork)

i2c_status_t i2c_start_bodge(uint8_t address, uint16_t timeout) {
    i2c_start(address);

    // except on ChibiOS where the only way is do do "something"
    uint8_t data = 0;
    return i2c_readReg(address, 0, &data, sizeof(data), I2C_SCANNER_TIMEOUT);
}

#    define i2c_start i2c_start_bodge

void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_start to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_start(address << 1, I2C_SCANNER_TIMEOUT);
        if (error == I2C_STATUS_SUCCESS) {
            i2c_stop();
            xprintf("  I2C device found at address 0x%02X\n", I2C_SCANNER_TIMEOUT);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        xprintf("No I2C devices found\n");
    else
        xprintf("done\n");
}

uint16_t scan_timer = 0;

void matrix_scan_i2c(void) {
    if (timer_elapsed(scan_timer) > 5000) {
        do_scan();
        scan_timer = timer_read();
    }
}

void keyboard_post_init_i2c(void) {
    i2c_init();
    scan_timer = timer_read();
}
#endif

__attribute__((weak)) uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

__attribute__((weak)) bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is tapped:
    // return true;
    // Do not select the hold action when another key is tapped.
    // return false;
    switch (keycode) {
        default:
            return false;
    }
}

__attribute__((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is pressed.
    // return true;
    // Do not select the hold action when another key is pressed.
    // return false;
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;
        default:
            return false;
    }
}

__attribute__((weak)) bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    // return true;
    // Force the mod-tap key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    // return false;
    switch (keycode) {
        default:
            return true;
    }
}

__attribute__((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}

__attribute__((weak)) bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}
