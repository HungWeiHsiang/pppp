#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"
#include "map.h"
#include <cstdlib>
using namespace std;
int gx;
int gy;
int px;
int py;
int cx;
int cy;
int gover=0;
int cch=0;
static int cntt=0;
static int v=2;
static int u=4;
static int uup=0;
static int ddo=0;
static int lle=0;
static int rri=0;
static int kee=0;
int ggov()
{
	if(gover!=1)
	{
		
		return 0;	
	}
	uup=0;
	ddo=0;
	lle=0;
	rri=0;
	return 1;
}
GameObject::GameObject(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
void GameObject::Update()
{
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
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpos;
	int r=ypos;
	while(gover==0&&t==xpos&&r==ypos)
	{
			det=5;
			int tt=rand()%10+3;
			int dn=tt%4;
			switch(dn)
			{
			case 0:
				if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
				{
					xpos=xpos+v;
					i=0;
					break;
				}
			case 1:
				if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
				{
					ypos=ypos+v;
					i=1;
					break;
				}
			case 2:
				if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
				{
					xpos=xpos-v;
					i=2;
					break;
				}
			case 3:
				if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
				{
					ypos=ypos-v;
					i=3;
					break;
				}
			default:
				{
					break;	
				}		
			}		
	}
	det=0;
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(t<800)
	{
		dead();
	}
}
void GameObject::dead()
{
	if(gx-px<32&&px-gx<32&&gy-py<32&&py-gy<32)
	{
//		gameover();
	}
}
void GameObject::gameover()
{
	if(gover==0)
	{
		cout<<"Gameover!"<<endl;
	}
	gover=1;
}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Ghost::Ghost(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
void Ghost::Update()
{
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
	if(cntt<10000)
	{
		cntt=cntt+1;
	}
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpos;
	int r=ypos;
	while(cntt>=1000&&gover==0&&t==xpos&&r==ypos)
	{
		
		int tt=rand()%10+3;
		int dn=tt%4;
		switch(dn)
		{
		case 0:
			if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+u;
				i=0;
				break;
			}
		case 1:
			if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+u;
				i=1;
				break;
			}
		case 2:
			if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-u;
				i=2;
				break;
			}
		case 3:
			if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-u;
				i=3;
				break;
			}
		default:
			{
				break;	
			}		
		}
			
	}
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(t<800)
	{
		dead();
	}
}
void Ghost::dead()
{
	if(gx-px<32&&px-gx<32&&gy-py<32&&py-gy<32)
	{
//		gameover();
	}
}
void Ghost::gameover()
{
	if(gover==0)
	{
		cout<<"Gameover!"<<endl;
	}
	gover=1;
}
void Ghost::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Player::Player(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}

static int dir=-1;
void Player::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 1; 
			break;
        case SDLK_DOWN: 
			ddo = 1; 
			break;
        case SDLK_LEFT: 
			lle = 1; 
			break;
        case SDLK_RIGHT: 
			rri = 1; 
			break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 0; 
			break;
    	case SDLK_DOWN: 
			ddo = 0; 
			break;
        case SDLK_LEFT: 
			lle = 0; 
			break;
        case SDLK_RIGHT: 
			rri = 0; 
			break;
        }
    }
}
void Player::Update()
{
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
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
/*	if(uup==1)
	{
		cout<<"up";
	}
	if(ddo==1)
	{
		cout<<"dow";
	}
	if(lle==1)
	{
		cout<<"lef";
	}
	if(rri==1)
	{
		cout<<"rig";
	}
	cout<<endl;
*/	if((uup==1&&ddo==1&&rri==0&&lle==0)||(uup==0&&ddo==0&&rri==1&&lle==1))
	{
		xpo=xpo;
		ypo=ypo;
	}
	else if(rri==1&&ddo==1)
	{
		if(dir==0||dir==3)
		{
			if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				ypo=ypo+u;
				dir=1;
			}
			else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				xpo=xpo+u;
				dir=0;
			}
		}
		if(dir==1||dir==2)
		{
			if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				xpo=xpo+u;
				dir=0;
			}
			else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				ypo=ypo+u;
				dir=1;
			}
		}	
	}
	else if(rri==1&&uup==1)
	{
		if(dir==0||dir==1)
		{
			if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				ypo=ypo-u;
				dir=3;
			}
			else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				xpo=xpo+u;
				dir=0;
			}
		}
		if(dir==3||dir==2)
		{
			if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				xpo=xpo+u;
				dir=0;
			}
			else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				ypo=ypo-u;
				dir=3;
			}
		}	
	}
	else if(lle==1&&uup==1)
	{
		if(dir==0||dir==3)
		{
			if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				xpo=xpo-u;
				dir=2;
			}
			else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				ypo=ypo-u;
				dir=3;
			}		
		}
		if(dir==1||dir==2)
		{
			if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				ypo=ypo-u;
				dir=3;
			}
			else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				xpo=xpo-u;
				dir=2;
			}
		}	
	}
	else if(lle==1&&ddo==1)
	{
		if(dir==1||dir==0)
		{
			if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				xpo=xpo-u;
				dir=2;
			}
			else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				ypo=ypo+u;
				dir=1;
			}
		}	
		if(dir==2||dir==3)
		{
			if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				ypo=ypo+u;
				dir=1;
			}
			else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				xpo=xpo-u;
				dir=2;
			}	
		}	
	}
	else
	{
		if(rri==1&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
		{
			xpo=xpo+u;
			dir=0;
		}
		else if(ddo==1&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
		{
			ypo=ypo+u;
			dir=1;
		}
		else if(lle==1&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
		{
			xpo=xpo-u;
			dir=2;
		}
		else if(uup==1&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
		{
			ypo=ypo-u;
			dir=3;
		}
		else if(ggov()!=1)
		{
			if(kee==0)
			{
				kee=5;
			}
			else if(xpo%32==0&&ypo%32==0&&kee>2)
			{
				kee=kee-1;
			}
			if(kee>3)
			{
				if(dir==0&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					
				}
				else if(dir==1&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					
				}
				else if(dir==2&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					
				}
				else if(dir==3&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
				}	
			}
		}	
		if(uup==1||ddo==1||rri==1||lle==1)
		{
			kee=0;
		}		
	}	
	px=xpo;
	py=ypo;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Chi::Chi(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}
void Chi::Update()
{
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
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpo;
	int r=ypo;
	while(gover==0&&r<640&&t==xpo&&r==ypo)
	{
			det=5;
			int tt=rand()%10+3;
			int dn=tt%4;
			switch(dn)
			{
			case 0:
				if(j!=2&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{	
					xpo=xpo+v;
					j=0;
					break;
				}
			case 1:
				if(j!=3&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+v;
					j=1;
					break;
				}
			case 2:
				if(j!=0&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-v;
					j=2;
					break;
				}	
			case 3:
				if(j!=1&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-v;
					j=3;
					break;
				}
			default:
				{
					break;	
				}		
			}	
			
	}
	det=0;
	cx=xpo;
	cy=ypo;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(r<640)
	{
		ced();
	}
}
void Chi::ced()
{
	if(cx-px<32&&px-cx<32&&cy-py<32&&py-cy<32)
	{
		xpo=0+32*cch;
		ypo=640;
		cch=cch+1;
		if(cch==4)
		{
			finish();
		}
	}
}
void Chi::finish()
{
	if(gover==0)
	{
		cout<<"Victory!"<<endl;
	}
	gover=1;
}
void Chi::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}
