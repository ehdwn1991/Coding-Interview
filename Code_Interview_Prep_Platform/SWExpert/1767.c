// 1767. [SW Test 샘플문제] 프로세서 연결하기
// int arr[7][7]={
	// 	{0, 0, 1, 0, 0, 0, 0},
	// 	{0, 0, 1, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 1, 0},
	// 	{0, 0, 0, 0, 0, 0, 0},
	// 	{1, 1, 0, 1, 0, 0, 0},
	// 	{0, 1, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0}};
		// printf("%d\n",pick(arr,7));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pick_chip();
int main(){
	int Tc=0,N=0;
	int input=0;
	int temp;
	scanf("%d",&Tc);

	for (int i = 1; i <= Tc; ++i)
	{
		scanf("%d",&N);

		int **board=(int**)malloc(sizeof(int*)*N);

		for (int j = 0; j < N; ++j)
		{	
			board[j]=(int*)malloc(sizeof(int)*N);
			for (int k = 0; k < N; ++k)
			{	
				scanf("%d",&board[j][k]);
			}
		}
		pick_chip(board,N);
	}



}

void pick_chip(int **board,int size){
	// 0:None   2: path   1: chip
	//path 우선 순위 대각행렬 제외, boundary 제외
	//boundary와 중심, 대각을 제외한 부분부터 검색
	int centorid = size/2;
	int **draw_chip_map=(int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i)
	{
		draw_chip_map[i]=(int*)malloc(sizeof(int)*size);
		memcpy(draw_chip_map[i],board[i],sizeof(int*)*size);
	}

	
	// for (int i = 0; i < size; ++i)
	// {
	// 	for (int j = 0; j < size; ++j)
	// 	{
	// 		printf("%d ",draw_chip_map[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n========================\n");
	//검색시에 달팽이 배열 사용
// while(){

// }

}
