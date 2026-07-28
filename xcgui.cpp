#include "pxt.h"

/*
 * These public headers are supplied by the codal-xc-gui-bin repository.
 * They are not duplicated in this MakeCode extension repository.
 */
#include "LCD.h"
#include "XGUI.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/* Symbols supplied by libXC_GUI.a and the bitmap source files. */
extern "C"
{
    extern XGUI_DRIVER g_LCD_ST7789_DRV;
    extern const XC_FONT g_FontOpenSansLight48;

    extern const uint16_t bmp_clock[];
    extern const uint16_t bmpneedle_hour120[];
    extern const uint16_t bmpneedle_min120[];
    extern const uint16_t bmpneedle_sec120[];
}

namespace 
{
    /* Same buffer sizes as the working CODAL test application. */
    static XC_DATA g_aBuf[4096 * 2];
    static GUI_HANDLE g_hGUI;

    static int g_nCount = 0;
    static char g_textBuf[64] = "00";

    static float g_secondAngle = 10.0f;
    static float g_minuteAngle = 20.0f;
    static float g_hourAngle = 30.0f;

    static uint16_t g_HandTemp[11 * 120];
    static uint16_t g_HandMinTemp[10 * 100];
    static uint16_t g_HandHourTemp[10 * 80];

    static bool g_initialized = false;
}

/*
 * XC_GUI calls this application callback from GUI_Draw_Exe().
 * C linkage is required because XC_GUI is compiled as C in libXC_GUI.a.
 */
extern "C" void GUI_AppDraw(size_t bFrameStart)
{
    if (bFrameStart == 1)
    {
        ++g_nCount;

        if (g_nCount >= 99)
        {
            g_nCount = 0;
        }

        snprintf(g_textBuf, sizeof(g_textBuf), "%02d", g_nCount);
        g_secondAngle = static_cast<float>(g_nCount);
    }

    GUI_Clear(XC_Blue);
    GUI_DrawBitmap(bmp_clock, 0, 0);

    GUI_DrawBitmapRotatedTransparentAt(
        bmpneedle_hour120,
        118,
        124,
        5,
        12,
        g_hourAngle + 180.0f,
        0x0000,
        2,
        g_HandHourTemp,
        10 * 80
    );

    GUI_DrawBitmapRotatedTransparentAt(
        bmpneedle_min120,
        118,
        124,
        4,
        14,
        g_minuteAngle + 180.0f,
        0x0000,
        2,
        g_HandMinTemp,
        10 * 100
    );

    GUI_DrawBitmapRotatedTransparentAt(
        bmpneedle_sec120,
        118,
        124,
        5,
        15,
        g_secondAngle + 180.0f,
        0x0000,
        2,
        g_HandTemp,
        11 * 120
    );

    GUI_PrintString(g_textBuf, XC_White, 0, 250);
}

namespace xcgui
{
    //%
    void initialize()
    {
        if (g_initialized)
        {
            return;
        }

        /* MakeCode has already initialized pxt::uBit. */
        GUI_Init(
            &g_hGUI,
            g_aBuf,
            sizeof(g_aBuf),
            GUI_PIXEL_FORMAT_RGB565,
            &g_LCD_ST7789_DRV,
            0,
            LCD_PORTRAIT
        );

        GUI_ATH(&g_hGUI, "www.gigasitron.com");
        GUI_16BitPerPixel(0);
        GUI_SetPenWidth(1);
        GUI_SetFont(&g_FontOpenSansLight48);

        g_initialized = true;
    }

    //%
    void drawFrame()
    {
        if (!g_initialized)
        {
            initialize();
        }

        GUI_Draw_Exe();
    }

    //%
    void resetDemo()
    {
        g_nCount = 0;
        g_secondAngle = 10.0f;
        g_minuteAngle = 20.0f;
        g_hourAngle = 30.0f;
        snprintf(g_textBuf, sizeof(g_textBuf), "%02d", g_nCount);
    }
}
