#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <stdint.h>

typedef struct {
	float odometer;      // 总里程
	float amp_hours;     // 总耗电量
	float amp_hours_chg; // 总充电量
	uint32_t save_flag;  // 校验标志
} store_data_t;

extern store_data_t g_store_data;

void data_store_init(void);
void data_store_periodic(void);
void data_store_save(void);
void data_store_load(void);

#endif // DATA_STORE_H