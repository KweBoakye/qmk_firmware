#pragma once

#include "timer.h"
#include "analog.h"
#include "pointing_device.h"
#include "kweboakye.h"
#include "drivers/sensors/analog_joystick.h"



typedef enum {
    ANALOG_JOYSTICK_MODE_MOUSE = 0,
    ANALOG_JOYSTICK_MODE_ARROWS,
    ANALOG_JOYSTICK_MODE_SCROLL,
    _ANALOG_JOYSTICK_MODE_LAST  // Do not use, except for looping through enum values
} analog_joystick_mode_t;


// Parameters
#define ANALOG_JOYSTICK_DEAD_ZONE 90   // Values below this are ignored (deadzone)
#define ANALOG_JOYSTICK_FINE_ZONE 180  // Values below this enable fine movement

#define ANALOG_JOYSTICK_MODE ANALOG_JOYSTICK_MODE_MOUSE
#define ANALOG_JOYSTICK_SPEED 256
#define ANALOG_JOYSTICK_FINE_SPEED 96
#define ANALOG_JOYSTICK_SCROLL_SPEED 1

#define ANALOG_JOYSTICK_EIGHT_AXIS true
#define ANALOG_JOYSTICK_AXIS_SEPARATION 0.5f

// Implicit and derived constants
#define ANALOG_JOYSTICK_TIMEOUT 10          // Mouse report throttling time in ms
#define ANALOG_JOYSTICK_SCROLL_TIMEOUT 200  // Mouse scroll throttling time in ms
#define ANALOG_JOYSTICK_RANGE_CENTER (ANALOG_JOYSTICK_AXIS_MIN - ANALOG_JOYSTICK_AXIS_MAX + 1) / 2





typedef struct {
    analog_joystick_mode_t mode;
    uint16_t          deadZone;
    uint16_t          fineZone;
    uint16_t          speed;
    uint16_t          fineSpeed;
    float             axisSeparation;
    bool              eightAxis;
} analog_joystick_config_t;

typedef struct {
    bool up;
    bool right;
    bool down;
    bool left;
} analog_joystick_direction_t;

typedef struct {
    int16_t x;
    int16_t y;
} analog_joystick_vector_t;



typedef struct {
    analog_joystick_config_t    config;
    report_analog_joystick_t    vector;
    analog_joystick_direction_t direction;
    analog_joystick_direction_t lastDirection;
    report_mouse_t         report;
} analog_joystick_state_t;

uint16_t analog_joystickTimer;
uint16_t analog_joystickScrollTimer;


report_mouse_t analog_joystick_pointing_device_task(report_mouse_t mouse_report);

analog_joystick_state_t analog_joystick_state;

void analog_joystick_mode_set(analog_joystick_mode_t mode);

analog_joystick_mode_t analog_joystick_mode_get(void);

void analog_joystick_mode_cycle(bool reverse);

void analog_joystick_logic_init(void);

// Axis-level wrapper to read raw value, do logging and calculate speed
int16_t analog_joystick_get_component(uint32_t pin);

// Fix direction within one of 8 axes (or 4 if 8-axis is disabled)
analog_joystick_direction_t analog_joystick_get_discretized_direction(report_analog_joystick_t vector, float axisSeparation, bool eightAxis);

//void analog_joystick_process(void);

void update_keycode_status(uint16_t keycode, bool last, bool current);

process_record_result_t process_record_analog_joystick(uint16_t keycode, keyrecord_t *record);

