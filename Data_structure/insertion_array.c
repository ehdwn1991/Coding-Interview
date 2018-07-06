#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arr_rand();
void showall();
void swap();
void insertion();
int main(){

	int arr[10]={0,};
	int ss=sizeof(arr)/sizeof(int);
	arr_rand(arr,ss);
	insertion(arr,ss);
	printf("After  sorting : ");
	showall(arr,ss);




}
void insertion(int *arr ,int arr_size){
	int pick=0,pick_loc=0;
	for (int i = 1; i < arr_size; ++i)
	{
		pick=arr[i];
		// printf("pick: %d i:%d\n",pick,i);
		for (int j = i-1; j >=0 ; --j)
		{
			if(pick<arr[j]){
				// printf("j: %d\n",j );
				// arr[j+1]=arr[j];
				// arr[j]=pick;
				swap(&arr[j+1],&arr[j]);
				// showall(arr,arr_size);
			}
		}
	}
}


void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void showall(int *arr,int arr_size){
	for (int i = 0; i < arr_size; ++i)
	{
		printf("%3d",arr[i] );
	}
	printf("\n");

}

void arr_rand(int *arr,int arr_size){
	int count=0;
	int *point_count=&count;
	srand( (unsigned)time(NULL) );
	int temp_rand;
	for (int j = 0; j <= count; ++j)
	{
		temp_rand=(rand()%100)+1;
		if(count==arr_size)
			break;
		if(arr[j]!=temp_rand){
			arr[j]=temp_rand;
			*point_count+=1;
		}
	}
	printf("Before sorting : ");
	showall(arr,arr_size);

	
}