
#include "fractyl.h"



#if RGB_MATRIX_ENABLE
// clang-format off
const is31fl3743a_led_t PROGMEM g_is31fl3743a_leds[IS31FL3743A_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |        G location
 *   |  |        |        B location
 *   |  |        |        | */
    // {0, CS18_SW1, CS17_SW1, CS16_SW1},
    // {0, CS18_SW2, CS17_SW2, CS16_SW2},
    // {0, CS18_SW3, CS17_SW3, CS16_SW3},
    // {0, CS18_SW4, CS17_SW4, CS16_SW4},
    // {0, CS18_SW5, CS17_SW5, CS16_SW5},
    {0, SW1_CS9, SW1_CS7, SW1_CS8},
    {0, SW2_CS9, SW2_CS7, SW2_CS8},
    {0, SW3_CS9, SW3_CS7, SW3_CS8},
    {0, SW4_CS9, SW4_CS7, SW4_CS8},
    {0, SW5_CS9, SW5_CS7, SW5_CS8},

    {0, SW1_CS11, SW1_CS10, SW1_CS12},
    {0, SW2_CS11, SW2_CS10, SW2_CS12},
    {0, SW3_CS11, SW3_CS10, SW3_CS12},
    {0, SW4_CS11, SW4_CS10, SW4_CS12},
    {0, SW5_CS11, SW5_CS10, SW5_CS12},

    {0, SW1_CS14, SW1_CS13, SW1_CS15},
    {0, SW2_CS14, SW2_CS13, SW2_CS15},
    {0, SW3_CS14, SW3_CS13, SW3_CS15},
    {0, SW4_CS14, SW4_CS13, SW4_CS15},
    {0, SW5_CS14, SW5_CS13, SW5_CS15},

    {0, SW1_CS17, SW1_CS16, SW1_CS18},
    {0, SW2_CS17, SW2_CS16, SW2_CS18},
    {0, SW3_CS17, SW3_CS16, SW3_CS18},

    // {0, CS18_SW1, CS17_SW1, CS16_SW1},
    // {0, CS18_SW2, CS17_SW2, CS16_SW2},
    // {0, CS18_SW3, CS17_SW3, CS16_SW3},
    // {0, CS18_SW4, CS17_SW4, CS16_SW4},
    // {0, CS18_SW5, CS17_SW5, CS16_SW5},

    // {0, CS15_SW1, CS14_SW1, CS13_SW1},
    // {0, CS15_SW2, CS14_SW2, CS13_SW2},
    // {0, CS15_SW3, CS14_SW3, CS13_SW3},
    // {0, CS15_SW4, CS14_SW4, CS13_SW4},
    // {0, CS15_SW5, CS14_SW5, CS13_SW5},

    // {0, CS12_SW1, CS11_SW1, CS10_SW1},
    // {0, CS12_SW2, CS11_SW2, CS10_SW2},
    // {0, CS12_SW3, CS11_SW3, CS10_SW3},
    // {0, CS12_SW4, CS11_SW4, CS10_SW4},
    // {0, CS12_SW5, CS11_SW5, CS10_SW5},

    // {0, CS9_SW1, CS8_SW1, CS7_SW1},
    // {0, CS9_SW2, CS8_SW2, CS7_SW2},
    // {0, CS9_SW3, CS8_SW3, CS7_SW3},
    {0, SW1_CS9, SW1_CS7, SW1_CS8},
    {0, SW2_CS9, SW2_CS7, SW2_CS8},
    {0, SW3_CS9, SW3_CS7, SW3_CS8},
    {0, SW4_CS9, SW4_CS7, SW4_CS8},
    {0, SW5_CS9, SW5_CS7, SW5_CS8},

    {0, SW1_CS11, SW1_CS10, SW1_CS12},
    {0, SW2_CS11, SW2_CS10, SW2_CS12},
    {0, SW3_CS11, SW3_CS10, SW3_CS12},
    {0, SW4_CS11, SW4_CS10, SW4_CS12},
    {0, SW5_CS11, SW5_CS10, SW5_CS12},

    {0, SW1_CS14, SW1_CS13, SW1_CS15},
    {0, SW2_CS14, SW2_CS13, SW2_CS15},
    {0, SW3_CS14, SW3_CS13, SW3_CS15},
    {0, SW4_CS14, SW4_CS13, SW4_CS15},
    {0, SW5_CS14, SW5_CS13, SW5_CS15},

    {0, SW1_CS17, SW1_CS16, SW1_CS18},
    {0, SW2_CS17, SW2_CS16, SW2_CS18},
    {0, SW3_CS17, SW3_CS16, SW3_CS18},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  //Left Hand
  {4, 3, 2, 1, 0},
  {9, 8, 7, 6 ,5},
  {14, 13, 12, 11, 10},
  {NO_LED, NO_LED,17, 16, 15,},
  //Right hand
  {22, 21, 20, 19, 18},
  //{18, 19, 20, 21, 22},
  {27, 26, 25, 24, 23},
  //{23, 24, 25, 26, 27},
  {32, 31, 30, 29, 28},
  //{28, 29, 30, 31, 32},
  {NO_LED,NO_LED, 35, 34, 33}
  //{33, 34, 35, NO_LED, NO_LED}
}, {
  // LED Index to Physical Position
  //Left Hand
  {224.00, 15}, {173, 7}, {126, 0.00}, {81, 5}, {34, 8},
{214, 31}, {168, 23}, {124, 15}, {83, 21}, {33, 23},
{210, 47}, {168, 39}, {126, 31}, {89, 36}, {42, 38},
                                    {94, 48}, {45, 54}, {0.00, 64.00},
//Right Hand
{34, 8}, {81, 5}, {126, 0.00}, {173, 7}, {224.00, 15},
{33, 23}, {83, 21}, {124, 15}, {169, 23}, {214, 31},
{42, 39}, {89, 36}, {126, 31}, {168, 39}, {210, 47},
{0.00, 64.00}, {45, 54}, {94, 48}
}, {
  // LED Index to Flag
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4,
  //Right hand
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4

} };

// clang-format on

#endif

