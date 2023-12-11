#ifndef FIRE_H
#define FIRE_H
#include "lvgl/lvgl.h"


#define FIRE_BARS_COUNT (3) //reserved for future, do not touch
#define DEFAULT_HEIGHT (20)
#define DEFAULT_WIDTH (15)
#define DEFAULT_BAR_WIDTH (3)

//contains structure allocated by lv_malloc. Deletes itself on parent destruction.
lv_obj_t* fire_widget_create(lv_obj_t* parent);

lv_obj_t* fire_set_size(lv_obj_t* fire, int container_width, int container_height, int bar_width);

void fire_widget_start(lv_obj_t* container);
void fire_widget_stop(lv_obj_t* container);



#endif
