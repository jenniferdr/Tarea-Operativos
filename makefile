all: proyecto.o estructuras.o
	gcc proyecto.o estructuras.o -o tarea

proyecto.o: proyecto.c estructuras.h
	gcc -c proyecto.c -o proyecto.o

estructuras.o: estructuras.c estructuras.h
	gcc -c estructuras.c -o estructuras.o

clean:
	rm *.o tarea
