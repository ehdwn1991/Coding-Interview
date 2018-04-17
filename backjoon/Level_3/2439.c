#include <stdio.h>

int main(){
	int N,space,asteric=0;
	scanf("%d",&N);
	space=N-1;
	for (int i = 0;i<N ; ++i)
	{	
		for (int j = 0; j < space-i; ++j)
		{
			printf(" ");//space
		}
		for (int k = 0; k <= i; ++k)
		{
			printf("*");//asteric
		}
		printf("\n");
	}


}