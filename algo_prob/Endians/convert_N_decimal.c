#include <stdio.h>

int main(){
	int a=1000;
	int x=0,n=16;
	int *N_decimal;
	while(a<n){

		num=a/16;
		x=num%2;
		*N_decimal=x;
		N_decimal++;
	}

	puts(N_decimal);
}