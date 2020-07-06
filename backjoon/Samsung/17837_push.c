#include <stdio.h>
#include <stdlib.h>
int N, K;
int chessColorMap[15][15] = {{0},};



int dirHorizontal[5] = {0, 1, -1, 0, 0};
int dirVertical[5] = {0, 0, 0, -1, 1};
typedef struct chessMan
{
    int row, col, dir;
    int numbering;
    struct chessMan *next;
} CHESSMAN;

CHESSMAN *infoChessMens[12];
CHESSMAN *chessMenMap[15][15];
CHESSMAN *extractMens(CHESSMAN *headPoint, CHESSMAN *point);
void additionMens(void *headPoint, CHESSMAN *point);
CHESSMAN *reverseList();
void execWhiteBoard(int nthChessman, int forwardRow, int forwardCol);
void execRedBoard(int nthChessman, int forwardRow, int forwardCol);
void execBlueBoard(int nthChessman, int forwardRow, int forwardCol);
void simpleMove(int nthChessman, int forwardRow, int forwardCol)
{
    chessMenMap[forwardRow][forwardCol] = infoChessMens[nthChessman];
}

int inlineCheck(int forwardRow, int forwardCol)
{

    if ((forwardRow >= 1 && forwardRow <= N) && (forwardCol >= 1 && forwardCol <= N))
    {
        return 1;
    }
    return 0;
}
void changeListElement(int nthChessman, int forwardRow, int forwardCol)
{
    CHESSMAN *head = infoChessMens[nthChessman];
    while (head != NULL)
    {
        head->row = forwardRow;
        head->col = forwardCol;
        head = head->next;
    }
}

void execBlueBoard(int nthChessman, int forwardRow, int forwardCol)
{
    int tempDir = infoChessMens[nthChessman]->dir;
    int forwardColor;
    infoChessMens[nthChessman]->dir = (tempDir % 2 == 0 ? tempDir - 1 : tempDir + 1);
    forwardColor = chessColorMap[infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir]][infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir]];
    forwardRow = infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir];
    forwardCol = infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir];
    if (forwardColor < 2 && inlineCheck(forwardRow, forwardCol))
    {
        if (forwardColor == 0)
        {
            execWhiteBoard(nthChessman, forwardRow, forwardCol);
        }
        else
        {

            execRedBoard(nthChessman, forwardRow, forwardCol);
        }

    }
}

void execRedBoard(int nthChessman, int forwardRow, int forwardCol)
{
    CHESSMAN *temp;

    if (nthChessmanLoc(nthChessman) == 1)
    {
        temp = reverseList(infoChessMens[nthChessman]);
        chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col] = NULL;

    }
    else
    {

        temp = extractMens(chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col], infoChessMens[nthChessman]);
        temp=reverseList(temp);
    }
    changeListElement(temp->numbering, forwardRow, forwardCol);

    if(chessMenMap[forwardRow][forwardCol]!=NULL){
    additionMens(&chessMenMap[forwardRow][forwardCol], temp);

    }else{
        chessMenMap[forwardRow][forwardCol]=temp;
    }
}

void execWhiteBoard(int nthChessman, int forwardRow, int forwardCol)
{
    CHESSMAN *temp;
    if (nthChessmanLoc(nthChessman) == 1)
    {
        if (chessMenMap[forwardRow][forwardCol]!=NULL)
        {
            additionMens(&chessMenMap[forwardRow][forwardCol], infoChessMens[nthChessman]);
        }
        else
        {
            simpleMove(nthChessman, forwardRow, forwardCol);
        }
        chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col] = NULL;
    }
    else
    {
        temp = extractMens(chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col], &infoChessMens[nthChessman]);
        if (chessMenMap[forwardRow][forwardCol]!=NULL)
        {
            additionMens(&chessMenMap[forwardRow][forwardCol], temp);
        }
        else
        {
            chessMenMap[forwardRow][forwardCol] = temp;
        }
    }
    changeListElement(nthChessman, forwardRow, forwardCol);
}

int forwardBoardColor(int nthChessman,int forwardRow, int forwardCol)
{
    if (inlineCheck(forwardRow, forwardCol))
    {
        switch (chessColorMap[forwardRow][forwardCol])
        {
        case 0: // White
            execWhiteBoard(nthChessman, forwardRow, forwardCol);
            break;

        case 1: // Red
            execRedBoard(nthChessman, forwardRow, forwardCol);
            break;

        case 2: //Blue
            execBlueBoard(nthChessman, forwardRow, forwardCol);
            break;
        }
    }
    else
    {
        execBlueBoard(nthChessman, forwardRow, forwardCol);
    }
    return 0;
}

void moveChessMen(int nthChessman)
{
    int forwardHorizontal, forwardVertical;
    forwardVertical = infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir];
    forwardHorizontal = infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir];
    forwardBoardColor(nthChessman,forwardVertical, forwardHorizontal);
}



int gameIsEnd()
{
    int isEnd;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (chessMenMap[i][j])
            {
                isEnd = nChessMesList(chessMenMap[i][j]);
                if (isEnd >3)
                {
                    return isEnd;
                }
                else
                {
                    isEnd = 0;
                }
            }
        }
    }

    return isEnd;
}


int nChessMesList(CHESSMAN *headMen)
{
    int stackCount = 0;
    CHESSMAN *head;
    head = headMen;
    while (head != NULL)
    {
        stackCount++;
        head = head->next;
    }
    return stackCount;
}

int sol()
{
    int timesOfTurn = 0;
    int i;
    while (!gameIsEnd())
    {
        if (timesOfTurn >= 1000)
        {
            timesOfTurn = -1;
            break;
        }
        for (i = 1; i <= K; i++)
        {
            moveChessMen(i);
        }
        timesOfTurn++;
    }

    return timesOfTurn;
}

int nthChessmanLoc(int nthChessman)
{
    CHESSMAN *head;
    int i = 1;
    head = chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col];
    while (head != NULL)
    {
        if (head->numbering == infoChessMens[nthChessman]->numbering)
        {
            return i;
        }
        head = head->next;
        i++;
    }
    return 0;
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

void additionMens(void *headPoint, CHESSMAN *point)
{
    CHESSMAN *p;
    p = *((CHESSMAN **)headPoint);
    
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            p->next = point;
            break;
        }
        p = p->next;
    }

}

CHESSMAN *extractMens(CHESSMAN *headPoint, CHESSMAN *point)
{
    CHESSMAN *p,*r;
    // p = *((CHESSMAN **)headPoint);
    p = headPoint;

    while (p != NULL)
    {
        if (p->numbering == point->numbering)
        {
            printf("point->num[%d]\n",point->numbering);
            r->next = NULL;
            break;
        }
        r = p;
        p = p->next;
    }
    return p;
}

void freeAllResource(){
int i;
for(i=1;i<=K;i++){
    free(infoChessMens[i]);
}
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

    for (k = 1; k <= K; k++)
    {
        infoChessMens[k] = (CHESSMAN *)malloc(sizeof(CHESSMAN));
        scanf("%d %d %d", &(infoChessMens[k]->row), &(infoChessMens[k]->col), &(infoChessMens[k]->dir));
        infoChessMens[k]->next = NULL;
        infoChessMens[k]->numbering = k;
        chessMenMap[infoChessMens[k]->row][infoChessMens[k]->col] = infoChessMens[k];

    }

    printf("%d\n",sol());
    freeAllResource();
    return 0;
}