#include <stdio.h>

int main(){
	int in_num,factorial=1,num;
	printf("Factorial equation :");
	scanf("%d",&in_num);
	num=in_num;
	printf("%d! = ",in_num);
	while(in_num>1){
	printf("(%d) * ",in_num);
	factorial*=(in_num--);
	}
	
	printf(" (1)\nCalculate %d's Factorical : %d\n",num,factorial);

}
