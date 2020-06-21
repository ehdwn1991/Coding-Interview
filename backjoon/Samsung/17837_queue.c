#include <stdio.h>
#include <stdlib.h>
int N, K;
int chessColorMap[11][11] = {
    0,
};

int *chessMenMap[11][11] = {
    0,
};
//→, ←, ↑, ↓
int dirHorizontal[5] = {0, 1, -1, 0, 0};
int dirVertical[5] = {0, 0, 0, -1, 1};
typedef struct chessMan
{
    int row, col, dir;
    int countStack, numbering; //def 1
    struct chessMan *next;
} CHESSMAN;

CHESSMAN *infoChessMens[11] = {
    0,
};
CHESSMAN *mensQu[4] = {
    0,
};
CHESSMAN *extractMens(void *headPoint, CHESSMAN *point);
void additionMens(void *headPoint, CHESSMAN *point);
CHESSMAN *reverseList();
void execWhiteBoard(int nthChessman, int forwardRow, int forwardCol);
void execRedBoard(int nthChessman, int forwardRow, int forwardCol);
void execBlueBoard(int nthChessman, int forwardRow, int forwardCol);
void showChessMenMap();
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
        printf("change [%d]th [%d][%d]: d[%d] count[%d]\n", head->numbering, head->row, head->col, head->dir, head->countStack);
        head = head->next;
    }
    // infoChessMens[nthChessman]->row = forwardRow;
    // infoChessMens[nthChessman]->col = forwardCol;
}

void execBlueBoard(int nthChessman, int forwardRow, int forwardCol)
{
    int tempDir = infoChessMens[nthChessman]->dir;
    int forwardColor;
    infoChessMens[nthChessman]->dir = (tempDir % 2 == 0 ? tempDir - 1 : tempDir + 1);
    forwardColor = chessColorMap[infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir]][infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir]];
   printf("forwardcolor[%d] row[%d]col[%d]\n",forwardColor,infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir],infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir]);
    forwardRow = infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir];
    forwardCol = infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir];
    // forward map BLUE, don't move
    if (forwardColor < 2 && inlineCheck(forwardRow, forwardCol))
    {
        if (forwardColor == 0)
        {
            printf("White\n");
            execWhiteBoard(nthChessman, forwardRow, forwardCol);
        }
        else
        {
            printf("Red\n");

            execRedBoard(nthChessman, forwardRow, forwardCol);
        }

    }
}

void execRedBoard(int nthChessman, int forwardRow, int forwardCol)
{
    CHESSMAN *temp;


    // When The Chessman is Head of list
    if (nthChessmanLoc(nthChessman) == 1)
    {
        printf("Red Head\n");
        printf("before infoChessMens [%d] [%d][%d]\n",infoChessMens[nthChessman]->numbering,infoChessMens[nthChessman]->row,infoChessMens[nthChessman]->col);
        temp = reverseList(infoChessMens[nthChessman]);
        printf("after infoChessMens [%d] [%d][%d]\n",infoChessMens[nthChessman]->numbering,infoChessMens[nthChessman]->row,infoChessMens[nthChessman]->col);
        printf("after temp [%d] [%d][%d]\n",temp->numbering,temp->row,temp->col);
    chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col] = 0;

    }
    else
    {
        printf("Red Not Head\n");

        temp = extractMens(&chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col], infoChessMens[nthChessman]);
        temp=reverseList(temp);
    }
    printf("reverse [%d] %d,%d\n",temp->numbering,temp->row,temp->col);
    changeListElement(temp->numbering, forwardRow, forwardCol);

    if(chessMenMap[forwardRow][forwardCol]){
    additionMens(&chessMenMap[forwardRow][forwardCol], temp);

    }else{
        chessMenMap[forwardRow][forwardCol]=temp;
    }
}

void execWhiteBoard(int nthChessman, int forwardRow, int forwardCol)
{
    CHESSMAN *temp;
    // nth is head
    // printf("White stack %d\n",nthChessmanLoc(nthChessman));
    if (nthChessmanLoc(nthChessman) == 1)
    {
        if (chessMenMap[forwardRow][forwardCol])
        {
            printf("Stack addtion\n");
            additionMens(&chessMenMap[forwardRow][forwardCol], infoChessMens[nthChessman]);
        }
        else
        {
            printf("simple white\n");

            simpleMove(nthChessman, forwardRow, forwardCol);
        }
        chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col] = 0;
    }
    else
    {
        temp = extractMens(&chessMenMap[forwardRow][forwardCol], infoChessMens[nthChessman]);
        if (chessMenMap[forwardRow][forwardCol])
        {
            additionMens(&chessMenMap[forwardRow][forwardCol], temp);
        }
        else
        {
            simpleMove(nthChessman, forwardRow, forwardCol);
            // chessMenMap[forwardRow][forwardCol] = temp;
        }
    }
    nChessMesList(&chessMenMap[forwardRow][forwardCol]);
    changeListElement(nthChessman, forwardRow, forwardCol);
}

int forwardBoardColor(int nthChessman, int manRow, int manCol, int forwardRow, int forwardCol)
{
    CHESSMAN *temp;
    if (inlineCheck(forwardRow, forwardCol))
    {
        switch (chessColorMap[forwardRow][forwardCol])
        {
        case 0: // White
            printf("White\n");
            execWhiteBoard(nthChessman, forwardRow, forwardCol);
            break;

        case 1: // Red
            printf("Red\n");
            execRedBoard(nthChessman, forwardRow, forwardCol);
            break;

        case 2: //Blue
            printf("Blue\n");
            execBlueBoard(nthChessman, forwardRow, forwardCol);
            break;
        }
    }
    else
    {
        printf("Line End Blue\n");
        execBlueBoard(nthChessman, forwardRow, forwardCol);
    }
    return 0;
}

void moveChessMen(int nthChessman)
{

    int forwardHorizontal, forwardVertical;
    forwardVertical = infoChessMens[nthChessman]->row + dirVertical[infoChessMens[nthChessman]->dir];
    forwardHorizontal = infoChessMens[nthChessman]->col + dirHorizontal[infoChessMens[nthChessman]->dir];
    printf("move [%d][%d]\n", forwardVertical, forwardHorizontal);
    forwardBoardColor(nthChessman, infoChessMens[nthChessman]->row, infoChessMens[nthChessman]->col, forwardVertical, forwardHorizontal);
    showChessMenMap();
}

int chessmanHasStack(CHESSMAN *point)
{

    if (point->countStack)
    {
        return 1;
    }
    return 0;
}

int gameIsEnd()
{
    int isEnd;
    int i, j;
    CHESSMAN *temp;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (chessMenMap[i][j])
            {
                isEnd = nChessMesList(((CHESSMAN *)chessMenMap[i][j]));
                // printf("isEnd [%d] [%d][%d]\n",isEnd,i,j);
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

void showChessMenMap()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        printf("[%d] ",i);
        for (j = 1; j <= N; j++)
        {
            if((CHESSMAN *)chessMenMap[i][j]){
            printf("%3d ", ((CHESSMAN *)chessMenMap[i][j])->numbering);   
            }
            else
            {
                printf("%3d ",chessMenMap[i][j]);
            }
            
        }
        printf("\n");
    }
}

void showInfoChessMens()
{
       int i, j;
    for (i = 1; i <= N; i++)
    {
        printf("[%d] ",i);
        for (j = 1; j <= N; j++)
        {
            if((CHESSMAN *)chessMenMap[i][j]){
            }
            
        }
        printf("\n");
    }

}

int nChessMesList(CHESSMAN *headMen)
{
    int stackCount = 0;
    CHESSMAN *head;
    head = headMen;
    while (head != NULL)
    {
        stackCount++;
        printf("[%d][%d]: number[%d] d[%d] count[%d]\n", head->row, head->col, head->numbering, head->dir, head->countStack);
        head = head->next;
    }
    return stackCount;
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
            printf("[%d]th [%d][%d]: d[%d] count[%d]\n", head->numbering, head->row, head->col, head->dir, head->countStack);

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
        if (timesOfTurn >= 1000)
        {
            timesOfTurn = -1;
            break;
        }
        for (i = 1; i <= K; i++)
        {
            moveChessMen(i);
        }
        printf("[%d]times==========>\n",timesOfTurn);
        // showListChessMens();
        timesOfTurn++;
    }

    return timesOfTurn;
}

int nthChessmanLoc(int nthChessman)
{
    // 0==chessMenMap[][] is empty,1== first ,1> not first(stack entry)
    CHESSMAN *p, *q, *r, *head;
    int i = 1;
    head = chessMenMap[infoChessMens[nthChessman]->row][infoChessMens[nthChessman]->col];
    while (head != NULL)
    {
        if (head->numbering == infoChessMens[nthChessman]->numbering)
        {
            printf("[%d][%d]: number[%d] d[%d] count[%d]\n", head->row, head->col, head->numbering, head->dir, head->countStack);
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
    // printf("reverse [%d] %d,%d\n",q->numbering,q->row,q->col);
    nChessMesList(q);
    printf("Reverse End\n");
    return q;
}

void additionMens(void *headPoint, CHESSMAN *point)
{
    CHESSMAN *p, *q, *r;
    p = *((CHESSMAN **)headPoint);
    
    // printf("head %d\n",*p);
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            printf("addition [%d][%d] [%d]\n",p->row,p->col,p->numbering);
            p->next = point;
            // nChessMesList(p);
            break;
        }
        printf("addtion while %d\n",p->numbering);
        p = p->next;
    }
    printf("addtion end\n");

}

// headpoint : chessmen address, point : want to extract Chessman
CHESSMAN *extractMens(void *headPoint, CHESSMAN *point)
{
    CHESSMAN *p, *q, *r;
    // printf("!!!!!!!!!\n [%p]\n[%p]!!!!!!!!\n",headPoint,((CHESSMAN *)headPoint));
    p = *((CHESSMAN **)headPoint);
    q = NULL;
    //point is list of head

    //point is not list of head
    while (p != NULL)
    {
        if (p->numbering == point->numbering)
        {
            r->next = NULL;
            break;
        }
        r = p;
        p = p->next;
    }
    return p; //return we want specific point
}
void addtionAfterextract()
{
    CHESSMAN *temp;
    printf("1\n");
    infoChessMens[1]->next = infoChessMens[2];
    //  showListChessMens();
    printf("2\n");
    infoChessMens[2]->next = infoChessMens[3];
    //  showListChessMens();
    printf("3\n");
    infoChessMens[3]->next = infoChessMens[4];

    infoChessMens[3]->row = 2;
    infoChessMens[3]->col = 1;
    // infoChessMens[2]->row = 2;
    // infoChessMens[2]->col = 1;
    infoChessMens[4]->row = 2;
    infoChessMens[4]->col = 1;
    // printf("[2][1]\n");
    // nChessMesList(((CHESSMAN *)chessMenMap[2][1]));

    // chessMenMap[1][1] = extractMens(&chessMenMap[2][1], infoChessMens[3]);
    // printf("extract to [1][1]\n");
    // nChessMesList(((CHESSMAN *)chessMenMap[1][1]));
    // printf("extract to [2][1]\n");
    // nChessMesList(((CHESSMAN *)chessMenMap[2][1]));
    // // nChessMesList(infoChessMens[3]);
    // // reverse
    // Not Head
    printf("Extract\n");
    chessMenMap[2][1]=infoChessMens[1];
    // temp=extractMens(&chessMenMap[infoChessMens[3]->row][infoChessMens[3]->col],infoChessMens[3]);
   temp = extractMens(&chessMenMap[2][1], infoChessMens[3]);
    
    temp=reverseList(temp);
    printf("After Reverse [%d]\n",temp->numbering);
    changeListElement(temp->numbering,4,4);
    nChessMesList(temp);

 temp=reverseList(temp);
    printf("After Reverse [%d]\n",temp->numbering);
    changeListElement(temp->numbering,2,3);
    nChessMesList(temp);
    // printf("Addtion to [2][1] from [1][1]");
    // // addtion test
    // additionMens(&chessMenMap[2][1], infoChessMens[3]);
    // printf("############\n");
    // nChessMesList(infoChessMens[1]);
}

int main()
{
    int i, j, k;
    CHESSMAN *temp;
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
        if (k == 0)
        {
            infoChessMens[k]->numbering = 0;
            infoChessMens[k]->next = NULL;
            continue;
        }
        scanf("%d %d %d", &(infoChessMens[k]->row), &(infoChessMens[k]->col), &(infoChessMens[k]->dir));
        infoChessMens[k]->countStack = 1;
        infoChessMens[k]->next = NULL;
        infoChessMens[k]->numbering = k;
        chessMenMap[infoChessMens[k]->row][infoChessMens[k]->col] = infoChessMens[k];

    }
    // addtionAfterextract();
    // showListChessMens();
    printf("%d\n",sol());
    // showListChessMens();
    // printf("Before ##########\n");
    // for (i = 1; i < K; i++)
    // {
    //     printf("[%d]th\n",i);
    //     moveChessMen(i);
    // }
    // showListChessMens();

    // printf("Addtion After extract\n");
    // addtionAfterextract();

    //  showListChessMens();
    // nChessMesList(infoChessMens[1]);
    // printf("#######\n");
    // infoChessMens[3]->next = reverseList(infoChessMens[3]->next);
    // temp = reverseList(infoChessMens[3]);
    // nChessMesList(temp);
    // //  showListChessMens();
    // nChessMesList(infoChessMens[1]);
    // CHESSMAN *qwe;
    // qwe = chessMenMap[4][1];
    // printf("[%d][%d][%d]\n", ((CHESSMAN *)chessMenMap[4][1])->col, qwe->row, qwe->col);
    // qwe->col = 12;
    // printf("[%d]\n", infoChessMens[4]->col);

    // printf("``````\n [%p][%p][%p]\n````````\n", chessMenMap[2][1], &chessMenMap[2][1], infoChessMens[1]);

    // nChessMesList(infoChessMens[3]);
    // printf("@@@@@\n");
    // printf("%d %d\n", ((CHESSMAN *)chessMenMap[1][1])->row, ((CHESSMAN *)chessMenMap[1][1])->col);
    // printf("@@@@@\n");
    // chessMenMap[1][1] = infoChessMens[0];

    // Show at chessmap
    // nChessMesList(((CHESSMAN *)chessMenMap[1][1]));
    // moveChessMen(1);

    // moveChessMen(2);
    // moveChessMen(3);

    // moveChessMen(4);
    // printf("nth[%d]\n", nthChessmanLoc(2));
}