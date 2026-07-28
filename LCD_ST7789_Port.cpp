#include "pxt.h"
#include "NRF52SPI.h"
#include "inc/LCD_ST7789_Port.h"

using namespace pxt;
using namespace codal;

/*
 * MakeCode creates and initializes pxt::uBit.
 * Create the LCD SPI peripheral only when XC_GUI initializes the driver.
 */
static NRF52SPI *g_lcdSpi = nullptr;

void ST7789_Port_Init(void)
{
    if (g_lcdSpi == nullptr)
    {
        /* Constructor order: MOSI, MISO, SCK. */
        g_lcdSpi = new NRF52SPI(
            uBit.io.P15,
            uBit.io.P14,
            uBit.io.P13
        );
    }

    /* LCD control-pin inactive states. */
    uBit.io.P8.setDigitalValue(1);     // RESET high
    uBit.io.P12.setDigitalValue(1);    // CS inactive
    uBit.io.P16.setDigitalValue(1);    // DC data mode

    g_lcdSpi->setMode(0, 8);
    g_lcdSpi->setFrequency(8000000);
}

void ST7789_RST_Write(uint8_t value)
{
    uBit.io.P8.setDigitalValue(value != 0);
}

void ST7789_CS_Write(uint8_t value)
{
    uBit.io.P12.setDigitalValue(value != 0);
}

void ST7789_DC_Write(uint8_t value)
{
    uBit.io.P16.setDigitalValue(value != 0);
}

void ST7789_SPI_WriteByte(uint8_t value)
{
    if (g_lcdSpi != nullptr)
    {
        g_lcdSpi->write(value);
    }
}

void ST7789_SPI_Write(const uint8_t *data, uint32_t length)
{
    if (g_lcdSpi == nullptr || data == nullptr || length == 0)
    {
        return;
    }

    constexpr uint32_t MAX_TRANSFER_SIZE = 65535;

    while (length > 0)
    {
        const uint32_t transferSize =
            length > MAX_TRANSFER_SIZE ? MAX_TRANSFER_SIZE : length;

        g_lcdSpi->transfer(
            data,
            transferSize,
            nullptr,
            0
        );

        data += transferSize;
        length -= transferSize;
    }
}

void ST7789_DelayMs(uint32_t milliseconds)
{
    uBit.sleep(milliseconds);
}
