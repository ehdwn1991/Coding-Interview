//파도반 수열을 간단 하다 처음 초기값 1 1 1 1 2 2를 잡아주고
//PD[N]=PD[N-1]+PD[N-5]로 구할수 있다 하지만 원래 있던 수열에 제일 앞에
//1을 추가한 배열로 시작 하면 되지만 맘에 안듬
//다른 방법 찾음
//삼각형 과 역삼각형 존재 삼각형과 역삼각형의 조합으로 다음 값을 구할수있음

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long vertical_plus();
long long diagonal_plus();
int main(){
	int N,count=0,test_case;
	int iterate_N; 	
	long long up_triangle[50]={0,};
	long long down_triangle[50]={0,};
	scanf("%d",&test_case);
	for(int i=0;i<test_case;i++){
	scanf("%d",&N);
	iterate_N=N;

	up_triangle[0]=down_triangle[0]=1;
	while(2<iterate_N){
	up_triangle[count+1]=diagonal_plus(up_triangle,down_triangle,count);
//	printf("up: %lld \n",up_triangle[count+1]);
	iterate_N--;
	down_triangle[count+1]=vertical_plus(up_triangle,down_triangle,count);
//	printf("down: %lld \n",down_triangle[count+1]);

	iterate_N--;
	count++;
	}
	count=0;
	
	
	if(N%2!=0)
	printf("%lld\n",up_triangle[(N/2)]);
	else
	printf("%lld\n",down_triangle[(N/2)-1]);

	}
}

long long vertical_plus(long long *up,long long *down,int count){
//	printf("in down func up[%d]:%lld down[%d]:%lld\n",
//count,*(up+count),count,*(down+count));
return *(up+count)+*(down+count);
	}

long long diagonal_plus(long long *up,long long *down,int count){
	if(count==0)
		return *(up+count); // [-1]의 주소를 참조하는것을 방지
//	printf("in up func up[%d]:%lld down[%d]:%lld\n",
//count,*(up+count),count,*(down+count-1));
return *(up+count)+*(down+count-1);


}



