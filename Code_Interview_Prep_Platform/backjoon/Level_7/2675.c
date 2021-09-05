#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void QR_code();
int main(){
	int N;
	char buf[24]={'\0',};
//	문자는 20글자 앞에 반복횟수 N  공백 까지 22에 마지막 엔터 23으로 되야 하는데 안되서 24로 잡음
	scanf("%d",&N);
	while(getchar()!=10);

	for(int i=0;i<N;i++){
		fgets(buf,sizeof(buf),stdin);
				QR_code(buf);
				puts("");
	memset(buf,'\0',strlen(buf));
}



}

void QR_code(char *q){
		
	for(int i=2;i<strlen(q)-1;i++){
		for(int j=0;j<(*q)-48;j++){
			printf("%c",*(q+i));
		}
			
}

}
