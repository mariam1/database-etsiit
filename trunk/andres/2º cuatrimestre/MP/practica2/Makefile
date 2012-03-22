# Nombre: makefile

SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I $(INC) -c

# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
all:	$(BIN)/main1 $(BIN)/main2

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
	
$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o
	
libcodificar.a:	$(OBJ)/imagenES.o $(OBJ)/codificar.o
	ar rvs libcodificar.a $(OBJ)/imagenES.o $(OBJ)/codificar.o
	
$(OBJ)/main1.o: $(SRC)/main1.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/main1.cpp -o $(OBJ)/main1.o
	
$(OBJ)/main2.o: $(SRC)/main2.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/main2.cpp -o $(OBJ)/main2.o

$(BIN)/main1:	libcodificar.a $(OBJ)/main1.o
	$(CXX) -o bin/main1 $(OBJ)/main1.o libcodificar.a
	
$(BIN)/main2:	libcodificar.a $(OBJ)/main2.o
	$(CXX) -o bin/main2 $(OBJ)/main2.o libcodificar.a
	
# ************ Limpieza ************
clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
