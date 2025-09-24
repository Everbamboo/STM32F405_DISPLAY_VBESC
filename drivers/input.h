#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

typedef enum {
	BUTTON_1 = 0, // PB0
	BUTTON_2,     // PB1
	BUTTON_3,     // PB2
	BUTTON_MAX
} button_id_t;

typedef enum {
	BUTTON_EVENT_NONE = 0,
	BUTTON_EVENT_SHORT_PRESS,
	BUTTON_EVENT_LONG_PRESS
} button_event_t;

typedef void (*button_callback_t)(button_id_t btn, button_event_t evt);

void input_init(void);
void input_poll(void);
void input_set_callback(button_callback_t cb);

#endif // INPUT_H