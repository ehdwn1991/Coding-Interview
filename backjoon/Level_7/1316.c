#include <stdio.h>
#include <string.h>
int checker();
int main(){
	int N;
	char buf[101]={'\0',};
	int result=0;
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		scanf("%s",buf);
		result+=checker(buf);
//		puts(buf);

//		puts("");
	}
printf("%d\n",result);



} 

int checker(char *q){
	char alpha[101]={'\0'};
	int duplicate_count=0;
	for(int i=0;i<strlen(q);i++){
		if(alpha[duplicate_count]==0&&alpha[duplicate_count-1]!=(*(q+i))){
			alpha[duplicate_count]=(*(q+i));
			duplicate_count++;
		}
	}
	
	for(int j=0;j<strlen(alpha);j++){
		for(int k=j+1;k<strlen(alpha);k++){
			if(alpha[j]==alpha[k])
				return 0;
		}

		}

return 1;
}
