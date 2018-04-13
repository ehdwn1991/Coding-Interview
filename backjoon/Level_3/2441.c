#include <stdio.h>

int main(){
	int N,space,asteric=0;
	scanf("%d",&N);
	space=N;
	for (int i = 0;i<N ; ++i)
	{	
		for (int k = 0; k <i; ++k)
		{
			printf(" ");//asteric
		}
		for (int j = 0; j < space-i; ++j)
		{
			printf("*");//space
		}
		printf("\n");
	}


}