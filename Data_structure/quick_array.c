#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arr_rand();
void showall();
void swap();
void quick();
int partition();
int main(){

	int arr[10]={0,};
	int ss=sizeof(arr)/sizeof(int);
	arr_rand(arr,ss);
	quick(arr,0,ss-1);
	printf("After  sorting : ");
	showall(arr,ss);




}

int partition(int *arr,int low_point,int high_point){
    int pivot = arr[high_point]; 
    int pivot_loc=low_point-1;
    printf("high: %d pi:%d \n",high_point,pivot );
    for (int i = low_point; i <= high_point-1; ++i)
    {
    	printf("Before  ");
    	showall(arr,high_point+1);
    	if(arr[i]<=pivot){
    		pivot_loc++;
    		swap(&arr[pivot_loc],&arr[i]);
    	printf("After   ");
    	showall(arr,high_point+1);

    	}

    }
    swap(&arr[pivot_loc+1],&arr[high_point]);

    return pivot_loc+1;

}
void quick(int *arr,int low_point, int high_point){

	if(low_point <high_point){
		int pivot=partition(arr,low_point,high_point);
		quick(arr,low_point,pivot-1);
		quick(arr,pivot+1,high_point);
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