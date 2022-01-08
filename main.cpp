#include "game.h"
#include "gameobject.h"

Game *game;

int main(int argc,char *argv[])
{
	const int fps=6;
	const int fdelay=100/fps;
	Uint32 fstart;
	int ftime;
	game=new Game();
	game->init("BirchEngine",
	SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
	800,672,false);
	
	while(game->running())
	{
		
		fstart=SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		ftime=SDL_GetTicks()-fstart;
		if(fdelay>ftime)
		{
			SDL_Delay(fdelay-ftime);
		}
	}
	game->clean();
	
	return 0;
}
