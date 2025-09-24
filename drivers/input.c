
#include "input.h"
#include <string.h>

static button_callback_t g_btn_cb = 0;

void input_init(void) {
    // 初始化PB0/PB1/PB2为输入，带上拉
}

void input_set_callback(button_callback_t cb) {
    g_btn_cb = cb;
}

void input_poll(void) {
    // 伪代码：扫描PB0/PB1/PB2，做防抖，判断短按/长按
    // 检测到事件后 if (g_btn_cb) g_btn_cb(btn, evt);
}
