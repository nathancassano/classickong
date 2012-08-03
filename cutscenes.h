/*

Copyright 2012 Bubble Zap Games

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at 

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

//set kong floor hitting animation frame
//used in the levels clear cutscene

void kong_stand_animation_both(void)
{
	kong_frame=kongAnimationBoth[kong_frame_cnt>>2];

	++kong_frame_cnt;

	if(kong_frame_cnt>=6<<2)
	{
		sfx_play(SFX_CHN+1,SFX_KONG_RIGHT,kong_x+16);
		kong_frame_cnt=0;
	}
}



//show levels clear cutscene

void cutscene_levels_clear(void)
{
	static unsigned int ptr,frame,spr;
	static unsigned char i,j,x,bright,fall_start,fall_ground,princess_frame,bounce_cnt;
	static unsigned char platform_y[4];
	static unsigned char platform_hit[4];
	static int ky,kdy;

	set_bright(0);
	setup_hdma_gradient(-1);
	oam_clear();

	setup_ingame_graphics();
	clear_nametables();
	set_background(4);

	unrle(map,mape);

	for(ptr=0;ptr<32*32;++ptr) nametable1[ptr]=map[ptr]+0x0140|BG_PAL(1)|BG_PRI;

	update_nametables();
	setup_palettes();
	update_palette();

	bright=0;

	platform_y[0]=55;
	platform_y[1]=55+40;
	platform_y[2]=55+80;
	platform_y[3]=55+120;

	for(i=0;i<4;++i) platform_hit[i]=0;

	ky=23<<6;
	kdy=0;

	kong_x=112;
	kong_frame_cnt=0;

	princess_x=48;
	princess_y=27;
	princess_frame=0;

	player_x=192;
	player_y=39;

	particles_clear();
	kong_stand_animation_both();

	setup_hdma_gradient(5);

	for(i=0;i<128;++i) oam_size(i<<2,1);//set all sprites to 16x16 size

	spc_volume(global_volume);//unmute sound after previous fade out

	ptr=0xf7;
	fall_start=FALSE;
	fall_ground=FALSE;
	bounce_cnt=0;

	for(frame=0;frame<14*60;++frame)
	{
		nmi_wait();
		copy_vram(POS(8,7),(unsigned char*)&nametable1[POS(8,7)],16*2);//update the bridge area of the nametable

		if(bright<15)
		{
			++bright;
			set_bright(bright);
		}

		if(frame<6*4*6)
		{
			/*kong is just stands hitting the floor for few first frames*/
			
			kong_stand_animation_both();
		}
		else
		{
			/*then platforms and kong falling sequence starts*/
			
			if(platform_y[0]>=200)
			{
				if(bounce_cnt<5)
				{
					if(!fall_start)
					{
						fall_start=TRUE;

						sfx_play(SFX_CHN+2,SFX_KONG_FALLS,128);
					}

					ky+=kdy;

					if(kdy<(2<<6)) kdy+=6;

					if(ky>=(182<<6))
					{
						ky=182<<6;

						kdy=0-((kdy<<6)/96);
						++bounce_cnt;

						if(!fall_ground)
						{
							fall_ground=TRUE;
							kong_frame=kongLargeSpriteFell;

							sfx_play(SFX_CHN+2,SFX_KONG_FELL,128);
						}
					}

					if(!fall_ground) kong_frame=(kong_y&16)?kongLargeSpriteFalling1:kongLargeSpriteFalling2;
				}
			}
			else
			{
				platform_y[0]+=2;
			}

			//move platforms down
			
			for(i=0;i<4;++i)
			{
				if(platform_y[i]<200)//if it didn't hit the floor yet
				{
					if(i&&platform_y[i]<platform_y[i-1]+8)//if it touched previous platform
					{
						if(!platform_hit[i])//register the first hit (another platform)
						{
							platform_hit[i]=1;
							sfx_play(SFX_CHN+3,SFX_RAFT_FALL,128);
						}

						platform_y[i]=platform_y[i-1]+8;//align platform to the previous
					}
				}
				else//if it hit the floor
				{
					if(platform_hit[i]<2)//register the second hit (floor)
					{
						platform_hit[i]=2;
						sfx_play(SFX_CHN+3,SFX_RAFT_FALL,128);
					}
				}
			}
		}

		//update all sprites
		
		kong_y=ky>>6;

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		oam_spr1(player_x,player_y,playerWalkAnimLeft[(player_x>>1)&3],OAM_PLAYER);

		spr=64<<2;

		for(i=0;i<4;++i)
		{
			x=72;

			for(j=0;j<7;++j)
			{
				oam_spr1(x,platform_y[i],PLAYER_TILE+0x4e|PLAYER_ATR,spr);
				x+=16;
				spr+=4;
			}
		}

		particle_process();

		/*when kong is on the ground, start victory music*/
		
		if(frame==350) music_play(MUS_VICTORY);

		/*put the bridge into the nametable piece by piece*/
		
		if(frame>420&&!(frame&3))
		{
			if(ptr>0xe7)
			{
				nametable1[ptr--]=0x0145|BG_PAL(1)|BG_PRI;
			}
		}

		princess_frame=game_frame_cnt&32?2:0;

		/*when the bridge is fully appeared, mario and princess start slowly walking to each other*/
		
		if(frame>400+80)
		{
			i=frame%3;

			if(princess_x<(128-16-16))
			{
				if(!i) ++princess_x;

				princess_frame=game_frame_cnt&8?1:0;
			}

			if(!i)
			{
				if(player_x>(128+16)) --player_x;
			}
		}

		/*when they come closer, a heart appears*/
		
		if(frame==670)
		{
			particle_add(PART_TYPE_HEART,120,32);
			sfx_play(SFX_CHN+3,SFX_LOVE,128);
		}

		/*after a pause they start to move again, now faster*/
		
		if(frame>14*60-30)
		{
			if(frame&1)
			{
				++princess_x;
				--player_x;
			}

			princess_frame=game_frame_cnt&8?1:0;
		}

		++game_frame_cnt;
	}

	fade_screen(FALSE,TRUE);
}



//show the 'how high you can get' cutscene

void cutscene_level(void)
{
	static unsigned char i,bright,delay;
	static unsigned int frame,ptr;
	const char* const heightStr[]={"100 M  $"," 50 M  $"," 25 M  $"};
	static int stack_y[3],stack_ty[3],stack_dy[3];
	static unsigned char stack_frame[3],stack_jump[3],stack_delay[3];
	static int y;

	set_bright(0);
	setup_hdma_gradient(-1);
	oam_clear();

	setup_ingame_graphics();
	clear_nametables();
	set_background(-1);

	for(i=0;i<3;++i) put_str(&nametable1[POS(5,7+i*6)],heightStr[i]);

	put_str(&nametable1[POS(5,25)],"HOW HIGH CAN YOU GET?");

	update_nametables();
	setup_palettes();
	update_palette();

	y=(40+48*2)<<6;

	for(i=0;i<3;++i)
	{
		stack_y    [i]=-32<<6;
		stack_ty   [i]=y;
		stack_dy   [i]=0;
		stack_frame[i]=0;
		stack_jump [i]=0;
		stack_delay[i]=i*25;

		y-=(48<<6);
	}

	for(i=0;i<128;++i) oam_size(i<<2,1);

	bright=0;
	delay=25;

	spc_volume(global_volume);

	for(frame=0;frame<250;++frame)
	{
		nmi_wait();

		if(bright<15)
		{
			++bright;
			set_bright(bright);
		}

		for(i=0;i<game_level+1;++i)
		{
			if(stack_delay[i])
			{
				--stack_delay[i];
				continue;
			}

			if(stack_jump[i]<3)
			{
				stack_y[i]+=stack_dy[i];

				if(stack_dy[i]<(4<<6)) stack_dy[i]+=6;

				if(stack_y[i]>=stack_ty[i])
				{
					stack_y [i]=stack_ty[i];
					stack_dy[i]=0-((stack_dy[i]<<6)/160);

					++stack_jump[i];
				}
			}

			if(stack_jump[i])
			{
				if(game_frame_cnt&1)
				{
					if(stack_frame[i]<3) ++stack_frame[i];
				}
			}

			kong_frame=kongAnimationStartCutscene[stack_frame[i]];

			game_show_kong(i<<4,128-16,stack_y[i]>>6);
		}

		if(delay)
		{
			--delay;

			if(!delay) music_play(MUS_STAGE_START);
		}

		++game_frame_cnt;
	}

	fade_screen(FALSE,TRUE);
}



//update bending platform for the intro cutscene

void cutscene_update_platform(unsigned int off,unsigned int ptr,unsigned char wdt,char dx)
{
	static unsigned char i,j,cnt,hgt;

	off<<=5;
	cnt=0;
	hgt=1;

	for(i=0;i<wdt;++i)
	{
		j=platformAnimCnt[off];

		if(j<hgt)
		{
			j<<=1;

			nametable1[ptr+0 ]=platformAnim[j+0];
			nametable1[ptr+32]=platformAnim[j+1];

			++platformAnimCnt[off];
		}

		ptr+=dx;

		++off;
		++cnt;

		if(cnt==3)
		{
			cnt=0;

			if(hgt<7) ++hgt;
		}
	}
}



//update falling ladders fragments for the intro cutscene

void cutscene_intro_show_ladders(void)
{
	static unsigned char i,delay;

	for(i=0;i<LADDERS_MAX;++i)
	{
		if(ladders_y[i]>=240) continue;

		oam_spr1(ladders_x[i],ladders_y[i],BARREL_TILE+0x0e|BARREL_ATR,(127-i)<<2);

		if(ladders_delay[i])
		{
			--ladders_delay[i];
			continue;
		}

		ladders_y[i]+=2;
	}
}



//update princess coordinates according to the kong coordinates for the intro cutscene

unsigned char cutscene_intro_princess_hold(unsigned char hold,unsigned char shift)
{
	static unsigned char princess_frame;

	if(hold)
	{
		princess_x=kong_x+24-3;
		princess_y=kong_y-(game_frame_cnt&8?0:1);
		princess_frame=0;
	}
	else
	{
		if(shift&&!(game_frame_cnt&3)&&princess_y>3) --princess_y;
		princess_frame=game_frame_cnt&32?2:0;
	}

	return princess_frame;
}



//show the intro cutscene

void cutscene_intro(void)
{
	static unsigned char i,j,y,bright,hold,jump_cnt,princess_frame;
	static unsigned int frame,ptr;
	static int ky,kdy;

	set_bright(0);
	setup_hdma_gradient(-1);
	oam_clear();

	setup_ingame_graphics();
	clear_nametables();
	set_background(-1);

	unrle(map,mapi);

	for(ptr=0;ptr<32*32;++ptr) nametable1[ptr]=map[ptr]+0x0140|BG_PAL(1);

	update_nametables();
	setup_palettes();
	update_palette();

	for(i=0;i<128;++i) oam_size(i<<2,1);

	for(i=0;i<6*32;++i) platformAnimCnt[i]=0;

	music_play(MUS_GAME_START);

	y=224-8;

	for(i=0;i<LADDERS_MAX;++i)
	{
		ladders_x[i]=!(i&1)?118:130;
		ladders_y[i]=y;
		ladders_delay[i]=50+(i<<3)+(rand()&15);

		if(i&1) y-=16;
	}

	cutscene_intro_show_ladders();

	kong_x=128-16+3;
	kong_y=240;

	bright=0;

	princess_frame=0;

	/* kong is climbing up */

	while(kong_y>40)
	{
		nmi_wait();

		if(bright<15)
		{
			++bright;
			set_bright(bright);
		}

		kong_frame=game_frame_cnt&8?kongLargeSpriteClimb1:kongLargeSpriteClimb2;
		--kong_y;

		princess_frame=cutscene_intro_princess_hold(TRUE,TRUE);

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		cutscene_intro_show_ladders();

		++game_frame_cnt;
	}

	/* kong jumps onto the floor and releases the princess */

	ky=kong_y<<6;
	kdy=-1<<6;
	hold=TRUE;

	while(1)
	{
		nmi_wait();

		ky+=kdy;
		++kdy;

		if(kdy>0) ++kdy;

		kong_y=ky>>6;

		if(kong_y<10) hold=FALSE;

		princess_frame=cutscene_intro_princess_hold(hold,TRUE);

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);
		cutscene_intro_show_ladders();

		++game_frame_cnt;

		if(kdy>0&&kong_y>=25)
		{
			kong_y=25;
			break;
		}
	}

	/* kong jumps to the position, platforms are bending every jump */

	kong_frame=kongLargeSpriteFace4Both;
	kdy=-1<<6;
	jump_cnt=0;
	frame=0;

	while(1)
	{
		nmi_wait();
		copy_vram(0x0000,(unsigned char*)nametable1,32*32*2);

		if(bright<15)
		{
			++bright;
			set_bright(bright);
		}

		if(game_frame_cnt&1)
		{
			if(jump_cnt==6) cutscene_update_platform(0,POS(27,25),27,-1);
			if(jump_cnt==5) cutscene_update_platform(1,POS( 4,21),24, 1);
			if(jump_cnt==4) cutscene_update_platform(2,POS(27,18),24,-1);
			if(jump_cnt==3) cutscene_update_platform(3,POS( 4,14),24, 1);
			if(jump_cnt==2) cutscene_update_platform(4,POS(27,10),24,-1);
			if(jump_cnt==1) cutscene_update_platform(5,POS(19, 7), 9, 1);
		}

		cutscene_intro_show_ladders();

		if(jump_cnt<6)
		{
			kong_y=ky>>6;

			if(kong_y>=24) kong_y=24;

			ky+=kdy;
			kdy+=4;

			if(!(game_frame_cnt&1)) --kong_x;

			if(ky>=(24<<6))
			{
				ky=24<<6;
				kdy=-1<<6;
				++jump_cnt;

				sfx_play(SFX_CHN+1,SFX_KONG_RIGHT,kong_x+16);
			}
		}

		princess_frame=game_frame_cnt&32?2:0;

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		++game_frame_cnt;

		if(jump_cnt>=6)
		{
			j=frame>>2;
			if(j>3) j=3;

			kong_frame=kongAnimationBoth[3-j];

			++frame;

			if(frame>=48) break;
		}
	}

	/* kong laugh */

	for(i=0;i<5*16;++i)
	{
		nmi_wait();

		if((i&15)==0)
		{
			sfx_play(SFX_CHN+1,SFX_KONG_LAUGH,kong_x+16);
			kong_frame=kongLargeSpriteLaugh;
		}

		if((i&15)==8)
		{
			kong_frame=kongLargeSpriteFace1;
		}

		princess_frame=game_frame_cnt&32?2:0;

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		++game_frame_cnt;
	}

	delay(25);

	fade_screen(FALSE,TRUE);
}


//show the level 1 and 2 clear cutscene

void cutscene_next_level(void)
{
	static unsigned char i,princess_frame,hold;
	static int ky,kdy,kong_oy;
	const unsigned char heart_x=120,heart_y=16;

	/* heart appears */

	enemy_clear();
	enemy_process(0);

	kong_frame=kongLargeSpriteFace1;
	game_show_kong(OAM_KONG,kong_x,kong_y);

	for(i=0;i<16;++i)
	{
		nmi_wait();
		oam_spr(heart_x,heart_y+((15-i)>>1),PRINCESS_TILE+((i&2)^2)+0x0c|PRINCESS_ATR,OAM_PARTICLES);
	}

	delay(25);

	/* kong jumps from his position to the ladder, grabbing the princess in the process */

	kong_frame=kongLargeSpriteClimb1;

	kong_oy=kong_y+1;
	ky=kong_y<<4;
	kdy=-1<<4;
	hold=FALSE;

	while(kong_x<78)
	{
		nmi_wait();

		ky+=kdy;
		++kdy;
		kong_y=ky>>4;
		if(kong_y>kong_oy) kong_y=kong_oy;
		++kong_x;
		if(kong_x>=60) hold=TRUE;

		princess_frame=cutscene_intro_princess_hold(hold,FALSE);

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		++game_frame_cnt;
	}

	/* kong climbs away with the princess */

	while(kong_y>-32)
	{
		nmi_wait();

		if(game_frame_cnt&1) --kong_y;

		kong_frame=game_frame_cnt&8?kongLargeSpriteClimb1:kongLargeSpriteClimb2;
		princess_frame=cutscene_intro_princess_hold(TRUE,FALSE);

		game_show_kong(OAM_KONG,kong_x,kong_y);
		game_show_princess(princess_frame);

		++game_frame_cnt;
	}

	/* the heart gets broken */

	delay(16);

	oam_spr(heart_x,heart_y,PLAYER_TILE+0x4c|PLAYER_ATR,OAM_PARTICLES);
	sfx_play(SFX_CHN,SFX_CRACK,heart_x);

	delay(80);
}
