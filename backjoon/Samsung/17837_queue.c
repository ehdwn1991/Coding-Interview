#include <stdio.h>
#include <stdlib.h>
int N,K;
int chessColorMap[11][11]={0,};
int chessMenMap[11][11]={0,};

typedef struct chessMan{
    int row,col,dir;
    int countStack; //def 1
    struct chessMan *next;

}CHESSMAN;

CHESSMAN *infoChessMens[11]={0,};
CHESSMAN *mensQu[4]={0,};

void execBlueBoard(){

}
void execRedBoard(){

}
void execWhiteBoard(int nthChessman,int forwardRow,int forwardCol){

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

void showChessMenMap(){
    int i,j;
    for ( i = 1; i <= N; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            printf("%d ",chessMenMap[i][j]);
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


CHESSMAN *reverseList(CHESSMAN *point){
     CHESSMAN *p, *q, *r;
    p = point;
    q = NULL;
    while(p!=NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

return q;
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
    chessMenMap[infoChessMens[k]->row][infoChessMens[k]->col]=k;
}


}