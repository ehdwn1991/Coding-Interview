#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
#define SQUARE(a) ((a) * (a))
int beeHive[11][11] = {
    0,
};
int weightHive[11][11] = {
    0,
};

int N, M, C;
int maxWeight = 0;

int combinationMaxExpected(int row, int col)
{

    int sol = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            if (i == row)
            {
                if (j >= col + M)
                    sol = MAX(sol, weightHive[i][j]);
            }
            else
            {
                    sol = MAX(sol, weightHive[i][j]);
            }
        }
    }

    return sol;
}

int weightDfs(int row, int col, int cnt, int sumOfHoney, int sumOfSquare)
{
    int retval = 0, a = 0;
    if (cnt == M)
    {
        return 0;
    }
    if (sumOfHoney + beeHive[row][col] <= C)
    {
        retval = weightDfs(row, col + 1, cnt + 1, sumOfHoney + beeHive[row][col], sumOfSquare + SQUARE(beeHive[row][col])) + SQUARE(beeHive[row][col]);
    }
    a = weightDfs(row, col + 1, cnt + 1, sumOfHoney, sumOfSquare);
    retval = MAX(retval, a);
    return weightHive[row][col] = retval;
}

void buildWeight()
{
    int row, col;
    int retval;
    for (row = 0; row < N; row++)
    {
        retval = 0;
        for (col = 0; col <= N - M; col++)
        {
            retval = MAX(retval, weightDfs(row, col, 0, 0, 0));
        }
    }
}

int sol()
{
    maxWeight = 0;
    memset(weightHive, 0, sizeof(weightHive));
    buildWeight();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            maxWeight = MAX(maxWeight, combinationMaxExpected(i, j) + weightHive[i][j]);
        }
    }
    return maxWeight;
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
        printf("#%d %d\n", i, sol());
    }
}