/*

Program: Multiplicacion de enteros grandes
Asignatura: Algoritmica

autor: J. Huete

*/

#include "enterolargo.h"
#define MAX(X,Y) (X>Y)?X:Y


// Metodos de entero largo
enterolargo::enterolargo(){}
enterolargo::enterolargo(const enterolargo & e){ entero = e.entero;}
  
  int enterolargo::longitud(){return entero.size();}
  
  enterolargo & enterolargo::operator= (const enterolargo & e){
           if (this != &e) {
	     entero = e.entero;
	   }
	   return *this;
  }


enterolargo::enterolargo (const string & s){
string::const_reverse_iterator i;

for (i=s.rbegin(); i!=s.rend(); i++)
  entero.push_back((*i)-'0');
}

enterolargo::enterolargo (long int & num){
int i;

//llenamos el vector con el número invertido
if (num==0) entero.push_back(0);
else  {
  while (num > 0) {
    entero.push_back( num % 10);
    num /= 10;
   }
 }
}



  

int enterolargo::pot_2 (int n) {// potencia de dos mas proxima a n

return  pow(2, ceil(log(n)/log(2)) );

}

void enterolargo::desplazarDerecha(int n){
    vector<int>  resul(n,0);
    for (int i = 0; i<entero.size(); i++)
       resul.push_back(entero[i]);
    
    entero = resul;
  }

  void enterolargo::completa_izq(int n){
    while (entero.size() <n)
      entero.push_back(0);
  }
  
  void enterolargo::ajusta( ){ // elimina ceros no significativos.
      while ((entero.size()>1) && (entero.back()==0))
	entero.pop_back();
  }

  

ostream & operator<<(ostream & x, enterolargo & e){
  vector<int>::reverse_iterator it;
 
  for (it = e.entero.rbegin(); it!= e.entero.rend(); ++it)
    x << *it;
  return x;
}

enterolargo enterolargo::clasico(enterolargo & e){
		enterolargo resul;
		
}



enterolargo  enterolargo::operator*(enterolargo & d){

int mul;
int acarreo=0;
int k;
int lon=this->entero.size();
enterolargo resul;

for(k=0;k<lon;k++){
	mul=(entero[k]*d.entero[k])+acarreo;
	acarreo=mul/10;
	mul=mul%10;
	resul.entero.push_back(mul);
}

cout << "mul_1: " << mul << endl;
cout << "acarreo: " << acarreo << endl;

if(acarreo!=0) resul.entero.push_back(acarreo);
//resul.signo='+';

cout << "resul: " << resul << endl;

return resul;
}

enterolargo  enterolargo::operator+(enterolargo & d){
  
int Nmin;  
int k;
enterolargo resul;

Nmin = (entero.size() < d.entero.size())?entero.size(): d.entero.size();

int acarreo=0;

//cout << "numero minimo: " << Nmin << endl;

for (k=0; k<Nmin; k++) {
  resul.entero.push_back( (entero[k] + d.entero[k] + acarreo ) % 10); //sacamos el modulo
  acarreo = (entero[k] + d.entero[k] + acarreo ) / 10; // saco el acarreo
  }
if (Nmin == entero.size()) 
{
  for  ( ; k<d.entero.size();k++){
      resul.entero.push_back( (d.entero[k] + acarreo ) % 10); //sacamos el modulo
      acarreo = (d.entero[k] + acarreo ) / 10; // saco el acarreo
  }
} else 
   for  ( ; k<entero.size();k++){
      resul.entero.push_back( (entero[k] + acarreo ) % 10); //sacamos el modulo
      acarreo = (entero[k] + acarreo ) / 10; // saco el acarreo
  }
  
if (acarreo>0) resul.entero.push_back(acarreo);
//cout << "acarreo: " << acarreo << endl;
//cout << "resultado: " << resul << endl;
return resul;
}
 
 
enterolargo enterolargo::operator-(enterolargo & d) {

// asumimos *this > d

int Nmin;  
int k;
enterolargo resul;

Nmin = (entero.size() < d.entero.size())?entero.size(): d.entero.size();

int i;

int debito = 0;
for (i=0; i<Nmin; i++) {

  resul.entero.push_back(entero[i] - d.entero[i] - debito);/* (rest1-(rest2+debito))*/
  if (resul.entero.back() >= 0)
    debito = 0;
    // la resta es negativa
  else {
    resul.entero.back() += 10;
    debito = 1;
    }//fin else
}//fin for
if (Nmin == entero.size()) 
{
  for  ( ; i<d.entero.size();i++){

       resul.entero.push_back( (d.entero[i] -debito ) ); 
       if (resul.entero.back() >= 0) debito = 0;
       else { resul.entero.back() += 10; debito = 1;
            }//fin else
  }
} else 
   for  ( ; i<entero.size();i++){

       resul.entero.push_back( (entero[i] -debito ) ); 
       if (resul.entero.back() >= 0) debito = 0;
       else { resul.entero.back() += 10; debito = 1;
            }//fin else
  }
  
return resul;

}//fin metodo resta

enterolargo enterolargo::dyv_multiplicacion(enterolargo & d){
	
	enterolargo resultado;
	enterolargo resultado2;
	enterolargo resultado3;
	
	int primera_mitad_entero = (entero.size()/2-1);
	//enterolargo primera_mitad_d = (d.entero.size()/2-1);
}
