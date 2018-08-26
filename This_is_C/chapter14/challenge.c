#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void challenge_1();
void challenge_2();
void challenge_3();
void print_sort();
void print_origin();
void sorting();
void avg_branch();
void insert_word();
void arr_sum();
int main(){
	// challenge_1();
	// challenge_2();
	challenge_3();


}

void challenge_3(){
	int sort[4]={0,};
	char sales_branch[4][100]={"관악점","강남점","명동점","대림점"};
	int sales_score[4][7]={{70,45,100,92,150,81},
	{88,92,77,30,53,55},
	{50,90,88,75,77,49},
	{120,92,80,150,130,105}};
	avg_branch(sales_score);
	sorting(sales_score,sort);
	print_sort(sales_score,sales_branch,sort);
	puts("");
	print_origin(sales_score,sales_branch);
}	

void print_origin(int (*p)[7],char (*q)[100]){
	puts("Branch sorting=============");
	for (int j = 0; j < 4; ++j)
	{
		printf("%s ",q[j] );
		for (int i = 0; i < 7; ++i)
		{
			printf("%4d", p[j][i]);
		}
		puts("");
	}
}

void print_sort(int (*p)[7],char (*q)[100],int sort[4]){
	int end_sort=0;
	int print_row=0;
	int sort_numbering=0;
	puts("Record sorting=============");
	while(1){
		if(sort_numbering>3)
			break;
		
		for (int i = 0; i < 4; ++i)
		{
			if(sort[sort_numbering]==p[i][6]){
				print_row=i;
				end_sort++;
				sort_numbering++;
				break;
			}
		}
		printf("%s ",q[print_row] );
		for (int i = 0; i < 7; ++i)
		{
			printf("%4d", p[print_row][i]);
		}
		puts("");

	}

	// printf("%d\n",p[0][6]);

}

void sorting(int (*p)[7],int arr[4]){
	int temp=0;
	for (int i = 0; i < 4; ++i)
	{
		arr[i]=p[i][6];
		// printf("%d\n\n",arr[i] );
	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 5; j>i ; --j)
		{
			if(arr[j-1]<arr[j]){
				temp = arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}

		}
	}

	// for (int i = 0; i < 4; ++i)
	// {
	// 	printf("%d\n",arr[i] );
	// }

}




void avg_branch(int (*p)[7]){
	double sum=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <7 ; ++j)
		{
			sum+=p[i][j];
			if(j==6)
				p[i][j]=(((sum/6)*10)+5)/10;
		}
		sum=0;
	}

}

void challenge_2(){
	char input[11][100]={0,};
	insert_word(input);

}

void insert_word(char (*p)[100]){
	char buf[100];
	int word_count=0;
	int i=0;
	for (int i = 0; i < 10; ++i)
	{
		printf("Insert any words :");
		scanf("%s",buf);
		if(strcmp(buf,"end")==0){
			break;
		}
		else{
			strcpy(p[word_count++],buf);
		}	
	}
	printf("Total %d Words\n",word_count);


	while(1){

		printf("Insert Search words : ");
		scanf("%s",buf);
		if(strcmp(buf,"end")==0){
			break;
		}
		while(1){
			if(i>9){
				printf("No such words %s\n",buf);
				break;
			}
			if(strcmp(p[i],buf)==0){
				printf("Find %s in %dth Words\n",p[i],i+1);
				break;
			}
			i++;
		}
		i=0;
	}

}


void challenge_1(){
	int arr[5][6]={0,};
	int count=1;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			arr[i][j]=count++;
			// printf("%d  ",arr[i][j] );
		}
		// printf("\n");
	}
	arr_sum(arr);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			// arr[i][j]=count++;
			printf("%3d  ",arr[i][j] );
		}
		printf("\n");
	}
}

void arr_sum(int (*p)[6]){
	int row_sum=0,col_sum=0,total_sum=0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			row_sum+=p[i][j];
			if(j==5){
				p[i][j]=row_sum;
				// total_sum+=row_sum;
				row_sum=0;
			}
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			col_sum+=p[j][i];
			if(j==4){
				p[j][i]=col_sum;
				total_sum+=col_sum;
				col_sum=0;
			}

			if(i==5){
				total_sum+=p[j][i];
			}

			if(i==5&&j==4)
				p[j][i]=total_sum;

		}
	}

}