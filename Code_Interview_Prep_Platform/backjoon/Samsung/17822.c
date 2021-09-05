#include <stdio.h>
#include <string.h>

int M, N, T;

int circleDisk[51][51] = {
    0,
};
int compCircleDisk[51][51] = {
    0,
};

int calAvg()
{
    // 평균 계산 할떄에 정수 형으로 계산시 틀림으로 처리
    // 떄문에 반드시 avg는 double 형으로
    double avg = 0, sumNum = 0;
    int cnt = 0;
    int i, j, row;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (circleDisk[i][j])
            {
                sumNum += circleDisk[i][j];
                cnt++;
            }
        }
    }

    if (cnt != 0)
    {
        
        avg = sumNum / cnt;
        for (i = 0; i < N; i++)
        {
            {
                for (j = 0; j < M; j++)
                {
                    if (circleDisk[i][j])
                    {
                        if (circleDisk[i][j] > avg)
                        {
                            circleDisk[i][j] -= 1;
                        }
                        else if(circleDisk[i][j] < avg)
                        {
                            circleDisk[i][j] += 1;
                        }
                    }
                }
            }
        }
        return 1;
    }else{
        return 0;
    }
}

int deleteAction(int row)
{
    int i, j, tempLeft, tempRight, isdeleteExecute = 0, execAction = 0, avg = 0;

    for (i = 0; i < M; i++)
    {

        isdeleteExecute = 0;
        if (circleDisk[row][i] && circleDisk[row][i] == circleDisk[row][tempLeft = i - 1 >= 0 ? i - 1 : M - 1])
        {
            compCircleDisk[row][tempLeft] = 1;
            isdeleteExecute = 1;
        }
        if (circleDisk[row][i] && circleDisk[row][i] == circleDisk[row][tempRight = i + 1 < M ? i + 1 : 0])
        {
            compCircleDisk[row][tempRight] = 1;

            isdeleteExecute = 1;
        }
        if (circleDisk[row][i] && (row + 1 < M && circleDisk[row][i] == circleDisk[row + 1][i]))
        {
            compCircleDisk[row + 1][i] = 1;

            isdeleteExecute = 1;
        }
        if (circleDisk[row][i] && (!(row - 1 < 0) && circleDisk[row][i] == circleDisk[row - 1][i]))
        {
            compCircleDisk[row - 1][i] = 1;

            isdeleteExecute = 1;
        }

        if (isdeleteExecute)
        {
            compCircleDisk[row][i] = 1;

            execAction = 1;
        }
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
        circleDisk[row][i] = temp[i];
    }
}

int selectZeroPos(int row, int direction, int nTimes)
{
    int i, temp;
    temp = nTimes % M;
    if (!direction)
    {
        return M - temp;
    }
    else
    {
        return temp;
    }
}

void sol(int x, int d, int k)
{
    int i = 0, j, retval = 0;
    memset(compCircleDisk, 0, sizeof(compCircleDisk));

    for (i = 0; i < N; i++)
    {
        // x:row, d:direction 0==clockwise 1==counterwise k:nTimes
        if (((i + 1) % x) == 0)
        {
            rotation(i, selectZeroPos(i, d, k));
        }
    }

    for (i = 0; i < N; i++)
    {
        retval += deleteAction(i);
    }
    if (!retval)
    {

        calAvg();
    }
    else
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (compCircleDisk[i][j])
                {
                    circleDisk[i][j] = 0;
                }
            }
        }
    }
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

    for (solTimes = 0; solTimes < T; solTimes++)
    {
        scanf("%d %d %d", &x, &d, &k);

        {
            sol(x, d, k);
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            circleSumation += circleDisk[i][j];
        }
    }
    printf("%d\n", circleSumation);
}