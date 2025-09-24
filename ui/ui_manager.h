#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <stdint.h>

typedef enum {
	UI_STYLE_DEFAULT = 0,
	UI_STYLE_DARK,
	UI_STYLE_LARGE_FONT,
	UI_STYLE_MAX
} ui_style_t;

typedef enum {
	UNIT_METRIC = 0, // 公制
	UNIT_IMPERIAL     // 英制
} unit_system_t;

typedef enum {
	TEMP_C = 0, // 摄氏
	TEMP_F
} temp_unit_t;

typedef enum {
	LANG_CHINESE = 0,
	LANG_ENGLISH
} lang_t;


void ui_init(void);
void ui_update(void);
void ui_set_style(ui_style_t style);
void ui_set_unit(unit_system_t unit);
void ui_set_temp_unit(temp_unit_t temp_unit);
void ui_set_language(lang_t lang);
void ui_next_screen(void);

#endif // UI_MANAGER_H