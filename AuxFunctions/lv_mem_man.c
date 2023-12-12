#include "lv_mem_man.h"

#include "lvgl/lvgl.h"

#include "AuxFunctions/PrintDebug.h"
#include "AuxFunctions/char_strings.h"


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void container_deleted_free_data(lv_event_t* event)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif    
    void* data = lv_event_get_user_data(event);
    lv_mem_free(data);
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


//#define DEBUG_FUNCTION
#ifdef  DEBUG_FUNCTION
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void container_deleted_del_timer(lv_event_t* event)
{
#ifdef SHOW_BEGIN_END    
    PRNT_FBEGIN();
#endif    
    lv_timer_t* timer = lv_event_get_user_data(event);
    lv_timer_del(timer);
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
