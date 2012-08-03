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

//clear enemy list

void enemy_clear(void)
{
	static unsigned char i;
	
	memset(enemy_type,ENEMY_NONE,ENEMY_MAX);
	
	enemy_free=0;
	
	for(i=0;i<ENEMY_MAX;++i) oam_spr(0,240,0,OAM_ENEMY+(i<<2));

}



//add an enemy into the list

void enemy_add(unsigned char type,int x,int y,int dx)
{
	static unsigned char i,j,off,take_ladder,crazy;

	i=enemy_free;

	for(j=0;j<ENEMY_MAX;++j)
	{
		if(enemy_type[i])
		{
			++i;
			continue;
		}

		enemy_type[i]=type;
		crazy=FALSE;

		switch(type)
		{
		case ENEMY_CRAZY_BARREL:
			crazy=TRUE;
		case ENEMY_ROLLING_BARREL:
			enemy_x    [i]=x;
			enemy_y    [i]=y;
			enemy_dx   [i]=dx;
			enemy_fall [i]=0;
			enemy_anim [i]=0;
			enemy_land [i]=255;
			enemy_crazy[i]=crazy;
			break;

		case ENEMY_BOUNCE:
			enemy_ix   [i]=x<<BOUNCE_FP;
			enemy_iy   [i]=y<<BOUNCE_FP;
			enemy_sy   [i]=y;
			enemy_idy  [i]=-3<<BOUNCE_FP;
			enemy_land [i]=0;
			enemy_speed[i]=game_bounce_speed<<1;
			sfx_play(SFX_CHN+2,SFX_BOUNCE_JUMP,x);
			break;

		case ENEMY_FIREBALL_1_JUMP_IN:
			enemy_x     [i]=x;
			enemy_y     [i]=y-2;
			enemy_dx    [i]=dx;
			enemy_cnt   [i]=0;
			enemy_ladder[i]=DIR_NONE;
			break;

		case ENEMY_FIREBALL_1:
		case ENEMY_FIREBALL_2:
			enemy_x     [i]=x;
			enemy_y     [i]=y;
			enemy_dx    [i]=dx;
			enemy_cnt   [i]=8+(rand()&7);
			enemy_ladder[i]=DIR_NONE;
			enemy_spawn [i]=0;
			break;
		}

		break;
	}

	++enemy_free;

	if(enemy_free>=ENEMY_MAX) enemy_free=0;
}



//process all enemies and update their sprites

unsigned char enemy_process(unsigned char clear)
{
	static unsigned char i,frame,fire;
	static unsigned int spr,anim;
	static unsigned char ox,oy,sy,hx,hy,off;
	static unsigned char random,difficulty,barrel_dir,take_ladder;
	static int dx;

	difficulty=(game_level_difficulty>>1)+1;

	spr=OAM_ENEMY;
	frame=game_frame_cnt;
	fire=FALSE;

	for(i=0;i<ENEMY_MAX;++i)
	{
		switch(enemy_type[i])
		{
		case ENEMY_NONE:
			{
				oam_spr(0,240,0,spr);
			}
			break;

		case ENEMY_ROLLING_BARREL:
			{
				ox=enemy_x[i];
				oy=enemy_y[i];

				if(!game_barrel_jump&&player_jump==JUMP_AIR)//check for jumping over a barrel
				{
					if(player_x>=ox-1&&player_x<ox+1)
					{
						if(oy>=player_y+12&&oy<player_jump_y+8)
						{
							sfx_play(SFX_CHN+3,SFX_OVER_BARREL,ox);

							game_add_score(100);
							particle_add(PART_TYPE_100,ox,oy);

							game_barrel_jump=4;//prevent getting few bonuses from the same barrel
						}
					}
				}

				if(enemy_land[i]<sizeof(barrelLandingAnimation))
				{
					sy=oy-barrelLandingAnimation[enemy_land[i]++];
				}
				else
				{
					sy=oy;
				}

				oam_spr1(ox,sy,BARREL_TILE|((enemy_anim[i]&3)<<1)|BARREL_ATR,spr);

				if(!((TEST_MAP(ox+6,oy+14)|TEST_MAP(ox+10,oy+14))&T_LDRTOP))
				{
					++enemy_fall[i];
					++oy;

					if(frame&1) break;//half the horizontal speed while falling
				}
				else
				{
					if(enemy_fall[i]>1)
					{
						enemy_dx  [i]=0-enemy_dx[i];
						enemy_land[i]=0;

						sfx_play(SFX_CHN+2,SFX_BARREL1+(rand()&3),ox);
					}

					enemy_fall[i]=0;
				}

				ox+=enemy_dx[i];

				if((ox&7)==4)
				{
					//when barrel is on top of a ladder, make a decision as described in
					//http://donhodges.com/Controlling_the_barrels_in_Donkey_Kong.htm

					if(TEST_MAP(ox+8,oy+14)&T_LADDER)
					{
						take_ladder=FALSE;

						if(!barrel_fire) take_ladder=TRUE;

						if(oy<player_y+8)
						{
							random=rand();

							if((random&3)<difficulty)
							{
								if(ox==player_x)
								{
									take_ladder=TRUE;
								}
								else
								{
									barrel_dir=(enemy_dx[i]==1)?DIR_RIGHT:DIR_LEFT;

									if(player_dir==barrel_dir)
									{
										take_ladder=TRUE;
									}
									else
									{
										if(!(random&0x18)) take_ladder=TRUE;
									}
								}
							}
						}

						if(take_ladder)
						{
							enemy_land[i]=255;
							enemy_fall[i]=0;
							enemy_type[i]=ENEMY_LADDER_BARREL;
							break;
						}
					}
				}

				if(!(frame&7)) ++enemy_anim[i];

				if(oy>=192)
				{
					if(ox==32)
					{
						enemy_type[i]=ENEMY_NONE;
						enemy_free=i;

						if(enemy_crazy[i]) fire=TRUE;
					}
				}
			}
			break;

		case ENEMY_LADDER_BARREL:
			{
				ox=enemy_x[i];
				oy=enemy_y[i];

				oam_spr1(ox,oy,BARREL_TILE+0x08|((enemy_anim[i]&1)<<1)|BARREL_ATR,spr);

				if(!(frame&1))
				{
					++oy;

					if(TEST_MAP(ox+8,oy+14)&T_FLOOR)
					{
						enemy_dx  [i]=0-enemy_dx[i];
						enemy_type[i]=ENEMY_ROLLING_BARREL;
					}
				}

				if(!(frame&7)) ++enemy_anim[i];
			}
			break;

		case ENEMY_CRAZY_BARREL:
			{
				ox=enemy_x[i];
				oy=enemy_y[i];

				oam_spr1(ox,oy,BARREL_TILE+0x08|((enemy_anim[i]&1)<<1)|BARREL_ATR,spr);

				if(enemy_fall[i])
				{
					--enemy_fall[i];
				}
				else
				{
					ox+=enemy_dx[i];
					++oy;

					if(TEST_MAP(ox+8,oy+14)==T_FLOOR)
					{
						enemy_dx  [i]=0-enemy_dx[i];
						enemy_fall[i]=4;

						sfx_play(SFX_CHN+2,SFX_BARREL1+(rand()&3),ox);
					}

					if(oy==192)
					{
						enemy_type[i]=ENEMY_ROLLING_BARREL;
						enemy_fall[i]=0;
						enemy_dx  [i]=1;
					}
				}

				if(!(frame&7)) ++enemy_anim[i];
			}
			break;

		case ENEMY_FIREBALL_1_JUMP_IN:
			{
				off=enemy_cnt[i];

				ox=enemy_x[i]+fireBallJumpInAnimation[off+0];
				oy=enemy_y[i]+fireBallJumpInAnimation[off+1];

				oam_spr1(ox,oy-2,ENEMY_TILE+0x04|(((frame>>1)&1)<<1)|ENEMY_ATR|SPR_HFLIP,spr);

				enemy_cnt[i]+=2;

				if(enemy_cnt[i]>=sizeof(fireBallJumpInAnimation))
				{
					enemy_type[i]=ENEMY_FIREBALL_1;

					if(game_level<2)
					{
						enemy_cnt[i]=3+(rand()&7);
					}
					else
					{
						enemy_cnt[i]=8+(rand()&31);
					}
				}
			}
			break;

		case ENEMY_FIREBALL_1:
		case ENEMY_FIREBALL_2:
			{
				ox=enemy_x[i];
				oy=enemy_y[i];
				dx=enemy_dx[i];

				anim=ENEMY_TILE+0x04|(frame&2)|ENEMY_ATR|(dx<=1?SPR_HFLIP:0);

				if(enemy_type[i]==ENEMY_FIREBALL_2)
				{
					if(enemy_spawn[i]<sizeof(fireBallSpawnAnim))
					{
						anim=fireBallSpawnAnim[enemy_spawn[i]>>1];

						++enemy_spawn[i];

						oam_spr1(ox,oy-2,anim,spr);

						break;
					}
					else
					{
						if(!player_hammer_time) anim+=4; else anim+=8;
					}
				}

				oam_spr1(ox,oy-2,anim,spr);

				if(enemy_ladder[i]==DIR_NONE)
				{
					if(frame&1)
					{
						if(dx)
						{
							if(dx==1)
							{
								if(map[NAM_OFF(ox+12,oy+15)]==0xf5) enemy_dx[i]=-1;
							}
							else
							{
								if(map[NAM_OFF(ox+4,oy+15)]==0xf5) enemy_dx[i]=1;
							}

							ox+=dx;

							if(enemy_type[i]==ENEMY_FIREBALL_1)
							{
								if(!(TEST_MAP(ox+8,oy+16)&T_SOLID))
								{
									if(TEST_MAP(ox+8,oy+15)&T_SOLID) --oy; else ++oy;
								}
							}
						}

						--enemy_cnt[i];

						if(!enemy_cnt[i])
						{
							enemy_cnt[i]=4+(rand()&15);

							if(!dx||(player_y==oy&&(rand()&255)>32))
							{
								if(player_x<ox) enemy_dx[i]=-1; else enemy_dx[i]=1;
							}
							else
							{
								enemy_dx[i]=((rand()&31)/12)-1;

								if(!enemy_dx[i]) enemy_cnt[i]=(enemy_cnt[i]&7)+1;
							}
						}
					}
					else
					{
						if((ox&7)==4)
						{
							if(TEST_MAP(ox+8,oy+16)&T_LADDER)
							{
								if((rand()&255)>192)
								{
									enemy_ladder[i]=DIR_DOWN;
									break;
								}
							}

							if(TEST_MAP(ox+8,oy+15)&T_LADDER)
							{
								if((rand()&255)>192)
								{
									enemy_ladder[i]=DIR_UP;
									break;
								}
							}
						}
					}
				}
				else
				{
					if(!(frame&3))
					{
						if(enemy_ladder[i]==DIR_UP)
						{
							--oy;

							if(!(TEST_MAP(ox+8,oy+15)&(T_LADDER|T_LADDER_BROKEN)))
							{
								enemy_ladder[i]=DIR_NONE;
							}
						}
						else
						{
							++oy;

							if(!(TEST_MAP(ox+8,oy+16)&(T_LADDER|T_LADDER_BROKEN)))
							{
								enemy_ladder[i]=DIR_NONE;
							}
						}
					}
				}
			}
			break;

		case ENEMY_BOUNCE:
			{
				ox=(enemy_ix[i]>>BOUNCE_FP);
				oy=(enemy_iy[i]>>BOUNCE_FP);

				oam_spr(enemy_ix[i]>>BOUNCE_FP,oy,ENEMY_TILE+(enemy_land[i]?0x02:0x00)|ENEMY_ATR,spr);

				if(enemy_idy[i]<(3<<BOUNCE_FP))
				{
					if(ox<184&&oy>=enemy_sy[i])
					{
						enemy_idy [i]=-3<<BOUNCE_FP;
						enemy_land[i]=10;
						sfx_play(SFX_CHN+2,SFX_BOUNCE_JUMP,ox);
					}

					enemy_ix [i]+=bounce_speed[enemy_speed[i]+0];
					enemy_idy[i]+=bounce_speed[enemy_speed[i]+1];

					if(enemy_idy[i]>=(3<<BOUNCE_FP)) sfx_play(SFX_CHN+2,SFX_BOUNCE_FALL,ox);
				}

				enemy_iy[i]+=enemy_idy[i];

				if(enemy_land[i]) --enemy_land[i];

				if(enemy_iy[i]>=(224<<BOUNCE_FP))
				{
					enemy_type[i]=ENEMY_NONE;
					enemy_free=i;
				}
			}
			break;
		}

		//check every enemy for interaction with player and hammer
		
		if(enemy_type[i])
		{
			if(!(player_x+12<ox+4||player_x+4>ox+12
			   ||player_y+12<oy+4||player_y+4>oy+12))
			{
				clear=LEVEL_LOSE;
			}

			if(player_hammer_time&&player_jump!=JUMP_AIR&&!player_fall)//check hammer collision
			{
				off=(player_hammer_phase+(player_dir_prev==DIR_LEFT?0:2))<<1;

				hx=player_x+hammerOffsets[off+0]+3;
				hy=player_y+hammerOffsets[off+1]+3;

				if(!(ox+10<hx||ox+6>hx+10
				   ||oy+10<hy||oy+6>hy+10))
				{
					splat_x=ox;
					splat_y=oy;
					splat_cnt=0;
					
					sfx_play(SFX_CHN,SFX_DESTROY,ox);

					game_add_score(500);
					particle_add(PART_TYPE_500,ox,oy);

					oam_spr(0,240,0,spr);

					if(enemy_type[i]==ENEMY_FIREBALL_1) fire=TRUE;

					enemy_type[i]=ENEMY_NONE;
					enemy_free=i;

					break;//prevent destroying more than one barrel at once
				}
			}

			enemy_x[i]=ox;
			enemy_y[i]=oy;
		}

		spr+=4;
		++frame;//to distribute time-based events between objects
	}

	//automatically add a fireball when the crazy barrel gets to the burning barrel
	
	if(fire)
	{
		barrel_start_fire();

		if(game_fireballs<2)
		{
			++game_fireballs;

			enemy_add(ENEMY_FIREBALL_1_JUMP_IN,barrel_fire_x,barrel_fire_y+8,0);
			sfx_play(SFX_CHN+2,SFX_FIRE_SPAWN,barrel_fire_x+8);
		}
	}

	return clear;
}
