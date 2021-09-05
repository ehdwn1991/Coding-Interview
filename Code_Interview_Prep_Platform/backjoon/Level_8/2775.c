// 평소 반상회에 참석하는 것을 좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어 
// 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.
// 이 아파트에 거주를 하려면 조건이 있는데,
// “a 층의 b 호에 살려면 자신의 아래(a-1)층에 1호부터 b 호까지 사람들의 수의 합만큼 
// 사람들을 데려와 살아야한다” 는 계약 조항을 꼭 지키고 들어와야 한다.

// 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정 했을 때
// 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있나를 출력하라. 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층에 i호에는 i명이 산다.
// 입력 : 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다. (1 <= k <= 14, 1 <= n <= 14)
// 1호 부터 있음 (14층 14호)
// floor 0 => 1호 =1, 2호=2, 3호=3
// 0:1 2 3 4 5 6...
// 1:1 3 6 10 ...
// 2:1 4 10 16...
// 3:1 5 15 25...
// 4:1 6 21 45
// i floor k number





#include <stdio.h>
int many_people();
int main(){
	int home[15][15]={0,};
	int N=0,floor=0,number=0;

	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&floor);
		scanf("%d",&number);
		printf("%d\n",many_people(home,floor,number));
		// printf("%d %d \n",floor,number );
	}



}

int many_people(int (*arr1)[15],int floor,int number){
	int temp=0;
	int people_in=0;
	// printf("arr: %d\n",*(*(arr1+0)+1));
	for(int i=0;i<floor;i++){
		(*(*(arr1+i)+0))=1;
		for(int j=0;j<number;j++){
	// printf("erroe\n");
			// printf("j:%d\n",j );
			if(i==0){
				(*(*(arr1+i)+j))=((j+1)*(j+2))/2;
	// printf("arr[%d][%d]: %d\n",i,j,*(*(arr1+i)+j));
			}
			if(j!=0&&i!=0){
				(*(*(arr1+i)+j))=(*(*(arr1+i-1)+j))+(*(*(arr1+i)+j-1));
			}

		}
	}
	return (*(*(arr1+floor-1)+number-1));

}