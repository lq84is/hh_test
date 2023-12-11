#include "Fire.h"
#include "lvgl/lvgl.h"

#include "AuxFunctions/PrintDebug.h"
#include "AuxFunctions/char_strings.h"

#include "AuxFunctions/lv_mem_man.h"


typedef struct {
    lv_obj_t* bars[FIRE_BARS_COUNT];
    lv_obj_t* container;
    lv_anim_t animation_variable;
    lv_anim_t* animation_pointer;
    int bar_width;
    int bar_spacing;
    int container_width;
    int container_height;
    unsigned running : 1;
} fire_widget_t;

/*----------------set_temp-------------------*/


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static void set_temp(void* data, int32_t temp)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    void** bars = (void**)data;
    if (!bars || !lv_obj_check_type(bars[0], &lv_bar_class)) return;

    for (int i = 0; i < FIRE_BARS_COUNT; i++) {
        PRINT_DEBUG("setting value");
        lv_bar_set_value(bars[i], temp, LV_ANIM_ON);
    }
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

/*----------------fire_set_size-------------------*/

lv_obj_t* fire_set_size(lv_obj_t* external_container, int container_width, int container_height, int bar_width) {

    lv_obj_t* container = lv_obj_get_child(external_container, 0);

    fire_widget_t* fire = lv_obj_get_user_data(container);

    fire->container_width = container_width;
    fire->container_height = container_height;
    fire->bar_width = bar_width;

    int total_width = fire->bar_width * FIRE_BARS_COUNT + fire->bar_spacing * (FIRE_BARS_COUNT - 1);
    lv_obj_set_size(fire->container, total_width, fire->container_height);
    for (int i = 0; i < FIRE_BARS_COUNT; i++) {
        lv_obj_set_size(fire->bars[i], fire->bar_width, fire->container_height);
        if (i == 0) {
            lv_obj_align(fire->bars[i], LV_ALIGN_LEFT_MID, 0, 0);
        }
        else {
            lv_obj_align_to(fire->bars[i], fire->bars[i - 1], LV_ALIGN_OUT_RIGHT_MID, fire->bar_spacing, 0);
        }
    }
    return external_container;
}

void anim_deleted(lv_anim_t* anim) {
    PRINT_DEBUG_TRACE("animation deleted");
}


extern lv_style_t style_indic;
extern lv_style_t style_zero_width_container;

/*----------------fire_widget_create-------------------*/

//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
//#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* fire_widget_create(lv_obj_t* parent){//, int container_width, int container_height, int bar_width) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    fire_widget_t* fire = lv_mem_alloc(sizeof(fire_widget_t));
#ifdef DEBUG_FUNCTION
    if (!fire) {
        PRINT_DEBUG("NULL POINTER");
        return NULL;
    }
#endif 
    PRINT_DEBUG("fire addr = 0x%X", fire);
    lv_memset_00(fire, sizeof(fire_widget_t));

    lv_obj_t* external_container = lv_obj_create(parent);
    lv_obj_add_style(external_container, &style_zero_width_container, 0);

    fire->container = lv_obj_create(external_container);
    lv_obj_set_user_data(fire->container, fire);
    fire->container_width = DEFAULT_WIDTH;
    fire->container_height = DEFAULT_HEIGHT;
    fire->bar_width = DEFAULT_BAR_WIDTH;
    fire->bar_spacing = (fire->container_width - (3 * fire->bar_width)) / 2;

    lv_obj_add_style(fire->container, &style_zero_width_container, 0);
    lv_obj_add_event_cb(fire->container, container_deleted_free_data, LV_EVENT_DELETE, fire);
    //lv_obj_add_event_cb(external_container, excontainer_delete_clb, LV_EVENT_DELETE, fire);
        
    lv_obj_set_scrollbar_mode(fire->container, LV_SCROLLBAR_MODE_OFF);
    for (int i = 0; i < FIRE_BARS_COUNT; i++) {
        fire->bars[i] = lv_bar_create(fire->container);
        lv_obj_add_style(fire->bars[i], &style_indic, LV_PART_INDICATOR);
        lv_bar_set_range(fire->bars[i], 0, 70);
        if (i == 0) {
            lv_obj_align(fire->bars[i], LV_ALIGN_LEFT_MID, 0, 0);
        }
        else {
            lv_obj_align_to(fire->bars[i], fire->bars[i - 1], LV_ALIGN_OUT_RIGHT_MID, 4, 0);
        }
    }
    lv_bar_set_range(fire->bars[1], 0, 50);
    fire_set_size(external_container, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_BAR_WIDTH);

    lv_anim_init(&fire->animation_variable);
    lv_anim_set_exec_cb(&fire->animation_variable, set_temp);
    //lv_anim_set_deleted_cb(&fire->animation_variable, anim_deleted);
    lv_anim_set_time(&fire->animation_variable, 50);
    lv_anim_set_playback_time(&fire->animation_variable, 50);
    lv_anim_set_var(&fire->animation_variable, fire->bars);
    lv_anim_set_values(&fire->animation_variable, 30, 50);
    lv_anim_set_repeat_count(&fire->animation_variable, LV_ANIM_REPEAT_INFINITE);
    fire->running = 0;

    set_temp(fire->bars, 0);


    lv_obj_set_size(external_container, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    //return fire->container;
    return external_container;
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


//#define DEBUG_fire_widget_start
#ifdef DEBUG_fire_widget_start
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void fire_widget_start(lv_obj_t* external_container) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* container = lv_obj_get_child(external_container, 0);
    fire_widget_t* fire = lv_obj_get_user_data(container);
    if (!fire->running) {
        fire->animation_pointer = lv_anim_start(&fire->animation_variable);
        fire->running = true;
    }
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


/*----------------fire_widget_stop-------------------*/

//#define DEBUG_fire_widget_stop
#ifdef DEBUG_fire_widget_stop
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void fire_widget_stop(lv_obj_t* external_container) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* container = lv_obj_get_child(external_container, 0);
    fire_widget_t* fire = lv_obj_get_user_data(container);
    if (fire->running) {
        lv_anim_del(fire->bars, NULL);
        set_temp(fire->bars, 0);
        fire->running = false;
    }
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
