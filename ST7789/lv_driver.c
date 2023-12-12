#include "core.h"
#include "lv_driver.h"
#include "stdlib.h"

static lv_disp_drv_t *LastDriver;

// void ILI9341_flush(struct _disp_drv_t * drv, const lv_area_t * area,  lv_color_t * color_map)
void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area,  lv_color_t * color_map)
{
    LCD_Show_Image(area->x1,area->y1,area->x2-area->x1+1,area->y2-area->y1+1,(uint8_t *)color_map);
    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(drv);
}
//void DMA_ILI9341_SPI_TransmitComplete_Callback(void)
//{
//	lv_disp_flush_ready(LastDriver);
//}






