#include "circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

void Circulo::escribir() const{
    // Formato de escritura del círculo: radio-(x,y)
	cout << radio << "-(" << this->getCentro().getX() << "," << this->getCentro().getY() << ")"; 
}

void Circulo::leer(){
    // Formato de lectura del círculo: radio-(x,y)
	char caracter;
	cin >> radio;
	cin >> caracter;
	centro.leer();
}

double Circulo::area() const{
	double area;
	const double pi = 3.141592;
	area = pi*getRadio()*getRadio();
	return area;

}


/**
@brief Calcula la distancia entre dos circulos
@param c1 primer círculo
@param c2 segundo círculo
@return la distancia entre el círculo @a c1 y el círculo @a c2

La distancia entre dos círculos se define como la distancia entre los centros menos los dos radios.
Nótese que la distancia puede ser negativa si los círculos se intersecan
*/
double distancia (Circulo c1, Circulo c2){
	double d;
	d=sqrt(pow(c1.getCentro().getX(),2) + pow(c1.getCentro().getY(),2)) - sqrt(pow(c2.getCentro().getX(),2) + pow(c2.getCentro().getY(),2))/2;
	return d;
}


/**
@brief Comprueba si un punto es interior a un círculo
@param p punto a comprobar
@param c circulo
@retval true si el punto @a p es interior al círculo @a c
@retval false en caso contrario
*/
bool interior (Punto p, Circulo c){  // Esta función la he comentado porque me da fallo al compilar y no se muy bien el porqué
	bool dist; 
	dist = distancia(p,c.getCentro()) <= c.getRadio() ? true:false;
	return dist;
}

