#ifndef LV_MEM_MAN_H
#define LV_MEM_MAN_H

#include "lvgl/lvgl.h"

void container_deleted_free_data(lv_event_t* event);
void container_deleted_del_timer(lv_event_t* event);


#endif
