#include "../../lv_examples.h"
#if LV_USE_SPINBOX && LV_BUILD_EXAMPLES

static lv_obj_t * spinbox;

/*
static void lv_spinbox_increment_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED || code  == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_increment(spinbox);
    }
}

static void lv_spinbox_decrement_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_decrement(spinbox);
    }
}
*/


void lv_example_spinbox_1(void)
{
    static lv_style_t my_spinbox_style;
    lv_style_init(&my_spinbox_style);
    lv_style_set_pad_top(&my_spinbox_style, 1); // Adjust top padding
    lv_style_set_pad_bottom(&my_spinbox_style, 1); // Adjust bottom padding
    
    spinbox = lv_spinbox_create(lv_scr_act());
    lv_spinbox_set_range(spinbox, -1000, 25000);
    lv_spinbox_set_digit_format(spinbox, 5, 2);
    lv_spinbox_step_prev(spinbox);
    lv_obj_set_width(spinbox, 100);
    lv_obj_center(spinbox);

    lv_obj_add_style(spinbox, &my_spinbox_style, LV_PART_MAIN);
    
    //lv_coord_t h = lv_obj_get_height(spinbox);

    //lv_obj_t * btn = lv_btn_create(lv_scr_act());
    //lv_obj_set_size(btn, h, h);
    //lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    //lv_obj_set_style_bg_img_src(btn, LV_SYMBOL_PLUS, 0);
    //lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_ALL,  NULL);
    //
    //btn = lv_btn_create(lv_scr_act());
    //lv_obj_set_size(btn, h, h);
    //lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    //lv_obj_set_style_bg_img_src(btn, LV_SYMBOL_MINUS, 0);
    //lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_ALL, NULL);
}

#endif
