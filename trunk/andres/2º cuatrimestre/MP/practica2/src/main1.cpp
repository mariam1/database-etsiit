#include<iostream>
#include<string>
#include<cstring>
#include"imagenES.h"
#include"codificar.h"

using namespace std;

int main(){

const int MAXBUFFER= 1000000;
const int MAXNOMBRE= 100;
const int MAXMENSAJE= 125000;
char mensaje[MAXMENSAJE];
char nombre_imagen[MAXNOMBRE];
char imagen_salida[MAXNOMBRE];
unsigned char buffer[MAXBUFFER];
TipoImagen img;
int fil,col;

cout<<"Introduzca la imagen de entrada: " << endl;
cin.getline(nombre_imagen,MAXNOMBRE);
img=LeerTipoImagen(nombre_imagen,fil,col);

cout<<"Introduzca la imagen de salida: " << endl;
cin.getline(imagen_salida,MAXNOMBRE);

cout<<"Introduzca el mensaje:" <<endl;
cin.getline(mensaje,MAXMENSAJE);

//

if(img == IMG_PGM){
	char extension[]=".pgm";
	LeerImagenPGM(nombre_imagen,fil,col, buffer);
	strcat(imagen_salida,extension);
	Ocultar(buffer,mensaje);
	EscribirImagenPGM(imagen_salida, buffer, fil, col);
	cout<< "Ocultando..."<< endl;

}else if( img == IMG_PPM){
		char extension[]=".ppm";
		LeerImagenPPM(nombre_imagen,fil,col,buffer);
		strcat(imagen_salida,extension);
		Ocultar(buffer,mensaje);
		EscribirImagenPPM(imagen_salida,buffer,fil,col);
		cout<< "Ocultando..."<< endl;

}else
		cout<<"La imagen no se puede leer"<<endl;

}
