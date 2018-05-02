#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char buf[8]={0,};
	int start_num=2;
	fgets(buf,sizeof(buf),stdin);

	for(int i=3;0<i;i--){
		if(buf[i-1]>buf[i+3]&&(buf[i-1]!=buf[i+3])){
			start_num=2;
			break;
			}
		else{
			if(buf[i-1]<buf[i+3]&&(buf[i-1]!=buf[i+3])){
			start_num=6;
			break;
			}
			}
				
		
		}
	for(int j=0;j<3;j++){
	printf("%c",buf[start_num-j]);
		}
		puts("");
}
