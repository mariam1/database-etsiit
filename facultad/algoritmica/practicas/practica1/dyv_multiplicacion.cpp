#include <string>
#include <iostream>
#include <cmath>
#include "enterolargo.h"
#include <ctime>

#define MAX(X,Y) (X>Y)?X:Y

using namespace std;


enterolargo enterolargo::dyv_multiplicacion(enterolargo & d,enterolargo & e){

if(entero.size()<=1){
	enterolargo r;
	r = e*d;
	return r;
}
else{
	enterolargo x1,x2,y1,y2;
	enterolargo x,y;
	
	int n = entero.size();  /*partir el numero en dos*/
	int m = d.entero.size();
	for( int i = 0; i<n/2; i++)
		x1.entero.push_back(entero[i]);
	for ( int i = n/2; i<n; i++)
		x2.entero.push_back(entero[i]);
	for( int j = 0; j<m/2; j++)
		y1.entero.push_back(d.entero[j]);
	for( int j = m/2; j<m; j++)
		y2.entero.push_back(d.entero[j]);
	
	
	x = x1 + x2;
	y = y1 + y2;
	
	
	/*llamada recursiva*/
	
	enterolargo u = dyv_multiplicacion(x1,y1);
	enterolargo v = dyv_multiplicacion(x2,y2);
	enterolargo w = dyv_multiplicacion(x,y);
	
	enterolargo uSUMAv = u + v;
	enterolargo wRESTAuv = w - uSUMAv;
	enterolargo z = u + wRESTAuv;
	enterolargo resul = z + v;
	
	return z;
	}
}

int main(){

int k,f;
enterolargo i;
 clock_t antes,desp;
 for( f=0; f <= 100;f++){
	 antes = clock();
	 k = dyv_multiplicacion(f);
	 desp = clock();
	 cout << i << " " << desp-antes << endl;

return 0;

	}
}
