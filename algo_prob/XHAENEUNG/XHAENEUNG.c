#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 500
char bubble(char *a);
void swap(char *p, char *q);
int convert_to_num(char *a);
char *result_check(int correct_result,char *a);
void run_process();
int operation(int operator,char *firsrt_num,char *second_num);
char show_result[1000];

int main(){
	int run_time;
	scanf("%d\n",&run_time);
	for (int i = 0; i < run_time; ++i)
	{
		run_process();
	}

	printf("%s",show_result);


	return 0;
}
void run_process(){
	int i=0;
	int calculate_equation=0;
	char input_buffer[Max];
	char *token=NULL;
	char *token_split=" -*=+/\n";
	char temp_in[100][100];
	char *temp1;
	int operator;
	fgets(input_buffer,Max,stdin);
	if(strstr(input_buffer,"+")!=NULL){
		operator='+';
	}
	else if(strstr(input_buffer,"-")!=NULL){
		operator='-';
	}
	else if(strstr(input_buffer,"*")!=NULL){
		operator='*';
	}
	else if(strstr(input_buffer,"/")!=NULL){
		operator='/';
	}
	else{
		strcat(show_result,"No");
		strcat(show_result,"\n");
	}
	token=strtok(input_buffer,token_split);
	
	while(token!=NULL){
		strcpy(temp_in[i],token);
		token=strtok(NULL,token_split);
		i++;
	}
	calculate_equation= operation(operator,temp_in[0],temp_in[1]);
	if(calculate_equation>11 || calculate_equation<0){
		temp1="No";
	}
	else{
		temp1=result_check(calculate_equation,temp_in[2]);
	}
	strcat(show_result,temp1);
	strcat(show_result,"\n");

}


int operation(int operator,char *firsrt_num,char *second_num){
	int calculate_equation;
	switch(operator){
		case '+' :
		calculate_equation=(convert_to_num(firsrt_num)+convert_to_num(second_num));
		break;
		case '-':
		calculate_equation=(convert_to_num(firsrt_num)-convert_to_num(second_num));
		break;
		case '*':
		calculate_equation=(convert_to_num(firsrt_num)*convert_to_num(second_num));
		break;
		case '/':
		calculate_equation=(convert_to_num(firsrt_num)/convert_to_num(second_num));
		break;
	}
	return calculate_equation;
}
int convert_to_num(char *a){
	char comp_char[11][100]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
	int convert_num=0;
	for (int i = 0; i <= 10; ++i)
	{
		if(strcmp(a,comp_char[i])==0){
			convert_num=i;
		}
		
	}
	return convert_num;
}

char *result_check(int correct_result,char *a){
	char comp_char[11][100]={"zero","one","two","three", "four" ,"five","six","seven","eight","nine","ten"};
	char *temp_comp=comp_char[correct_result];
	char *check_result;
	bubble(temp_comp);
	bubble(a);
	if(correct_result<0 || correct_result>11)
		check_result ="No";
	else if(strcmp(temp_comp,a)==0)
		check_result ="Yes";
	else
		check_result ="No";


	return check_result;

}


char bubble(char *a)
{	
	int i, j,k;
	int n=(int)strlen(a);
	for (i = 0; i < n-1 ; ++i){
		for (j = n-1 ; j > i; --j){
			if (a[j-1] > a[j]){
				swap(&a[j-1],&a[j]);

			}
		}

	}
	return *a;
}

void swap(char *p,char *q){
	static char cnt=1;
	char temp=*p;
	*p=*q;
	*q=temp;
	cnt++;
}