#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "enterolargo.h"
#include <ctime>

#define MAX(X,Y) (X>Y)?X:Y

using namespace std;


int main(){
	
	long int a = 1234;
	long int b = 2314;
	
	enterolargo numero1(a),enterolargo numero2(b);
    
   for (int n=4; n <= 16384; n*=2){
		for (int i=0; i < n; i++){
			numero1 = numero1 * 10;
			numero1 = numero1 + (rand()%9)+1;
		}

		srand(time(0));
		const int NUM_VECES = 100;
		time_t tantes,tdespues;
    
		time(&tantes);
		for (int i=0;i<NUM_VECES;i++)
			dyv_multiplicacion(numero1,numero1);
        
		time(&tdespues);
		cout<< n << " " << (difftime(tdespues,tantes))/(double)NUM_VECES<<endl;
	}
}
