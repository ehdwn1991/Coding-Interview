#include <stdio.h>

/* 


generation          dicomposition
198+1+9+8  => 216



 */



int Sol(int N,int Max){


int tempN=N;
int dicompositNum=0;

if(N==Max){
return 0;
}

// while((tempN--)>0){
dicompositNum=(tempN+decomposeSumation(tempN));
// printf("N: %d dicompositNum: %d\n",tempN,dicompositNum);
if(dicompositNum==Max){
    // printf("%d",tempN);
    return tempN;
    // break;
}
Sol(N+1,Max);

// }


}

int decomposeSumation(int N){
    int tempN=N;
    int decomposeNum=0;
    int sumOfDecompose=0;
    while(tempN>0){

        decomposeNum= tempN%10;
        // printf("%d\n",decomposeNum);
        sumOfDecompose+=decomposeNum;
        tempN-=decomposeNum;
        tempN/=10;
    }

return sumOfDecompose;
}

int main(){
int N;

scanf("%d",&N);
printf("%d",Sol(0,N));

}
