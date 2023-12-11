#ifndef THEME_H
#define THEME_H
#include "lvgl/lvgl.h"

#define DEFAULT_BUTTON_COLOR (0x002040)

extern lv_style_t style_indic;
extern lv_style_t style_zero_width_container;
extern lv_style_t style_big_label;

void theme_init_and_set(void);
void fire_style_init(void);
void zero_width_container_style_init(void);
void style_big_label_init(void);


#endif
