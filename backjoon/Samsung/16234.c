
#include <stdio.h>

int peopleMap[2501][2501]={0,};

int sol(){


}

int main(){
    int N,L,R,input;
    int row=0,col=0;
    scanf("%d %d %d",&N,&L,&R);

    while((scanf("%d",&peopleMap[row][col++]))!=EOF){
        if(N==col){
            col=0;
            row++;
        }
        if(row==N){
            break;
        }
    }

    while(sol)
}