Level_1 
===

1178번[그대로 출력하기]
---
> 문제 : 입력 받은 대로 출력하는 프로그램을 작성하시오.

```c
#include <stdio.h>

int main(int argc,char **argv){
	char through_out;
	while((through_out=getchar())!=EOF){
		putchar(through_out);
	}	
}
```
> 풀이 : 여러가지 함수가 있지만 개행(\n)문자가 들어와도 입력이 끝나면 안된다.
>
> ​	때문에 getchar함수를 통해 개행(\n)문자 까지 출력하면 입력 그대로 출력 완료



11719번[그대로 출력하기2]
---
> 문제 : 입력 받은 대로 출력하는 프로그램을 작성하시오
> 단,알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다. 각 줄은 100글자를 넘지 않으며,
> 빈 줄이 주어질 수도 있고, 각 줄의 앞 뒤에 공백이 있을 수도 있다.

```c
#include <stdio.h>
int main(int argc,char **argv){
	char through_out;
	while((through_out=getchar())!=EOF){
		putchar(through_out);
	}	
}
```

> 풀이 : 위와 동일. 입력시 한 글자씩 입력을 받고 받은 그대로 출력하기 때문에 공백, 빈칸, 대 소 문자, 숫자 뭐든지 입력 그대로 출력 됨.



[모든 내용은 Git Hub에도 있습니다.](https://github.com/ehdwn1991/Codex/tree/master/backjoon)

