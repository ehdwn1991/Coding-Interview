입력 버퍼 비우기
---
```c
void clear(){
	while(getchar()!=10);
	//10(enter)가 나올때 까지 입력 버퍼를 비워준다
}
```
>linux 계열은 fflush를 지원해주지 않는다. 때문에 현재 stdin으로 들어온 버퍼를 비워주는 동작을 하는 함수를 만들어 줘야 한다.