#ifndef ROTATINGLABEL_H
#define ROTATINGLABEL_H

#include "lvgl/lvgl.h"

//contains structure allocated by lv_malloc. Deletes itself on parent destruction.
lv_obj_t* rotating_label_create(lv_obj_t* parent);

void rotating_label_start(lv_obj_t* container);
void rotating_label_stop(lv_obj_t* container);

#endif
