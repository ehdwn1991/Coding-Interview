#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	
	int a,b,c,multi;
	int count[10]={0,};
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	multi=a*b*c;

	while(multi>0){
		count[multi%10]+=1;
		multi/=10;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",count[i]);

	}

}
