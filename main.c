#define BOOL int
#define TRUE 1
#define FALSE 0

#include <stdio.h>

#include <GL/gl.h>
#include <SDL/SDL.h>

SDL_Surface* screen;
Uint32 lastTickTime;

BOOL doneWindow = FALSE;

BOOL init()
{
	freopen( "CON", "wt", stdout );
	freopen( "CON", "wt", stderr );

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return FALSE;
	}
	
	lastTickTime = SDL_GetTicks();

	if((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
	{
		return FALSE;
	}

	return TRUE;
}

void deinit()
{
	SDL_Quit();
}

void update(double delta)
{
	//
}

void render()
{
	//
}

int main(int argc, char* argv[])
{
	if (init() != TRUE)
	{
		perror("error initalizing SDL");
		return 1;
	}
	
	while (!doneWindow)
	{
		Uint32 currentTickTime = SDL_GetTicks();

		update((double)(currentTickTime - lastTickTime));
		render();
		
		lastTickTime = currentTickTime;
		
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				doneWindow = TRUE;
			}
		}
	}
	
	deinit();

	return 0;
}
