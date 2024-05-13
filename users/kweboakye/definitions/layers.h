
#pragma once
#include "quantum.h"

typedef enum user_layers {
  _COLEMAK_MOD_DH = 0,
  _FIRST_DEFAULT_LAYER = 0,
  _QWERTY,
  _COLEMAK_DH_GAMING,
  _QWERTY_GAMING,
  _GAME,
  _LAST_DEFAULT_LAYER = _GAME,
  _SYM,
   _NAV,
   _FN,
   _MAINTENANCE,
   _UNICODE,
   _FUNCTIONS,
   _NUMPAD,
  _MOUSE,
  _MEDIA,
  _GAMING_NUM_LAYER
} layers_t;

layer_state_t get_layer_real_index(layer_state_t state);

const char * layer_to_string(layer_state_t state);


#define COLEMAK_MOD_DH_LAYER_STRING "Colemak DH"
#define QWERTY_LAYER_STRING "Qwerty"
#define COLEMAK_DH_GAMING_LAYER_STRING "Clmk DH Gm"
#define QWERTY_GAMING_LAYER_STRING "Qwerty Gm"
#define GAME_LAYER_STRING "Game"
#define SYM_LAYER_STRING "Symbol"
#define NAV_LAYER_STRING "Navigtion"
#define FN_LAYER_STRING "Function" 
#define NUMPAD_LAYER_STRING "Numpad" 
#define MOUSE_LAYER_STRING "Mouse" 
#define FUNCTIONS_LAYER_STRING "Functions" 
#define MEDIA_LAYER_STRING "Media" 
#define MAINTENANCE_LAYER_STRING "Maintainance" 
#define UNICODE_LAYER_STRING "Unicode" 