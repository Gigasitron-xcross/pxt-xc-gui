#ifndef LCD_ST7789_PORT_H
#define LCD_ST7789_PORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ST7789_Port_Init(void);

void ST7789_RST_Write(uint8_t value);
void ST7789_CS_Write(uint8_t value);
void ST7789_DC_Write(uint8_t value);

void ST7789_SPI_WriteByte(uint8_t value);
void ST7789_SPI_Write(const uint8_t *data, uint32_t length);

void ST7789_DelayMs(uint32_t milliseconds);

#ifdef __cplusplus
}
#endif

#endif