
#include <stdio.h>

#define MAX 2500
typedef struct queue
{
    int x;
    int y;
    int data;
} Queue;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Right  left Up Down

int peopleMap[50][50] = {
    0,
};
int vMap[50][50] = {
    0,
};
Queue qu[MAX] = {
    0,
};
int front = -1;
int rear = -1;
int N, L, R;
int numOfAlliance = 0;
int numOfPeople = 0;
int isFull();
int isEmpty();
int pop();
void push();
void testQ();
void quClear();
void showMap();

int checkInline(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        return 1;
    }
    return 0;
}

void findAlliance(int x, int y)
{
    int i, j;
    int gap;
    int nextX;
    int nextY;

    for (i = 0; i < 4; i++)
    {
        nextX = x + moveDir[i].x;
        nextY = y + moveDir[i].y;

        if (checkInline(nextX, nextY))
        {

            gap = abs(peopleMap[x][y] - peopleMap[nextX][nextY]);

            if (gap >= L && gap <= R && !vMap[nextX][nextY])
            {

                numOfPeople += peopleMap[nextX][nextY];
                numOfAlliance++;
                vMap[nextX][nextY] = 1;
                push(nextX, nextY);
                findAlliance(nextX, nextY);
            }

            gap = 0;
        }
    }
}

int sol()
{
    int quLefts = 0;
    int times = 0;
    int isEnd = 0;
    int i, j;
    int moveAtLeatOne = 0;
    int posQ;
    while (1)
    {
        memset(vMap, 0, sizeof(vMap));
        moveAtLeatOne = 0;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (vMap[i][j] != 1)
                {
                    vMap[i][j] = 1;
                    numOfAlliance = 1;
                    numOfPeople = peopleMap[i][j];

                    quClear();

                    push(i, j);
                    findAlliance(i, j);
                }
                else
                {
                    continue;
                }

                if (numOfAlliance > 1)
                {
                    moveAtLeatOne = 1;
                    while (!isEmpty())
                    {
                        posQ = pop();
                        peopleMap[qu[posQ].x][qu[posQ].y] = numOfPeople / numOfAlliance;
                    }
                }
                numOfAlliance = 0;
                numOfPeople = 0;
            }
        }
        if (moveAtLeatOne)
        {

            times++;
        }
        else
        {

            break;
        }
    }

    return times;
}

int main()
{
    int input;
    int row = 0, col = 0;
    scanf("%d %d %d", &N, &L, &R);

    while ((scanf("%d", &peopleMap[row][col++])) != EOF)
    {
        if (N == col)
        {
            col = 0;
            row++;
        }
        if (row == N)
        {
            break;
        }
    }

    printf("%d\n", sol());
}

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
