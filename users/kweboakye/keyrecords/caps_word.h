// Copyright 2021-2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
// Caps Word, activated by pressing both shift keys at the same time.
//
// This library implements "Caps Word", which is like conventional Caps Lock,
// but automatically disables itself at the end of the word. This is useful for
// typing all-caps identifiers like `MOD_MASK_ALT`.
//
// Caps Word is activated by pressing the left and right shift keys at the same
// time. This way you don't need a dedicated key for using Caps Word. I've
// tested that this works as expected with one-shot mods and Space Cadet Shift.
// If your shift keys are mod-taps, activate Caps Word by holding both shift
// mod-tap keys until the tapping term, release them, then begin typing.
//
// Optionally, Caps Word may be configured to deactivate if the keyboard is idle
// for some time. This is useful to mitigate unintended shifting when you get
// interrupted or switch to the mouse while Caps Word is active. In your
// config.h, define `CAPS_WORD_IDLE_TIMEOUT` with a time in milliseconds:
//
//   #define CAPS_WORD_IDLE_TIMEOUT 5000  // Turn off Caps Word after 5 seconds.
//
// and in your keymap.c, define (or add to) `matrix_scan_user()` as
//
//   void matrix_scan_user(void) {
//     caps_word_task();
//     // Other tasks...
//   }
//
// For full documentation, see
// https://getreuer.info/posts/keyboards/caps-word

#pragma once

#include QMK_KEYBOARD_H

bool caps_word_press_user(uint16_t keycode);


