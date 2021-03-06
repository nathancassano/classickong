; Copyright 2012 Bubble Zap Games
; 
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
; http://www.apache.org/licenses/LICENSE-2.0
; 
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.

;all binary resources are included here
;they are declared as extern variables for C compiler in the data.h


.section ".rodata4" superfree

map1:			.incbin "nametables\map1.rle"
map2:			.incbin "nametables\map2.rle"
map3:			.incbin "nametables\map3.rle"
map4:			.incbin "nametables\map4.rle"
mape:			.incbin "nametables\mape.rle"
mapi:			.incbin "nametables\mapi.rle"

hdmaGradient0List0:
 .db $02,$3F,$0C,$3F,$06,$3F,$07,$3F,$02,$3E,$05,$3E,$06,$3E,$09,$3E,$03,$3D,$01,$3D,$08,$3D,$06,$3D,$07,$3D,$02,$3C,$03,$3C,$07,$3C,$06,$3C,$04,$3B,$03,$3B,$07,$3B,$04,$3B,$02,$3A,$01,$3A,$01,$3A,$01,$39,$02,$39,$01,$39,$02,$38,$02,$37,$01,$37,$01,$36,$01,$35,$01,$35,$01,$34,$01,$33,$01,$33,$02,$32,$01,$31,$01,$30,$01,$2F,$02,$2E,$02,$2D,$01,$2C,$01,$2C,$01,$2B,$01,$2B,$01,$2A,$01,$2A,$01,$29,$02,$28,$03,$27,$03,$26,$03,$26,$02,$26,$02,$26,$07,$26,$02,$26,$02,$26,$06,$26,$04,$26,$04,$26,$03,$26,$01,$26,$04,$26,$06,$26,$03,$27,$16,$27
hdmaGradient0List1:
 .db $02,$5F,$0C,$5F,$06,$5F,$07,$5F,$02,$5F,$05,$5F,$06,$5F,$09,$5F,$03,$5F,$01,$5F,$08,$5F,$06,$5F,$07,$5F,$02,$5F,$03,$5F,$07,$5F,$06,$5F,$04,$5F,$03,$5F,$07,$5F,$04,$5F,$02,$5F,$01,$5F,$01,$5F,$01,$5F,$02,$5F,$01,$5F,$02,$5F,$02,$5F,$01,$5F,$01,$5F,$01,$5F,$01,$5E,$01,$5E,$01,$5E,$01,$5D,$02,$5C,$01,$5C,$01,$5B,$01,$5A,$02,$59,$02,$58,$01,$58,$01,$57,$01,$57,$01,$56,$01,$56,$01,$55,$01,$55,$02,$54,$03,$54,$03,$54,$03,$54,$02,$55,$02,$55,$07,$56,$02,$56,$02,$57,$06,$58,$04,$59,$04,$59,$03,$59,$01,$5A,$04,$5A,$06,$5B,$03,$5B,$16,$5B
hdmaGradient0List2:
 .db $02,$9F,$0C,$9E,$06,$9D,$07,$9C,$02,$9C,$05,$9B,$06,$9A,$09,$99,$03,$99,$01,$98,$08,$97,$06,$96,$07,$95,$02,$95,$03,$94,$07,$93,$06,$92,$04,$92,$03,$91,$07,$90,$04,$8F,$02,$8E,$01,$8D,$01,$8C,$01,$8C,$02,$8B,$01,$8A,$02,$89,$02,$88,$01,$87,$01,$87,$01,$87,$01,$87,$01,$86,$01,$86,$01,$86,$02,$86,$01,$86,$01,$86,$01,$86,$02,$86,$02,$86,$01,$86,$01,$86,$01,$86,$01,$86,$01,$86,$01,$86,$01,$86,$02,$86,$03,$86,$03,$86,$03,$87,$02,$87,$02,$88,$07,$88,$02,$89,$02,$89,$06,$89,$04,$89,$04,$88,$03,$87,$01,$87,$04,$86,$06,$86,$03,$86,$16,$86

hdmaGradient1List0:
 .db $02,$3F,$0C,$3E,$02,$3E,$04,$3D,$04,$3D,$03,$3C,$06,$3C,$01,$3B,$06,$3A,$02,$3A,$07,$39,$06,$38,$01,$38,$05,$37,$05,$37,$03,$36,$05,$35,$05,$34,$07,$33,$01,$33,$05,$32,$04,$32,$03,$31,$07,$30,$04,$2F,$02,$2E,$01,$2D,$01,$2C,$03,$2B,$01,$2A,$01,$2A,$01,$29,$02,$28,$01,$27,$01,$27,$01,$27,$01,$27,$01,$26,$01,$26,$01,$26,$02,$26,$02,$26,$01,$26,$01,$26,$01,$26,$01,$26,$01,$26,$02,$26,$02,$26,$01,$26,$01,$26,$03,$26,$01,$26,$03,$26,$03,$26,$02,$26,$02,$26,$02,$26,$02,$26,$01,$26,$04,$26,$04,$26,$04,$26,$02,$26,$04,$26,$01,$26,$03,$26,$04,$26,$04,$26,$06,$26,$19,$26
hdmaGradient1List1:
 .db $02,$5F,$0C,$5F,$02,$5F,$04,$5F,$04,$5F,$03,$5F,$06,$5F,$01,$5F,$06,$5F,$02,$5F,$07,$5F,$06,$5F,$01,$5F,$05,$5F,$05,$5F,$03,$5F,$05,$5F,$05,$5F,$07,$5F,$01,$5F,$05,$5F,$04,$5F,$03,$5F,$07,$5F,$04,$5F,$02,$5F,$01,$5F,$01,$5F,$03,$5F,$01,$5F,$01,$5F,$01,$5F,$02,$5F,$01,$5F,$01,$5F,$01,$5F,$01,$5E,$01,$5E,$01,$5E,$01,$5D,$02,$5C,$02,$5B,$01,$5A,$01,$5A,$01,$59,$01,$59,$01,$58,$02,$57,$02,$56,$01,$56,$01,$55,$03,$54,$01,$54,$03,$54,$03,$54,$02,$54,$02,$55,$02,$55,$02,$54,$01,$55,$04,$55,$04,$55,$04,$56,$02,$57,$04,$57,$01,$58,$03,$59,$04,$5A,$04,$5A,$06,$5B,$19,$5B
hdmaGradient1List2:
 .db $02,$9F,$0C,$9F,$02,$9E,$04,$9E,$04,$9D,$03,$9D,$06,$9C,$01,$9C,$06,$9C,$02,$9B,$07,$9A,$06,$9A,$01,$99,$05,$99,$05,$98,$03,$98,$05,$97,$05,$96,$07,$96,$01,$95,$05,$95,$04,$94,$03,$94,$07,$93,$04,$92,$02,$91,$01,$91,$01,$90,$03,$8F,$01,$8F,$01,$8E,$01,$8E,$02,$8E,$01,$8E,$01,$8D,$01,$8E,$01,$8D,$01,$8D,$01,$8E,$01,$8D,$02,$8E,$02,$8E,$01,$8E,$01,$8F,$01,$8E,$01,$8F,$01,$8F,$02,$8F,$02,$8F,$01,$90,$01,$90,$03,$90,$01,$91,$03,$92,$03,$93,$02,$94,$02,$94,$02,$95,$02,$95,$01,$95,$04,$96,$04,$97,$04,$97,$02,$98,$04,$99,$01,$99,$03,$99,$04,$99,$04,$98,$06,$98,$19,$98

hdmaGradient2List0:
 .db $02,$3F,$0C,$3E,$06,$3D,$07,$3C,$07,$3B,$06,$3A,$09,$39,$04,$38,$08,$37,$06,$36,$07,$35,$05,$34,$07,$33,$06,$32,$07,$31,$07,$30,$04,$2F,$02,$2E,$01,$2D,$01,$2C,$01,$2C,$02,$2B,$01,$2A,$02,$29,$02,$28,$01,$27,$01,$26,$01,$26,$02,$25,$01,$24,$02,$23,$02,$22,$01,$21,$01,$21,$01,$20,$02,$20,$01,$20,$01,$20,$02,$20,$01,$20,$01,$20,$01,$20,$01,$20,$01,$20,$01,$20,$02,$20,$01,$20,$01,$20,$02,$20,$01,$20,$02,$20,$02,$20,$02,$20,$04,$20,$02,$20,$04,$20,$05,$20,$06,$20,$04,$20,$01,$20,$02,$20,$04,$20,$01,$20,$04,$21,$02,$21,$04,$21,$15,$21
hdmaGradient2List1:
 .db $02,$5F,$0C,$5F,$06,$5F,$07,$5F,$07,$5F,$06,$5F,$09,$5F,$04,$5F,$08,$5F,$06,$5F,$07,$5F,$05,$5F,$07,$5F,$06,$5F,$07,$5F,$07,$5F,$04,$5F,$02,$5F,$01,$5F,$01,$5F,$01,$5E,$02,$5E,$01,$5E,$02,$5E,$02,$5D,$01,$5D,$01,$5D,$01,$5C,$02,$5B,$01,$5B,$02,$5A,$02,$59,$01,$58,$01,$57,$01,$56,$02,$55,$01,$54,$01,$52,$02,$51,$01,$50,$01,$4F,$01,$4E,$01,$4D,$01,$4C,$01,$4B,$02,$4A,$01,$49,$01,$48,$02,$47,$01,$46,$02,$45,$02,$44,$02,$43,$04,$43,$02,$42,$04,$42,$05,$42,$06,$43,$04,$44,$01,$45,$02,$46,$04,$47,$01,$48,$04,$49,$02,$4A,$04,$4B,$15,$4B
hdmaGradient2List2:
 .db $02,$9F,$0C,$9F,$06,$9F,$07,$9F,$07,$9F,$06,$9F,$09,$9F,$04,$9F,$08,$9F,$06,$9F,$07,$9F,$05,$9F,$07,$9F,$06,$9F,$07,$9F,$07,$9F,$04,$9F,$02,$9F,$01,$9F,$01,$9F,$01,$9F,$02,$9F,$01,$9F,$02,$9F,$02,$9F,$01,$9F,$01,$9F,$01,$9F,$02,$9F,$01,$9F,$02,$9F,$02,$9F,$01,$9F,$01,$9F,$01,$9F,$02,$9F,$01,$9E,$01,$9E,$02,$9D,$01,$9C,$01,$9C,$01,$9C,$01,$9C,$01,$9B,$01,$9B,$02,$9A,$01,$9A,$01,$9A,$02,$9A,$01,$9A,$02,$9B,$02,$9B,$02,$9B,$04,$9C,$02,$9C,$04,$9D,$05,$9E,$06,$9F,$04,$9F,$01,$9F,$02,$9F,$04,$9F,$01,$9F,$04,$9F,$02,$9F,$04,$9F,$15,$9F

hdmaGradient3List0:
 .db $02,$3F,$4E,$3F,$01,$3F,$02,$3F,$01,$3F,$01,$3F,$03,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$02,$3F,$02,$3F,$02,$3F,$01,$3F,$01,$3F,$02,$3F,$02,$3F,$02,$3F,$02,$3F,$01,$3F,$01,$3F,$02,$3F,$02,$3F,$01,$3F,$01,$3F,$02,$3F,$02,$3F,$03,$3F,$01,$3E,$01,$3E,$01,$3D,$02,$3C,$02,$3B,$01,$3B,$01,$3B,$01,$3A,$01,$3A,$01,$39,$01,$39,$01,$38,$01,$37,$03,$36,$02,$35,$01,$34,$03,$33,$02,$32,$02,$31,$02,$30,$02,$2F,$02,$2E,$01,$2E,$01,$2D,$02,$2C,$03,$2B,$02,$2A,$01,$29,$03,$28,$01,$27,$02,$26,$02,$26,$01,$25,$01,$24,$03,$23,$03,$22,$01,$21,$01,$21,$01,$20,$26,$20
hdmaGradient3List1:
 .db $02,$5D,$4E,$5D,$01,$5C,$02,$5D,$01,$5C,$01,$5C,$03,$5C,$01,$5B,$01,$5B,$01,$5C,$01,$5B,$02,$5B,$02,$5B,$02,$5A,$01,$5B,$01,$5A,$02,$5A,$02,$5A,$02,$59,$02,$5A,$01,$59,$01,$59,$02,$59,$02,$59,$01,$58,$01,$58,$02,$58,$02,$58,$03,$57,$01,$57,$01,$56,$01,$56,$02,$55,$02,$54,$01,$55,$01,$54,$01,$54,$01,$53,$01,$53,$01,$52,$01,$53,$01,$51,$03,$50,$02,$50,$01,$4F,$03,$4E,$02,$4E,$02,$4D,$02,$4C,$02,$4B,$02,$4B,$01,$4A,$01,$4A,$02,$49,$03,$48,$02,$47,$01,$47,$03,$46,$01,$45,$02,$45,$02,$44,$01,$44,$01,$43,$03,$42,$03,$41,$01,$41,$01,$40,$01,$40,$26,$40
hdmaGradient3List2:
 .db $02,$95,$4E,$94,$01,$93,$02,$93,$01,$92,$01,$91,$03,$90,$01,$90,$01,$8F,$01,$8F,$01,$8E,$02,$8D,$02,$8C,$02,$8B,$01,$8B,$01,$8A,$02,$89,$02,$88,$02,$87,$02,$86,$01,$86,$01,$85,$02,$84,$02,$83,$01,$83,$01,$82,$02,$81,$02,$80,$03,$80,$01,$80,$01,$80,$01,$80,$02,$80,$02,$80,$01,$80,$01,$80,$01,$80,$01,$80,$01,$80,$01,$80,$01,$80,$01,$80,$03,$80,$02,$80,$01,$80,$03,$80,$02,$80,$02,$80,$02,$80,$02,$80,$02,$80,$01,$80,$01,$80,$02,$80,$03,$80,$02,$80,$01,$80,$03,$80,$01,$80,$02,$80,$02,$80,$01,$80,$01,$80,$03,$80,$03,$80,$01,$80,$01,$80,$01,$80,$26,$80

hdmaGradient4List0:
 .db $02,$37,$4D,$36,$02,$35,$03,$34,$01,$33,$03,$32,$01,$31,$02,$30,$01,$30,$01,$2F,$02,$2E,$02,$2D,$02,$2C,$02,$2B,$02,$2A,$02,$29,$02,$28,$01,$28,$01,$27,$02,$26,$01,$26,$01,$25,$01,$25,$01,$24,$02,$23,$01,$22,$02,$22,$01,$21,$01,$21,$01,$20,$01,$20,$03,$20,$01,$20,$01,$20,$02,$20,$02,$20,$02,$20,$01,$20,$01,$20,$01,$20,$02,$20,$01,$20,$02,$20,$01,$20,$03,$20,$01,$20,$03,$20,$02,$20,$02,$20,$01,$20,$01,$20,$01,$20,$01,$20,$02,$20,$02,$20,$02,$20,$02,$20,$02,$20,$02,$20,$01,$20,$01,$20,$02,$20,$01,$20,$02,$20,$02,$20,$03,$20,$01,$20,$03,$20,$25,$20
hdmaGradient4List1:
 .db $02,$5B,$4D,$5B,$02,$5A,$03,$59,$01,$59,$03,$58,$01,$58,$02,$57,$01,$58,$01,$57,$02,$57,$02,$56,$02,$55,$02,$55,$02,$55,$02,$54,$02,$54,$01,$53,$01,$53,$02,$53,$01,$52,$01,$52,$01,$51,$01,$52,$02,$51,$01,$51,$02,$50,$01,$4F,$01,$50,$01,$50,$01,$4F,$03,$4F,$01,$4E,$01,$4E,$02,$4D,$02,$4D,$02,$4D,$01,$4C,$01,$4C,$01,$4C,$02,$4B,$01,$4B,$02,$4B,$01,$4A,$03,$4A,$01,$49,$03,$48,$02,$48,$02,$48,$01,$47,$01,$47,$01,$47,$01,$46,$02,$46,$02,$45,$02,$45,$02,$45,$02,$44,$02,$44,$01,$43,$01,$43,$02,$43,$01,$42,$02,$42,$02,$41,$03,$41,$01,$40,$03,$40,$25,$40
 hdmaGradient4List2:
 .db $02,$9F,$4D,$9F,$02,$9F,$03,$9F,$01,$9F,$03,$9F,$01,$9F,$02,$9F,$01,$9F,$01,$9F,$02,$9F,$02,$9F,$02,$9F,$02,$9F,$02,$9F,$02,$9F,$02,$9F,$01,$9F,$01,$9F,$02,$9F,$01,$9F,$01,$9F,$01,$9F,$01,$9F,$02,$9F,$01,$9F,$02,$9F,$01,$9F,$01,$9F,$01,$9F,$01,$9F,$03,$9E,$01,$9E,$01,$9D,$02,$9C,$02,$9B,$02,$9A,$01,$9A,$01,$99,$01,$98,$02,$98,$01,$97,$02,$96,$01,$95,$03,$94,$01,$93,$03,$92,$02,$91,$02,$90,$01,$90,$01,$8F,$01,$8E,$01,$8E,$02,$8D,$02,$8C,$02,$8B,$02,$8A,$02,$89,$02,$88,$01,$88,$01,$87,$02,$86,$01,$85,$02,$84,$02,$83,$03,$82,$01,$81,$03,$80,$25,$80

hdmaGradient5List0:
 .db $02,$3F,$0C,$3F,$06,$3F,$03,$3F,$04,$3F,$01,$3F,$01,$3F,$02,$3F,$04,$3F,$02,$3F,$03,$3F,$05,$3F,$04,$3F,$03,$3F,$01,$3F,$08,$3F,$01,$3F,$05,$3F,$07,$3F,$05,$3F,$08,$3F,$05,$3F,$03,$3F,$04,$3F,$03,$3F,$04,$3F,$02,$3F,$02,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$01,$3F,$02,$3F,$01,$3F,$01,$3F,$01,$3E,$02,$3E,$01,$3D,$03,$3C,$02,$3B,$01,$3A,$02,$39,$02,$38,$01,$38,$01,$37,$02,$36,$02,$36,$01,$35,$03,$35,$01,$34,$03,$34,$02,$34,$02,$35,$04,$35,$05,$36,$04,$36,$02,$37,$01,$37,$05,$38,$04,$39,$04,$39,$04,$3A,$04,$3A,$06,$3B,$19,$3B
hdmaGradient5List1:
 .db $02,$5F,$0C,$5E,$06,$5E,$03,$5D,$04,$5D,$01,$5C,$01,$5D,$02,$5C,$04,$5C,$02,$5B,$03,$5B,$05,$5A,$04,$5A,$03,$59,$01,$59,$08,$58,$01,$58,$05,$57,$07,$56,$05,$55,$08,$54,$05,$54,$03,$53,$04,$53,$03,$52,$04,$52,$02,$51,$02,$51,$01,$50,$01,$50,$01,$4F,$01,$4E,$01,$4F,$01,$4E,$01,$4D,$01,$4D,$01,$4C,$01,$4C,$02,$4C,$01,$4B,$01,$4B,$01,$4B,$02,$4B,$01,$4B,$03,$4C,$02,$4C,$01,$4D,$02,$4D,$02,$4D,$01,$4E,$01,$4E,$02,$4E,$02,$4F,$01,$4F,$03,$50,$01,$50,$03,$51,$02,$52,$02,$53,$04,$54,$05,$55,$04,$56,$02,$56,$01,$57,$05,$57,$04,$58,$04,$57,$04,$57,$04,$56,$06,$56,$19,$56
hdmaGradient5List2:
 .db $02,$9F,$0C,$9E,$06,$9D,$03,$9D,$04,$9C,$01,$9C,$01,$9C,$02,$9C,$04,$9B,$02,$9B,$03,$9A,$05,$9A,$04,$99,$03,$99,$01,$98,$08,$98,$01,$97,$05,$96,$07,$95,$05,$94,$08,$93,$05,$92,$03,$92,$04,$91,$03,$91,$04,$90,$02,$90,$02,$8F,$01,$8F,$01,$8E,$01,$8E,$01,$8D,$01,$8C,$01,$8C,$01,$8B,$01,$8A,$01,$8A,$01,$89,$02,$88,$01,$88,$01,$87,$01,$87,$02,$86,$01,$86,$03,$86,$02,$86,$01,$86,$02,$86,$02,$86,$01,$86,$01,$86,$02,$86,$02,$86,$01,$86,$03,$86,$01,$86,$03,$86,$02,$86,$02,$86,$04,$86,$05,$86,$04,$86,$02,$86,$01,$86,$05,$86,$04,$86,$04,$86,$04,$86,$04,$86,$06,$86,$19,$86
 
hdmaGradient6List0:
 .db $02,$3F,$0A,$3F,$06,$3F,$09,$3F,$06,$3F,$08,$3F,$08,$3F,$08,$3F,$07,$3F,$06,$3F,$0A,$3F,$45,$3F,$0A,$3F,$05,$3F,$08,$3F,$08,$3F,$07,$3F,$08,$3F,$06,$3F,$0A,$3F,$05,$3F,$08,$3F
hdmaGradient6List1:
 .db $02,$5F,$0A,$5F,$06,$5F,$09,$5F,$06,$5F,$08,$5F,$08,$5F,$08,$5F,$07,$5F,$06,$5F,$0A,$5F,$45,$5F,$0A,$5F,$05,$5F,$08,$5F,$08,$5F,$07,$5F,$08,$5F,$06,$5F,$0A,$5F,$05,$5F,$08,$5F
hdmaGradient6List2:
 .db $02,$95,$0A,$96,$06,$97,$09,$98,$06,$99,$08,$9A,$08,$9B,$08,$9C,$07,$9D,$06,$9E,$0A,$9F,$45,$9E,$0A,$9D,$05,$9C,$08,$9B,$08,$9A,$07,$99,$08,$98,$06,$97,$0A,$96,$05,$95,$08,$95

 
tileset2alt_gfx:	.incbin "gfx\tileset2alt.chr"

music_title_data:	.incbin "sound\music_title.bin" FSIZE _music_title_size
music_title_size:	.dw _music_title_size

music_game_start_data:	.incbin "sound\music_game_start.bin" FSIZE _music_game_start_size
music_game_start_size:	.dw _music_game_start_size

music_stage_start_data:	.incbin "sound\music_stage_start.bin" FSIZE _music_stage_start_size
music_stage_start_size:	.dw _music_stage_start_size

music_stage_clear_data:	.incbin "sound\music_stage_clear.bin" FSIZE _music_stage_clear_size
music_stage_clear_size:	.dw _music_stage_clear_size

music_hammer_data:	.incbin "sound\music_hammer.bin" FSIZE _music_hammer_size
music_hammer_size:	.dw _music_hammer_size

music_level1_data:	.incbin "sound\music_level1.bin" FSIZE _music_level1_size
music_level1_size:	.dw _music_level1_size

music_lose_data:	.incbin "sound\music_lose.bin" FSIZE _music_lose_size
music_lose_size:	.dw _music_lose_size

music_time_out_data:	.incbin "sound\music_time_out.bin" FSIZE _music_time_out_size
music_time_out_size:	.dw _music_time_out_size

music_victory_data:	.incbin "sound\music_victory.bin" FSIZE _music_victory_size
music_victory_size:	.dw _music_victory_size

.ends



.section ".rodata5" superfree

title_top_gfx:		.incbin "gfx\title_top.chr"
title_bottom_gfx:	.incbin "gfx\title_bottom.chr"
font_gfx:			.incbin "gfx\font.chr"
tileset1_gfx:		.incbin "gfx\tileset1.chr"
tileset2_gfx:		.incbin "gfx\tileset2.chr"
sprites1_gfx:		.incbin "gfx\sprites1.chr"
sprites2_gfx:		.incbin "gfx\sprites2.chr"
sprites3_gfx:		.incbin "gfx\sprites3.chr"
sprites4_gfx:		.incbin "gfx\sprites4.chr"
sprites5_gfx:		.incbin "gfx\sprites5.chr"

back1_pal:			.incbin "gfx\back1.pal"
font_pal:			.incbin "gfx\font.pal"
tileset1_pal:		.incbin "gfx\tileset1.pal"
tileset1alt1_pal:	.incbin "gfx\tileset1alt1.pal"
tileset1alt2_pal:	.incbin "gfx\tileset1alt2.pal"
tileset2_pal:		.incbin "gfx\tileset2.pal"
tileset2alt_pal:	.incbin "gfx\tileset2alt.pal"
sprites1_pal:		.incbin "gfx\sprites1.pal"
sprites2_pal:		.incbin "gfx\sprites2.pal"
sprites3_pal:		.incbin "gfx\sprites3.pal"
sprites4_pal:		.incbin "gfx\sprites4.pal"
sprites5_pal:		.incbin "gfx\sprites5.pal"
sprites5alt_pal:	.incbin "gfx\sprites5alt.pal"
sprites6_pal:		.incbin "gfx\sprites6.pal"
title_top_pal:		.incbin "gfx\title_top.pal"
title_bottom_pal:	.incbin "gfx\title_bottom.pal"
bzlogo_pal:			.incbin "gfx\bubblezaplogo.pal"

.ends



.section ".rodata6" superfree

spc700_data:	.incbin "spc700.bin" FSIZE _spc700_size
spc700_size:	.dw _spc700_size

.ends



.section ".rodata7" superfree

back1_gfx:		.incbin "gfx\back1.chr"
bzlogo_gfx:		.incbin "gfx\bubblezaplogo.chr"
sprites6_gfx:	.incbin "gfx\sprites6.chr"

.ends
