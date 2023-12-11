#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include "AuxFunctions/compound_types.h"
#include "AuxFunctions/PrintDebug.h"
#include "../lvgl/lvgl.h"

typedef enum{
    nothing = 0,
    up_e,
    down_e,
    right_e,
    left_e,
    left_right_e,
    enter_e,
}menuCommands_e;

typedef enum {
    etryDummy  = 0,
    entryReference, //to page

    entrySwitch,    //bool
    entryCheckbox,  //bool
    entryLedBool,   //bool
    entryDropdown,  //digital variable, represented as text

    entrySpin,      //digital
    entryLedAnalog, //digital
    
    entryLabelText,
    entryLabelInt,
    entryLabelFloat,

}entryWidgetType;

typedef struct entry_s{
    void (*sel_callback)(const struct entry_s*);//pointer to this entry will be passed

    translations_t* str_storage;
    val_p  data;//pointer to data
    val_t  min;
    val_t  max;
    val_t  inc;
    type_tip type;
    const char* icon;
    const char* text[2];
    const char* confirmActionIcon;//if 
    //void (*confirmAction)(struct entry_s*, void* widget_data);
    uint16_t update_period_ms;
    entryWidgetType wid_type;
    uint32_t color; //for LED

    unsigned sbDidgitNum      : 6;  //used in spinbox to display float values (to user), can be integer divided by power of 10
    unsigned sbDigitAfterDot  : 3;  //used in spinbox to display float values (to user), can be integer divided by power of 10
    unsigned useConfirmBtn    : 1;  //show/hide confirm button
                                    //call sel_callback
    //unsigned displayData      : 1;  //show/hide widget (spinbox, switch, diode, dropdown, etc.)
    unsigned readOnly         : 1;  //make editing widget disabled, confirm button will be showed to focus on entry
    unsigned confirmWhileEdit : 1;  //if 1, call sel_callback after changing value of editing widget,
                                    //if 0, call sel_callback after pressing confirm button,useConfirmBtn will be ignored
    unsigned updateAlways     : 1;  //update even if focused
}entry_t;

typedef struct menuPage_s {
  const entry_t* entries;
  uint32_t size;
  uint32_t selectedIndex;
  uint32_t activeIndex;
  void (*thisPageDrawer)(lv_event_t* e);//has to have its own screen
  const char* title[2];
  struct menuPage_s* pageBack;
  void (*backFunctionDrawer)(lv_event_t* e);
}menuPage_t;

extern menuPage_t main_page;

void setDefaultExitMenuFunction(void (*exitFunctionDrawer)(lv_event_t*));
void defaultMenuPageDrawer(lv_event_t* e);



void setActivePage(void* data, type_tip none);
void setActivePageWrap(entry_t* entry);
void renderMenu(void);
void printEntry(const entry_t* e);

//menu_entry has to have entry in user date
lv_obj_t* add_spinbox(lv_obj_t* menu_entry);
lv_obj_t* create_spinbox_from_entry(lv_obj_t* parent, const entry_t* entry);
void resize_spinbox_to_entry_and_font(lv_obj_t* sb, const entry_t* entry, lv_font_t* used_font);
lv_obj_t* default_menu_create(lv_obj_t* parent, menuPage_t* page_dsc);
lv_obj_t* add_wid_from_entry(lv_obj_t* parent, const entry_t* entry);
lv_obj_t* add_text(lv_obj_t* parent, const char* icon, const char* txt);

#endif

