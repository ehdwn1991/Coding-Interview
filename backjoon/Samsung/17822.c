#include <stdio.h>
#define MAX 2501
void showMap();
void quClear();
int isEmpty();
int isFull();
void push();
int pop();

int M, N, T;
int front = -1;
int rear = -1;
int circleDisk[51][51] = {
    0,
};
typedef struct queue
{
    int x;
    int y;
    int data;
} Queue;

Queue qu[MAX] = {
    0,
};
/*
5/3 1.6 2>
12/5 2.4 2>
12/4 3 3>
기준 0
0 1 2 3 4 5
2번 회전
size 6
pick 4

1123
left pick
clock[pick 3th]: 3112

3112
right pick
counter[pick 1th] : 1123

2.4
2 x
*/

void quClear()
{
    while (!isEmpty())
    {
        pop();
    }
}

int isEmpty(void)
{
    if (front == rear)
        return 1;
    else
        return 0;
}
int isFull(void)
{
    int tmp = (rear + 1) % MAX;
    if (tmp == front)
        return 1;
    else
        return 0;
}

void push(int x, int y)
{
    if (isFull())
    {
    }
    else
    {
        qu[rear].x = x;
        qu[rear].y = y;
        rear = (rear + 1) % MAX;
    }
}

int pop()
{
    int test;
    Queue *tempQ = malloc(sizeof(Queue));
    if (!isEmpty())
    {
        tempQ = &qu[front];
        test = front;
        front = (front + 1) % MAX;
        return test;
    }
    return -1;
}

void calAvg()
{
    int avg = 0, sumNum = 0, cnt = 0;
    int i, j, row;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            /* code */
            // printf("circle[%d][%d]:%d\n",i,j,circleDisk[i][j]);
            if (circleDisk[i][j])
            {
                sumNum += circleDisk[i][j];
                cnt++;
            }
        }
    }
    // showMap();
    avg = sumNum / cnt;
    printf("SUM[%d] AVG[%d]\n", sumNum, avg);
    for (i = 0; i < M; i++)
    {
        if (sumNum % M)
        {
            for (j = 0; j < M; j++)
            {
                if (circleDisk[i][j])
                {
                    if (circleDisk[i][j] > avg)
                    {

                        circleDisk[i][j] -= 1;
                    }
                    else
                    {
                        circleDisk[i][j] += 1;
                    }
                }
            }
        }
        else
        {
            for (j = 0; j < M; j++)
            {
                if (circleDisk[i][j] && circleDisk[i][j] != avg)
                {
                    if (circleDisk[i][j] > avg)
                    {

                        circleDisk[i][j] -= 1;
                    }
                    else
                    {
                        circleDisk[i][j] += 1;
                    }
                }
            }
        }
    }
}
int deleteAction(int row)
{
    int i,j, tempLeft, tempRight, isdeleteExecute = 0, execAction = 0, avg = 0;

    for (i = 0; i < M; i++)
    {
        isdeleteExecute = 0;
        //same Circle
        if (circleDisk[row][i] && circleDisk[row][i] == circleDisk[row][tempLeft = i - 1 >= 0 ? i - 1 : M - 1])
        {
            // printf("[%d][%d] temp-1[%d]\n", row, i, temp);
            circleDisk[row][tempLeft] = 0;
            isdeleteExecute = 1;
        }
        if (circleDisk[row][i] && circleDisk[row][i] == circleDisk[row][tempRight = i + 1 < M ? i + 1 : 0])
        {
            // printf("[%d][%d] temp+1[%d]\n", row, i, temp);

            circleDisk[row][tempRight] = 0;

            isdeleteExecute = 1;
        }
        //same line in other adjoin circle
        if (circleDisk[row][i] && (row + 1 < M && circleDisk[row][i] == circleDisk[row + 1][i]))
        {
            // printf("[%d][%d] row+1\n", row, i);
            circleDisk[row + 1][i] = 0;
            isdeleteExecute = 1;
        }
        if (circleDisk[row][i] && (!(row - 1 < 0) && circleDisk[row][i] == circleDisk[row - 1][i]))
        {
            // printf("[%d][%d] row-1\n", row, i);

            circleDisk[row - 1][i] = 0;
            isdeleteExecute = 1;
        }

        if (isdeleteExecute)
        {
            circleDisk[row][i] = 0;
            execAction = 1;
        }
        // showMap();
    }
    return execAction;
}

void rotation(int row, int zeroPos)
{
    int temp[50] = {
        0,
    },
        i;
    int circleSize = M;
    printf("zeorpos : %d\n", zeroPos);
    for (i = 0; i < M; i++)
    {
        if (zeroPos + i >= circleSize)
        {
            temp[i] = circleDisk[row][zeroPos + i - circleSize];
        }
        else
        {
            temp[i] = circleDisk[row][zeroPos + i];
        }
    }

    for (i = 0; i < M; i++)
    {
        printf("temp[%d]:%d \t circle[%d]:[%d]\n", i, temp[i], i, circleDisk[row][i]);
        circleDisk[row][i] = temp[i];
    }
}

int selectZeroPos(int row, int direction, int nTimes)
{
    int i, temp;
    temp = nTimes % M;
    // direction 1== counterclockwise 0==counterwise
    printf("temp:%d M-1-temp:%d \n", temp, M - 1 - temp);
    if (!direction)
    {
        return M - temp;
    }
    else
    {
        return temp;
    }

    // 1234
    // 4123 3412 2341 1234
}

void showMap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", circleDisk[i][j]);
        }
        printf("\n");
    }
    printf("########\n");
}
void sol(int x, int d, int k)
{
    int i = 0, retval = 0;
    for (i = 0; i < N; i++)
    {
        // x:row, d:direction 0==clockwise 1==counterwise k:nTimes

        if (((i + 1) % x) == 0)
        {
            printf("Show x[%d] rotation[%d]\n", x, i);
            rotation(i, selectZeroPos(i, d, k));
            showMap();
        }
    }

    for (i = 0; i < M; i++)
    {
        retval += deleteAction(i);
    }
    if (!retval)
    {
        printf("RETVAL %d\n", retval);

        calAvg();
    }
    showMap();
}
int main()
{
    int x, d, k;
    int i = 0, j = 0, solTimes, circleSumation = 0;
    scanf("%d %d %d", &N, &M, &T);
    while ((scanf("%d", &circleDisk[i][j++])) != EOF)
    {
        if (i == N - 1 && j == M)
        {
            break;
        }
        if (j == M)
        {
            i++;
            j = 0;
        }
    }
    showMap();
    for (solTimes = 0; solTimes < T; solTimes++)
    {
        scanf("%d %d %d", &x, &d, &k);
        // printf("x:%d d:%d k:%d\n", x, d, k);
        sol(x, d, k);
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            circleSumation += circleDisk[i][j];
        }
    }
    printf("%d\n", circleSumation);
}