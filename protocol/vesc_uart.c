
#include "vesc_uart.h"
#include <string.h>

vesc_data_t g_vesc_data;

// 伪代码：实际需用HAL/LL库或裸机实现
void vesc_uart_init(void) {
    // 初始化USART1，波特率115200，8N1
}

// 发送请求帧，获取VESC数据
int vesc_uart_send_request(void) {
    // 发送最新VESC 6.05+兼容的请求帧
    return 0;
}

// 解析VESC串口返回数据包
int vesc_uart_parse_packet(const uint8_t* buf, uint16_t len) {
    // 解析协议帧，填充g_vesc_data
    // 兼容VESC 6.05+，如COMM_GET_VALUES等
    return 0;
}

// 轮询接收与解析
void vesc_uart_poll(void) {
    uint8_t rx_buf[VESC_MAX_PAYLOAD];
    uint16_t rx_len = 0;
    // 伪代码：接收串口数据到rx_buf, rx_len
    // if (rx_len > 0) {
    //     vesc_uart_parse_packet(rx_buf, rx_len);
    // }
}
