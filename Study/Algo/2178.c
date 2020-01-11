#include <stdio.h>

typedef struct solQueue
{
    int x;
    int y;
    int depth;
} Queue;

int N,M;
int **navimap;
int **visited;
int answer = 0; 
//directionRow : L U R D
int directionRow[4] = {  0, 1, 0, -1 };
//directionCol : D L U R
int directionCol[4] = { -1, 0, 1, 0  };
// Max N, M(2 ≤ N, M ≤ 100)
Queue Qu[100001];


void validPathCheck(int x,int y){


}

void findPath(){
     // 시작점
    visited[0][0] = 1;
    answer++;
 
}

int makeMap(int ** anonmap){
for (int i = 0; i < N; i++){
        anonmap[i] = (int*)malloc(sizeof(int)*M);
    }

}
int setMap(int **anonmap){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &anonmap[i][j]);
            visited[i][j] = 0;
        }
    }
}
int main()
{
    scanf("%d %d",&N,&M);
    navimap = (int **)malloc(sizeof(int *) * N);
    makeMap(navimap);
    visited = (int **)malloc(sizeof(int *) * N);
    makeMap(visited);

    setMap(navimap);
        printf("\n");
        printf("\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d",navimap[i][j]);
        }
        printf("\n");
    }
    
}