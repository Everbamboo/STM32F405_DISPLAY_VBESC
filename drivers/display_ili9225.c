
#include "display_ili9225.h"
#include "board.h"
#include <string.h>

// 伪代码：实际需根据HAL/LL库或裸机实现
static void ili9225_write_cmd(uint16_t cmd) {
    // TODO: SPI发送命令
}
static void ili9225_write_data(uint16_t data) {
    // TODO: SPI发送数据
}

void display_init(void) {
    // SPI与GPIO初始化（由board_init调用或此处实现）
    // 复位
    // 配置ILI9225寄存器，初始化屏幕
    // 清屏
}

void display_set_backlight(uint8_t percent) {
    // PWM调节背光亮度
}

void display_fill(uint16_t color) {
    // 全屏填充指定颜色
}

void display_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
    // 画点
}

void display_draw_string(uint16_t x, uint16_t y, const char* str, uint16_t color, uint8_t size) {
    // 字符串显示（需字库支持）
}
