#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	char buf[500]={0,};
	char comp[100]={0,};
	char a;
	int comp_count=0;
	int state=0; //0==not equal, 1==equal
	int same_word=0;
	FILE *file;
	if((file=fopen(argv[1],"rt"))==NULL){
		printf("error\n");
		return 0;
	}
	fgets(buf,1024,file);
	printf("you input => %s\n",buf );

	while(1){

	while((a=getchar())!=10){
		comp[comp_count]=a;
		comp_count++;
	}
	comp[comp_count]='\0';
	if(strcmp(comp,"end")==0){
		break;
	}
	for (int i = 0; i < strlen(buf); ++i)
	{
		if(buf[i]==comp[0]){
			state=0;
			for (int j = 0; j < strlen(comp); ++j)
			{	state=1;
				if(buf[i+j]!=comp[j]){
					state=0;
					break;
				}
			}
			if(state==1){
				same_word++;
			}
		}

	}
	printf("%d\n",same_word );
	same_word=0;
	comp_count=0;
	state=0;
	for (int i = 0; i < strlen(comp); ++i)
	{	
		comp[i]=0;
	}

}





}

