#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAX_VERTEX_COUNT 1000
#define SIZE_OF_VERTEX 2
#define SIZE_OF_COLOR 3

#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>

#include "glew.h"
//#include <GL/gl.h>
#include <SDL/SDL.h>

SDL_Surface* screen;
Uint32 lastTickTime;

BOOL doneWindow = FALSE;

GLfloat* vertexArray = NULL;
GLfloat* colorArray = NULL;

BOOL init()
{
	freopen( "CON", "wt", stdout );
	freopen( "CON", "wt", stderr );

	if ((vertexArray = malloc(sizeof(GLfloat) * MAX_VERTEX_COUNT * SIZE_OF_VERTEX)) == NULL || (colorArray = malloc(sizeof(GLfloat) * MAX_VERTEX_COUNT * SIZE_OF_COLOR)) == NULL)
	{
		perror("error allociating vertex arrays");
		return FALSE;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		perror("error setting up SDL");
		return FALSE;
	}

	if((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL)) == NULL)
	{
		perror("error setting video mode");
		return FALSE;
	}
	
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return FALSE;
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

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
	free(vertexArray);
	free(colorArray);

	SDL_Quit();
}

void update(double delta)
{
	vertexArray[0] = 1.0f;
	vertexArray[1] = 1.0f;
        vertexArray[2] = 100.0f;
	vertexArray[3] = 1.0f;
	vertexArray[4] = 100.0f;
	vertexArray[5] = 100.0f;
	colorArray[0] = 1.0f;
	colorArray[1] = 0.0f;
	colorArray[2] = 0.0f;
	colorArray[3] = 0.0f;
	colorArray[4] = 1.0f;
	colorArray[5] = 0.0f;
	colorArray[6] = 0.0f;
	colorArray[7] = 0.0f;
	colorArray[8] = 1.0f;
	
	vertexArray[6] = 100.0f;
	vertexArray[7] = 100.0f;
        vertexArray[8] = 200.0f;
	vertexArray[9] = 200.0f;
	vertexArray[10] = 100.0f;
	vertexArray[11] = 200.0f;
	colorArray[9] = 1.0f;
	colorArray[10] = 0.0f;
	colorArray[11] = 0.0f;
	colorArray[12] = 0.0f;
	colorArray[13] = 1.0f;
	colorArray[14] = 0.0f;
	colorArray[15] = 0.0f;
	colorArray[16] = 0.0f;
	colorArray[17] = 1.0f;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//enable vertex array writing
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//set the array the GPU should use
	glVertexPointer(SIZE_OF_VERTEX, GL_FLOAT, 0, vertexArray);
	glColorPointer(SIZE_OF_COLOR, GL_FLOAT, 0, colorArray);

	//draw the first 8 elements as a triangle
	glDrawArrays(GL_TRIANGLES, 0, 16);
	
	//disable vertex array writing
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

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
