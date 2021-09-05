#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	int now_point=0,total_point=0;
	int count=0;
	char buf[81]={'\0',};
	scanf("%d",&count);
	while(getchar()!=10);
// 입력 버퍼를 비워 주지 않으면 테스트 횟수 입력후 첫번째 케이스 문자가 입력이 안됨
// 왜냐면 처음 반복 횟수 입력후 버퍼의 상태는 N\n 이렇게 들어있음 즉 숫자와 엔터가
// 들어있는 상태임 그래서 그다음에 fgets 를 쓰려고 하면 입력이 끝나 버리는것
//그래서 두가지 방법중 하나를 써줘야됨
//1.scanf("%d ") => 공백을 하나 추가하여 

//2.while(getchar()!=10) \n 이 나올때까지 입력 버퍼를 비워줌
	for(int i=0;i<count;i++){
	fgets(buf,sizeof(buf),stdin);
	for(int j=0;j<strlen(buf);j++){
//	printf("%c",buf[j]);
	if(buf[j]=='O'){
	++now_point;
	total_point+=now_point;
	}
	
	if(buf[j]=='X'){
	now_point=0;
	}	
	
	}
	printf("%d\n",total_point);
	total_point=0;
	now_point=0;
	
	memset(buf,'\0',strlen(buf));
	}
	
}

