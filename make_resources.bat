@echo off

rem convert all graphics

path=path;tools\
del gfx\*.chr >nul
del gfx\*.pal >nul
snesbmp gfx\font.bmp -b
snesbmp gfx\tileset1.bmp -b
snesbmp gfx\tileset1alt.bmp -b
snesbmp gfx\tileset2.bmp -b
snesbmp gfx\sprites1.bmp -b
snesbmp gfx\sprites2.bmp -b
snesbmp gfx\sprites3.bmp -b
snesbmp gfx\sprites4.bmp -b
snesbmp gfx\sprites5.bmp -b
snesbmp gfx\sprites6.bmp -b
snesbmp gfx\title_top.bmp -b
snesbmp gfx\title_bottom.bmp -b
snesbmp gfx\back1.bmp -b
snesbmp gfx\back2.bmp -b
snesbmp gfx\back3.bmp -b
snesbmp gfx\back4.bmp -b
snesbmp gfx\back5.bmp -b
snesbmp gfx\bubblezaplogo.bmp -b -256