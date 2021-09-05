#include <stdio.h>
#include <stdlib.h>
int main(){
	int N;
	scanf("%d",&N);

	int **row;
	row=(int**)malloc(sizeof(int*)*N);

	for (int i = 0; i < N; ++i)
	{
		row[i]=(int*)malloc(sizeof(int)*((N*2)-1));
	}

	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i+1; ++j)
		{
			if(j==0||j==i){
				*(*(row+i)+(N-1+(j*2)-i))=1;
			}
			else{
				*(*(row+i)+(N-1-i+(j*2)))=(*(*(row+i-1)+(N-1-i-1+(j*2))))+(*(*(row+(i-1))+(N-1-i+(j*2)+1)));
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int q = 0; q < (N*2)-1; ++q)
		{
			
			if(*(*(row+i)+q)%2==1)
			// if(*(*(row+i)+q)!=0)
				printf("%d",*(*(row+i)+q));
			else{
				printf(" ");
			}

		}

		free(*(row+i));
		puts("");
	}

}