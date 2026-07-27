/**
 * XC_GUI graphics support for Gigasitron LCD modules.
 */
//% color="#1976D2" weight=90 icon="\uf108" block="XC_GUI"
namespace xcGUI {
    const LCD_RST = DigitalPin.P8
    const LCD_DC = DigitalPin.P12
    const LCD_SCK = DigitalPin.P13
    const LCD_MISO = DigitalPin.P14
    const LCD_MOSI = DigitalPin.P15
    const LCD_CS = DigitalPin.P16

    let hardwareInitialized = false

    /**
     * Test the XC_GUI extension.
     */
    //% blockId=xc_gui_test
    //% block="test XC_GUI extension"
    //% weight=100
    export function testExtension(): void {
        basic.showString("XC")
    }

    /**
     * Configure SPI and reset the LCD.
     */
    //% blockId=xc_gui_initialize_hardware
    //% block="initialize XC_GUI hardware"
    //% weight=90
    export function initializeHardware(): void {
        pins.digitalWritePin(LCD_CS, 1)
        pins.digitalWritePin(LCD_DC, 1)
        pins.digitalWritePin(LCD_RST, 1)

        pins.spiPins(
            LCD_MOSI,
            LCD_MISO,
            LCD_SCK
        )

        pins.spiFormat(8, 0)
        pins.spiFrequency(1000000)

        pins.digitalWritePin(LCD_RST, 1)
        basic.pause(10)

        pins.digitalWritePin(LCD_RST, 0)
        basic.pause(20)

        pins.digitalWritePin(LCD_RST, 1)
        basic.pause(150)

        hardwareInitialized = true
    }

    /**
     * Check whether the hardware was initialized.
     */
    //% blockId=xc_gui_hardware_is_initialized
    //% block="XC_GUI hardware is initialized"
    //% weight=80
    export function isHardwareInitialized(): boolean {
        return hardwareInitialized
    }
}
