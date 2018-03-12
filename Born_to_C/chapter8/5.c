#include <stdio.h>

int main(){
	int a,b,c;
	printf("input: ");
	scanf("%d",&a);

	printf("input: ");
	scanf("%d",&b);
	
	printf("input: ");
	scanf("%d",&c);

	if(a>=b&&a>=c)
		printf("result : %d\n",a);
	else if(b>=c&&b>=a)
		printf("result : %d\n",b);

	else
		printf("result : %d\n",c);


}
