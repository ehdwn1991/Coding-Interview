##[2439번[별찍기2]](https://www.acmicpc.net/problem/2439)
>문제  : 다음과 같이 만들어지도록 출력

```c
	*
   **
  ***
 ****
*****
```

```c
#include <stdio.h>
int main(){
	int N,space,asteric=0;
	scanf("%d",&N);
	space=N-1;
	for (int i = 0;i<N ; ++i) //N줄 까지 공백과 별을 출력해줘야함
	{	
		for (int j = 0; j < space-i; ++j)
		{//space갯수는 N-1개부터 별 의 갯수만큼 감소
			printf(" ");//space
		}
		for (int k = 0; k <= i; ++k)
		{//별의 갯수는 N번째 줄 N개가됨.
			printf("*");//asteric
		}
		printf("\n");
	}
}
```

> 풀이 :  N줄 까지 우측 정렬로 출력 하는 문제.



## [2441번 [별찍기4]](https://www.acmicpc.net/problem/2441)
> 문제  : 다음과 같이 만들어지도록 출력

```c
*****
 ****
  ***
   **
    *
```

```c
#include <stdio.h>

int main(){
	int N,space,asteric=0;
	scanf("%d",&N);
	space=N;
	for (int i = 0;i<N ; ++i)
	{	
		for (int k = 0; k <i; ++k)
		{
			printf(" ");//asteric
		}
		for (int j = 0; j < space-i; ++j)
		{
			printf("*");//space
		}
		printf("\n");
	}


}
```

> 풀이 :  N줄 까지 역순 우측 정렬로 출력 하는 문제. 2439번에서 for문 순서만 바꿔주면 된다.


## [1924번 [2007]](https://www.acmicpc.net/problem/1924)
> 문제  : 오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

```c
#include <stdio.h>

int main(){
	char *day_of_week[7]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	//2007year 1month 1day is monday
	// SUN, MON, TUE, WED, THU, FRI, SAT
	int month_of_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	//1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까
	int month=0,day=0,now_of_day=0;
	// printf("\n");
	scanf("%d %d",&month,&day);
	for(int i=0;i<month-1;i++){
			now_of_day+=month_of_day[i];
	}
	now_of_day+=day;
	printf("%s\n",*(day_of_week+(now_of_day%7)));
}
```

> 풀이 : 월 과 일이 입력으로 주어지고, 현재 1월1일부터 몇일이 지났는지 now_of_day에 저장 후 요일을 계산

##[8393번[합]](https://www.acmicpc.net/problem/1924)
> 문제  : n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
```c
#include <stdio.h>

int main(){
    int N,sum=0;
    scanf("%d",&N);
        for(int i=1;i<=N;i++)
            sum+=i;
    printf("%d\n",sum);
    
}
```
##[11720번[숫자의 합]](https://www.acmicpc.net/problem/11720)
> 문제 : N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
```c
#include <stdio.h>
#include <stdlib.h>
int main(){
	char input;
	int result=0;
	int N,buf;
	scanf("%d\n",&N);
	for (int i = 0; i < N; ++i)
	{
		// input=getchar();
		// result+=atoi(&input);
			result+=(getc(stdin))-48;
	}
	//이렇게 해도 똑같은데 그럼 N을 쓸일이 없고 아무래도 atoi함수를 써서 틀린거 같음 노이해
	// while((input=getchar())!=10){
	// 	result+=atoi(&input);
	// }
	printf("%d\n",result );
}
```
>풀이 : 키보드로 부터 입력 받은 수(decimal)를 result에 계속 더함


##[11721번[열개씩 끊어서 출력하기]](https://www.acmicpc.net/problem/11720)
> 문제 : 알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다. 
> 한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.

```c
#include <stdio.h>
#include <string.h>
int main(){
	int N;
	char buf[1001];
	fgets(buf,sizeof(buf),stdin);
	for (int i = 1; i < strlen(buf); ++i)
	{
		printf("%c",buf[i-1] );
		
		if(i%10==0)
			printf("\n");
	}
}
```
>풀이 : fgets으로 한줄을 입력 받고 buf에서 10글자씩 출력 해준후 개행(\n).

##[15552번[열개씩 끊어서 출력하기]](https://www.acmicpc.net/problem/15552)
>문제 : 각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.(입력 A,B는 1000이하 케이스 T는 최대 1,000,000이다.)

```c
#include <stdio.h>

int main(){
	int N;
	int a,b;
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
}
```

[모든 내용은 Git Hub에도 있습니다.](https://github.com/ehdwn1991/Codex/tree/master/backjoon/Level_3)