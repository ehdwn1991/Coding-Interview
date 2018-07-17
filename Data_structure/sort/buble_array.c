#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arr_rand();
void showall();
void swap();
void bubble();
int main(){

	int arr[10]={0,};
	int ss=sizeof(arr)/sizeof(int);
	arr_rand(arr,ss);
	bubble(arr,ss);
	showall(arr);
}

void bubble(int *arr,int arr_size){
	int check_swap=0;
	// 버블 소트 최적화 => 스왑이 발생하지 안으면 반복문 종료후 다음 인덱스 버블
	for (int i = 0; i < arr_size; ++i)
	{	
		check_swap=0;
		for (int j = i; j < arr_size; ++j)
		{
			if(arr[i]>arr[j]){
				swap(&arr[i],&arr[j]);
				check_swap=1;
			}
		}
		if(check_swap==0)
			break;
	}
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void showall(int *arr){
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",arr[i] );
	}
	

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


	
}