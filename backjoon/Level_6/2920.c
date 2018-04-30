/*
c d e f g a b C, 총 8개 음으로 이루어져있다. 이 문제에서 8개
음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.

1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending,
둘 다 아니라면 mixed 이다.

연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지 
아니면 mixed인지 판별하는 프로그램을 작성하시오.

cdefgabC
12345678
*/
#include <stdio.h>

int main(){
	int temp[8]={0,};
	int state[8]={0,};
	int now_state;
	// 0=ascending 1=descending 2=mix


	for(int i=0;i<8;i++){
	scanf("%d",&temp[i]);
	}
	now_state=temp[1]-temp[0];

	
	for(int j=0;j<7;j++){
		if(now_state==1&&now_state==(temp[j+1]-temp[j]))
			continue;
	
		else if(now_state<0&&now_state==(temp[j+1]-temp[j]))
			continue;
		else{
			now_state=2;
		break;

		}
			
	}	

	if(now_state==1)
		printf("ascending\n");
	else if(now_state<0)
		printf("descending\n");
	else
		printf("mixed\n");

		


}
