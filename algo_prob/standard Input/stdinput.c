#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 500


void showall(char *a);
char input();

int main(){
	char *temp;
	temp=input();
	showall(temp);





	return 0;
}

char input(){
	int i,j,k=0;
	int string_size;
	char buffer[255];
	char *temp;
	
	fgets(buffer,Max,stdin);

	string_size = (int)strlen(buffer);


	char *sizearr= (char*)malloc(sizeof(char));

	for (int i = 0; i < string_size; ++i)
	{
		if(buffer[i]==10){
			*(sizearr+k) ='\0';
			printf("k:%d  i: %d str_before:1 %d\n",k,i,*(sizearr+k));
		}

		if(buffer[i]!=32 && buffer[i]!=10){  //32 space bar
			*(sizearr+k) = buffer[i];
			printf("k:%d  i: %d str_before: %d\n",k,i,*(sizearr+k));
			k++;
		}
		
	}
	temp=sizearr;
	showall(sizearr);
	return *sizearr;
}

void showall(char *a){
	int i=0;
	for (int i = 0; *(a+i)!='\0'; ++i)
	{
		//printf("[%d]:%d ",i,(int)(sizearr+i) );
		printf("[%d]:%#x (%d)  ",i,(a[i]),*(a+i)-48 );
		(a[i])= '\0';
	}
	printf("\n");
}