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

	if((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL)) == NULL)
	{
		return FALSE;
	}

	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	//printf("OpenGL Version: %s by %s\n", glGetString(GL_VERSION), glGetString(GL_VENDOR));

	lastTickTime = SDL_GetTicks();

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
	glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
	glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
	glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
	glEnd();

	SDL_GL_SwapBuffers();
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
