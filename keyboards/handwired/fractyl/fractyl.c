#include "fractyl.h"

const is31_led __flash g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |        G location
 *   |  |        |        B location
 *   |  |        |        | */
    {0, CS1_SW1, CS2_SW1, CS3_SW1}
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   1, NO_LED, NO_LED,   NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {   NO_LED, NO_LED, NO_LED,   NO_LED },
  {   NO_LED, NO_LED, NO_LED,   NO_LED }
}, {
  // LED Index to Physical Position
  { 188,  16 }
}, {
  // LED Index to Flag
  41
} };