#ifndef VESC_UART_H
#define VESC_UART_H

#include <stdint.h>

// VESC串口协议相关常量
#define VESC_UART_BAUDRATE 115200
#define VESC_MAX_PAYLOAD 64

// 兼容VESC 6.05+，可根据最新协议扩展
typedef struct {
	float speed_rpm;
	float voltage;
	float current;
	float amp_hours;
	float amp_hours_charged;
	float watt_hours;
	float watt_hours_charged;
	float tachometer;
	float tachometer_abs;
	float temperature_mos;
	float temperature_motor;
	float odometer_km;
	uint8_t fault_code;
} vesc_data_t;

extern vesc_data_t g_vesc_data;

void vesc_uart_init(void);
void vesc_uart_poll(void);
int vesc_uart_send_request(void);
int vesc_uart_parse_packet(const uint8_t* buf, uint16_t len);

#endif // VESC_UART_H