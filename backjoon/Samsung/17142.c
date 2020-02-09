#include <stdio.h>
#include <string.h>


/*  
DFS

Queue has vertex location and next searching node info

*/

typedef struct queue{
    int x;
    int y;
}QUEUE;

int vMap[51][51]={0,};
QUEUE qu[51];
int rear=0;
int qIsEmpty(){
    if(){

    }
}

int qIsFull(){

}

int pushQ(){

}
int popQ(){

}

int main(){
    int N,M,i=0,j=0;
    int row=0,col=0;
    scanf("%d %d",&N,&M);
    while((scanf("%d",&vMap[row][col++]))!=EOF){
        if(col==N){
            col=0;
            row++;
        }
        qu[row].x=i++;
        qu[row].y=i+j++;
    }

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
printf("%d ",vMap[i][j]);
        }
        puts("");
    }



    for ( i = 0; i < 51; i++)
    {
        printf("x: %d y:%d",qu[i].x,qu[i].y);
        puts("");
    }


}