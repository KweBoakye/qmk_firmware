#include "quantum.h"
#include "ST7789_logic.h"
#include "color.h"
#include "../graphics/rotating_hand.qgf.h"
#include "../fonts/Microgramma_Normal.qff.h"


 painter_device_t display;
 static painter_image_handle_t my_image;
 static painter_font_handle_t microgramma_normal;
static deferred_token my_anim;
void keyboard_post_init_kb_display(void) {
 setPinOutput(DISPLAY_POWER_ENABLE_PIN);
    writePinHigh(DISPLAY_POWER_ENABLE_PIN);

    // Let the LCD get some power...
    wait_ms(150);

    display = qp_st7789_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 3);      // Create the display
    qp_init(display, QP_ROTATION_90);   // Initialise the display

    qp_power(display, true);
  qp_rect(display, 0, 0, 239, 239, HSV_BLACK, true);

   backlight_enable();
    backlight_level(BACKLIGHT_LEVELS);

microgramma_normal = qp_load_font_mem(font_Microgramma_Normal);
    if (microgramma_normal != NULL) {
        static const char *text = "WELCOME TO THE WORLD";
        int16_t width = qp_textwidth(microgramma_normal, text);
        qp_drawtext(display, 0, 0, microgramma_normal, text);
    }

    my_image = qp_load_image_mem(gfx_rotating_hand);
    if (my_image != NULL) {
        my_anim = qp_animate(display, (239 - my_image->width), (239 - my_image->height), my_image);
    }
}

//static uint8_t last_backlight = 255;
void suspend_power_down_user_display(void) {
    qp_power(display, false);
}

void suspend_wakeup_init_user_display(void) {
    qp_power(display, true);

}

void housekeeping_task_display(void) {
 /*    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw a 240px high vertical rainbow line on X=0:
        for (int i = 0; i < 239; ++i) {
            qp_setpixel(display, 0, i, i, 255, 255);
        }
        qp_flush(display);
    } */
}



