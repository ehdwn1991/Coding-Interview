#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_SIZE 1024
int count=0;
int big_num(int *data_sheet,char argument);
int main(int argc,char **argv){
	int i=0;
	char buf[MAX_STR_SIZE];
	FILE *fp ;
	char *temp;
	fp = fopen(argv[1], "rt");
	fseek(fp,0,SEEK_END);
	int file_size = ftell(fp);
	rewind(fp);
	int *check_in=(int*)malloc(sizeof(int)*file_size);
	while(!feof(fp))
	{
		fgets(buf,MAX_STR_SIZE,fp);
		temp=strtok(buf," \n");
		while(temp!=NULL){
			check_in[i]=atoi(temp);
			printf("temp : %s int : %d\n",temp,check_in[i]);
			temp=strtok(NULL," \n");
			i++;
			count++;
		}



		i=big_num(check_in,"floor_number");

	}

}
int big_num(int *data_sheet,char *argument){
	int num;
	// if(argument=="floor_number"){}
	// else if(argument=="room_number"){}
	// else{
	// 	printf("Invalid argument!!!\n");
	// 	return 0;
	// }


	return num;
}