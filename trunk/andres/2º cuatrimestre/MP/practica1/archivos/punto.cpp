#include "punto.h"
#include <iostream>
#include <cmath>

using namespace std;

void Punto::escribir() const{
    // Formato de escritura del punto: (x,y)
	cout <<"(" << x << "," << y << ")";
}

void Punto::leer(){
    // Formato de lectura del punto: (x,y)
	char car;
	double x,y;
	cin >> car;
	cin >> x;
	cin >> car;
	cin >> y;
	cin >> car;
	//cin >> car >> car >> x >> car >> y >> car;
	this->setX(x);
	this->setY(y);
}

/**
@brief Calcula la distancia entre dos puntos
@param p1 primer punto
@param p2 segundo punto
@return la distancia entre el punto @a p1 y el punto @a p2
*/
double distancia(Punto p1, Punto p2){
	
	return sqrt(pow(p1.getX(),2) + pow(p1.getY(),2)) - sqrt(pow(p2.getX(),2) + pow(p2.getY(),2))/2;
	//double a,b;
	//a=p1.getX()-p2.getY();
	//b=p1.getX()-p2.getY();
	//double dist;
	//dist = sqrt((a*a)+(b*b));
	//return dist;
}

/**
@brief Calcula el punto que está entre dos puntos dados con distancia mínima a ambos
@param p1 primer punto
@param p2 segundo punto
@return un punto entre el punto @a p1 y el punto @a p2 con distancia mínima a ambos
*/
Punto puntoMedio(Punto p1, Punto p2){
	Punto pMedio((p1.getX()+p2.getX())/2,(p1.getY()+p2.getY()/2));
	return pMedio;
}
