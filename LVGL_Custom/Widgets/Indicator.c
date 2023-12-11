#include "Indicator.h"
#include "lvgl/lvgl.h"

#include "AuxFunctions/PrintDebug.h"
#include "AuxFunctions/char_strings.h"

#include "LVGL_Custom/display_settings.h"

lv_obj_t* indicator_create(lv_obj_t* parent, indicator_entry_t* entry) {
    lv_obj_t* obj = entry->creator(parent);
    if(obj != NULL){
        lv_obj_set_user_data(obj, entry);
    }
    return obj;
}

//#define DEBUG_obj_list_delete
#ifdef  DEBUG_obj_list_delete
//#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static void obj_list_delete_clb(lv_event_t* e) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    indicator_array_t* array = lv_event_get_user_data(e);
    PRINT_DEBUG("deleting indicator_array_t with %s widgets", array->name);
    lv_mem_free(array->indicators);
    lv_mem_free(array);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
//#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
indicator_array_t* default_indicator_mass_create(lv_obj_t* parent, indicators_list_t* list) {
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif

    indicator_array_t* array = lv_mem_alloc(sizeof(indicator_array_t));
    if (!array) {
        PRINT_DEBUG("array NULL POINTER");
        return NULL;
    }
    array->size = list->size;
    array->indicators = lv_mem_alloc(sizeof(lv_obj_t*) * list->size);
    if (!array->indicators) {
        PRINT_DEBUG("array->indicators NULL POINTER");
        lv_mem_free(array);
        return NULL;
    }
    for (int i = 0; i < list->size; i++) {
        indicator_entry_t* entry = (indicator_entry_t* ) &list->entries[i];
        lv_obj_t* indicator = indicator_create(parent, entry);
        if (indicator == NULL) {
            while (--i >= 0) { // Clean up previously created indicators
                lv_obj_del(array->indicators[i]);
            }
            lv_mem_free(array->indicators);
            lv_mem_free(array);
            return NULL;
        }
        array->indicators[i] = indicator;
        if(entry->widget_setter)
            entry->widget_setter(indicator);
    }
    lv_obj_add_event_cb(parent, obj_list_delete_clb, LV_EVENT_DELETE, array);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif

    return array;
}
#ifdef DEBUG_FUNCTION
#undef DEBUG_FUNCTION
#endif 
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


indicator_array_t* indicator_mass_create(lv_obj_t* parent, indicators_list_t* list) {
    indicator_array_t* array;
    if (list->custom_mass_creator) {
        array = list->custom_mass_creator(parent, list);
    }
    else {
        array = default_indicator_mass_create(parent, list);
    }
    array->name = list->title[CURRENT_LANGUAGE];
    return array;
}

void indicator_mass_set(indicator_array_t* array) {
    if (!array) {
        PRINT_DEBUG_TRACE("NULL PONTER!!!");
        return;
    }
    for (int i = 0; i < array->size; i++) {
        lv_obj_t* obj = array->indicators[i];
        indicator_entry_t* entry = lv_obj_get_user_data(obj);
        entry->widget_setter(obj);
    }
}


void indicator_arrays_list_mass_set(indicator_arrays_list_t* list) {
    if (!list) {
        PRINT_DEBUG_TRACE("NULL PONTER!!!");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        indicator_array_t* array = list->arrays[i];
        indicator_mass_set(array);
    }
}
