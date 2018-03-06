#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>
#define Max 10000
int main(){
	int input_case=0;
	int running_case=0;
	int i=0,j=0;
	long convert_hex=0;
	char *input_buffer=(char*)malloc(sizeof(char)*Max);
	char temp_arr[Max]={'\0'};
	scanf("%d\n",&input_case);
	for(int running_case=0; running_case<input_case; running_case++){
		fgets(input_buffer,Max,stdin);
	}
	j=atoi(input_buffer);
	convert_hex=strtol(input_buffer,NULL,10);
	printf("%d  hex : %x   convert_hex : %ld\n",j,j,convert_hex );
	for(int i=0;i<sizeof(input_buffer);i++){
		printf("%c",*input_buffer);
		input_buffer++;
	}
	// printf("%0.00x\n",*input_buffer);

}


int convert_to_hex(int convert_hex){
	int a=0;

}
