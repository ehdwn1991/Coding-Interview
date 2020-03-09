#include <stdio.h>

int beeHive[11][11] = {
    0,
};
int weightHive[11][10] = {
    0,
};
int vHive[11] = {
    0,
};
void showWeight();
void showH();
int N, M, C;
int maxWeight=0;

void weightDfs(int row, int col,int cnt){
    int i;
for ( i = col; i < N; i++)
{
    if(vHive[col]==1) continue;
    vHive[col]=1;
    weightDfs(row,col+1,cnt++);
    vHive[col]=0;
}


}

void checkWeight(int row,int col){
    int validWeight=0;
    int temp=0,i;
    for (i = 0; i < M; i++)
    {
        validWeight+=beeHive[row][col+i];
        // if(validWeight<=C){
            temp=beeHive[row][col+i];
            weightHive[row][col]+=(temp*temp);
        // }
    }
    if(weightHive[row][col]>maxWeight){
        maxWeight=weightHive[row][col];
    }


}
void buildWeight(){
    int row,col;
    for ( row = 0; row < N; row++)
    {
        for ( col = 0; col <= N-M; col++)
        {
            checkWeight(row,col);
        }
        
    }
    showWeight();
    
}


int sol(){
    buildWeight();



maxWeight=0;
return 1;
}
void showWeight(){
    int r,c;
     for (r = 0; r < N; r++)
        {
            for (c = 0; c <= N-M; c++)
            {
                printf("%d ",weightHive[r][c]);
            }
            printf("\n");
        }
    printf("\n###############\n");

}
void showMap(){
    int r,c;
    printf("N:%d  M:%d  C:%d\n",N,M,C);
     for (r = 0; r < N; r++)
        {
            for (c = 0; c < N; c++)
            {
                printf("%d ",beeHive[r][c]);
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

        memset(beeHive,0,sizeof(beeHive));
        memset(weightHive,0,sizeof(weightHive));
        scanf("%d %d %d", &N, &M, &C);
        for (r = 0; r < N; r++)
        {
            for (c = 0; c < N; c++)
            {
                scanf("%d",&beeHive[r][c]);
            }
        }
        showMap();
        printf("#%d %d",i,sol());
        

    }
}