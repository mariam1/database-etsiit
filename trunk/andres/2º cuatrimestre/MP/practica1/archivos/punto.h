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

Punto puntoMedio(Punto p1, Punto p2);
double distancia(Punto p1, Punto p2);
