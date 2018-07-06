// 입력값이 음수가 들어올수도 있음

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort();
void swap();
int main(){
	int N,input,count=1;
	scanf("%d",&N);

	int *arr=(int*)malloc(sizeof(int)*N);
	memset(arr,0,sizeof(int)*N);

	for (int i = 0; i <N ; i++)
	{
		scanf("%d",&arr[i]);

	}
	sort(arr,N);

	for (int i = 0; i < N; ++i)
	{
		printf("%d\n",arr[i] );


	}
}


void sort(int *arr,int n){
	int i, j,k;
	for (i = 0; i < n - 1; ++i){
		for (j = n - 1; j > i; --j){
			if (arr[j-1] > arr[j]){
				swap(&arr[j-1],&arr[j]);

			}
		}

	}

}


void swap(int *a, int *b){
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}