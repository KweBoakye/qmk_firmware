#pragma once

#if defined(UNICODEMAP_ENABLE)


enum unicode_names {
    OPEN_O_UPPER_CASE,
    OPEN_O_LOWER_CASE,
    OPEN_E_UPPER_CASE,
    OPEN_E_LOWER_CASE,
    BANG,
    IRONY,
    SNEK
};

const uint32_t unicode_map[] PROGMEM = {
    [OPEN_O_UPPER_CASE] = 0x0186 , // Ɔ
    [OPEN_O_LOWER_CASE] = 0x0254 , // ɔ
    [OPEN_E_UPPER_CASE] = 0x0190 , // Ɛ
    [OPEN_E_LOWER_CASE] = 0x025B, // ɛ
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};

#define OPEN_O XP(OPEN_O_UPPER_CASE, OPEN_O_LOWER_CASE)
#define OPEN_E XP(OPEN_E_UPPER_CASE, OPEN_E_LOWER_CASE)
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE //, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX
//#define UNICODE_CYCLE_PERSIST false
#endif