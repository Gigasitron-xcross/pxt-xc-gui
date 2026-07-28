/*****************************************************************************
 @Project	: 
 @File 		: XGUI.h
 @Details  	: 
 @Author	: Gigasitron Xcross
 @Hardware	: Any
 
 --------------------------------------------------------------------------
 @Revision	:
  Ver  	Author    	Date        	Changes
 --------------------------------------------------------------------------
   1.0  Name     XXXX-XX-XX  		Initial Release
   2.0
   3.0
   
******************************************************************************/

#ifndef __XGUI_DOT_H__
#define __XGUI_DOT_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "XC_GUI_Types.h"
#include "LCD.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 Define
******************************************************************************/
typedef struct s_tagGUI_HANDLE
{
	uint32_t array[23];
}GUI_HANDLE, *PGUI_HANDLE;
 

/*****************************************************************************
 Pixel format
******************************************************************************/
typedef enum
{
    GUI_PIXEL_FORMAT_RGB565 = 16,
    GUI_PIXEL_FORMAT_MONO1  = 1
} GUI_PIXEL_FORMAT;

/*****************************************************************************
 Macro
******************************************************************************/


/******************************************************************************
 Fonts - List of selectable fonts Please use DP_FontGen.exe to generate more
******************************************************************************/
//extern const GUI_FONT g_sFontCalibri10;
//extern const GUI_FONT g_sFontCalibri24;


/******************************************************************************
 Global functions
******************************************************************************/

/******************************************************************************
 @Description 	: Must authorise first using password "www.gigasitron.com" call after GUI_Init()

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
char *GUI_ATH( GUI_HANDLE  *pHandle,    char *pPassword );


/******************************************************************************
 @Description 	: Intialization of GUI libary.  This is hardware independent.
				  User need to intializes all LCD pins and Peripherals interface 
				  at Hal.c

 @param			: pHandle  - Mempty handle from user. User are not allow to access
				             this handle. 
				  nMaxPhyX - Physical LCD Horizontal size in pixel
				  nMaxPhyY - Physical LCD Vertical size in pixel
				  pBuf     - Array to store pixels before send to LCD
				  nSize	   - arrary size in byte. Suggested to use 'sizeof()'

 @revision		: 1.0.0
 
******************************************************************************/
XC_GUI_STATUS GUI_Init(
	GUI_HANDLE          *pHandle,
	void                *pBuf,
	int                 nSize,
    GUI_PIXEL_FORMAT    PixelFormat,
    XGUI_DRIVER         *pDriver,
	void                *pHwHandle,
	LCD_ORIENTATION 	Orientation );


void GUI_AttachDriver(GUI_HANDLE  *pHandle, const  XGUI_DRIVER  *pDriver);

/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_AddCbFrameEnd( XC_FRAME_END_CALLBACK *pFrameComplete );
		
void GUI_AddCbBlockEnd( XC_BLOCK_END_CALLBACK *pBlockComplete );

/******************************************************************************
 @Description 	: Transfer memory pixel in 16bits. User responsible to ensure 
				  that its interface support 16 per pixel transfer

 @param			: bEn - TRUE/FALSE - Enable/Disable
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_16BitPerPixel( size_t bEn );
		

/******************************************************************************
 @Description 	: Transfer memory pixel data to LCD base on buffer size. It will 
				  callback to GUI_AppDraw() several time without waiting until
				  1 frame of LCD is painted. consume less time.

 @param			: None. But GUI_AppDraw() callback need to be prepared for 
				  this function
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_Draw_Exe( void );


/******************************************************************************
 @Description 	: Transfer memory pixel data to LCD base on buffer size. It will 
				  callback to GUI_AppDraw() several time and waiting until
				  1 frame of LCD is painted. consume more time but LCD is 
				  painted in oneshot

 @param			: None. But GUI_AppDraw() callback need to be prepared for 
				  this function
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawEx_Exe( void );


/******************************************************************************
 @Description 	: Callback for LCD painting. This function is to display user
				  Graphics

 @param			: bFrameStart - This flag indicate that when you can update your
								dynamic data. If data if updated before previous
								frame is complelely patined, a corrupted display 
								might observed withiin a short period
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_AppDraw( size_t bFrameStart );


/******************************************************************************
 @Description 	: To clear the LCD to a specified color

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_Clear( XC_COLOR Color );


/******************************************************************************
 @Description 	: Set color for geometry drawing

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_SetColor( XC_COLOR Color );


/******************************************************************************
 @Description 	: Set already converted 16bit color for geometry drawing

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_SetColor16( uint16_t Color );

/******************************************************************************
 @Description 	: Set pen line width for geometry drawing

 @param			: minimum is 1
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_SetPenWidth( int nWidth );


/******************************************************************************
 @Description 	: Draw a line

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawLine(
        int x0,
        int y0,
        int x1,
        int y1,
        XC_COLOR Color );



/******************************************************************************
 @Description 	: Draw a Triangle

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawTriangle(
    int x0,
    int y0,
    int x1,
    int y1,
    int x2,
    int y2,
    XC_COLOR Color );


/******************************************************************************
 @Description 	: Draw a Triangle

 @param			: Color - color code such as ClrBlue
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawFilledTriangle(
    int x0,
    int y0,
    int x1,
    int y1,
    int x2,
    int y2,
    XC_COLOR Color
);
/******************************************************************************
 @Description 	: Draw a circle with its location, radius and color

 @param			: nPosX - Horizontal position in pixel
				  nPosY - Vertical position in pixel
				  nRadius - Radius in pixel
				  Color - color code
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawCircle( int nPosX, int nPosY, int nRadius, size_t bFill, XC_COLOR Color ) ;



/******************************************************************************
 @Description 	: Draw a rectangle with its location, radius and color

 @param			: Left - Left position in pixel
				  Top - Top position in pixel
				  Right - Right position in pixel
				  Bottom - Bottom position in pixel
				  Color - color code
 @revision		: 1.0.0
 
******************************************************************************/
void
GUI_DrawRect(
    int 		Left,
    int 		Top,
    int 		Right,
    int 		Bottom,
    XC_COLOR  Color );

/******************************************************************************
 @Description 	: Draw a Filled rectangle with its location, radius and color

 @param			: Left - Left position in pixel
				  Top - Top position in pixel
				  Right - Right position in pixel
				  Bottom - Bottom position in pixel
				  Color - color code
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawFilledRect(
			int 		Left,
			int 		Top,
			int 		Right,
			int 		Bottom,
            XC_COLOR  Color );


/******************************************************************************
 @Description 	: Select Font from available font

 @param			: pFont - point to avaialble font. such as GUI_CONSOLE10_FONT
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_SetFont( const XC_FONT *pFont );


/******************************************************************************
 @Description 	: Select font background color

 @param			: Color - color code
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_FontBackColorEnable( uint8_t bEn );
void GUI_SetFontBackColor( XC_COLOR Color );
void GUI_SetFontBackColor16( uint16_t Color );


/******************************************************************************
 @Description 	: Print a charactor on screen with postion and color. Use 
				  "GUI_SetFontBackColor()" to set your font background color

 @param			: Charactor - ascii to print
				  Color - Color code
				  nPosX - Horizontal position in pixel
				  nPosY - Vertical position in pixel
				  
 @revision		: 1.0.0
 
******************************************************************************/
uint8_t GUI_PrintChar(
			char 		Charactor,
			XC_COLOR 	Color,
			int 		nPosX,
			int		 	nPosY );


/******************************************************************************
 @Description 	: Print a string on LCD with location and specified color

 @param			: pStr - string to print
				  Color - Color code
				  nPosX - Horizontal position in pixel
				  nPosY - Vertical position in pixel
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_PrintString(
			void const 	*pStr,
			XC_COLOR 	Color,
			int 		nPosX,
			int 		nPosY );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawBitmap( void const *pBmp, int nPosX, int nPosY );
			
	
/******************************************************************************
 @Description 	: This function is using FF Chan system to access SD card to display
				  Bitmap. Only bitmap with 160x128 or less supported

			@param			: pPath - File path on Sd card.eg. "0://A.bmp"
 
 @revision		: 1.0.0
 
******************************************************************************/			
#ifdef __FF_EN
void GUI_DrawBitmapFile( char *pPath, int nPosX, int nPosY );
#endif
			
/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawVertLine( int nX, int Top, int Bottom,  XC_COLOR Color );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawHortLine( int nY, int Left, int Right,  XC_COLOR Color );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawPolygon( const GUI_POINT *points, int count, size_t bFill, XC_COLOR color );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawRotatedPolygon(
    const GUI_POINT *points,
    int count,
    int cx,
    int cy,
    float angleDeg,
    size_t bFill,
    XC_COLOR color );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawRotatedPolygonAt(
    const GUI_POINT *points,
    int count,
    int posX,
    int posY,
    float angleDeg,
    size_t bFill,
    XC_COLOR color
);


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawBitmapRotatedAt(
    void const *pBmp,
    int centerX,
    int centerY,
    float angleDeg,
    uint16_t *pTempRaw,
    uint32_t tempPixelCount );


/******************************************************************************
 @Description 	: 

 @param			: 
 
 @revision		: 1.0.0
 
******************************************************************************/
void GUI_DrawBitmapRotatedTransparentAt(
    void const *pBmp,
    int nPosX,
    int nPosY,
    int nPivotX,
    int nPivotY,
    float angleDeg,
    uint16_t transparentColor,
    uint8_t tolerance,
    uint16_t *pTempRaw,
    uint32_t tempPixelCount );

#ifdef __cplusplus
}
#endif

#endif /* __XGUI_DOT_H__ */
















































