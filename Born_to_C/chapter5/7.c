#include <stdio.h>
int main(){
	int input;
	int x, result;
	int decimal_8,decimal_4,decimal_2,decimal_1;
	printf("input decimal : ");
	scanf("%d",&input);
	x=input;
	 decimal_8= x>=1000?(result+=8,x-=1000,1):0;	
	decimal_4= x>=100?(result+=4,x-=100,1):0;	
	decimal_2= x>=10?(result+=2,x-=10,1):0;	
	decimal_1= x>=1?(result+=1,1):0;	
	printf("binary to decimal :   %d  binary number : %d%d%d%d \n",result,decimal_8,decimal_4,decimal_2,decimal_1);
}
