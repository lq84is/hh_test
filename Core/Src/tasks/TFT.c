#include "TFT.h"
//#include "boiler_data.h"
#include "AuxFunctions/PrintDebug.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

//#include "semaphores.h"
#include "stm32f1xx_hal.h"

//#include "rtc.h"
//#include "io_pins.h"

//#include "encoder.h"
//#include "encoder_lvgl_drv.h"

#include "../lvgl/lvgl.h"

#include "ST7789/core.h"
#include "ST7789/lv_driver.h"

#include "../lvgl/examples/lv_examples.h"
#include "spi.h"

//#include "../interface/interface.h"
#include "LVGL_Custom/display_settings.h"

#include "lv_demos.h"

#define hspi_handle hspi2

static lv_disp_draw_buf_t disp_buf;
#define ILI_SCR_HORIZONTAL 240
#define ILI_SCR_VERTICAL   240
#define BUFFOR_SCR_ROWS 2
//static lv_color_t buf_1[ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS] ;
//static lv_color_t buf_2[ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS] ; //__attribute__ ((section (".LvBufferSection")))
                                                                //DMA don't have acces to CCMRAM :(
                                                                //I don't have so too much time on experiments
static lv_disp_drv_t disp_drv;

//lv_group_t* enc_group; 


#define DEBUG_StartTFT
#ifdef DEBUG_StartTFT
#define SHOW_BEGIN_END
#define PRINT_DEBUG PRINT_DEBUG_TRACE
#else
#define PRINT_DEBUG(...) do{}while(0);
#endif
void StartTFT(void const * argument)
{
#ifdef SHOW_BEGIN_END
    PRNT_FBEGIN();
#endif
    
    LCD_Init();
    vTaskDelay(pdMS_TO_TICKS(30));
    
//    lv_init();
//   
//    lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS);
//    
//    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
//    disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
//    disp_drv.flush_cb = tft_flush;      /*Set a flush callback to draw to the display*/
//    disp_drv.hor_res = ILI_SCR_HORIZONTAL;  /*Set the horizontal resolution in pixels*/
//    disp_drv.ver_res = ILI_SCR_VERTICAL;    /*Set the vertical resolution in pixels*/
//    
//    disp_drv.sw_rotate = 1;
//    disp_drv.rotated = 0;//SCREEN_ROTATION;
//    
//    lv_disp_drv_register(&disp_drv);        /*Register the driver and save the created display objects*/ 
//    vTaskDelay(pdMS_TO_TICKS(10));
//    
//    
//    //ILI9341_fillRect(319, 0, 1, 241, 0);
//    
//    lv_example_spinbox_1();
//    //interfaceStart();
    PRINT_DEBUG("Running");
    TickType_t xLastWakeTime = xTaskGetTickCount();
    for(;;)
    {
        //PRINT_DEBUG("Stack remain: %d", uxTaskGetStackHighWaterMark(NULL));
        //lv_task_handler();
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(5));
    }
}
#ifdef SHOW_BEGIN_END
#undef SHOW_BEGIN_END
#endif
#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#endif
