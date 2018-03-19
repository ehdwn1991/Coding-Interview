#include <stdio.h>
int abs();
int main(){
	int a=0,result;
	printf("Insert num :");
	scanf("%d",&a);
	result = abs(a);
	printf("abs : %d\n",result);
}

int abs(int a){
	if(a<0)
		return -a;
	else
		return a;
}
