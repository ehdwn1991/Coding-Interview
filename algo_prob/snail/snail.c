#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int snail();
int find_blank();
int num_of_blank();
void show_all();
int main(){
	int vecter=0,count=1,last_row=0,last_col=0; //vecter =>plus or minus
	int **ar;
	int size;
	printf("input N by N size :");
	scanf("%d",&size);
	ar=(int**)calloc(size,sizeof(int*));
	for(int i=0;i<size;i++){
		ar[i]=(int*)calloc(size,sizeof(int));
	}

	while(1){

		if(count>(size*size)) break;
		count=snail(0,&vecter,&last_row,&last_col,count,ar,size);

		if(count>(size*size)) break;
		count=snail(1,&vecter,&last_row,&last_col,count,ar,size);
	}
	show_all(ar,size);

}

int snail(int angle,int *vecter,int *recent_row,int *recent_col,int count,int *arr[],int size){
	int blank,not_blank;
	int number_of_blank;
	if(*vecter==0){
		if(angle==0){

			blank=find_blank(arr,angle,*recent_row,size,0);	

			number_of_blank=num_of_blank(arr,angle,*recent_row,size);
			for(int i=blank;0<number_of_blank;i++,number_of_blank--){

				*(*(arr+*recent_row)+i)=count++;

				*recent_col=i;
			}
			*recent_row=(blank);

			return count;
		}

		else{

			blank=find_blank(arr,angle,*recent_col,size,0);	

			number_of_blank=num_of_blank(arr,angle,*recent_col,size);
			for(int i=blank;0<number_of_blank;i++,number_of_blank--){
				*(*(arr+i)+(*recent_col))=count++;
				*recent_row=i;
			}
			*vecter=1;
			return count;
		}
	}

	else{// vecter =1 decrease

		if(angle==0){

			blank=find_blank(arr,angle,*recent_row,size,0);	
			number_of_blank=num_of_blank(arr,angle,*recent_row,size);
			for(int i=*recent_col-1;0<number_of_blank;i--,number_of_blank--){
				*(*(arr+*recent_row)+i)=count++;
				*recent_col=i;
			}
			return count;
		}
		else{
			blank=find_blank(arr,angle,*recent_col,size,0);	
			number_of_blank=num_of_blank(arr,angle,*recent_col,size);
			for(int i=*recent_row-1;0<number_of_blank;i--,number_of_blank--){
				*(*(arr+i)+(*recent_col))=count++;
				*recent_row=i;
			}
			*vecter=0;
			return count;
		}
	}

}


int num_of_blank(int *arr[],int angle,int last_row_or_col,int size){
	int number_of_blank=0;
	if(angle==0){ //가로 블랭크 수
		for(int i=0;i<size;i++)
			if((*(*(arr+last_row_or_col)+i))=='\0') number_of_blank++;
		return number_of_blank;
	}
	else{//세로 블랭크 수
		for(int i=0;i<size;i++)
			if((*(*(arr+i)+last_row_or_col))=='\0') number_of_blank++;			
		return number_of_blank;
	}
}

int find_blank(int *arr[],int angle,int last_row_or_col,int N_by_N,int blank_or_not){
	if(angle==0){ //	angle=0 가로
		if(blank_or_not==0){//blank =0
			for(int i=0;i<N_by_N;i++)
				if((*(*(arr+last_row_or_col)+i))=='\0') return i;
		}

		else{//not blank =1
			for(int i=0;i<N_by_N;i++)
				if((*(*(arr+last_row_or_col)+i))!='\0') return i;

		}	
	}
	else{//angle =1
		if(blank_or_not==0){//blank =0
			for(int i=0;i<N_by_N;i++)
				if((*(*(arr+i)+last_row_or_col))=='\0') return i;
		}

		else{//not blank =1
			for(int i=0;i<N_by_N;i++)
				if((*(*(arr+i)+last_row_or_col))!='\0') return i;
		}
	}
	return -1;
}

void show_all(int *arr[],int size){
	printf("###########################################\n");
	for(int i=0;i<size;i++){
		for(int q=0;q<size;q++)
			printf("%d\t",arr[i][q]);
		printf("\n");
	}

}
