#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arr_rand();
void showall();
void swap();
void selection();
int main(){

	int arr[10]={0,};
	int ss=sizeof(arr)/sizeof(int);
	arr_rand(arr,ss);
	selection(arr,ss);
	printf("After  sorting : ");
	showall(arr,ss);




}
void selection(int *arr ,int arr_size){
	int min_element_loc;
	for (int i = 0; i < arr_size; ++i)
	{
		min_element_loc=i;
		printf("first min=>arr[%d]:%d\n",i,arr[i] );
		for (int j = i+1; j < arr_size; ++j)
		{
			if(arr[min_element_loc]>arr[j]){
				min_element_loc=j;
				printf("min=>arr[%d]:%d\n",j,arr[min_element_loc] );
				printf("min:%d\n",arr[min_element_loc] );
			}
		}
		swap(&arr[i],&arr[min_element_loc]);
				showall(arr,arr_size);
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