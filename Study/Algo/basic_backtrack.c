#include <stdio.h>
#include <stdlib.h>
 
int queens(int);
int promising(int);
int n;
int col[255]={0,};
 
 
int main() {
 
    printf("Max Board N? ");
    scanf("%d", &n);
    queens(0);

}
 
void printResult() {
    int i,j=0;
    printf("\nSol : \n");
    for(i = 1; i<=n; i++)
        printf("<%d,%d> ",i, col[i]);

    while(j<n){
    for(i=1;i<=n;i++){
        printf()
    }
 
}
 

int queens(int i) {
    int j;

    if(promising(i)) {
        if(i == n){  //base Step
            printResult();
            return 0;
        }
        else{

            for(j = 1; j <= n; j++) {
                col[i+1] = j;
                // printf("<%d,%d> \n into %d",i+1,col[i+1],i+1);
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
            // printf("Not Valid col [%d] \n",col[i]);

        }
        else{
        // printf("Valid col [%d] \n",col[i]);

        }
        k++;
    }
    return promising;
}

