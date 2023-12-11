#ifndef DISPLAY_SETTINGS_H
#define DISPLAY_SETTINGS_H

#include "lvgl/lvgl.h"
#include "AuxFunctions/compound_types.h"
#include "AuxFunctions/char_strings.h"

typedef enum {
    lang_EN,
    lang_RU,
    lang_max,
}langs_e;

extern translations_t language_str;
extern translations_t back_str;


//32bit aligned
typedef struct display_settings_s {
    uint16_t screen_timeout_s;
    uint8_t language;
    uint8_t brightness;
    uint8_t rotation;
}display_settings_t;

typedef union{
    display_settings_t members;
    char array_c[SIZEOF_PACK32TYPE(display_settings_t)];
}display_settings_nvm_data_u_aligned4;

extern display_settings_nvm_data_u_aligned4  DisplaySettings;

#define CURRENT_LANGUAGE (DisplaySettings.members.language)
#define SCREEN_TIMEOUT_S (DisplaySettings.members.screen_timeout_s)
#define SCREEN_BRIGHTNES (DisplaySettings.members.brightness)
#define SCREEN_ROTATION  (DisplaySettings.members.rotation)

#define INACTIVE_TIMEOUT_CHECK_MS (5000)

void setTimerLoadMainScreenOnInactivity(lv_obj_t* parent, uint32_t check_every_ms);

#endif
