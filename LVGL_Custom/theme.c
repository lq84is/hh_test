#include "theme.h"

#include "../lvgl/lvgl.h"

static lv_style_t style_minimal;
static lv_style_t style_minimal;
lv_style_t style_cursor_hidden;
lv_style_t style_cursor_edited;

lv_style_t style_indic;
lv_style_t style_zero_width_container;
lv_style_t style_big_label;


/*Will be called when the styles of the base theme are already added
  to add new styles*/
static void new_theme_apply_cb(lv_theme_t* th, lv_obj_t* obj)
{
    LV_UNUSED(th);
    lv_obj_add_style(obj, &style_minimal, 0);
}

void theme_init_and_set(void)
{
    /*Initialize the styles*/
    lv_style_init(&style_minimal);
    lv_style_set_pad_top(&style_minimal, 1); // Adjust top padding
    lv_style_set_pad_bottom(&style_minimal, 1); // Adjust bottom padding

    /*Initialize the new theme from the current theme*/
    lv_theme_t* th_act = lv_disp_get_theme(NULL);
    static lv_theme_t th_new;
    th_new = *th_act;

    /*Set the parent theme and the style apply callback for the new theme*/
    lv_theme_set_parent(&th_new, th_act);
    lv_theme_set_apply_cb(&th_new, new_theme_apply_cb);

    /*Assign the new theme to the current display*/
    lv_disp_set_theme(NULL, &th_new);
    
    lv_style_init(&style_cursor_hidden);
    lv_style_set_bg_opa(&style_cursor_hidden, LV_OPA_0);

    lv_style_init(&style_cursor_edited);
    lv_style_set_bg_opa(&style_cursor_edited, LV_OPA_100);
}

void fire_style_init(void) {
    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_VER);
    lv_style_set_border_width(&style_indic, 0);
}
void zero_width_container_style_init(void) {
    lv_style_init(&style_zero_width_container);
    lv_style_set_pad_left(&style_zero_width_container, 0);
    lv_style_set_pad_right(&style_zero_width_container, 0);
    lv_style_set_pad_top(&style_zero_width_container, 0);
    lv_style_set_pad_bottom(&style_zero_width_container, 0);
    lv_style_set_radius(&style_zero_width_container, 0);
    lv_style_set_border_width(&style_zero_width_container, 0);
}
void style_big_label_init(void) {
    lv_style_init(&style_big_label);
    lv_style_set_text_font(&style_big_label, &Noto72compressed);
}






