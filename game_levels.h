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

/*functions that implements logic unique for particular levels*/


unsigned char game_level1(unsigned char clear)
{
	unsigned int i;

	/*kong throws barrels in a complex loop consisting of few states*/

	switch(kong_state)
	{
	case KONG_STATE_STAND:
		{
			if(kong_delay) --kong_delay;

			if(!kong_start) kong_stand_animation_level1();

			if(!kong_delay&&(!(kong_frame_cnt>>2)||(kong_frame_cnt>>2)==6))
			{
				kong_start=FALSE;

				oam_spr(kong_x-8,kong_y+18,BARREL_TILE+0x00|BARREL_ATR,OAM_BARRELS+(4<<2));

				kong_state=KONG_STATE_TAKE;
				kong_frame=kongLargeSpriteSideL;
				kong_delay=14;
			}
		}
		break;

	case KONG_STATE_TAKE:
		{
			--kong_delay;

			if(!kong_delay)
			{
				oam_spr(kong_x+8,kong_y+18,BARREL_TILE+0x08|BARREL_ATR,OAM_BARRELS+(4<<2));

				kong_state=KONG_STATE_MIDDLE;
				kong_frame=kongLargeSpriteFace1;
				kong_delay=12;
			}
		}
		break;

	case KONG_STATE_MIDDLE:
		{
			--kong_delay;

			if(!kong_delay)
			{
				if(kong_throw_crazy_barrel)
				{
					oam_spr(0,240,0,OAM_BARRELS+(4<<2));

					enemy_add(ENEMY_CRAZY_BARREL,kong_x+8,kong_y+18,kong_crazy_barrel_type);

					kong_throw_crazy_barrel=FALSE;

					kong_state=KONG_STATE_WAIT;
					kong_frame=kongLargeSpriteThrow;
					kong_delay=68;

					break;
				}

				oam_spr(kong_x+24,kong_y+18,BARREL_TILE+0x00|BARREL_ATR,OAM_BARRELS+(4<<2));

				kong_state=KONG_STATE_DROP;
				kong_frame=kongLargeSpriteSideR;
				kong_delay=14;
			}
		}
		break;

	case KONG_STATE_DROP:
		{
			--kong_delay;

			if(!kong_delay)
			{
				oam_spr(0,240,0,OAM_BARRELS+(4<<2));

				enemy_add(ENEMY_ROLLING_BARREL,kong_x+24,kong_y+18,1);

				sfx_play(SFX_CHN+1,SFX_BARREL_ROLL,kong_x+32);

				kong_state=KONG_STATE_WAIT;
				kong_delay=68;
			}
		}
		break;

	case KONG_STATE_WAIT:
		{
			--kong_delay;

			if(!kong_delay)
			{
				kong_state=KONG_STATE_STAND;
				kong_delay=64;
				kong_frame_cnt=0;
			}
		}
		break;
	}

	game_show_kong(OAM_KONG,kong_x,kong_y);

	/*game level difficulty increases every 25 seconds*/

	if(game_level_difficulty_count<25*60)
	{
		++game_level_difficulty_count;
	}
	else
	{
		game_level_difficulty_count=0;

		if(game_level_difficulty<5) ++game_level_difficulty;

		kong_throw_crazy_barrel=TRUE;
		kong_crazy_barrel_type=-1;
	}

	/*barrel fire collision check and animation*/

	if(barrel_fire)
	{
		if(!(barrel_fire_x+16<player_x+4||barrel_fire_x>=player_x+12
		   ||barrel_fire_y+8 <player_y+4||barrel_fire_y>=player_y+12))
		{
			clear=LEVEL_LOSE;
		}
	}

	/*level ends when player gets to the top platform*/
	
	if(player_y==16) clear=TRUE;

	return clear;
}



unsigned char game_level2(unsigned char clear)
{
	kong_stand_animation_level2();
	
	game_show_kong(OAM_KONG,kong_x,kong_y);

	/*the bouncing spring is added every 180 frames*/
	
	if(!game_bounce_delay)
	{
		game_bounce_delay=180;

		enemy_add(ENEMY_BOUNCE,-16,kong_y+18,0);
	}
	else
	{
		--game_bounce_delay;
	}

	/*game level difficulty increases every 10 seconds, along with bouncing speed*/
	
	if(game_level_difficulty_count)
	{
		--game_level_difficulty_count;
	}
	else
	{
		game_level_difficulty_count=10*60;
		
		if(game_bounce_speed<4) ++game_bounce_speed;
	}
	
	/*level ends when player gets to the top platform*/
	
	if(player_y==16) clear=TRUE;

	return clear;
}



unsigned char game_level3(unsigned char clear)
{
	static unsigned char i,x,y;

	kong_stand_animation_level2();
	
	game_show_kong(OAM_KONG,kong_x,kong_y);

	/*game level difficulty increases every 10 seconds, new fireballs are added every time*/

	if(game_level_difficulty_count)
	{
		--game_level_difficulty_count;
	}
	else
	{
		game_level_difficulty_count=10*60;

		if(game_fireballs<5)
		{
			++game_fireballs;

			i=rand()%fireball_spawn_all;

			while(1)
			{
				x=fireball_spawn_x[i];
				y=fireball_spawn_y[i];

				if(!(y>player_y-32&&y<player_y+32)&&(x>>7)!=(player_x>>7)) break;

				i=(i+1)%fireball_spawn_all;
			}

			enemy_add(ENEMY_FIREBALL_2,x,y,0);
			sfx_play(SFX_CHN+2,SFX_FIRE_SPAWN,x+8);
		}
	}

	/*level ends when player removed all the rivets*/
	
	if(game_rivets==8) clear=LEVEL_CLEAR;

	return clear;
}

