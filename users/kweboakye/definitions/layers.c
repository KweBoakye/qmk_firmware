#include "layers.h"

layer_state_t get_layer_real_index(layer_state_t state){
    if(state <= _LAST_DEFAULT_LAYER){
        return _FIRST_DEFAULT_LAYER;
    } else {
        return state - _LAST_DEFAULT_LAYER;
    }
}

const char * layer_to_string(layer_state_t state){
    switch (get_highest_layer(state))
    {
   case _COLEMAK_MOD_DH:
   return COLEMAK_MOD_DH_LAYER_STRING;
   break;
   case _QWERTY:
   return QWERTY_LAYER_STRING;
   break;
   case _COLEMAK_DH_GAMING:
   return COLEMAK_DH_GAMING_LAYER_STRING;
   break;
   case _QWERTY_GAMING:
   return QWERTY_GAMING_LAYER_STRING;
   break;
   case _GAME:
   return GAME_LAYER_STRING;
   break;
   case _SYM:
   return SYM_LAYER_STRING;
   break;
   case _NAV:
   return NAV_LAYER_STRING;
   break;
   case _FN:
    return FN_LAYER_STRING;
    break;
   case _NUMPAD:
    return NUMPAD_LAYER_STRING ;
   break;
   case _MOUSE:
    return MOUSE_LAYER_STRING;
   break;
   case _FUNCTIONS:
     return FUNCTIONS_LAYER_STRING ;
   break;
   case _MEDIA:
     return MEDIA_LAYER_STRING;
   break;
   case _MAINTENANCE:
    return MAINTENANCE_LAYER_STRING ;
   break;
   case _UNICODE:
    return UNICODE_LAYER_STRING;
   break;
    default:
        return "";
        break;
    }
}