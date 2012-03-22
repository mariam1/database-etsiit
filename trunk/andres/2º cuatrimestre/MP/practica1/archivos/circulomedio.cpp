/**
   @file circulomedio.cpp
   @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
   @author MP
   @warning Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:
     Introduzca un circulo en formato radio-(x,y): 3-(0,0)
     Introduzca otro circulo: 4-(5,0)
     El círculo que pasa por los dos centros es: 2.5-(2.5,0)
**/

#include <iostream>
#include <cmath> // sqrt, M_PI
using namespace std;


class Punto {
private:
    double x; ///< coordenada x del punto
    double y; ///< coordenada y del punto

public:
    Punto(){ x=0;y=0;} ///< constructor. Pone a 0 las dos coordenadas
    Punto(double x, double y){this->x=x;this->y=y; } ///< constructor. Inicializa un punto con dos valores x y
    double getX() const { return x; } ///< Devuelve la coordenada x del punto
    double getY() const { return y;} ///< Devuelve la coordenada y del punto
    void setX(double newXValue){ x=newXValue;} ///< Asigna el valor newXValue a la coordenada x del punto
    void setY(double newYValue){ y=newYValue;} ///< Asigna el valor newYValue a la coordenada y del punto
    void escribir() const; ///<  Escribe un punto en formato (x,y)
    void leer(); ///< // Lee un punto en el formato (x,y)
};


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
bool interior (Punto p, Circulo c){
	return (distancia(p,c.getCentro()) <= c.getRadio()) ? true:false;
	}


int main()
{
    Circulo c1,c2;

    do {
        cout << "Introduzca un circulo en formato radio-(x,y): ";
        c1.leer();
        cout << "Introduzca otro circulo: ";
        c2.leer();
    } while (distancia(c1.getCentro(),c2.getCentro())==0);

    Circulo res;

    res.set(puntoMedio(c1.getCentro(),c2.getCentro()),
                     distancia(c1.getCentro(),c2.getCentro())/2);
    cout << "El círculo que pasa por los dos centros es: ";
    res.escribir();
    cout << endl;
}

/* Fin: circulomedio.cpp */
 
                
 