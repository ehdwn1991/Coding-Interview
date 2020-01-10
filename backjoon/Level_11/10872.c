#include <stdio.h>


int factorialFunc(int N){
    if(N<2){
        return 1;
    }
    return factorialFunc(N-1)*N;
}
int main(){
    int N;
    scanf("%d",&N);
    printf("%d",factorialFunc(N));

}