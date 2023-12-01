#pragma once
#include QMK_KEYBOARD_H

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



#define OPEN_O UP(OPEN_O_LOWER_CASE, OPEN_O_UPPER_CASE)
#define OPEN_E UP(OPEN_E_LOWER_CASE, OPEN_E_UPPER_CASE)
#endif