/* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#ifndef __LCD_H
#define __LCD_H
#include "stdlib.h"
#include "stdint.h"

//LCD��Ҫ������
typedef struct
{
    unsigned short 		width;			//LCD ���
    unsigned short 		height;			//LCD �߶�
    unsigned short 		id;				  //LCD ID
    unsigned char  		dir;			  //���������������ƣ�0��������1��������
    unsigned short	 	wramcmd;		//��ʼдgramָ��
    unsigned short  	rramcmd;   //��ʼ��gramָ��
    unsigned short  	setxcmd;		//����x����ָ��
    unsigned short  	setycmd;		//����y����ָ��
} _lcd_dev;

//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
/////////////////////////////////////�û�������///////////////////////////////////
#define USE_HORIZONTAL  	 0 //����Һ����˳ʱ����ת���� 	0-0����ת��1-90����ת��2-180����ת��3-270����ת

//////////////////////////////////////////////////////////////////////////////////
//����LCD�ĳߴ�
#define LCD_W 480
#define LCD_H 800

//TFTLCD������Ҫ���õĺ���
extern unsigned short  POINT_COLOR;//Ĭ�Ϻ�ɫ
extern unsigned short  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ


//LCD��ַ�ṹ��
typedef struct
{
    volatile unsigned short LCD_REG;
    volatile unsigned short LCD_RAM;
} LCD_TypeDef;

//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A15��Ϊ��������������
//ע������ʱSTM32�ڲ�������һλ����!
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x0000FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

//������ɫ
#define WHITE       0xFFFF
#define BLACK      	0x0000
#define BLUE       	0x001F
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ

#define LIGHTGREEN     	0X841F //ǳ��ɫ
#define LIGHTGRAY     	0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

void 								lcd_init(void);
unsigned short 			lcd_read(void);
void 								lcd_clear(unsigned short color);
void 								lcd_setcursor(unsigned short xpos, unsigned short ypos);
void 								lcd_drawpoint(unsigned short x,unsigned short y);//����
unsigned short  		lcd_readpoint(unsigned short x,unsigned short y); //����
void 								lcd_setwindows(unsigned short xstar, unsigned short ystar,unsigned short xend,unsigned short yend);
unsigned short 			lcd_rd_data(void);//��ȡlcd����
void 								lcd_writereg(unsigned short lcd_reg, unsigned short lcd_regvalue);
void 								lcd_wr_reg(unsigned short data);
void 								lcd_wr_data(unsigned short data);
void 								lcd_readreg(unsigned short lcd_reg,unsigned short *rval,int n);
void 								lcd_writeram_prepare(void);
void 								lcd_readram_prepare(void);
void 								lcd_writedata_16bit(unsigned short data);
unsigned short 			lcd_readdata_16bit(void);
void 								lcd_direction(unsigned char direction );
unsigned short 			lcd_read_id(void);
unsigned short 			color_to_565(unsigned char r, unsigned char g, unsigned char b);

#endif





