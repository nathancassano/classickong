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

//clear particles list and hide their sprites

void particles_clear(void)
{
	static unsigned char i,spr;

	memset(particle_type,PART_TYPE_NONE,PARTICLES_MAX);

	particle_free=0;

	spr=OAM_PARTICLES;

	for(i=0;i<PARTICLES_MAX;++i)
	{
		oam_spr1(0,240,0,spr);
		spr+=4;
	}
}



//add a particle into the list

void particle_add(unsigned char type,unsigned char x,unsigned char y)
{
	static unsigned char i,j,cnt1,cnt2;
	static unsigned int spr;

	i=particle_free;
	
	cnt1=0;
	cnt2=0;

	for(j=0;j<PARTICLES_MAX;++j)
	{
		if(particle_type[i])
		{
			++i;
			continue;
		}

		particle_type[i]=type;
		particle_x   [i]=x;
		particle_y   [i]=y;

		switch(type)
		{
		case PART_TYPE_100:
			cnt1=50;
			spr=ITEMS_TILE+0x20|SPR_PAL(1)|SPR_PRI(2);
			break;

		case PART_TYPE_300:
			cnt1=50;
			spr=ITEMS_TILE+0x0a|SPR_PAL(1)|SPR_PRI(2);
			break;

		case PART_TYPE_500:
			cnt1=50;
			spr=ITEMS_TILE+0x0c|SPR_PAL(1)|SPR_PRI(2);
			break;

		case PART_TYPE_800:
			cnt1=50;
			spr=ITEMS_TILE+0x0e|SPR_PAL(1)|SPR_PRI(2);
			break;

		case PART_TYPE_HELP:
			cnt1=32;
			spr=PRINCESS_TILE+0x08|PRINCESS_ATR;
			break;

		case PART_TYPE_SMOKE:
			cnt1=32;
			spr=ENEMY_TILE+0x40|ENEMY_ATR;
			break;

		case PART_TYPE_HEART:
			cnt1=8;
			cnt2=64;
			spr=PRINCESS_TILE+0x0c|PRINCESS_ATR;
			break;
		}

		particle_cnt1[i]=cnt1;
		particle_cnt2[i]=cnt2;
		particle_spr[i]=spr;

		break;
	}

	++particle_free;

	if(particle_free>=PARTICLES_MAX) particle_free=0;
}



//update particles state and sprites

void particle_process(void)
{
	static unsigned char i,j,x,y,cnt1,cnt2,spr;

	spr=OAM_PARTICLES;
	j=game_frame_cnt;

	for(i=0;i<PARTICLES_MAX;++i)
	{
		if(particle_type[i]==PART_TYPE_NONE)
		{
			oam_spr1(0,240,0,spr);
			spr+=4;

			continue;
		}

		x   =particle_x   [i];
		y   =particle_y   [i];
		cnt1=particle_cnt1[i];
		cnt2=particle_cnt2[i];

		switch(particle_type[i])
		{
		case PART_TYPE_100:
		case PART_TYPE_300:
		case PART_TYPE_500:
		case PART_TYPE_800:
			{
				--cnt1;

				if(!cnt1)
				{
					particle_type[i]=PART_TYPE_NONE;
				}
				else
				{
					if(j&1) --y;
				}
			}
			break;

		case PART_TYPE_HELP:
			{
				--cnt1;

				if(!cnt1)
				{
					particle_type[i]=PART_TYPE_NONE;
				}
				else
				{
					if(!(j&3)) --y;
				}
			}
			break;

		case PART_TYPE_SMOKE:
			{
				--cnt1;

				if(!cnt1)
				{
					particle_type[i]=PART_TYPE_NONE;
				}
				else
				{
					if(!(cnt1&3)) particle_spr[i]+=2;
				}
			}
			break;

		case PART_TYPE_HEART:
			{
				if(!(cnt2&3)&&j&1) --y;

				if(!cnt2)
				{
					if(cnt1&16) --x; else ++x;
				}

				++cnt1;
				
				if(cnt2) cnt2-=2;
				
				particle_spr[i]=PRINCESS_TILE+0x0c+(cnt2&2)|PRINCESS_ATR;

				if(y==240) particle_type[i]=PART_TYPE_NONE;
			}
			break;
		}

		oam_spr1(x,y,particle_spr[i],spr);

		particle_x   [i]=x;
		particle_y   [i]=y;
		particle_cnt1[i]=cnt1;
		particle_cnt2[i]=cnt2;

		spr+=4;
		++j;
	}
}
