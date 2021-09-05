#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

	int count=0,is_word=0;
	char input;
	//is_word=0 =>until not using any word
	//is_word=1 =>wherever used any word before using space

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
			if(input==32&&is_word==0){
			}
			else if(input==32&&is_word==1){
				count++;
				is_word=0;
			}
		}

	}
	printf("%d\n",count );

}
