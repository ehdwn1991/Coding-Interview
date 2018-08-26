#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void challenge_1();
void challenge_2();
void challenge_3();
void print_intro();
void sort_intro();
void init_intro();
int input_intro();
int input_name();
void print_name();
int search_name();
void swap();
int main(){
	// challenge_1();
	// challenge_2();
	challenge_3();
}

void challenge_3(){
	char intro[10][80]={0,};
	char *pint[10]={0,};
	int cnt;
	init_intro(intro,pint);
	cnt = input_intro(intro);
	sort_intro(pint,cnt);
	print_intro(1,pint,cnt);
	print_intro(0,intro,cnt);
}

void print_intro(int mode, void *vp,int cnt){


	if(mode ==1){
		for (int i = 0; i < cnt; ++i)
		{
			printf("\nDictionary order\n");
			printf("%s\n",*((char**)vp+i) ); //pint
			// 간접 접근
			// printf("%s\n",((char**)vp)[i] ); //pint
			// 직접 접근
		}
	}
	else{
	// printf("%s\n",((char*)vp) );  //intro
		for (int i = 0; i < cnt; ++i)
		{
			printf("\nOrdered by input numbering\n");
			// printf("%s\n",((char (*)[80])vp)+i);
			// 간접 접근
			printf("%s\n",((char (*)[80])vp)[i]);
			// 직접 접근
		}
	}
}


void sort_intro(char **pint,int cnt){
	char *temp;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = cnt-1; j > i; --j)
		{
			if(strcmp(pint[j-1],pint[j])>0){
				temp=pint[j-1];
				pint[j-1]=pint[j];
				pint[j]=temp;
			}

		}
	}
}

int input_intro(char (*intro)[80]){
	char buf[100];
	int intro_row=0;
	while(1){

		scanf("%s",buf);
		if(strcmp(buf,"end")==0){

			break;
		}
		else{
			strcpy(intro[intro_row++],buf);
			// pint[intro_row]=intro[intro_row];
		}

	}
	
	return intro_row;
}

void init_intro(char (*intro)[80],char **pint){
	for (int i = 0; i < 10; ++i)
	{
		pint[i]=intro[i];

	}
}

void challenge_2(){
	int a_age=0,b_age=0;
	double a_height=0,b_height=0;
	printf("First person :");
	scanf("%d %lf",&a_age,&a_height);
	printf("Second person :");
	scanf("%d %lf",&b_age,&b_height);
	swap("int",&a_age,&b_age);
	swap("double",&a_height,&b_height);
	printf("First=> %d %lf\n",a_age,a_height);
	printf("Second=> %d %lf\n",b_age,b_height);
}

void swap(char *p,void *a, void *b){
	int temp_int;
	double temp_double=0;
	if (strcmp(p,"int")==0)
	{
		temp_int = *((int*)a);
		*((int*)a)=*((int*)b);
		*((int*)b)=temp_int;
	}
	else{
		temp_double = *((double*)a);
		*((double*)a)=*((double*)b);
		*((double*)b)=temp_double;
		
	}
}

void challenge_1(){
	char name[10][20]={0,};
	int cnt=0;
	cnt = input_name(name);
	print_name(name,cnt);	
}

void print_name(char (*p)[20],int number_of_people){
	printf("Total %d people registered\n",number_of_people);
	for (int i = 0; i < number_of_people; ++i)
	{
		printf("%s\n",p[i] );
	}
	

}
int input_name(char (*p)[20]){
	char buf[20]={0,};
	int count=0;
	while(1){

		printf("name: ");
		scanf("%s",buf);
		if(search_name(p,buf,count)==0){
			printf("Overlapping name\n");
		}
		
		else if(strcmp(buf,"end")==0){
			break;
		}
		else{
			strcpy(p[count++],buf);
		}



	}

	return count;
}

int search_name(char (*p)[20],char *buf,int number_of_people){

	for (int i = 0; i < number_of_people; ++i)
	{
		if(strcmp(p[i],buf)==0)
			return 0;
	}
	return 1;
}