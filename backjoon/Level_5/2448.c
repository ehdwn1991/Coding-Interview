#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int N;
    // printf("!!!!!");
    // int a[3072][6143]={0,};
    scanf("%d",&N);
    int **row=(int**)malloc(sizeof(int*)*N),a[8][8];
    for (int i = 0; i < N; ++i)
    {
       row[i]=(int*)malloc(sizeof(int)*((2*N)-1));
       memset(row[i],0,sizeof(int)*((2*N)-1));
   }
    // a[0][N-1]=a[1][N-2]=a[1][N]=a[2][N-3]=a[2][N-2]=a[2][N-1]=a[2][N]=a[2][N+1]=1;
    //1은 별 그리고 0은 공백

   row[0][N-1]=row[1][N-2]=row[1][N]=row[2][N-3]=row[2][N-2]=row[2][N-1]=row[2][N]=row[2][N+1]=1;

    // row[0][N-1]=1;
    // row[1][N-2]=1;
    // printf("%d   %d \n",row[0][N-1],row[1][N-2] );
   for (int i = 0; i <N ; ++i)
   {

    for (int j = 0; j <=(N-1+i) ; ++j)
    {
        if(i>2){
            row[i][j]=((j>2&&row[i-3][j-3])^row[i-3][j+3]);
        }
    }

}

for (int q = 0; q < N; ++q)
{
    for (int w = 0; w < 2*N-1; ++w)
    {
            // printf("%d ",row[q][w] );
        if(row[q][w]==1)
            printf("*");
        else
            printf(" ");
    }
    puts("");
}

free(row);

}