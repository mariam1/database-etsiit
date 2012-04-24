/*

Program: Multiplicacion de enteros grandes
Asignatura: Algoritmica

autor: J. Huete

*/

#include <iostream>
#include <string>
#include "enterolargo.h"

using namespace std;



int main () {

string a;

long int b;


cout<<"primer numero a multiplicar:";

cin>>a;

cout<<"segundo numero a multiplicar:";

cin>>b;

enterolargo numero1(a), numero2(b);
enterolargo aux;

cout << numero1 << " " << numero2 << "\n\n";
aux = numero1.dyv_multiplicacion(numero2);
cout << "producto: " << aux << endl; 
return (0);

}
