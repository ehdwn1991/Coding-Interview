#include <stdio.h>

int cal();
int main(){
	int TC=0;
	int test_set[20][2]={0,}; //test_set[0][0]=> numeber of set , [0][1]=> max calory
	scanf("%d",&TC);
	for (int i = 0; i < TC; ++i)
	{
		scanf("%d %d",&test_set[0][0],&test_set[0][1]);
		for (int j = 1; j <= test_set[0][0]; ++j)
		{
			scanf("%d %d",&test_set[j][0],&test_set[j][1]);
		}
		cal(test_set,test_set[0][0]);

	}

}

int cal(int (*set)[2],int run_set){
	// 가중치 정렬 => 점수 /칼로리 
// 1
// 5 1000
// 100 200 => 0.5
// 300 500 => 0.6
// 250 300 => 0.8
// 500 1000 => 0.5
// 400 400 => 1





	// for (int i = 0; i < 20; ++i)
	// {
		// printf("%d %d\n",set[i][0],set[i][1] );
	// }

	return 0;
}