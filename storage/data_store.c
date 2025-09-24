
#include "data_store.h"
#include <string.h>

store_data_t g_store_data;

void data_store_init(void) {
    // 初始化存储（如EEPROM/Flash）
    data_store_load();
}

void data_store_save(void) {
    // 写入Flash/EEPROM，掉电保存
    // g_store_data.save_flag = 0xA5A5A5A5;
}

void data_store_load(void) {
    // 读取Flash/EEPROM，校验save_flag
    // 若无效则清零
}

void data_store_periodic(void) {
    // 定期调用，判断数据有变动则保存
}
