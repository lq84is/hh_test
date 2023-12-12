/*
 * TFT_ILI9341.h
 *
 *  Created on: Oct 30, 2020
 *      Author: Mateusz Salamon
 */



#ifndef TFT_CORE_H
#define TFT_CORE_H
#include "main.h"
#include "lv_driver.h"


extern uint16_t POINT_COLOR;	//������ɫ	Ĭ��Ϊ��ɫ
extern uint16_t BACK_COLOR;	//������ɫ	Ĭ��Ϊ��ɫ


extern SPI_HandleTypeDef hspi1;
#define SPI_HAL_HANDLE (hspi1)

//LCD�Ŀ�͸߶���
#define LCD_Width 	240
#define LCD_Height 	240

//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
//#define LIGHTGRAY        0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

/*
	LCD_PWR:	PB7
	LCD_RST:	PB6
	LCD_DC:		PB4
	LCD_CS:		PD7
*/

#define	LCD_RST(n)		(n?HAL_GPIO_WritePin(TFT_RES_GPIO_Port,TFT_RES_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(TFT_RES_GPIO_Port,TFT_RES_Pin,GPIO_PIN_RESET))
#define	LCD_DC(n)		(n?HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_RESET))
#define	LCD_CS(n)		//(n?HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_RESET))



void LCD_Init(void);																	//��ʼ��
void LCD_DisplayOn(void);																//����ʾ
void LCD_DisplayOff(void);																//����ʾ
void LCD_Write_HalfWord(const uint16_t da);													//д����ֽ����ݵ�LCD
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);									//����������ʾ����
void LCD_Clear(uint16_t color);																//����
void LCD_Fill(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color);				//��䵥ɫ
void LCD_Draw_Point(uint16_t x, uint16_t y);														//����
void LCD_Draw_ColorPoint(uint16_t x, uint16_t y,uint16_t color);										//������ɫ��
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);										//����
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);									//������
void LCD_Draw_Circle(uint16_t x0, uint16_t y0, uint8_t r);												//��Բ
void LCD_ShowChar(uint16_t x, uint16_t y, char chr, uint8_t size);										//��ʾһ���ַ�
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);									//��ʾһ������
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);							//��ʾ����
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,char *p);					//��ʾ�ַ���
void LCD_Show_Image(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *p);					//��ʾͼƬ
void Display_ALIENTEK_LOGO(uint16_t x,uint16_t y);												//��ʾALIENTEK LOGO


#endif /* INC_TFT_ILI9341_H_ */
