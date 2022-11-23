# Cradio keyboards

<<<<<<< HEAD
![Cradio](https://raw.githubusercontent.com/filterpaper/filterpaper.github.io/main/images/cradio.png)

Cradio are minimalist 34-key split-keyboards designed with no diodes, using direct micro-controller pin wiring.

## Keyboard Info

* Keyboard Maintainer: [David Barr](https://github.com/davidphilipbarr)
* Hardware Supported:
    * [Cradio](https://github.com/davidphilipbarr/36keys/tree/master/34Keys)
    * [Sweep](https://github.com/davidphilipbarr/Sweep)
    * [Hypergolic](https://github.com/davidphilipbarr/hypergolic)
    * Variants of the same 34-key direct pin PCB
* Hardware Availability: order PCBs using gerber files from the repository
=======
![Cradio](https://github.com/davidphilipbarr/hypergolic/raw/main/hypergarlic/ht.png)

Cradio are low-profile 34-key split-keyboards designed by [@davidphilipbarr](https://github.com/davidphilipbarr), with no diodes and direct micro-controller pin wiring.

## Keyboard Info

* Keyboard Maintainer: [davidphilipbarr](https://github.com/davidphilipbarr)
* Hardware Supported:
    * [Cradio](https://github.com/davidphilipbarr/36keys/tree/master/34Keys)
    * [Sweep](https://github.com/davidphilipbarr/Sweep)
    * [Hypergarlic](https://github.com/davidphilipbarr/hypergolic/tree/main/hypergarlic)
    * [Paroxysm](https://github.com/davidphilipbarr/hypergolic/tree/main/paroxysm)
    * Variants of the same 34-key direct pin PCB
* Hardware Availability: order PCBs with gerber files from the repository
>>>>>>> c0de397925 (merge bedore pointerwork)

Make example for this keyboard (after setting up your build environment):

    make cradio:default

<<<<<<< HEAD
### RP2040 Controllers

Pro Micro RP2040 controllers are supported with [QMK Converters](https://docs.qmk.fm/#/feature_converters). The make command example for Adafruit's KB2040 are:

    make CONVERT_TO=kb2040 cradio:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
=======
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Setting Handedness

Firmware uses [handedness by EEPROM](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom) as default and it must be *configured once* on each side. The make commands are:

    make cradio:default:dfu-split-left
    make cradio:default:dfu-split-right

[QMK Toolbox](http://qmk.fm/toolbox) can also be used to set EEPROM handedness. Place the controller in bootloader mode and select menu option Tools -> EEPROM -> Set Left/Right Hand
>>>>>>> c0de397925 (merge bedore pointerwork)

## Bootloader

Enter the bootloader in 3 ways:

<<<<<<< HEAD
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is configured.
* **Physical reset button**: Briefly press the reset button soldered on the PCB.
* **Bootmagic reset**: Hold down the top left key on the left half (or the top right key on the right half) and plug in the controller on that side.
=======
* **Bootmagic reset**: Hold down the top left key on the left half (or the top right right key on the right half) and plug in the controller on that side.
* **Physical reset button**: Briefly press the reset button soldered on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET` if it is configured.

## Swapped Pins

If you have one of the PCB variant with swapped letters `Q` and `B` / `P` and `N`, add the following code to your keymap's `config.h` to swap pins `E6` and `D7` in the firmware:
```c
#undef DIRECT_PINS
#define DIRECT_PINS { \
    { D7, F7, F6, F5, F4 }, \
    { B1, B3, B2, B6, D3 }, \
    { D1, D0, D4, C6, E6 }, \
    { B4, B5, NO_PIN, NO_PIN, NO_PIN } \
}
#undef DIRECT_PINS_RIGHT
#define DIRECT_PINS_RIGHT { \
    { F4, F5, F6, F7, D7 }, \
    { D3, B6, B2, B3, B1 }, \
    { E6, C6, D4, D0, D1 }, \
    { B5, B4, NO_PIN, NO_PIN, NO_PIN } \
}
```
>>>>>>> c0de397925 (merge bedore pointerwork)

