#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int star=0,blank=2;
	for(int i=0;i<5;i++){
		if(i>2){ 
			star-=2;
			blank++;
		}
		else{	
			star=2*i+1;
			blank--;
		}
		for(int k=0;k<=blank;k++) printf(" ");
		for(int j=0;j<star;j++){
			printf("*");
			}
		
		puts("");
	}
return 0;
}
