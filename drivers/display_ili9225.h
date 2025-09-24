#ifndef DISPLAY_ILI9225_H
#define DISPLAY_ILI9225_H

#include <stdint.h>

// ILI9225 屏幕引脚定义（可根据实际硬件修改）
#define TFT_CS_PIN    GPIO_PIN_4  // PA4
#define TFT_RST_PIN   GPIO_PIN_3  // PA3
#define TFT_RS_PIN    GPIO_PIN_2  // PA2
#define TFT_LED_PIN   GPIO_PIN_1  // PA1
#define TFT_SCK_PIN   GPIO_PIN_5  // PA5
#define TFT_MOSI_PIN  GPIO_PIN_7  // PA7
#define TFT_MISO_PIN  GPIO_PIN_6  // PA6

void display_init(void);
void display_set_backlight(uint8_t percent); // 背光调节
void display_fill(uint16_t color);
void display_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
void display_draw_string(uint16_t x, uint16_t y, const char* str, uint16_t color, uint8_t size);

#endif // DISPLAY_ILI9225_H