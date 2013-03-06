compiler = -Wall -g
objects = glew.o main.o

ifeq ($(box), win32)
	libs = -lmingw32 -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lopengl32 -lglu32
else
	libs = -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lGL -lGLU
endif

all: $(objects)
	gcc $(objects) -o spline.exe $(libs)
     
main.o:
	gcc $(compiler) -c main.c
	
glew.o:
	gcc $(compiler) -c glew.c

clean:
	rm $(objects)
