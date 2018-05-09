//다른 사람풀이를 보니 진짜 수학 문제처럼 규칙을 찾아 잘 푼것 같다.
// 처음 시작한 방법으로 끝을 보자 해서 이렇게 됬는데 내가 코딩한건 항상 변수가 많다
// 알고리즘은 속도 그래프에서 감을 얻었다.
// y=ax^2+b 의 식에서 분명 시작 부터 속도를 올렸다가 점차 감소하면서 속도가 1이 될떄 도착해야 하는것.
// x까지의 자연수의 합<=이동한거리/2 이 성립이 될때의 x를 찾는것이 중요
// 예를들어보자
// 이동 거리가 7이라면 7/2=3이다.그럼 3전 까지의 자연수의 합은 즉 2까지의 자연수의합
// 1+2 이다. 그럼 나머지 4의 이동거리를 구해야하는데 어차피 도착 할때는 속력이 1이다.
// 그럼 1+2+@+2+1 이런식일 것이다. 그럼 나머지 모자라는 수는 1이다.
// 12211 이렇게된다.
// 1. x까지의 자연수의 합<=총거리/2 이 되는 x를 찾고
// 2. 필요한 길이 
//
// . 현재의 거리가 총거리랑 같아 질때 까지 필요한 수를 찾아 더해주면됨.
#include <stdio.h>
int facto();
int main(){
	int sum_of_natural=0;

	int N=0;
	int start=0,end=0,total_distance=0;
	int now_distance=0;
	int need_distance=0;
	int Nth_natural_num=0;
	int count=0;
	scanf("%d",&N);


	while(N--){

	scanf("%d %d",&start,&end);
	// while(getchar()!=10);
	total_distance=end-start;
	// printf("total_distance :%d \n",total_distance);
	for(int i=0;sum_of_natural<=total_distance/2;i++){
		sum_of_natural+=i+1;
		// if(sum_of_natural>=total_distance/2){

			Nth_natural_num=i;
			// printf("hit%d\n",Nth_natural_num );
			// break;
		// }
	// printf("%d %d\n\n",i,sum_of_natural);
	}
	// printf("%d %d\n\n",Nth_natural_num,sum_of_natural);
	sum_of_natural=0;
	now_distance=facto(Nth_natural_num)*2; //현재 Nth_natural_num번째 까지 거리를 더함 
	need_distance=total_distance-now_distance;
	printf("path: ");
	while(now_distance!=total_distance){
		// printf("now :%d need :%d \n",now_distance,need_distance );
		if(need_distance>Nth_natural_num){
			printf("%d ",Nth_natural_num+1);
			now_distance+=Nth_natural_num+1;
			need_distance-=Nth_natural_num+1;
			count++;
		}
		else{
			printf("%d ",need_distance);
			now_distance+=need_distance;
			count++;
		}


	}
	// printf("Nth_natural_num: %d count: %d\n",Nth_natural_num,count);
	count+=Nth_natural_num*2;
	printf("%d\n",count );
	count=0;
}

}
int facto(int Num){
	if(Num<=1)
		return 1;
return Num+facto(Num-1);

}

void full_path(){


}

