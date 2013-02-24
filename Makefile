compiler = -Wall
objects = main.o

all: $(objects)
	gcc $(objects) -o spline.exe
     
main.o:
	gcc $(compiler) -c main.c

clean:
	rm $(objects)
