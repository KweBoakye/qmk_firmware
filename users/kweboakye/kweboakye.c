#include "kweboakye.h"
#include "haptic.h"
#include "transactions.h"

//  #ifdef UNICODEMAP_ENABLE
//  #    include "keyrecords/user_unicode.h"
//  #endif

userspace_config_t userspace_config;
//extern os_t os;

#ifdef drv2605l
extern haptic_config_t haptic_config;
extern bool should_send_haptic;
#endif

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record){
     if(get_tapping_force_hold_result(keycode)){
        return 0;
     } else {
        return QUICK_TAP_TERM;
     }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_term_result(keycode);
}

#ifdef AUDIO_ENABLE
#    ifndef GOODBYE_SONG
#        define GOODBYE_SONG SONG(GOODBYE_SOUND)
#    endif
float reset_song[][2] = GOODBYE_SONG;
#endif



/* bool get_retro_tapping(uint16_t keycode, keyrecord_t *record){
    return get_retro_tapping_result(keycode);
} */




/* bool check_side_to_buzz(uint16_t keycode, keyrecord_t *record){
    if(is_keyboard_left()){
    if(record->event.key.row > (MATRIX_ROWS / 2)){
        send_haptic(keycode, record);
       return false;
    } else {
        return true;
    }
    } else {
        if(record->event.key.row <= (MATRIX_ROWS / 2)){
        send_haptic(keycode, record);
        return false;
        } else {
        return true;
    }
    }
} */

#ifdef HAPTIC_ENABLE

bool  get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record){

//  #if defined(drv2605l) && defined(SPLIT_HAPTIC_ENABLE)
//   if(get_haptic_enabled_key_custom(keycode, record)){
//    /*  if(check_is_both_hand_combo(keycode)){
//         send_haptic(haptic_config.mode);
//         return true;
//     } */
//     if(should_primary_send_haptic(keycode, record)){
//      // send_haptic(haptic_config.mode);
//      should_send_haptic = true;
//     } else {
//         return true;
//     }
//   }
//   return false;
//   #else

// return get_haptic_enabled_key_custom(keycode, record);
//   #endif
  return get_haptic_enabled_key_custom(keycode, record);
}
#endif


void software_reset(void) {
    clear_keyboard();
#if defined(MIDI_ENABLE) && defined(MIDI_BASIC)
    process_midi_all_notes_off();
#endif
#ifdef AUDIO_ENABLE
#    ifndef NO_MUSIC_MODE
    music_all_notes_off();
#    endif
    uint16_t timer_start = timer_read();
    PLAY_SONG(reset_song);
    shutdown_user(false);
    while (timer_elapsed(timer_start) < 250) wait_ms(1);
    stop_all_notes();
#else
    shutdown_user(false);
    wait_ms(250);
#endif
#ifdef HAPTIC_ENABLE
    haptic_shutdown();
#endif

#if defined(PROTOCOL_LUFA)
    wdt_enable(WDTO_250MS);
#elif defined(PROTOCOL_CHIBIOS)
#    if defined(MCU_STM32) || defined(MCU_KINETIS)
    NVIC_SystemReset();
#    endif
#endif
}
