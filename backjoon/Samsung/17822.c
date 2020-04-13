#include <stdio.h>

int M, N, T;
int circleDisk[51][51] = {
    0,
};

/*
기준 0
0 1 2 3 4 5
2번 회전
기준 2


*/
void rotation(int turningNum,int row,int ){
    int temp[50]={0,},i;

    //clockwize
    for ( i = 0; i < M; i++)
    {
        if (i>=turningNum)
        {
            temp[i-turningNum]=circleDisk[row][i];
        }else{
            temp[M-turningNum-i]=circleDisk[row][i];
        }
        
    }
    // counter clock wise
    for ( i = 0; i < M; i++)
    {
        circleDisk[row][i]=temp[i];
    }
    

}

void showMap(){
    for (int i = 0; i < N; i++)
    {
for ( int j = 0; j < M; j++)
{
    printf("%d ",circleDisk[i][j]);
}
printf("\n");
    }
    
}
void sol(int x,int d,int k){
    rotation(2,2);
    showMap();
}
int main()
{
    int x, d, k;
    int i = 0, j = 0;
    scanf("%d %d %d", &N, &M, &T);
    while ((scanf("%d", &circleDisk[i][j++])) != EOF)
    {
        printf("%d\n",circleDisk[i][j]);
        if (i == N )
        {
            break;
        }
        if (j == M )
        {
            i++;
            j = 0;
        }
    }
    showMap();
    for (int ㅣ = 0; ㅣ < T; ㅣ++)
    {
    scanf("%d %d %d",&x,&d,&k);
    sol(x,d,k);
    }
    
}