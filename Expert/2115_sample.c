#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)
#define SQUARE(a) ((a)*(a))
int beeHive[11][11] = {
    0,
};
int weightHive[11][11] = {
    0,
};
int vHive[11][11] = {
    0,
};
void showWeight();
void showMap();
int N, M, C;
int maxWeight = 0;

/* 
4 2 13
6 1 9 7
9 8 5 8
3 4 5 3
8 2 6 7


37 82 81
81 89 89
25 41 34
68 40 85
sol=174(89+85)
 */

int findAppropriateHoneyBox(int row, int col, int cnt,int expectedValue){
    int retval=0,nowVal=0;

    if(row>N|| col >N){
        return 0;
    }
    if(cnt==1){
        printf("End row[%d] col[%d]  old[%d]+plus[%d]=[%d]\n",row,col,expectedValue,weightHive[row][col],expectedValue+weightHive[row][col]);
        return expectedValue+(weightHive[row][col]!=-1?weightHive[row][col]:0);
    }

    if(weightHive[row][col]!=-1){
        nowVal=weightHive[row][col];
    }
    printf("Next [%d][%d] cnt[%d], Now val[%d], expval[%d]\n",row,col,cnt,nowVal,expectedValue);

    if(col+M<=N-M+1){
        printf("In [%d][%d], Now val[%d]\n",row,col+M,expectedValue+nowVal);
        retval=findAppropriateHoneyBox(row,col+M,cnt+1,expectedValue+nowVal);
        // expectedValue-=weightHive[row][col+M];
        printf("Out retval[%d] expval[%d]\n",retval,expectedValue);

    }
        printf("Increase Row\n");
        retval=MAX(findAppropriateHoneyBox(row+1,0,0,0),retval);
        // retval=findAppropriateHoneyBox(row+1,0,cnt,expectedValue);
    

    return maxWeight=MAX(retval,maxWeight);
}

// int findAppropriateHoneyBox(int row,int col, int cnt, int expectedVal){
//     int nowVal=0,retval=0,compval;

//     if (row>N||col>N)
//     {
//         return 0;
//     }
    
//     if(cnt==2){
//         return expectedVal+(weightHive[row][col]!=-1?weightHive[row][col]:0);
//     }

//     if(weightHive[row][col]!=-1){
//         nowVal=weightHive[row][col];
//     }


//     // same row , col++
//     if(col+M<=N-M+1){
//         retval=findAppropriateHoneyBox(row,col+M,cnt+1,expectedVal+nowVal);
//     }

//    //row++ , reset col
//         compval=findAppropriateHoneyBox(row+1,0,cnt+1,expectedVal+nowVal);
    

// return MAX(retval,compval);

// }


int weightDfs(int row, int col, int cnt, int sumOfHoney, int sumOfSquare)
{
    int retval=0,compval=0;
    if (cnt == M)
    {
        return 0;
    }



    // retval=weightHive[row][col];
    // printf("weightHive[%d][%d]:%d\n",row,col,retval);
    // if(retval!=-1){
    //     return retval;
    // }
    // printf("pos[%d][%d] cnt[%d] beeHive[%d] sumOfHoney[%d] sumOfSquare[%d]\n",row,col,cnt,beeHive[row][col],sumOfHoney,sumOfSquare);
    if (sumOfHoney+beeHive[row][col]<=C){
        retval=weightDfs(row,col+1,cnt+1, sumOfHoney+beeHive[row][col],sumOfSquare+SQUARE(beeHive[row][col]))+SQUARE(beeHive[row][col]);
    }


    compval=weightDfs(row,col+1,cnt+1,sumOfHoney,sumOfSquare);
    // printf("Comp retval[%d] weightDfs[%d]\n",retval,compval);
    retval=MAX(retval,compval);
    // printf("weightHive[%d][%d]:%d\n",row,col,retval);

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
            // printf("buildWeight %d %d\n",row,col);
            retval=MAX(retval,weightDfs(row, col,0,0,0));
        }
        // printf("Row[%d] Maxnum:%d\n",row,retval);
    }

    // for ( row = 0; row < N; row++)
    // {
    //     for ( col = 0; col <= N-M; col++)
    // {
    //     retval=MAX(findAppropriateHoneyBox(row,col,0,0),retval);
    // }

    // }
    
    printf("Sol:[%d]\n",findAppropriateHoneyBox(0,0,0,0));
    showWeight();
}

int sol()
{

    memset(weightHive, -1, sizeof(weightHive));
    maxWeight = 0;

    buildWeight();

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