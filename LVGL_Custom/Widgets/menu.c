#include "menu.h"
#include "AuxFunctions/PrintDebug.h"
#include "AuxFunctions/char_strings.h"
#include "LVGL_Custom/theme.h"

#include "AuxFunctions/lv_mem_man.h"

#include "LVGL_Custom/display_settings.h"

#if defined(__has_include)
    #if __has_include("stm32f4xx_hal.h")
        #include "stm32f4xx_hal.h"
    #endif
#endif

#if 0
#undef PRINT
#undef PRNT_FBEGIN
#undef PRNT_FEND

#define PRINT(...)
#define PRNT_FBEGIN()
#define PRNT_FEND()
#endif

#define CONFIRM_BUTTON_HEIGHT   (19)
#define CONFIRM_BUTTON_WIDTH    (19)

#define LED_SIZE (15)

uint32_t get_char_len(const char* text) {
    int i = 0;
    while (*text != 0)
    {
        i++;
        text++;
    }
    return i;
}

const char* event_str[] = {
    "LV_EVENT_ALL",

    /** Input device events*/
    "LV_EVENT_PRESSED",             /**< The object has been pressed*/
    "LV_EVENT_PRESSING",            /**< The object is being pressed (called continuously while pressing)*/
    "LV_EVENT_PRESS_LOST",          /**< The object is still being pressed but slid cursor/finger off of the object */
    "LV_EVENT_SHORT_CLICKED",       /**< The object was pressed for a short period of time, then released it. Not called if scrolled.*/
    "LV_EVENT_LONG_PRESSED",        /**< Object has been pressed for at least `long_press_time`.  Not called if scrolled.*/
    "LV_EVENT_LONG_PRESSED_REPEAT", /**< Called after `long_press_time` in every `long_press_repeat_time` ms.  Not called if scrolled.*/
    "LV_EVENT_CLICKED",             /**< Called on release if not scrolled (regardless to long press)*/
    "LV_EVENT_RELEASED",            /**< Called in every cases when the object has been released*/
    "LV_EVENT_SCROLL_BEGIN",        /**< Scrolling begins. The event parameter is a pointer to the animation of the scroll. Can be modified*/
    "LV_EVENT_SCROLL_END",          /**< Scrolling ends*/
    "LV_EVENT_SCROLL",              /**< Scrolling*/
    "LV_EVENT_GESTURE",             /**< A gesture is detected. Get the gesture with `lv_indev_get_gesture_dir(lv_indev_get_act());` */
    "LV_EVENT_KEY",                 /**< A key is sent to the object. Get the key with `lv_indev_get_key(lv_indev_get_act());`*/
    "LV_EVENT_FOCUSED",             /**< The object is focused*/
    "LV_EVENT_DEFOCUSED",           /**< The object is defocused*/
    "LV_EVENT_LEAVE",               /**< The object is defocused but still selected*/
    "LV_EVENT_HIT_TEST",            /**< Perform advanced hit-testing*/

    /** Drawing events*/
    "LV_EVENT_COVER_CHECK",        /**< Check if the object fully covers an area. The event parameter is `lv_cover_check_info_t *`.*/
    "LV_EVENT_REFR_EXT_DRAW_SIZE", /**< Get the required extra draw area around the object (e.g. for shadow). The event parameter is `lv_coord_t *` to store the size.*/
    "LV_EVENT_DRAW_MAIN_BEGIN",    /**< Starting the main drawing phase*/
    "LV_EVENT_DRAW_MAIN",          /**< Perform the main drawing*/
    "LV_EVENT_DRAW_MAIN_END",      /**< Finishing the main drawing phase*/
    "LV_EVENT_DRAW_POST_BEGIN",    /**< Starting the post draw phase (when all children are drawn)*/
    "LV_EVENT_DRAW_POST",          /**< Perform the post draw phase (when all children are drawn)*/
    "LV_EVENT_DRAW_POST_END",      /**< Finishing the post draw phase (when all children are drawn)*/
    "LV_EVENT_DRAW_PART_BEGIN",    /**< Starting to draw a part. The event parameter is `lv_obj_draw_dsc_t *`. */
    "LV_EVENT_DRAW_PART_END",      /**< Finishing to draw a part. The event parameter is `lv_obj_draw_dsc_t *`. */

    /** Special events*/
    "LV_EVENT_VALUE_CHANGED",       /**< The object's value has changed (i.e. slider moved)*/
    "LV_EVENT_INSERT",              /**< A text is inserted to the object. The event data is `char *` being inserted.*/
    "LV_EVENT_REFRESH",             /**< Notify the object to refresh something on it (for the user)*/
    "LV_EVENT_READY",               /**< A process has finished*/
    "LV_EVENT_CANCEL",              /**< A process has been cancelled */

    /** Other events*/
    "LV_EVENT_DELETE",              /**< Object is being deleted*/
    "LV_EVENT_CHILD_CHANGED",       /**< Child was removed, added, or its size, position were changed */
    "LV_EVENT_CHILD_CREATED",       /**< Child was created, always bubbles up to all parents*/
    "LV_EVENT_CHILD_DELETED",       /**< Child was deleted, always bubbles up to all parents*/
    "LV_EVENT_SCREEN_UNLOAD_START", /**< A screen unload started, fired immediately when scr_load is called*/
    "LV_EVENT_SCREEN_LOAD_START",   /**< A screen load started, fired when the screen change delay is expired*/
    "LV_EVENT_SCREEN_LOADED",       /**< A screen was loaded*/
    "LV_EVENT_SCREEN_UNLOADED",     /**< A screen was unloaded*/
    "LV_EVENT_SIZE_CHANGED",        /**< Object coordinates/size have changed*/
    "LV_EVENT_STYLE_CHANGED",       /**< Object's style has changed*/
    "LV_EVENT_LAYOUT_CHANGED",      /**< The children position has changed due to a layout recalculation*/
    "LV_EVENT_GET_SELF_SIZE",       /**< Get the internal size of a widget*/

    "_LV_EVENT_LAST",               /** Number of default events*/


    "LV_EVENT_PREPROCESS",   /** This is a flag that can be set with an event so it's processed
                                      before the class default event processing */
};


typedef struct{
    lv_event_cb_t cb;
    void* user_data;
    lv_event_code_t filter : 8;
} lv_event_dsc_local_t;


void remove_all_event_callbacks(lv_obj_t* obj, lv_event_code_t event_code)
{
    // Check if spec_attr is NULL
    if (obj == NULL || obj->spec_attr == NULL) {
        // Handle the case where spec_attr is NULL (possibly allocate it)
        // You can choose to allocate it or take appropriate action as needed
        return;
    }
    lv_event_dsc_local_t* dsc = (lv_event_dsc_local_t*)obj->spec_attr->event_dsc;
    // Iterate through the event descriptors
    for (int i = 0; i < obj->spec_attr->event_dsc_cnt; i++) {
        // Check if the event code matches the one you want to remove
        if (dsc[i].filter == event_code) {
            // Remove the event callback using lv_obj_remove_event_cb
            lv_obj_remove_event_cb(obj, dsc[i].cb);

            // Reset the counter to zero to iterate again
            i = 0;
        }
    }
}

//#define DEBUG_event_code
#ifdef DEBUG_event_code
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
const char* event_code(lv_event_t* e) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    const char* event_text;
    if (e->code == LV_EVENT_PREPROCESS) {
        event_text = event_str[_LV_EVENT_LAST + 1];
    }
    else {
        event_text = event_str[e->code];
    }
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return event_text;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif



//entry and widget don't know each other, need to connect them
typedef struct {
    lv_timer_t* timer;                                              //    delete associated timer after/while entry is deleted
    lv_timer_t* focusChecker;                                       //    for safety, to safe delete menuEntryData with all timers
                                                                    //    not to use expired pointers
    const entry_t* entry;                                           //    where to take data from, entry_t has everything
    lv_obj_t* entry_container;                                      //    menu entry
    lv_obj_t* widget;                                               //    what widget to update, can test if it is selected
    lv_obj_t* confirm_btn;                                          //    test if is selected
    void (*setWidFcn)(lv_obj_t* widget, const entry_t* entry_with_data);  //    what function to use for that widget
    void (*setDataFcn)(lv_event_t* e);                              //    triggers on widget's LV_EVENT_VALUE_CHANGED or "save button" click, event's user_data contains this all structure
}menuEntryData_t;


static void (*defaultExitMenuFunction)(lv_event_t*) = NULL;

void setDefaultExitMenuFunction(void (*exitFunctionDrawer)(lv_event_t*)) {
    defaultExitMenuFunction = exitFunctionDrawer;
}

static lv_obj_t* create_entry(lv_obj_t* menu_page, const entry_t* entry);

extern lv_style_t style_cursor_hidden;
extern lv_style_t style_cursor_edited;

void emptyCallback(lv_event_t* e) {
}

lv_obj_t* default_menu_create(lv_obj_t* parent, menuPage_t* page_dsc) {
    lv_obj_t* menu_page;

    lv_obj_t* menu = lv_menu_create(parent);

    lv_obj_set_style_bg_color(menu, lv_color_black(), 0);

    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_center(menu);
    if (page_dsc->title[CURRENT_LANGUAGE]) {
        menu_page = lv_menu_page_create(menu, (char*)(page_dsc->title[CURRENT_LANGUAGE]));
    }
    else {
        menu_page = lv_menu_page_create(menu, "[Заголовок]");
    }
    lv_menu_set_page(menu, menu_page);
    lv_menu_t* menu_struct = (lv_menu_t*)menu;
    lv_label_set_long_mode(menu_struct->main_header_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_t* back_btn = lv_menu_get_main_header_back_btn(menu);
    lv_obj_set_style_bg_color(back_btn, lv_color_hex(DEFAULT_BUTTON_COLOR), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(back_btn, 0xff, 0);

    lv_obj_t* back_btn_label = lv_label_create(back_btn);

    lv_label_set_text(back_btn_label, back_str[0][CURRENT_LANGUAGE]);
    lv_obj_update_layout(menu_struct->main_header_title);
    lv_obj_set_width(menu_struct->main_header_title, lv_disp_get_hor_res(NULL) - lv_obj_get_width(back_btn) - 40);
    lv_obj_set_style_text_align(menu_struct->main_header_title, LV_TEXT_ALIGN_CENTER, 0);

    //customize back_btn's internal behaviour only after lv_menu_set_page and lv_menu_page_create
    remove_all_event_callbacks(back_btn, LV_EVENT_CLICKED);
    lv_obj_add_flag(back_btn, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_clear_flag(back_btn, LV_OBJ_FLAG_HIDDEN);
    if (page_dsc->pageBack) {
        if (page_dsc->backFunctionDrawer) {
            lv_obj_add_event_cb(back_btn, page_dsc->backFunctionDrawer, LV_EVENT_CLICKED, page_dsc->pageBack);
        }
        else {
            lv_obj_add_event_cb(back_btn, defaultMenuPageDrawer, LV_EVENT_CLICKED, page_dsc->pageBack);
        }
    }
    else {
        lv_obj_add_event_cb(back_btn, defaultExitMenuFunction, LV_EVENT_CLICKED, NULL);
    }
    return menu;
}



void defaultMenuPageDrawer(lv_event_t* e) {
    //lv_event_t* e contains user_data which page has to show
    lv_anim_del_all();

    menuPage_t* page_dsc = (menuPage_t*)lv_event_get_user_data(e);

    /*edit begin*/
    lv_obj_t* menu;
    lv_obj_t* menu_page;
    lv_menu_t* menu_struct;

    if (page_dsc == NULL) {
        //create empty default page
        lv_obj_t*  screen = lv_obj_create(NULL);

        menu = lv_menu_create(screen);
        lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
        lv_obj_center(menu);

        menu_page = lv_menu_page_create(menu, "Здесь пусто. Пока что.");
        menu_struct = (lv_menu_t*)menu;
        lv_label_set_long_mode(menu_struct->main_header_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_menu_set_page(menu, menu_page);

        lv_obj_t* back_btn = lv_menu_get_main_header_back_btn(menu);
        lv_obj_t* back_btn_label = lv_label_create(back_btn);
        lv_label_set_text(back_btn_label, "Назад");
        lv_obj_set_style_bg_color(back_btn, lv_color_hex(DEFAULT_BUTTON_COLOR), LV_PART_MAIN);
        
        remove_all_event_callbacks(back_btn, LV_EVENT_CLICKED);
        lv_obj_add_flag(back_btn, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
        lv_obj_clear_flag(back_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_event_cb(back_btn, defaultExitMenuFunction, LV_EVENT_CLICKED, NULL);

        lv_group_focus_obj(back_btn);
        lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 0, true);
        return;

    }
    else {
        if (page_dsc->thisPageDrawer) {
            //delegate to custom drawer
            page_dsc->thisPageDrawer(e);
            return;
        }
        else {
            //draw defaultly
            
            
            lv_obj_t* screen = lv_obj_create(NULL);
            lv_obj_add_style(screen, &style_zero_width_container, 0);

            lv_obj_set_style_bg_color(screen, lv_color_black(), 0);

            menu = default_menu_create(screen, page_dsc);
            menu_page = lv_menu_get_cur_main_page(menu);
            
            //Create menu entries, iterate through them
            for (int i = 0; i < page_dsc->size; i++) {
                const entry_t* entry = &page_dsc->entries[i];
                create_entry(menu_page, entry);
            }
            
            lv_obj_t* back_btn = lv_menu_get_main_header_back_btn(menu);
            
            lv_group_focus_obj(back_btn);
            lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 0, true);

            setTimerLoadMainScreenOnInactivity(screen, INACTIVE_TIMEOUT_CHECK_MS);
            

            return;
        }
    }
}

//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* add_text(lv_obj_t* parent, const char* icon, const char* txt)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* img = NULL;
    lv_obj_t* label = NULL;

    if (icon) {
        img = lv_img_create(parent);
        lv_img_set_src(img, icon);
    }

    if (txt) {
        label = lv_label_create(parent);
        lv_label_set_text(label, txt);
        PRINT_DEBUG("%s", txt);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
    }
    //lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return parent;
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


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* add_switch(lv_obj_t* menu_entry)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* sw = lv_switch_create(menu_entry);
    lv_obj_set_style_bg_color(sw, lv_palette_main(LV_PALETTE_GREEN), LV_STATE_CHECKED | LV_PART_INDICATOR);
    PRINT_DEBUG("switch: 0x%X", (uint32_t)sw);
    lv_obj_set_size(sw, 38, 19);
    lv_obj_set_flex_align(sw, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_group_remove_obj(menu_entry);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return sw;
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

//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* create_spinbox_from_entry(lv_obj_t* parent, const entry_t* entry) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* sb = lv_spinbox_create(parent);
    PRINT_DEBUG("sb created");
    PRINT_DEBUG("entry: %s", entry->text[CURRENT_LANGUAGE]);
    lv_spinbox_set_digit_format(sb, entry->sbDidgitNum, entry->sbDigitAfterDot);
    lv_obj_set_style_bg_color(sb, lv_color_black(), 0);
    if (entry->type == float_e) {
        PRINT_DEBUG("Float entry");
        float min = entry->min.f;
        float max = entry->max.f;

        PRINT_DEBUG("min = %f\tmax = %f", min, max);
        for (int i = 0; i < entry->sbDidgitNum - entry->sbDigitAfterDot; i++) {
            min *= 10;
            max *= 10;
        }
        PRINT_DEBUG("Spinbox range float->int values:");
        PRINT_DEBUG("min = %f\tmax = %f", min, max);
        lv_spinbox_set_range(sb, min, max);

    }
    else {
        PRINT_DEBUG("Spinbox range int values:");

        PRINT_DEBUG("min = %d\tmax = %d", entry->min.i32, entry->max.i32);
        val_t min_max[2] = { {.i32 = 0}, {.i32 = 0} };
        val_t* min_max_entry[2] = { (val_t*)&entry->min, (val_t*)&entry->max };

        for (char i = 0; i < 2; i++) {
            v_equals_v(entry->type, &min_max[i], min_max_entry[i]);
            switch (entry->type) {
            case int8_t_e:
                min_max[i].i16 = min_max[i].i8;
            case int16_t_e:
                min_max[i].i32 = min_max[i].i16;
            default:
                break;
            }
        }
        lv_spinbox_set_range(sb, min_max[0].i32, min_max[1].i32);
    }

#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return sb;
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



void resize_spinbox_to_entry_and_font(lv_obj_t* sb, const entry_t* entry, lv_font_t* used_font) {
    //reduce spinbox width to number of digits
    lv_font_glyph_dsc_t font_descriptor;
    lv_font_get_glyph_dsc_fmt_txt(used_font, &font_descriptor, '0', '0');
    uint32_t spinbox_width = font_descriptor.box_w * (entry->sbDidgitNum + 2) + 10;

    lv_obj_add_style(sb, &style_cursor_hidden, LV_STATE_DEFAULT | LV_PART_CURSOR);
    lv_obj_add_style(sb, &style_cursor_edited, LV_STATE_EDITED | LV_PART_CURSOR);
    lv_obj_set_width(sb, spinbox_width);

}


//#define DEBUG_add_spinbox
#ifdef DEBUG_add_spinbox
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* add_spinbox(lv_obj_t* menu_entry)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    menuEntryData_t* menuEntryData = lv_obj_get_user_data(menu_entry);
    const entry_t* entry = menuEntryData->entry;

    lv_obj_t* sb = create_spinbox_from_entry(menu_entry, entry);

    const lv_font_t* used_font = lv_theme_get_font_normal(sb);

    resize_spinbox_to_entry_and_font(sb, entry, (lv_font_t*) used_font);

    lv_obj_set_flex_align(sb, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_flex_grow(sb, 0);
    lv_obj_set_style_text_align(sb, LV_TEXT_ALIGN_RIGHT, 0);

    //lv_obj_set_size(sw, 38, 19);
    //lv_group_remove_obj(menu_entry);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return sb;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif



//#define DEBUG_add_dropdown
#ifdef DEBUG_add_dropdown
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* add_dropdown(lv_obj_t* menu_entry)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* dd = lv_dropdown_create(menu_entry);
    lv_dropdown_t* dd_full = (lv_dropdown_t*)dd;
    lv_dropdown_clear_options(dd);
    lv_obj_set_style_bg_color(dd, lv_color_black(), 0 );
    menuEntryData_t* menuEntryData = lv_obj_get_user_data(menu_entry);
    const entry_t* entry = menuEntryData->entry;
    PRINT_DEBUG("entry: %s", entry->text[CURRENT_LANGUAGE]);
    PRINT_DEBUG("str_storage min: %d", entry->min.u8);
    PRINT_DEBUG("str_storage max: %d", entry->max.u8 - 1);



    const lv_font_t* used_font = lv_theme_get_font_normal(dd);
    lv_coord_t max_width = 0;

    for (int i = entry->min.u8; i <= entry->max.u8; i++) {
        PRINT_DEBUG("adding %d", i);
        const char* text = (*entry->str_storage)[i][CURRENT_LANGUAGE];
        lv_dropdown_add_option(dd, text, i);
        
        lv_coord_t width = lv_txt_get_width(text, get_char_len(text), used_font, 0, 0);
        max_width = width > max_width ? width : max_width;
        PRINT_DEBUG("%s charlen: %d", text, get_char_len(text));
        PRINT_DEBUG("%s size: %d", text, width);
    }
    lv_obj_set_style_bg_color(lv_dropdown_get_list(dd), lv_color_black(), 0 );
    lv_obj_set_style_bg_color(lv_dropdown_get_list(dd), lv_color_hex(DEFAULT_BUTTON_COLOR), LV_PART_SELECTED | LV_STATE_CHECKED );
    const char* symDown = dd_full->symbol;
    uint32_t down_width = lv_txt_get_width(symDown, get_char_len(symDown), used_font, 0, 0);
    PRINT_DEBUG("down_width: %d", down_width);
    lv_obj_set_width(dd, max_width + down_width + 30);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return dd;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif



//#define DEBUG_add_led
#ifdef  DEBUG_add_led
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* add_led(lv_obj_t* menu_entry)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* led = lv_led_create(menu_entry);

    menuEntryData_t* menuEntryData = lv_obj_get_user_data(menu_entry);
    const entry_t* entry = menuEntryData->entry;
    PRINT_DEBUG("entry: %s", entry->text[CURRENT_LANGUAGE]);

    lv_led_set_color(led, lv_color_hex(entry->color));
    lv_obj_set_size(led, LED_SIZE, LED_SIZE);

#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return led;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


//#define DEBUG_add_confirm_btn
#ifdef  DEBUG_add_confirm_btn
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* add_confirm_btn(lv_obj_t* menu_entry, const char* icon)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* btn = lv_btn_create(menu_entry);
    lv_obj_set_style_bg_color(btn, lv_color_hex(DEFAULT_BUTTON_COLOR), 0);
    lv_obj_t* label = lv_label_create(btn);
    if (icon == NULL) {
        icon = LV_SYMBOL_LEFT;
    }
    lv_label_set_text(label, icon);
    lv_group_remove_obj(menu_entry);
    lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return btn;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif



//#define DEBUG_add_textLabel
#ifdef  DEBUG_add_textLabel
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* add_textLabel(lv_obj_t* menu_entry)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* label = lv_label_create(menu_entry);

    menuEntryData_t* menuEntryData = lv_obj_get_user_data(menu_entry);
    const entry_t* entry = menuEntryData->entry;
    PRINT_DEBUG("entry: %s", entry->text[CURRENT_LANGUAGE]);

#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return label;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif



static lv_obj_t* add_reference(lv_obj_t* menu_entry, lv_obj_t* page) {
    lv_obj_t* button = add_confirm_btn(menu_entry, LV_SYMBOL_RIGHT);
    lv_obj_add_event_cb(button, defaultMenuPageDrawer, LV_EVENT_CLICKED, page);

    //lv_obj_add_event_cb(menu_entry, defaultMenuPageDrawer, LV_EVENT_SHORT_CLICKED, page);
    return menu_entry;
}


//sw: switch
//val: 1 or 0, true/false
void setSwitch(lv_obj_t* sw, const entry_t* entry) {
    if (*entry->data.u8) {
        lv_obj_add_state(sw, LV_STATE_CHECKED);
    }
    else {
        lv_obj_clear_state(sw, LV_STATE_CHECKED);
    }
}

//sw: switch
//val: 1 or 0, true/false
void setLed(lv_obj_t* led, const entry_t* entry) {
    if (*entry->data.u8) {
        lv_led_on(led);
    }
    else {
        lv_led_off(led);
    }
}


//sw: switch
//val: 1 or 0, true/false
void setDataFromSwitch(lv_event_t* e) {
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    lv_obj_t* sw = menuEntryData->widget;
    const entry_t* entry = menuEntryData->entry;
    *entry->data.u8 = lv_obj_has_state(sw, LV_STATE_CHECKED);
    if (entry->sel_callback) {
        entry->sel_callback(entry);
    }
}


void readOnlyConfirmCallback(lv_event_t* e) {
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    const entry_t* entry = menuEntryData->entry;
    if (entry->sel_callback) {
        entry->sel_callback(entry);
    }
}


//sw: switch
//val: 1 or 0, true/false
//#define DEBUG_setSpinbox
#ifdef  DEBUG_setSpinbox
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void setSpinbox(lv_obj_t* sb, const entry_t* entry) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    int32_t sb_val = 0;
    val_t val = {.i32 = 0};
    v_equals_p(entry->type, (val_t*)&val, (val_p*)&(entry->data));
    if (entry->type == float_e) {
        float f_val = val.f;
        for (int i = 0; i < entry->sbDidgitNum - entry->sbDigitAfterDot; i++) {
            f_val *= 10;
        }
        sb_val = f_val;
    }
    else{
        switch(entry->type){
            case int8_t_e:
                val.i16 = val.i8;
            case int16_t_e:
                val.i32 = val.i16;
            default:
                break;
        }
        sb_val = val.i32;
    }
    PRINT_DEBUG("set %d...", sb_val);
    lv_spinbox_set_value(sb, sb_val);
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







void setTextLabel2(lv_obj_t* label, const entry_t* entry) {
    lv_label_set_text_fmt(label, "%f V", 3.3);//(*entry->str_storage)[0][CURRENT_LANGUAGE], 3.3);//(float)*(entry->data.f));
}


#define SET_TEXT_LABEL_FMT_NAME(type)         set_text_label_fmt_##type
#define SET_TEXT_LABEL_FMT_DECLARATION(type) void SET_TEXT_LABEL_FMT_NAME(type)(lv_obj_t* label, const entry_t* entry)
#define SET_TEXT_LABEL_FMT_BODY(type)        {lv_label_set_text_fmt(label, (*entry->str_storage)[0][CURRENT_LANGUAGE], *(entry->data.type));}
#define SET_TEXT_LABEL_FMT_FUNCTION(type)    SET_TEXT_LABEL_FMT_DECLARATION(type)SET_TEXT_LABEL_FMT_BODY(type)
FUNCTIONS(SET_TEXT_LABEL_FMT)
void (*set_text_label_fmt_fcns[])(lv_obj_t* label, const entry_t* entry) = {
    FARRAY(SET_TEXT_LABEL_FMT)
};

void setTextLabel(lv_obj_t* label, const entry_t* entry) {
    if (entry->type)
        set_text_label_fmt_fcns[(uint8_t)(entry->type - 1)](label, entry);
}



//#define DEBUG_focusChecker
#ifdef  DEBUG_focusChecker
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void focusChecker(lv_timer_t* timer)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    /*Use the user_data*/
    menuEntryData_t* menuEntryData = timer->user_data;
    lv_obj_t* widget = menuEntryData->widget;
    const entry_t* entry = menuEntryData->entry;
    lv_obj_t* menu_entry = menuEntryData->entry_container;

    lv_group_t* group = lv_group_get_default();
    lv_obj_t* focused_obj = lv_group_get_focused(group);

    lv_obj_t* parent = lv_obj_get_parent(focused_obj);

    if (parent != NULL) {
        //if (lv_obj_check_type(parent, &lv_menu_cont_class)) {
            if (parent == menu_entry) {
                goto skip;
            }
            else {
                goto update;
            }
        //}
        //else {
        //    goto update;
        //}
    }
    else {
        goto update;
    }
update:
    menuEntryData->setWidFcn(widget, entry);
skip:
    lv_timer_del(timer);
    menuEntryData->focusChecker = NULL;
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


//#define DEBUG_setWidgetOnEvent
#ifdef  DEBUG_setWidgetOnEvent
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void setWidgetOnEvent(lv_event_t* e) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif

    PRINT_DEBUG("setWidgetOnEvent on event %s", event_code(e));
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    if(!menuEntryData->focusChecker)
        menuEntryData->focusChecker = lv_timer_create(focusChecker, 10, menuEntryData);
    
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



//sw: switch
//val: 1 or 0, true/false
void setDataFromSpinbox(lv_event_t* e) {
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    lv_obj_t* sb = menuEntryData->widget;
    const entry_t* entry = menuEntryData->entry;
    int32_t sb_val = 0;
    sb_val = lv_spinbox_get_value(sb);
    if (entry->type == float_e) {
        float f_val = (float)sb_val;
        for (int i = 0; i < entry->sbDidgitNum - entry->sbDigitAfterDot; i++) {
            f_val /= 10;
        }
        *(float*)&sb_val = f_val;
    }
    p_equals_v(entry->type, (val_p*)&(entry->data), (val_t*)&sb_val);
    if (entry->sel_callback) {
        entry->sel_callback(entry);
    }
}


void setDropdown(lv_obj_t* dd, const entry_t* entry) {
    lv_dropdown_set_selected(dd, *entry->data.u8);
}


void setDataFromDropdown(lv_event_t* e) {
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    lv_obj_t* dd = menuEntryData->widget;
    const entry_t* entry = menuEntryData->entry;
    *entry->data.u8 = lv_dropdown_get_selected(dd) + entry->min.u8;
    if (entry->sel_callback) {
        entry->sel_callback(entry);
    }
}



//#define DEBUG_printEntryUpdateData
#ifdef DEBUG_printEntryUpdateData
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void printEntryUpdateData(char* printFromFunction, menuEntryData_t* menuEntryData) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    PRINT_DEBUG_TRACE("[%s]\tupdateData            = 0x%X", printFromFunction, (uint32_t)menuEntryData);
    PRINT_DEBUG_TRACE("[%s]\tupdateData->timer     = 0x%X", printFromFunction, (uint32_t)(menuEntryData->timer));
    PRINT_DEBUG_TRACE("[%s]\tupdateData->entry     = 0x%X", printFromFunction, (uint32_t)(menuEntryData->entry));
    PRINT_DEBUG_TRACE("[%s]\tupdateData->widget    = 0x%X", printFromFunction, (uint32_t)(menuEntryData->widget));
    PRINT_DEBUG_TRACE("[%s]\tupdateData->setWidFcn = 0x%X", printFromFunction, (uint32_t)(menuEntryData->setWidFcn));
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


//#define DEBUG_entryUpdateDataDelete
#ifdef DEBUG_entryUpdateDataDelete
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void menuEntryDataDelete(lv_event_t* e) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    PRINT_DEBUG("%s called", __FUNCTION__ );
    menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
    const entry_t* entry = menuEntryData->entry;
    PRINT_DEBUG("Deleting entry: %s", entry->text[CURRENT_LANGUAGE]);
    if (menuEntryData->timer) {
        PRINT_DEBUG("Deleting timer: 0x%X", menuEntryData->timer);
        lv_timer_del(menuEntryData->timer);
    }
    if (menuEntryData->focusChecker) {
        PRINT_DEBUG("Deleting timer: 0x%X", menuEntryData->focusChecker);
        lv_timer_del(menuEntryData->focusChecker);
    }

    lv_mem_free(menuEntryData);
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


//#define DEBUG_entryUpdater
#ifdef DEBUG_entryUpdater
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void entryUpdater(lv_timer_t* timer)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    /*Use the user_data*/
    menuEntryData_t* menuEntryData = timer->user_data;
#ifdef DEBUG_entryUpdater
    //printEntryUpdateData(__FUNCTION__, updateData);
#endif
    //PRINT_DEBUG("obj state = 0x%X", updateData->widget->state);
    if (menuEntryData->entry->updateAlways) {
        if (menuEntryData->setWidFcn) {
        menuEntryData->setWidFcn(menuEntryData->widget, menuEntryData->entry);
        }
        return;
    }

    if (!lv_obj_has_state(menuEntryData->widget, LV_STATE_FOCUSED )) {
        if (menuEntryData->confirm_btn) {
            if (!lv_obj_has_state(menuEntryData->confirm_btn, LV_STATE_FOCUSED)) {
                if (menuEntryData->setWidFcn) {
                menuEntryData->setWidFcn(menuEntryData->widget, menuEntryData->entry);
            }
        }
        }
        else {
            if (menuEntryData->setWidFcn) {
            menuEntryData->setWidFcn(menuEntryData->widget, menuEntryData->entry);
        }
    }
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


uint32_t test_timer_user_data = 10;


//#define DEBUG_findChildByClass
#ifdef  DEBUG_findChildByClass
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
lv_obj_t* findChildByClass(lv_obj_t* parent, const lv_obj_class_t* class_p) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif

    lv_obj_t* child = NULL;
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
        child = lv_obj_get_child(parent, i);
        if (lv_obj_check_type(child, class_p)) {
            PRINT_DEBUG("Found: 0x%X", (uint32_t)child);
            break;
        }
    }
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return child;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


char filter_event(lv_event_t* e)
{
    lv_event_code_t code = e->code;

    //if ((code == LV_EVENT_PRESSED) ||
    //    (code >= LV_EVENT_SHORT_CLICKED && code <= LV_EVENT_LONG_PRESSED_REPEAT) ||
    //    (code == LV_EVENT_RELEASED) ||
    //    (code >= LV_EVENT_KEY && code <= LV_EVENT_DEFOCUSED)) {
    //    return 1;
    //}
    //else {
    //    return 0;
    //}

    if ((code < LV_EVENT_COVER_CHECK) ||
        (code > LV_EVENT_VALUE_CHANGED && code != LV_EVENT_GET_SELF_SIZE) )
    {
        return 1;
    }
    else {
        return 0;
    }



}

//#define DEBUG_clearEditState
#ifdef DEBUG_clearEditState
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void clearEditState(lv_event_t* e) {
    if (filter_event(e)) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
        menuEntryData_t* menuEntryData = (menuEntryData_t*)lv_event_get_user_data(e);
        lv_obj_t* menu_entry = menuEntryData->entry_container;

        lv_obj_t* widget = menuEntryData->widget;
        lv_obj_t* cfrmBtn = menuEntryData->confirm_btn;

        const char* event_text = event_code(e);
        //PRINT_DEBUG("menu_entry = 0x%X", menu_entry);
        PRINT_DEBUG("event code = %s", event_text);
        PRINT_DEBUG("menu_entry state = 0x%X", lv_obj_get_state(menu_entry));

        lv_state_t widState = lv_obj_get_state(widget);
        PRINT_DEBUG("widState = 0x%X", widState);

        if (cfrmBtn) {
            lv_state_t btnState = lv_obj_get_state(cfrmBtn);
            PRINT_DEBUG("btnState = 0x%X", btnState);
        }
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
        //lv_obj_clear_state(menu_entry, LV_STATE_EDITED | LV_STATE_FOCUSED);
    }        
    else {
    }

}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


//#define DEBUG_extendMenuEntry
#ifdef  DEBUG_extendMenuEntry
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
menuEntryData_t* extendMenuEntry(lv_obj_t* menu_entry, const entry_t* entry, lv_obj_t* (*add_widget)(lv_obj_t* menu_entry), \
    void (*setWidFcn)(lv_obj_t* widget, const entry_t* entry_with_data), void (*setDataFcn)(lv_event_t* e))
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    menuEntryData_t* menuEntryData = lv_mem_alloc(sizeof(menuEntryData_t));
    lv_memset_00(menuEntryData, sizeof(menuEntryData_t));
    lv_obj_set_user_data(menu_entry, menuEntryData);
    lv_obj_add_event_cb(menu_entry, menuEntryDataDelete, LV_EVENT_DELETE, menuEntryData);
    PRINT_DEBUG("menu_entry title: %s", entry->text[CURRENT_LANGUAGE]);
    PRINT_DEBUG("menu_entry pointer: 0x%X", menu_entry);

    menuEntryData->entry = entry;
    menuEntryData->widget = add_widget(menu_entry);
    menuEntryData->setWidFcn = setWidFcn;
    menuEntryData->entry_container = menu_entry;

    lv_event_code_t exittrigger = LV_EVENT_DEFOCUSED;/////////
    lv_event_cb_t exitsetter = setWidgetOnEvent;/////////

    if (setWidFcn) {
        menuEntryData->setWidFcn(menuEntryData->widget, menuEntryData->entry);
        //setWidgetOnEvent
        lv_obj_add_event_cb(menuEntryData->widget, exitsetter, exittrigger, menuEntryData);/////////
    }
    if (entry->useConfirmBtn) {
        menuEntryData->confirm_btn = add_confirm_btn(menu_entry, entry->confirmActionIcon);
        if (setDataFcn) {
            if(entry->readOnly){
                lv_obj_add_event_cb(menuEntryData->confirm_btn, readOnlyConfirmCallback, LV_EVENT_CLICKED, menuEntryData);
            }
            else{
                lv_obj_add_event_cb(menuEntryData->confirm_btn, setDataFcn, LV_EVENT_CLICKED, menuEntryData);
            }
            lv_obj_add_event_cb(menuEntryData->confirm_btn, exitsetter, exittrigger, menuEntryData);/////////
        }
        else{
            if(entry->readOnly){
                lv_obj_add_event_cb(menuEntryData->confirm_btn, readOnlyConfirmCallback, LV_EVENT_CLICKED, menuEntryData);
            }
        }
    }
    else {
        if (setDataFcn) {
            if(!entry->readOnly){
                lv_obj_add_event_cb(menuEntryData->widget, readOnlyConfirmCallback, LV_EVENT_CLICKED, menuEntryData);
            }
            else{
                lv_obj_add_event_cb(menuEntryData->widget, setDataFcn, LV_EVENT_VALUE_CHANGED, menuEntryData);
            }
        }
        else{
            if(entry->readOnly)
                lv_obj_add_event_cb(menuEntryData->widget, readOnlyConfirmCallback, LV_EVENT_VALUE_CHANGED, menuEntryData);
        }
    }
    
    if (entry->update_period_ms) {
        menuEntryData->timer = lv_timer_create(entryUpdater, entry->update_period_ms, menuEntryData);
    }
    if (entry->readOnly) {
        //make entry selectable again
        //lv_group_t* g = lv_group_get_default();
        //lv_group_add_obj(g, menu_entry);
        //lv_group_remove_obj(menuEntryData->widget);
        // 
        //lv_obj_add_event_cb(menu_entry, clearEditState, LV_EVENT_ALL, menuEntryData);
        lv_obj_add_state(menuEntryData->widget, LV_STATE_DISABLED);
        //lv_obj_clear_flag(menuEntryData->widget, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_CHECKABLE| LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE);

    }
#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return menuEntryData;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif


lv_obj_t* add_wid_from_entry(lv_obj_t* parent, const entry_t* entry) {

    add_text(parent, entry->icon, entry->text[CURRENT_LANGUAGE]);
    switch (entry->wid_type) {
    case entryReference:
        add_reference(parent, (lv_obj_t*)entry->data.v);
        //menu_entry = create_reference(menu_page, entry->icon, entry->text[CURRENT_LANGUAGE], (lv_obj_t*) entry->data.v);
        break;
    case entrySwitch:
    {
        extendMenuEntry(parent, entry, add_switch, setSwitch, setDataFromSwitch);
        break;
    }
    case entrySpin:
    {
        extendMenuEntry(parent, entry, add_spinbox, setSpinbox, setDataFromSpinbox);
        break;
    }
    case entryDropdown:
    {
        extendMenuEntry(parent, entry, add_dropdown, setDropdown, setDataFromDropdown);
        break;
    }
    case entryLedBool:
    {
        extendMenuEntry(parent, entry, add_led, setLed, NULL);
        break;
    }
    case entryLabelText:
    {
        extendMenuEntry(parent, entry, add_textLabel, setTextLabel, NULL);
        break;
    }
    default:

        break;

    }
    return parent;
}


//#define DEBUG_create_entry
#ifdef DEBUG_create_entry
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
static lv_obj_t* create_entry(lv_obj_t* menu_page, const entry_t* entry) {
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif
    lv_obj_t* menu_entry = lv_menu_cont_create(menu_page);
    add_wid_from_entry(menu_entry, entry);

#ifdef SHOW_BEGIN_END    
    PRNT_FEND();
#endif
    return menu_entry;
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif

