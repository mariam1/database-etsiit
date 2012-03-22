#include <iostream>
#include <string>
#include "imagenES.h"
#include "codificar.h"

using namespace std;

int main(){

const int MAXBUFFER= 1000000;
const int MAXNOMBRE= 100;
const int MAXMENSAJE= 100;
char mensaje[MAXMENSAJE];
char nombre_imagen[MAXNOMBRE];
unsigned char buffer[MAXBUFFER];
TipoImagen img;
int fil,col;

cout <<"Introduzca la imagen de entrada:"<< endl;

cin.getline(nombre_imagen,MAXNOMBRE);
img=LeerTipoImagen(nombre_imagen,fil,col);

if(img == IMG_PGM){
	LeerImagenPGM(nombre_imagen,fil,col, buffer);
	cout << "Revelando..." << endl;
	cout << "El mensaje obtenido es: ";
	Revelar(buffer,mensaje);

   }
   else if( img == IMG_PPM){
	    LeerImagenPPM(nombre_imagen,fil,col,buffer);
	    cout << "Revelando..." << endl;
	    cout << "El mensaje obtenido es: ";
	    Revelar(buffer,mensaje);
   }
   else
	cout << "La imagen no se puede leer. " << endl;


for(int i=0; mensaje[i]!='\0'; i++)
	cout << mensaje[i];


cout << endl;

}
