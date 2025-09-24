// 主入口文件
#include "board.h"
#include "display_ili9225.h"
#include "vesc_uart.h"
#include "ui_manager.h"
#include "data_store.h"
#include "input.h"
#include "buzzer_led.h"

int main(void) {
    board_init();
    display_init();
    vesc_uart_init();
    ui_init();
    data_store_init();
    input_init();
    buzzer_led_init();

    while (1) {
        vesc_uart_poll();
        ui_update();
        input_poll();
        data_store_periodic();
    }
}
