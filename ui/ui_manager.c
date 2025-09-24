
#include "ui_manager.h"
#include "display_ili9225.h"
#include "vesc_uart.h"
#include <string.h>

static ui_style_t g_ui_style = UI_STYLE_DEFAULT;
static unit_system_t g_unit = UNIT_METRIC;
static temp_unit_t g_temp_unit = TEMP_C;
static lang_t g_lang = LANG_CHINESE;

void ui_init(void) {
    g_ui_style = UI_STYLE_DEFAULT;
    g_unit = UNIT_METRIC;
    g_temp_unit = TEMP_C;
    g_lang = LANG_CHINESE;
    display_fill(0xFFFF); // 白色清屏
}

void ui_set_style(ui_style_t style) {
    g_ui_style = style;
    // 可立即刷新界面
}

void ui_set_unit(unit_system_t unit) {
    g_unit = unit;
}

void ui_set_temp_unit(temp_unit_t temp_unit) {
    g_temp_unit = temp_unit;
}

void ui_set_language(lang_t lang) {
    g_lang = lang;
}


static uint8_t g_screen_idx = 0;
static const uint8_t SCREEN_MAX = 3;

static void draw_main_screen(void) {
    // 速度、里程、电压等主界面
    // 伪代码：display_draw_string(...)
}
static void draw_battery_screen(void) {
    // 电池电量、消耗、充电等
}
static void draw_fault_screen(void) {
    // 故障码、温度等
}

void ui_next_screen(void) {
    g_screen_idx = (g_screen_idx + 1) % SCREEN_MAX;
}

void ui_update(void) {
    switch (g_screen_idx) {
        case 0: draw_main_screen(); break;
        case 1: draw_battery_screen(); break;
        case 2: draw_fault_screen(); break;
        default: draw_main_screen(); break;
    }
}
