/*

Program: Multiplicacion de enteros grandes
Asignatura: Algoritmica

autor: J. Huete

*/
#ifndef __ENT_LARGO_H
#define __ENT_LARGO_H

#include <iostream>
#include <vector>
#include <cmath> 
#include <string>

using namespace std;


class enterolargo{
public: 
  enterolargo();
  enterolargo(const string & s);
  enterolargo(long int & e);
  enterolargo(const enterolargo & e);
  
  int longitud();
  
  enterolargo operator+(enterolargo &d); 
  enterolargo operator-(enterolargo & d);
  enterolargo operator*(enterolargo & d);
  enterolargo clasico(enterolargo & d);
  enterolargo dyv_multiplicacion(enterolargo & d);
  enterolargo & operator= (const enterolargo & e);
  enterolargo digitos(enterolargo & d);

  
  friend ostream & operator<<(ostream & x, enterolargo & e);

private:
 void desplazarDerecha(int n);
 void completa_izq(int n);
 void ajusta( );
 int pot_2(int n);
 char signo;
  
  // Por simplicidad asumimos numeros positivos.....
  vector<int> entero;  
  // El digito mas significativo del entero esta en la posi entero[entero.size()-1]
  
};

#endif
