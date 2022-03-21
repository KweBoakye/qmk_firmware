#include "analog_joystick_logic.h"


void analog_joystick_logic_init(void) {

    analog_joystick_init();
    analog_joystickTimer       = 0;
    analog_joystickScrollTimer = 0;

    analog_joystick_state.config.mode           = ANALOG_JOYSTICK_MODE_MOUSE;
    analog_joystick_state.config.deadZone       = ANALOG_JOYSTICK_DEAD_ZONE;
    analog_joystick_state.config.fineZone       = ANALOG_JOYSTICK_FINE_ZONE;
    analog_joystick_state.config.speed          = ANALOG_JOYSTICK_SPEED;
    analog_joystick_state.config.fineSpeed      = ANALOG_JOYSTICK_FINE_SPEED;
    analog_joystick_state.config.axisSeparation = ANALOG_JOYSTICK_AXIS_SEPARATION;
    analog_joystick_state.config.eightAxis      = ANALOG_JOYSTICK_EIGHT_AXIS;

#if defined ANALOG_JOYSTICK_DEBUG
    rawX               = 0;
    rawY               = 0;
    distX              = 0;
    distY              = 0;
    analog_joystickLogTimer = 0;
#endif
}

analog_joystick_direction_t scrollDirection;  // Declaring global to save stack space

void analog_joystick_mode_set(analog_joystick_mode_t mode) { analog_joystick_state.config.mode = mode; }

analog_joystick_mode_t analog_joystick_mode_get(void) { return analog_joystick_state.config.mode; }


void analog_joystick_mode_cycle(bool reverse) {
    analog_joystick_mode_t mode = analog_joystick_mode_get();
    if (reverse) {
        mode = (mode == 0) ? (_ANALOG_JOYSTICK_MODE_LAST - 1) : (mode - 1);
    } else {
        mode = (mode == (_ANALOG_JOYSTICK_MODE_LAST - 1)) ? 0 : (mode + 1);
    }
    analog_joystick_mode_set(mode);
}



// Fix direction within one of 8 axes (or 4 if 8-axis is disabled)
analog_joystick_direction_t analog_joystick_get_discretized_direction(report_analog_joystick_t vector, float axisSeparation, bool eightAxis) {
    analog_joystick_direction_t direction;
    uint16_t               absX                = abs(vector.x);
    uint16_t               absY                = abs(vector.y);
    uint16_t               maxComponent        = (absX > absY) ? absX : absY;
    bool                   insideDeadZone      = (maxComponent <= ANALOG_JOYSTICK_DEAD_ZONE);
    bool                   outsideDiagonalZone = ((abs(absX - absY) / (float)maxComponent) >= axisSeparation);
    if (insideDeadZone) {
        direction.up = direction.down = direction.left = direction.right = false;
    } else {
        direction.up    = (vector.y < 0);
        direction.down  = (vector.y > 0);
        direction.left  = (vector.x < 0);
        direction.right = (vector.x > 0);
        // Let only the dominant direction remain under the right conditions
        if (outsideDiagonalZone || !eightAxis) {
            if (absX > absY) {
                direction.up = direction.down = false;
            } else {
                direction.left = direction.right = false;
            }
        }
    }
    return direction;
}


// Axis-level wrapper to read raw value, do logging and calculate speed
int16_t analog_joystick_get_component(uint32_t pin) {
    uint16_t analogValue = analogReadPin(pin);
    // Compute direction
    bool directionIsPositive = (analogValue > ANALOG_JOYSTICK_RANGE_CENTER);
    // Compute distance from the center
    uint16_t distance = directionIsPositive ? (analogValue - ANALOG_JOYSTICK_RANGE_CENTER) : (ANALOG_JOYSTICK_RANGE_CENTER - analogValue);
#if defined ANALOG_JOYSTICK_DEBUG
    if (pin == ANALOG_JOYSTICK_X_AXIS_PIN) {
        rawX  = analogValue;
        distX = distance;
    } else {
        rawY  = analogValue;
        distY = distance;
    }
#endif
    // Compute component (range of [0 to 1023])
    return directionIsPositive ? distance : -(int16_t)distance;
}


report_mouse_t analog_joystick_get_report(report_mouse_t mouse_report) {
    report_analog_joystick_t data = analog_joystick_read();

    mouse_report.x = data.x;
    mouse_report.y = data.y;

    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, data.button, POINTING_DEVICE_BUTTON1);

    return mouse_report;
}

void update_keycode_status(uint16_t keycode, bool last, bool current) {
    if (last != current) {
        if (current) {
            register_code16(keycode);
        } else {
            unregister_code16(keycode);
        }
    }
}

report_mouse_t analog_joystick_pointing_device_task(report_mouse_t mouse_report){
 report_mouse_t analog_joystick_report;
     switch (analog_joystick_state.config.mode) {
            case ANALOG_JOYSTICK_MODE_MOUSE:

          analog_joystick_report = analog_joystick_get_report(mouse_report);
                mouse_report.x = analog_joystick_report.x;
                mouse_report.y = analog_joystick_report.y;
/* #ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Raw (%d, %d); Dist (%u, %u); Vec (%d, %d);\n", rawX, rawY, distX, distY, analog_joystick_state.vector.x, analog_joystick_state.vector.y);
                }
#endif */
                break;
            case ANALOG_JOYSTICK_MODE_ARROWS:
            analog_joystick_state.vector.x = analog_joystick_get_component(ANALOG_JOYSTICK_X_AXIS_PIN);
            analog_joystick_state.vector.y = analog_joystick_get_component(ANALOG_JOYSTICK_Y_AXIS_PIN);

             analog_joystick_state.direction = analog_joystick_get_discretized_direction(analog_joystick_state.vector, analog_joystick_state.config.axisSeparation, analog_joystick_state.config.eightAxis);
                update_keycode_status(KC_UP, analog_joystick_state.lastDirection.up, analog_joystick_state.direction.up);
                update_keycode_status(KC_DOWN, analog_joystick_state.lastDirection.down, analog_joystick_state.direction.down);
                update_keycode_status(KC_LEFT, analog_joystick_state.lastDirection.left, analog_joystick_state.direction.left);
                update_keycode_status(KC_RIGHT, analog_joystick_state.lastDirection.right, analog_joystick_state.direction.right);
                analog_joystick_state.lastDirection = analog_joystick_state.direction;
#ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Up %d; Down %d; Left: %d; Right %d; Vec (%d, %d);\n", direction.up, direction.down, direction.left, direction.right, analog_joystick_state.vector.x, analog_joystick_state.vector.y);
                }
#endif
                break;
            case ANALOG_JOYSTICK_MODE_SCROLL:
            if (timer_elapsed(analog_joystickScrollTimer) > ANALOG_JOYSTICK_SCROLL_TIMEOUT) {
                analog_joystick_state.vector.x = analog_joystick_get_component(ANALOG_JOYSTICK_X_AXIS_PIN);
                analog_joystick_state.vector.y = analog_joystick_get_component(ANALOG_JOYSTICK_Y_AXIS_PIN);
                    analog_joystickScrollTimer     = timer_read();
                    scrollDirection           = analog_joystick_get_discretized_direction(analog_joystick_state.vector, analog_joystick_state.config.axisSeparation, false);
                    analog_joystick_state.report.v = (scrollDirection.up || scrollDirection.down) ? (scrollDirection.up ? ANALOG_JOYSTICK_SCROLL_SPEED : -ANALOG_JOYSTICK_SCROLL_SPEED) : 0;
                    analog_joystick_state.report.h = (scrollDirection.left || scrollDirection.right) ? (scrollDirection.left ? -ANALOG_JOYSTICK_SCROLL_SPEED : ANALOG_JOYSTICK_SCROLL_SPEED) : 0;
                } else {
                    analog_joystick_state.report.v = analog_joystick_state.report.h = 0;
                }
                mouse_report.v = analog_joystick_state.report.v;
                mouse_report.h = analog_joystick_state.report.h;
#ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Scroll (%d, %d)\n", mouse_report.h, mouse_report.v);
                }
#endif
                break;
            default:
                break;
        }

        #ifdef ANALOG_JOYSTICK_CLICK_PIN
          bool click = !readPin(ANALOG_JOYSTICK_CLICK_PIN);
          mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, click, POINTING_DEVICE_BUTTON1);
        #endif

        return mouse_report;

}

process_record_result_t process_record_analog_joystick(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AJS_MODE:
            if (record->event.pressed) {
                analog_joystick_mode_cycle(false);
            }
    }
    return PROCESS_RECORD_CONTINUE;
}
