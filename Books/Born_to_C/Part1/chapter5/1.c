#include <stdio.h>

int main(){
	int x,y,z,result;
	printf("input x : ");
	scanf("%d",&x);
	printf("input y : ");
	scanf("%d",&y);
	printf("input z : ");
	scanf("%d",&z);
result=(x+y)*(x+z)/(y%z);	
	printf("(x+y)*(y+z)/(y%%z)=%d\n",result); //% is not print in your terminal so ecaping %
}
