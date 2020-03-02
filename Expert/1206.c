#include <stdio.h>
#include <string.h>

int APT[1001][256] = {
    0,
};
int numOfAPT;
int sol();



int sol()
{
    int i, j;
    int totalView = 0;
    for (i = 2; i < numOfAPT - 2; i++)
    {

        for (j = 0; j < 255; j++)
        {
            if (APT[i][j] == 1)
            {
                if (!APT[i - 2][j] && !APT[i - 1][j] && !APT[i+1][j] && !APT[i+2][j]){
                    totalView++;
                }
            }
        }
    }
    return totalView;
}

int main()
{
    int i, j, height,ans,cnt=1;

    while ((scanf("%d", &numOfAPT)) != EOF)
    {
        for (i = 0; i < numOfAPT; i++)
        {
            scanf("%d", &height);

            for (j = 0; j < height; j++)
            {
                APT[i][j] = 1;
            }
        }
        if ((ans=sol())!=0){
        printf("#%d %d\n",cnt++, ans);

        }
        memset(APT,0,sizeof(APT));
    }
}