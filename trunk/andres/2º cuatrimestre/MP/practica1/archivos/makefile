# Nombre: makefile_circulomedio
# Descripcion: Compila los modulos del programa central, y en enlaza objetos.

# Variable que indica el compilador que se va a utilizar.
CC = g++
# Variable que indica las opciones que se van a pasar al compilador.
CPPFLAGS = -Wall

# Variable que indica el directorio en donde se encuentran los archivos de cabecera.
INCLUDE_DIR = ./

# Variable que indica el directorio en donde se encuentran las bibliotecas.
LIB_DIR = ./

central: libformas.a central.o
	$(CC) -L$(LIB_DIR) -o central central.o -lformas
	
central.o: central.cpp circulo.h punto.h
	$(CC) -I$(INCLUDE_DIR) -c central.cpp

libformas.a: punto.o circulo.o
	ar -rvs libformas.a punto.o circulo.o

punto.o: punto.cpp punto.h
	$(CC) -I$(INCLUDE_DIR) -c punto.cpp

circulo.o: circulo.cpp circulo.h punto.h
	$(CC) -I$(INCLUDE_DIR) -c circulo.cpp

clean:
	rm *.o
	rm *central
