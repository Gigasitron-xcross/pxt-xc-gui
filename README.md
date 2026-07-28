# XC_GUI for micro:bit V2

This MakeCode extension uses a precompiled XC_GUI/ST7789 static library from:

`https://github.com/Gigasitron-xcross/codal-xc-gui-bin`

The private library repository must export these public headers through its
CMake include path:

- `XGUI.h`
- `LCD.h`
- `LCD_ST7789_Port.h`

The MakeCode extension contains only:

- TypeScript blocks (`xcgui.ts`)
- the native MakeCode wrapper (`xcgui.cpp`)
- the micro:bit-specific SPI/GPIO adapter (`LCD_ST7789_Port.cpp`)
- the clock demonstration bitmap data

## Test in MakeCode

1. Open `https://makecode.microbit.org/`.
2. Create a new project.
3. Open **Extensions**.
4. Paste the GitHub URL of this repository.
5. Add **initialize XC GUI**.
6. Run **draw XC GUI frame** inside a `forever` loop with a short pause.
7. Download the HEX for a micro:bit V2.

Example:

```typescript
xcgui.initialize()

basic.forever(function () {
    xcgui.drawFrame()
    basic.pause(10)
})
```

The external LCD is not simulated in the MakeCode simulator.
