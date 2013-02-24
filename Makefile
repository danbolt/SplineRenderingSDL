compiler = -Wall
objects = main.o

ifeq ($(box), win32)
	libs = -lmingw32 -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lopengl32 -lglu32
else
	libs = -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lGL -lGLU
endif

all: $(objects)
	gcc $(objects) -o spline.exe $(libs)
     
main.o:
	gcc $(compiler) -c main.c

clean:
	rm $(objects)
