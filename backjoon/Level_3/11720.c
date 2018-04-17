#include <stdio.h>
#include <stdlib.h>
// void clear();
int main(){
	char input;
	int result=0;
	int N,buf;
	scanf("%d\n",&N);

	// clear();


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


//입력 버퍼 비우는 함수 엔터(10)까지 내용을 전부 비워줌
// void clear(){

// 	while(getchar()!=10);


// }