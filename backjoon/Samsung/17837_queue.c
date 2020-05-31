#include <stdio.h>
#include <stdlib.h>
int N, K;
int chessColorMap[11][11] = {
    0,
};

int *chessMenMap[11][11] = {
    0,
};

typedef struct chessMan
{
    int row, col, dir;
    int countStack,numbering; //def 1
    struct chessMan *next;
} CHESSMAN;

CHESSMAN *infoChessMens[11] = {
    0,
};
CHESSMAN *mensQu[4] = {
    0,
};

void execBlueBoard()
{
}

void execRedBoard()
{
}

void execWhiteBoard(int nthChessman, int forwardRow, int forwardCol)
{
}

int forwardBoardColor(int manRow, int manCol, int forwardRow, int forwardCol)
{

    switch (chessColorMap[forwardRow][forwardCol])
    {
    case 0: // White

        break;

    case 1: // Red

        break;

    case 2: //Blues

        break;
    }
}

void moveChessMen(int numOfChessMan)
{
}

int gameIsEnd()
{
    int isEnd;

    return isEnd;
}

void showChessMenMap()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            printf("%d ", chessMenMap[i][j]);
        }
        printf("\n");
    }
}

void showInfoChessMens()
{
    int i;

    for (i = 1; i <= K; i++)
    {
        printf("[%d][%d]: d[%d] count[%d]\n", infoChessMens[i]->row, infoChessMens[i]->col, infoChessMens[i]->dir, infoChessMens[i]->countStack);
    }
}

void nChessMesList(CHESSMAN *headMen)
{

    CHESSMAN *head;
    head = headMen;
    while (head != NULL)
    {
        printf("[%d][%d]: number[%d] d[%d] count[%d]\n", head->row, head->col,head->numbering ,head->dir, head->countStack);
        head = head->next;
    }
}
void showListChessMens()
{
    int i;
    struct chessMan *head;
    struct chessMan *heated;

    for (i = 1; i <= K; i++)
    {
        head = infoChessMens[i];
        while (head != NULL)
        {
            printf("[%d][%d]: d[%d] count[%d]\n", head->row, head->col, head->dir, head->countStack);

            head = head->next;
        }
        printf("END\n");
    }
}
int sol()
{
    int timesOfTurn = 0;
    int i;
    while (!gameIsEnd())
    {
        for (i = 0; i < K; i++)
        {
            /* code */
            moveChessMen(i);
        }

        timesOfTurn++;
    }

    return timesOfTurn;
}

CHESSMAN *reverseList(CHESSMAN *point)
{
    CHESSMAN *p, *q, *r;
    p = point;
    q = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

// headpoint : chessmen address, point : want to extract Chessman
CHESSMAN *extractMens(void *headPoint,CHESSMAN *point)
{
    CHESSMAN *p, *q, *r;
    // printf("!!!!!!!!!\n [%p]\n[%p]!!!!!!!!\n",headPoint,((CHESSMAN *)headPoint));
    p = *((CHESSMAN **)headPoint);
    q = NULL;
    //point is list of head


    //point is not list of head
    while (p != NULL)
    {
        if (p == point)
        {
            r->next = NULL;
            break;
        }
        r = p;
        p = p->next;

    }
    return p; //return we want specific point
}

int main()
{
    int i, j, k;

    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &chessColorMap[i][j]);
        }
    }

    for (k = 0; k <= K; k++)
    {
        infoChessMens[k] = (CHESSMAN *)malloc(sizeof(CHESSMAN));
        if(k==0){
            infoChessMens[k]->numbering=0;
            infoChessMens[k]->next = NULL;
            continue;
        }
        scanf("%d %d %d", &(infoChessMens[k]->row), &(infoChessMens[k]->col), &(infoChessMens[k]->dir));
        infoChessMens[k]->countStack = 1;
        infoChessMens[k]->next = NULL;
        infoChessMens[k]->numbering=k;
        chessMenMap[infoChessMens[k]->row][infoChessMens[k]->col] = infoChessMens[k];
    }

    printf("1\n");
    infoChessMens[1]->next = infoChessMens[3];
    //  showListChessMens();
    printf("2\n");
    infoChessMens[4]->next = infoChessMens[2];
    //  showListChessMens();
    printf("3\n");
    infoChessMens[3]->next = infoChessMens[4];
    //  showListChessMens();
    nChessMesList(infoChessMens[1]);
    // printf("#######\n");
    // infoChessMens[3]->next = reverseList(infoChessMens[3]->next);
    // //  showListChessMens();
    // nChessMesList(infoChessMens[1]);
    // CHESSMAN *qwe;
    // qwe = chessMenMap[4][1];
    // printf("[%d][%d][%d]\n", ((CHESSMAN *)chessMenMap[4][1])->col, qwe->row, qwe->col);
    // qwe->col = 12;
    // printf("[%d]\n", infoChessMens[4]->col);

    printf("``````\n [%p][%p][%p]\n````````\n",chessMenMap[2][1],&chessMenMap[2][1],infoChessMens[1]);

   chessMenMap[1][1]= extractMens( &chessMenMap[2][1],infoChessMens[3]);
    nChessMesList(infoChessMens[1]);
    printf("@@@@@\n");

    nChessMesList(infoChessMens[3]);
    printf("@@@@@\n");
    printf("%d %d\n",((CHESSMAN *)chessMenMap[1][1])->row,((CHESSMAN *)chessMenMap[1][1])->col);
    printf("@@@@@\n");
    chessMenMap[1][1]=infoChessMens[0];    
    nChessMesList(((CHESSMAN *)chessMenMap[1][1]));

}