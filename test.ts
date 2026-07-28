basic.showIcon(IconNames.SmallDiamond)

xcgui.initialize()
xcgui.resetDemo()

basic.showIcon(IconNames.Yes)

basic.forever(function () {
    xcgui.drawFrame()
    basic.pause(10)
})
