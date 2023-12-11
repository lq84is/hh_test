#ifndef INDICATOR_H
#define INDICATOR_H
#include "lvgl/lvgl.h"
#include "AuxFunctions/compound_types.h"
#include "AuxFunctions/char_strings.h"

typedef struct {
    size_t size;
    lv_obj_t** indicators;
    const char* name;
} indicator_array_t;


typedef struct {
    uint32_t size;
    indicator_array_t** arrays;
}indicator_arrays_list_t;

typedef struct indicator_entry_s{
    const char* identifier[2];
    translations_t* str_storage;
    val_p data;
    type_tip type;
    void (*widget_setter)(lv_obj_t* obj); //has this entry as its user data
    lv_obj_t* (*creator)(lv_obj_t* parent);
}indicator_entry_t;

typedef struct indicators_list_s {
    const indicator_entry_t* entries;
    uint32_t size;
    const char* title[2];
    indicator_array_t* (*custom_mass_creator)(lv_obj_t* parent, struct indicators_list_s* list);
}indicators_list_t;


lv_obj_t* indicator_create(lv_obj_t* parent, indicator_entry_t* entry);

//indicator_array_t is allocated by lv_malloc. Deletes itself on parent destruction.
indicator_array_t* indicator_mass_create(lv_obj_t* parent, indicators_list_t* list);
indicator_array_t* default_indicator_mass_create(lv_obj_t* parent, indicators_list_t* list);

void indicator_mass_set(indicator_array_t* array);
void indicator_arrays_list_mass_set(indicator_arrays_list_t* list);


#endif
