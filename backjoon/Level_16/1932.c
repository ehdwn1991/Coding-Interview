#include <stdio.h>

int triangleMap[501][501]={0,};

int sumationMap[501][501]={0,};

int N;
/* 
case : left end
solMap[r][c]=solMap[r-1][c-1]
case : rignt end
solMap[r][c]=solMap[r-1][c]
case: else
solMap[r][c] = solMap[r-1][c-1]+solMap[r-1][c+1]
 */
void clear(){
while(getchar()!=10);
}

int biggerThan=0;

int findMax(int a, int b){
    return a>=b?a:b;
}
int checkValid(int row,int col){
    if(row>=0&&col>=0&&row<501&&col<501){
        if(col==0){
        return sumationMap[row-1][col];
        }
        else if(row==col){
        return sumationMap[row-1][col-1];
        
        }
        else{
        return findMax(sumationMap[row-1][col],sumationMap[row-1][col-1]);

        }

    }
}

void findPath(){
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col <= row; col++) // L1 1,L2 2, L3 3...The number of nodes is equal Level
        {
            sumationMap[row][col]+=checkValid(row,col);
            if(biggerThan<sumationMap[row][col]){
                biggerThan=sumationMap[row][col];
            }
        }
        
    }
    
}

int main(){
    int row=0,col=0,cnt=0,tens=1;
    char c;
scanf("%d",&N);
clear();

while((c=getchar())!=EOF){
    if(cnt==N)
        break;
    if(c==10&& cnt<N){
        row++;
        col=0;
        cnt++;
    }
    if(c==32){
        col++;
    }
    if(c>=48&& c<=57){
        sumationMap[row][col]*=10;
        sumationMap[row][col]+=(c-48);

    }


}


findPath();
//For Debug
// for (size_t i = 0; i < N; i++)
// {
//     for (size_t j = 0; j <= i; j++)
//     {
//         printf("%d ",sumationMap[i][j]);
//     }
//     puts("");
// }

printf("%d",biggerThan);
}