# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

SPLIT_KEYBOARD = yes
SWAP_HANDS_ENABLE = yes

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

OLED_ENABLE = no
ENCODER_ENABLE = no

#HAPTIC FEEBACK
HAPTIC_ENABLE = yes
HAPTIC_DRIVER = drv2605l


#PER KEY RGB
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes      # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
RGB_MATRIX_DRIVER = ws2812  # RGB matrix driver support
RGB_MATRIX_SUPPORTED = yes

#AUDIO
AUDIO_ENABLE = no
#MUSIC_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
ENCODER_ENABLE = no

PIN_COMPATIBLE = elite_c
CONVERT_TO=rp2040_ce
BACKLIGHT_ENABLE = yes