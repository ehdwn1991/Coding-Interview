#include <stdio.h>
#include <stdlib.h>
 
int queens(int);
int promising(int);
int n;
int col[255]={0,};
int numofSol=0;
 
int main() {
    scanf("%d", &n);
    queens(0);
    printf("%d\n",numofSol);
}
 

int queens(int i) {
    int j;
    if(promising(i)) {
        if(i == n){  //base Step
            numofSol++;
            return 0;
        }
        else{
            for(j = 1; j <= n; j++) {
                col[i+1] = j;
                queens(i+1);
            }
            
        }
            return 1;
    }
    return 0;
}
 
int promising(int i) { 
    int k = 1, promising = 1;
    while(k < i && promising) {
        if(col[i] == col[k] || abs(col[i]-col[k]) == abs(i-k)){
            promising = 0; 
        }
        k++;
    }
    return promising;
}

