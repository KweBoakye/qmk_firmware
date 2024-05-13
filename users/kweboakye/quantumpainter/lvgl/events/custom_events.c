#include "custom_events.h"




void register_event_ids(void){
CUSTOM_EVENT_LAYER_CHANGE = lv_event_register_id();
CUSTOM_EVENT_MOD_STATE_CHANGE_CTRL = lv_event_register_id();
CUSTOM_EVENT_MOD_STATE_CHANGE_SHIFT = lv_event_register_id();
CUSTOM_EVENT_MOD_STATE_CHANGE_ALT = lv_event_register_id();
CUSTOM_EVENT_MOD_STATE_CHANGE_GUI = lv_event_register_id();
CUSTOM_EVENT_ONESHOT_STATE_CHANGE_CTRL = lv_event_register_id();
CUSTOM_EVENT_ONESHOT_STATE_CHANGE_SHIFT = lv_event_register_id();
CUSTOM_EVENT_ONESHOT_STATE_CHANGE_ALT = lv_event_register_id();
CUSTOM_EVENT_ONESHOT_STATE_CHANGE_GUI = lv_event_register_id();
CUSTOM_EVENT_CAPS_LOCK_ON = lv_event_register_id();
CUSTOM_EVENT_CAPS_LOCK_OFF = lv_event_register_id();
CUSTOM_EVENT_NUM_LOCK_ON = lv_event_register_id();
CUSTOM_EVENT_NUM_LOCK_OFF = lv_event_register_id();
CUSTOM_EVENT_SCROLL_LOCK_ON = lv_event_register_id();
CUSTOM_EVENT_SCROLL_LOCK_OFF = lv_event_register_id();
CUSTOM_EVENT_CAPS_WORD_ON = lv_event_register_id();
CUSTOM_EVENT_CAPS_WORD_OFF = lv_event_register_id();
CUSTOM_EVENT_HAPTIC_STATE_CHANGE = lv_event_register_id();
CUSTOM_EVENT_HAPTIC_MODE_CHANGE = lv_event_register_id();
}