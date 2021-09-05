/*
	나이, 키 두개의 데이터를 각각 3개의 분류를 만들어서 그 가지수를 구함
	ex) 
	13 147
	27 169
	66 152
	72 143
	23 185
	Age (~32) group -> 
	height (~157) group : 1 
	height (~171) group : 1 
	height (~185) group : 1 
	Age (~51) group -> 
	height (~157) group : 0 
	height (~171) group : 0 
	height (~185) group : 0 
	Age (~72) group -> 
	height (~157) group : 2 
	height (~171) group : 0 
	height (~185) group : 0 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_SIZE 1024

void input_tokenize(char *data);
void categorize(int *data);
static	int count=0;
int main(int argc,char **argv){
	input_tokenize(argv[1]);
	return 0;
}
void input_tokenize(char *data){
	FILE *fp ;
	char buf[MAX_STR_SIZE];
	char buf1[MAX_STR_SIZE]={0};
	int i=0;
	// int integer_buf[(file_size*int)]={'\0'};
	char *convert_int;
	fp = fopen(data, "rt");
	fseek(fp,0,SEEK_END);
	int fileleng=ftell(fp);
	rewind(fp);
	// printf("size file : %d\n",fileleng );
	int *integer_buf=(int*)malloc(sizeof(int)*fileleng);
	while(!feof(fp))
	{
		fgets(buf,MAX_STR_SIZE,fp);
		//strcpy(buf1,buf); 
		convert_int=strtok(buf," \n");
		while(convert_int!=NULL){
			integer_buf[i]=atoi(convert_int);
			// printf("convert_int : %s int : %d\n",convert_int,integer_buf[i]);
			convert_int=strtok(NULL," \n");
			i++;
			count++;
		}
	}
	fclose(fp);
	categorize(integer_buf);
}
void categorize(int *data){
	int comp1,comp2;
	int min_age,max_age,avg_age;
	int min_height,max_height,avg_height;
	int data_sheet[9][3]={0,};
	min_age = data[0];
	max_age = data[0];
	min_height =data[1];
	max_height=data[1];
	for(int i=0;i<count;i++){
		
		if(i%2==0){
			max_age=max_age>data[i]?max_age:data[i];	
			min_age=min_age<data[i]?min_age:data[i];
		}
		else{
			max_height=max_height>data[i]?max_height:data[i];	
			min_height=min_height<data[i]?min_height:data[i];
		}	

	}
	avg_age= ((max_age-min_age)/3);
	avg_height=((max_height-min_height)/3);
	//printf("min_age: %d max_age: %d avg_age : %d \n min_height: %d max_height: %d height : %d\n",min_age,max_age,avg_age,min_height,max_height,avg_height );
	for (int i = 0; i < 9; ++i)
	{
		if(i<3)
			data_sheet[i][0]=min_age+avg_age;
		else if(3<=i&&i<6)
			data_sheet[i][0]=(avg_age*2+min_age);
		else
			data_sheet[i][0]=max_age;

	}
	for (int i = 0; i < 9; ++i)
	{
		if(i%3==0){
			data_sheet[i][1]=min_height+avg_height;
			data_sheet[i+1][1]=(avg_height*2+min_height);
			data_sheet[i+2][1]=(max_height);
		}
		/* code */
	}
	for (int i = 0; i <count; ++i)
	{
		if(i%2==0){
			if(min_age<=data[i]&&data[i]<=(avg_age+min_age)){
				if(min_height<=data[i+1]&&data[i+1]<=(avg_height+min_height)){
					data_sheet[0][2]+=1;
				}
				else if(avg_height<data[i+1]&&data[i+1]<=(2*avg_height+min_height)){
					data_sheet[1][2]+=1;
				}
				else
					data_sheet[2][2]+=1;
			}
			else if((avg_age+min_age)<data[i]&&data[i]<=(2*avg_age+min_age)){
				if(min_height<=data[i+1]&&data[i+1]<=(avg_height+min_height)){
					data_sheet[3][2]+=1;
				}
				else if(avg_height<data[i+1]&&data[i+1]<=(2*avg_height+min_height)){
					data_sheet[4][2]+=1;
				}
				else
					data_sheet[5][2]+=1;
			}
			else{
				if(min_height<=data[i+1]&&data[i+1]<=(avg_height+min_height)){
					data_sheet[6][2]+=1;
				}
				else if(avg_height<data[i+1]&&data[i+1]<=(2*avg_height+min_height)){
					data_sheet[7][2]+=1;
				}
				else
					data_sheet[8][2]+=1;
			}
		}
	}
	for (int i = 0; i <3; ++i)
	{
		printf("Age (~%d) group -> \n",data_sheet[i*3][0]);
		for (int j = 0; j < 3; ++j)
		{
			printf("height (~%d) group : %d \n",data_sheet[j+i*3][1],data_sheet[j+i*3][2]);
			
		}
	}
}

