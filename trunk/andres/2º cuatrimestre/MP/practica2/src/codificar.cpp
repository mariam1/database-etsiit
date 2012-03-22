#include <iostream>
#include <string>

using namespace std;


void Ocultar(unsigned char imagen[], char mensaje[]){
	
	int n, m = 0;
	int byte = 0;
		
	for(unsigned int i = 0 ; byte < 8; ++i){ // cuando encuentra 00000000 -> ha terminado el mensaje 
		
		byte = 0;
		n = 128;

		for(unsigned int j = 0 ; j < 8 ; ++j){

			
			if((n&mensaje[i])==0){			// hay un 0 en la letra -> hay que insertar un 0 en el bit menos significativo del i-esimo pixel			
				byte++;
				//if((imagen[i]&1)==1) 			// hay un 1 en el pixel (bit menos significativo)
					imagen[m]=(imagen[m]&(~1)); 	// inserto 0 


			}else						// hay un 1 en la letra -> hay que insertar 1 en el bit menos sign. del i-esimo pixel
				//if((imagen[i]&1)!=1) 			// hay un 0 en el pixel (bit menos significativo)
					imagen[m]=(imagen[m]|1);	// inserto 1
			
			n=n>>1; // 128 -> 64 -> 32 -> ...
			m++;
		}
		

			
			
	}
	
}


void Revelar(unsigned char imagen[], char mensaje[]){

	int parar = 0;
	int m = 0;
	int a;
	
	for(unsigned int i=0; parar < 8 ; ++i){
		a = 0;
	        parar = 0;
		for(unsigned int j=0; j < 8 ; j++){
			a = a<<1;

			if((imagen[m]&1)!=0){ 	// hay un 1 en el pixel
				a = a|1;	// inserto 1 (luego a = a<<1)
			}
			else
				parar++;	// contador de ceros ++
			m++;
		}
	mensaje[i] = a;
	}
	
}
