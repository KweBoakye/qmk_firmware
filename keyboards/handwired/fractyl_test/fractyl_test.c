
#include "fractyl_test.h"



#if RGB_MATRIX_ENABLE
// clang-format off
const is31_led __flash g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |        G location
 *   |  |        |        B location
 *   |  |        |        | */
    {0, CS18_SW1, CS17_SW1, CS16_SW1},
    {0, CS18_SW2, CS17_SW2, CS16_SW2},
    {0, CS18_SW3, CS17_SW3, CS16_SW3},
    {0, CS18_SW4, CS17_SW4, CS16_SW4},
    {0, CS18_SW5, CS17_SW5, CS16_SW5},

    {0, CS15_SW1, CS14_SW1, CS13_SW1},
    {0, CS15_SW2, CS14_SW2, CS13_SW2},
    {0, CS15_SW3, CS14_SW3, CS13_SW3},
    {0, CS15_SW4, CS14_SW4, CS13_SW4},
    {0, CS15_SW5, CS14_SW5, CS13_SW5},

    {0, CS12_SW1, CS11_SW1, CS10_SW1},
    {0, CS12_SW2, CS11_SW2, CS10_SW2},
    {0, CS12_SW3, CS11_SW3, CS10_SW3},
    {0, CS12_SW4, CS11_SW4, CS10_SW4},
    {0, CS12_SW5, CS11_SW5, CS10_SW5},

    {0, CS9_SW1, CS8_SW1, CS7_SW1},
    {0, CS9_SW2, CS8_SW2, CS7_SW2},
    {0, CS9_SW3, CS8_SW3, CS7_SW3},

};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  //Left Hand

  //Right hand
  
  {0, 1, 2 , 3, 4},
  {5, 6, 7, 8, 9},
  {10,11, 12, 13, 14},
  {15, 16, 17, NO_LED, NO_LED},
  
}, {
  // LED Index to Physical Position
  //Left Hand

//Right Hand
{34.38, 7.84}, {80.81, 5.21}, {126.10, 0.00}, {172.93, 7.41}, {224.00, 14.71},
{32.75, 23.15}, {82.57, 20.52}, {123.70, 15.38}, {168.14, 23.15}, {213.99, 31.03},
{41.70, 38.45}, {89.41, 35.82}, {126.10, 30.76}, {168.48, 38.88}, {210.03, 47.34},
{0.00, 64.00}, {45.19, 53.86}, {94.08, 47.72}
}, {
  // LED Index to Flag

  //Right hand
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4

} };

// clang-format on

#endif

