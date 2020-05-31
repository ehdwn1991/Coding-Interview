#include <stdio.h>
#include <stdlib.h>
int N,K;
int chessColorMap[11][11]={0,};
int MapLayer_0[11][11]={0,};
int MapLayer_1[11][11]={0,};
int MapLayer_2[11][11]={0,};
int MapLayer_3[11][11]={0,};

typedef struct chessMan{
    int row,col,dir,layer;
    int countStack; //def 0
    struct chessMan *next;

}CHESSMAN;


CHESSMAN *infoChessMens[11]={0,};




void moveWithStack(int nthChessman, int forwardRow, int forwardCol){
    int i=infoChessMens[nthChessman]->countStack;
    if (i)
    {
        for ( i; i < 4; i++)
        {
            if()
            infoChessMens[i]->row=forwardRow;
            infoChessMens[i]->col=forwardCol;


        }
        
    }
    

}


void execBlueBoard(){

}
void execRedBoard(){

}
void execWhiteBoard(int nthChessman,int forwardRow,int forwardCol){
    infoChessMens[nthChessman]->row=forwardRow;
    infoChessMens[nthChessman]->col=forwardCol;


}


int forwardBoardColor(int manRow,int manCol,int forwardRow,int forwardCol){

    switch (chessColorMap[forwardRow][forwardCol]){
        case 0:  // White

        break;
        
        case 1: // Red

        break;
        
        case 2:  //Blues

        break;

    }

}

void moveChessMen(int numOfChessMan){



}

int gameIsEnd(){
    int isEnd;

    return isEnd;
}

void showMapLayer_1(){
    int i,j;
    for ( i = 1; i <= N; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            printf("%d ",MapLayer_1[i][j]);
        }
        printf("\n");
        
    }
    
}

void showInfoChessMens(){
    int i;

for ( i = 1; i <= K; i++)
{
    printf("[%d][%d]: d[%d] count[%d]\n",infoChessMens[i]->row,infoChessMens[i]->col,infoChessMens[i]->dir,infoChessMens[i]->countStack);
}
}

int sol(){
    int timesOfTurn=0;
    int i;
    while (!gameIsEnd())
    {
        for ( i = 0; i < K; i++)
        {
            /* code */
            moveChessMen(i);
        }
        
        timesOfTurn++;
    }
    return timesOfTurn;
}






int main(){
    int i,j,k;

scanf("%d %d",&N,&K);

for ( i = 1; i <= N; i++)
{
    for ( j = 1; j <= N; j++)
    {
        scanf("%d",&chessColorMap[i][j]);
    }
}

for ( k = 1; k <= K; k++)
{
    infoChessMens[k]=(CHESSMAN*)malloc(sizeof(CHESSMAN));
    scanf("%d %d %d",&(infoChessMens[k]->row),&(infoChessMens[k]->col),&(infoChessMens[k]->dir));
    infoChessMens[k]->countStack=1;
    infoChessMens[k]->next=NULL;
    MapLayer_1[infoChessMens[k]->row][infoChessMens[k]->col]=k;
}

showInfoChessMens();




}