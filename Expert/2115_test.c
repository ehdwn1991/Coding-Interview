#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)
#define SQUARE(a) ((a)*(a))
int beeHive[11][11] = {
    0,
};
int weightHive[11][31] = {
    0,
};
int vHive[11] = {
    0,
};
void showWeight();
void showMap();
int N, M, C;
int maxWeight = 0;

/* 
123

12 r,c+1
123 r,c+1 r,c+2
13 r,c+2

4 2 13
6 1 9 7
6,1
1,9
9,7

 */

int weightDfs(int row, int col, int cnt, int sumOfHoney, int sumOfSquare)
{
    int retval=0,a=0;
    if (cnt == M)
    {
        return 0;
    }



    // retval=weightHive[row][col];
    // printf("weightHive[%d][%d]:%d\n",row,col,retval);
    // if(retval!=-1){
        // return retval;
    // }
    printf("pos[%d][%d] cnt[%d] beeHive[%d] sumOfHoney[%d] sumOfSquare[%d]\n",row,col,cnt,beeHive[row][col],sumOfHoney,sumOfSquare);
    if (sumOfHoney+beeHive[row][col]<=C){
        retval=weightDfs(row,col+1,cnt+1, sumOfHoney+beeHive[row][col],sumOfSquare+SQUARE(beeHive[row][col]))+SQUARE(beeHive[row][col]);
    }


    a=weightDfs(row,col+1,cnt+1,sumOfHoney,sumOfSquare);
    printf("Comp retval[%d] weightDfs[%d]\n",retval,a);
    retval=MAX(retval,a);
    printf("weightHive[%d][%d]:%d\n",row,col,retval);

    return weightHive[row][col]=retval;
}


void buildWeight()
{
    int row, col;
    int retval;
    for (row = 0; row < N; row++)
    {   retval=0;
        for (col = 0; col <= N - M; col++)
        {
            printf("buildWeight %d %d\n",row,col);
            retval=MAX(retval,weightDfs(row, col,0,0,0));
        }
        printf("Row[%d] Maxnum:%d\n",row,retval);
    }
    showWeight();
}

int sol()
{

    memset(weightHive, -1, sizeof(weightHive));

    buildWeight();

    maxWeight = 0;
    return 1;
}
void showWeight()
{
    int r, c;
    for (r = 0; r < N; r++)
    {
        for (c = 0; c <= N - M; c++)
        {
            printf("%d ", weightHive[r][c]);
        }
        printf("\n");
    }
    printf("\n###############\n");
}
void showMap()
{
    int r, c;
    printf("N:%d  M:%d  C:%d\n", N, M, C);
    for (r = 0; r < N; r++)
    {
        for (c = 0; c < N; c++)
        {
            printf("%d ", beeHive[r][c]);
        }
        printf("\n");
    }
    printf("\n###############\n");
}
int main()
{
    int TC, i, r, c;
    scanf("%d", &TC);
    for (i = 1; i <= TC; i++)
    {

        memset(beeHive, 0, sizeof(beeHive));
        scanf("%d %d %d", &N, &M, &C);
        for (r = 0; r < N; r++)
        {
            for (c = 0; c < N; c++)
            {
                scanf("%d", &beeHive[r][c]);
            }
        }
        showMap();
        printf("#%d %d", i, sol());
    }
}