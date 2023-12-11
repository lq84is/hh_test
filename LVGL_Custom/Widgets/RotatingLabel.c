#include "RotatingLabel.h"
#include "lvgl/lvgl.h"

#include "AuxFunctions/PrintDebug.h"
#include "AuxFunctions/char_strings.h"

#include "AuxFunctions/lv_mem_man.h"

typedef struct {
    lv_obj_t* label;
    lv_anim_t animation_variable;
    lv_anim_t* animation_pointer;
    unsigned running : 1;
} rotating_label_t;


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static void label_set_angle(void * var, int32_t v) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif   
    lv_obj_set_style_transform_pivot_x(var, lv_obj_get_width(var) / 2, 0);
    lv_obj_set_style_transform_pivot_y(var, lv_obj_get_height(var) / 2, 0);
    lv_obj_set_style_transform_angle(var, v, 0);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif    
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


extern lv_style_t style_zero_width_container;

//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
//#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* rotating_label_create(lv_obj_t* parent){
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    rotating_label_t* rlabel = lv_mem_alloc(sizeof(rotating_label_t));
    if (!rlabel) {
        PRINT_DEBUG("rlabel NULL POINTER");
        return NULL;
    }
    lv_memset_00(rlabel, sizeof(rotating_label_t));

    lv_obj_t* container = lv_obj_create(parent);
    lv_obj_add_style(container, &style_zero_width_container, 0);
    //lv_obj_set_style_bg_color(container, lv_color_black(), 0);

    rlabel->label = lv_label_create(container);
    lv_label_set_recolor(rlabel->label, true);
    lv_label_set_text(rlabel->label, "X");
    lv_obj_center(rlabel->label);
    lv_obj_set_user_data(rlabel->label, rlabel);

    lv_obj_add_event_cb(rlabel->label, container_deleted_free_data, LV_EVENT_DELETE, rlabel);
    lv_anim_init(&rlabel->animation_variable);
    lv_anim_set_var(&rlabel->animation_variable, rlabel->label);
    lv_anim_set_exec_cb(&rlabel->animation_variable, label_set_angle);
    lv_anim_set_values(&rlabel->animation_variable, 800, 0);
    lv_anim_set_time(&rlabel->animation_variable, 250);
    lv_anim_set_repeat_count(&rlabel->animation_variable, LV_ANIM_REPEAT_INFINITE);
    rlabel->running = 0;
    
    label_set_angle(rlabel->label, 0);

    lv_obj_set_size(container, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return container;
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

/*----------------fire_widget_start-------------------*/

void rotating_label_start(lv_obj_t* container) {
    lv_obj_t* label = lv_obj_get_child(container, 0);
    rotating_label_t* rlabel = lv_obj_get_user_data(label);
    if (!rlabel->running) {
        rlabel->animation_pointer = lv_anim_start(&rlabel->animation_variable);
        rlabel->running = true;
    }
}

/*----------------fire_widget_stop-------------------*/

void rotating_label_stop(lv_obj_t* container) {
    lv_obj_t* label = lv_obj_get_child(container, 0);
    rotating_label_t* rlabel = lv_obj_get_user_data(label);
    if (rlabel->running) {
        lv_anim_del(rlabel->label, NULL);
        label_set_angle(rlabel->label, 0);
        rlabel->running = false;
    }
}
