#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

	int count=0,is_space=0,is_word=0; //is_space => 0=before space 1=after space
	char input;

	// fgets(buf,sizeof(buf),stdin);

	// printf("len: %lu\n",strlen(buf) );

	// for (int i = 0; i < strlen(buf); ++i)
	// {
	// 	if(buf[i]==' '||buf[i]==10){
	// 		count++;


	// 	}


	// }

	while((input=getchar())!=EOF){
		if(input==10){
			if(is_word==1)
				count++;
			break;
		}
		if(input>32){
			is_word=1;
		}
		else{
			if(input==32&&is_word==0){//is space
				is_space=1;
			}
			else if(input==32&&is_word==1){
				count++;
				is_space=1;
				is_word=0;
			}
		}

	}
	printf("%d\n",count );

}