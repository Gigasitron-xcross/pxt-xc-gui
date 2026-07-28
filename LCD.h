/*****************************************************************************
 @Project	: 
 @File 		: 
 @Details  	:                   
 @Author	: 
 @Hardware	: 
 
 --------------------------------------------------------------------------
 @Revision	:
  Ver  	Author    	Date        	Changes
 --------------------------------------------------------------------------
   1.0  Name     XXXX-XX-XX  		Initial Release
   
******************************************************************************/

#ifndef __LCD_DRIVER_DOT_H__
#define __LCD_DRIVER_DOT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
 Define
******************************************************************************/


/*****************************************************************************
 Type definiton
******************************************************************************/
typedef void LCD_CB_DONE( void );


typedef enum _tagLCD_ORIENTATION
{
	LCD_PORTRAIT,
	LCD_LANDSCAPE
}
LCD_ORIENTATION;

typedef void XGUI_DRV_LCD_INIT( void *pSpimHandle, LCD_ORIENTATION Orientation );
typedef void XGUI_DRV_LCD_SET_MEMBUF( void *pBuf, uint32_t nByte );
typedef int  XGUI_DRV_LCD_GET_SIZE( int *pScreenX, int *pScreenY );
typedef void XGUI_DRV_LCD_RESET( void );
typedef void XGUI_DRV_LCD_SET_WINDOW(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
typedef void XGUI_DRV_LCD_WR_PIXEL( void const *pData, int nPixel );
typedef void XGUI_DRV_LCD_PUT_PIXEL(int16_t x, int16_t y, char color);
typedef void XGUI_DRV_LCD_ADD_CALLBACK( LCD_CB_DONE *pDone );


typedef struct _tagXGUI_DRIVER
{
    XGUI_DRV_LCD_INIT *pInit;
    XGUI_DRV_LCD_SET_MEMBUF *pSetMemBuf;
    XGUI_DRV_LCD_GET_SIZE *pGetSize;
    XGUI_DRV_LCD_RESET *pReset;
    XGUI_DRV_LCD_SET_WINDOW *pSetWindow;
    XGUI_DRV_LCD_WR_PIXEL *pWritePixel;
    XGUI_DRV_LCD_PUT_PIXEL *pPutPixel;
    XGUI_DRV_LCD_ADD_CALLBACK *cbDone;
} XGUI_DRIVER, *PXGUI_DRIVER;


/*****************************************************************************
 Macro
******************************************************************************/


/******************************************************************************
 Global functions
******************************************************************************/


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
//void LcdInit( void *pSpimHandle, LCD_ORIENTATION Orientation );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
//void LCD_GetSize( int *pScreenX, int *pScreenY );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
//void LCD_AddCallback( LCD_CB_DONE *pDone );

#ifdef __cplusplus
}
#endif

#endif /* __LCD_DRIVER_DOT_H__ */









