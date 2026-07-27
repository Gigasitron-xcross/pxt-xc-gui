    /*
     * Native function implemented by xcgui.cpp.
     */
    //% shim=xcgui_native::testMagic
    function testMagicNative(): number {
        return 0
    }

    /**
     * Test whether the XC_GUI static library is linked.
     */
    //% blockId=xc_gui_test_static_library
    //% block="test XC_GUI static library"
    //% weight=98
    export function testStaticLibrary(): void {
        const result = testMagicNative()

        if (result == 0x5843) {
            basic.showString("XC")
        } else {
            basic.showString("ER")
        }
    }
