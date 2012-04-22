#include <string>
#include <iostream>
#include <cmath>
#include "enterolargo.h"

#define MAX(X,Y) (X>Y)?X:Y

using namespace std;

enterolargo enterolargo::digitos(enterolargo &d){
	
enterolargo res;

int Nmin = (entero.size() < d.entero.size())?entero.size()-1: d.entero.size();

//int aux = min(d, (unsigned int)entero.size()-1);

while (Nmin>=0 && entero[Nmin]==0)
Nmin--;

//for (int i=Nmin; i>=max((int)entero.size(), 0); i--)
for (int i = Nmin; i >=MAX(entero.size(),0);i--)
res.entero.insert(res.entero.begin(), entero[i]);

return res;
}

enterolargo enterolargo::dyv_multiplicacion(enterolargo & d){

enterolargo resultado;
enterolargo resultado2;
enterolargo resultado3;

enterolargo m1_e = entero.digitos(0,entero.size()/2-1);
enterolargo m1_d = d.entero.digitos(0,d.entero.size()/2-1);

enterolargo m2_e = entero.digitos( entero.size()/2,entero.size() );
enterolargo m2_d = d.entero.digitos( d.entero.size()/2,d.entero.size() );

if ( entero.size() < 3 )
	resultado = entero * d;

return resultado;
}

/*Nmin = (entero.size() < d.entero.size())?entero.size(): d.entero.size();
 * 
 * bigint bigint::digits(unsigned int a, unsigned int b) const
{
bigint res;
int aux = min(b, (unsigned int)digitos.size()-1);

while (aux>=0 && digitos[aux]==0)
aux--;

for (int i=aux; i>=max((int)a, 0); i--)
res.digitos.insert(res.digitos.begin(), digitos[i]);

return res;
}
* 
* 
 * 
 * enterolargo enterolargo::dyv_multiplicacion(enterolargo & d){
	
	enterolargo resultado;
	enterolargo resultado2;
	enterolargo resultado3;
	
	enterolargo primera_mitad_e = (entero.size()/2-1);
	//enterolargo primera_mitad_d = (d.entero.size()/2-1);
	
	
	
	return primera_mitad_e;
}
* 

int main (){
	
long int a;

cout << "Introduce un numero: " << endl;
cin >> a;

enterolargo numero1(a);

dyv_multiplicacion(numero1);

cout << "a: "<< numero1 << endl;


return 0;

}*/
