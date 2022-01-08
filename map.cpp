#include "map.h"
#include "texturemanager.h"
#include "gameobject.h"
using namespace std;
int lvl1[20][25]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map()
{
	dirt=TextureManager::LoadTexture("dirt.bmp");
	grass=TextureManager::LoadTexture("grass.bmp");
	water=TextureManager::LoadTexture("water.bmp");
	LoadMap(lvl1);
	src.x=src.y=0;
	src.w=dest.w=32;
	src.h=dest.h=32;
	dest.x=dest.y=0;
}
void Map::LoadMap(int arr[20][25])
{
	for(int row=0;row<20;row=row+1)
	{
		for(int col=0;col<25;col=col+1)
		{
			map[row][col]=arr[row][col];
		}
	}
}
void Map::DrawMap()
{
	int type=0;
	for(int row=0;row<20;row=row+1)
	{
		for(int col=0;col<25;col=col+1)
		{
			type=map[row][col];
			dest.x=col*32;
			dest.y=row*32;
			switch(type)
			{
				case 0:
					TextureManager::Draw(dirt,src,dest);
					break;
				case 1:
					TextureManager::Draw(grass,src,dest);
					break;
				case 2:
					TextureManager::Draw(water,src,dest);
					break;
				default:
					break;
			}
		}
	}
}
void Map::upd()
{
	static int ccn=0;
	ccn=ccn+1;
	if(ccn>=500&&ggov()==0)
	{
		map[3][11]=1;
		map[3][13]=1;
		map[16][11]=1;
		map[16][13]=1;
	}
}
