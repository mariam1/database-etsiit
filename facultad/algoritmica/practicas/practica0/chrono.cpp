#include<iostream>
#include<ctime>

using namespace std;

int H1(int n){
	if (n==0) return 1;
	else return H1(n-1)*H1(n-1);
}

int H2(int n){
	double aux;
	if (n==0) return 1;
	aux = H2(n-1);
	return aux*aux;
}

int main(){
	int i,k;
	clock_t antes,desp;
	for(i=0;i<40;i++){
		antes=clock();
		k=H1(i);
		desp=clock();
		cout << i << " " << desp-antes << endl;
	}
}