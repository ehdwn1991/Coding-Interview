#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void buble();
void swap();
int main(){
	int N;
	scanf("%d",&N);
	int *rand_arr=(int*)malloc(sizeof(int)*N);
	srand(time(NULL));
	for (int i = 1; i <= N; ++i)
	{
		// rand_arr[i-1]=(rand()%100)+1;
		rand_arr[N-1-i]=i;
		printf("%d ",rand_arr[i-1] );

	}
	buble(rand_arr,N);
	puts("");
	
	for (int i = 0; i < N; ++i)
	{
		printf("%d ",rand_arr[i] );
	}
	puts("");

}

void buble(int *arr,int size){
	for (int i = 0; i < size; ++i)
	{
		for (int j =i+1; j < size; ++j)
		{
			if(*(arr+j-1)>*(arr+j)){
	printf("\nddd\n");
				swap(arr[j-1],arr[j]);
			}
		}
	}



}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}