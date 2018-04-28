/*
에라토스테네스의 체 알고리즘을 기준으로 찾는다.
2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다. 그림에서 회색 사각형으로 두른 수들이 여기에 해당한다.
2는 소수이므로 오른쪽에 2를 쓴다. (빨간색)
자기 자신을 제외한 2의 배수를 모두 지운다.
남아있는 수 가운데 3은 소수이므로 오른쪽에 3을 쓴다. (초록색)
자기 자신을 제외한 3의 배수를 모두 지운다.
남아있는 수 가운데 5는 소수이므로 오른쪽에 5를 쓴다. (파란색)
자기 자신을 제외한 5의 배수를 모두 지운다.
남아있는 수 가운데 7은 소수이므로 오른쪽에 7을 쓴다. (노란색)
자기 자신을 제외한 7의 배수를 모두 지운다.
위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	int N,count=1;
	scanf("%d",&N);

	char *arr=(char*)malloc(sizeof(char)*N);

	memset(arr,1,sizeof(char)*N);
	puts(arr);
	for (int i = 2;  (i*i)<= N; ++i) //루트 N까지만 체크
	{
		if(arr[i]==1){
			for (int j = i*i; j < N; j+=i)
			{
				arr[j]=0;//1 is prime 0 is not prime
			}
		}

	}

	for (int i = 2; i < N; ++i)
	{
		if(arr[i]==1){
			printf("%d ",i);
		if(count%10==0)
			puts("");
		count++;

		}

	}

		free(arr);



}