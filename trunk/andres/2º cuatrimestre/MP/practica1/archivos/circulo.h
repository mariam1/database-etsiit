#include <iostream>
#include <cmath>
#include "punto.h"

class Circulo {
private:

    Punto centro; ///< Centro del círculo
    double radio; ///< radio del círculo

public:

    Circulo(){ centro.setY(0); centro.setX(0);radio=0;} ///< Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double radio){this->centro=centro; this->radio=radio; } ///< Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double radio){ this->centro=centro; this->radio=radio; } ///< Asigna el centro y el radio a un circulo
    Punto getCentro() const { return centro;} ///< Devuelve el centro de un circulo
    double getRadio() const { return radio;} ///< Devuelve el radio de un circulo
    void escribir() const; ///< Escribe círculo en formato radio-centro
    void leer(); ///< lee círculo en formato radio-centro
    double area() const; ///< Devuelve el área de un círculo

};

double distancia (Circulo c1, Circulo c2);
