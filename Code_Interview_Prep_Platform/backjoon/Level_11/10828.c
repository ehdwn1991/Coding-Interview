// push X: 정수 X를 스택에 넣는 연산이다.

// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

// size: 스택에 들어있는 정수의 개수를 출력한다.

// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.

// top: 스택의 가장 위에 있는 정수를 출력한다.
// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 	int TC=0;
 	int a,b;
 	scanf("%d",&TC);
 	char **stack_point=(char**)malloc(sizeof(char*)*TC);
 	
 	for (int i = 0; i < TC; ++i)
 	{
 		*stack_point[i]=(char*)malloc(sizeof(char)*1024);
 	}



 	for (int i = 0; i < TC; ++i)
 	{
 	char *command=(char*)malloc(sizeof(char)*100);
 	fgets(command,1024,stdin);
 	free(command);
 	}

 	// printf("%d\n",strncmp(q,"push",4));

 	printf("%s %d\n",q,a );


}




void push(){

}

void pop(){}

void size(){}

