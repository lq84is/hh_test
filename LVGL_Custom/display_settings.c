#include "display_settings.h"
#include "main_screen.h"
#include "AuxFunctions/lv_mem_man.h"


translations_t language_str = {
    {"English", "English"},
    {"Русский", "Русский"},
};

translations_t back_str = {
    {"Back", "Назад"},
};

display_settings_nvm_data_u_aligned4  DisplaySettings = {
    .members.brightness = 100,
    .members.language = lang_RU,
    .members.screen_timeout_s = 60,
    .members.rotation = LV_DISP_ROT_NONE,
};


static void screenTimeOut(lv_timer_t* timer) {
    if (lv_disp_get_inactive_time(NULL) >= (SCREEN_TIMEOUT_S * 1000)) {
        mainScreenSet(NULL);
    }
}

void setTimerLoadMainScreenOnInactivity(lv_obj_t* parent, uint32_t check_every_ms) {
    lv_timer_t* timer_screenTimeout = lv_timer_create(screenTimeOut, check_every_ms, NULL);
    lv_obj_add_event_cb(parent, container_deleted_del_timer, LV_EVENT_DELETE, timer_screenTimeout);

}
