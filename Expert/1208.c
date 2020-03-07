#include <stdio.h>

int dirtMap[101][101]={0,};

int lowDirt,highDirt=0,numOfBox=0;

int sol(){

}

void showMap(){
    int i,j;
    for ( i = 0; i < numOfBox; i++)
    {
        for ( j = 0; j < numOfBox; j++)
        {
            printf("%d ",dirtMap[i][j]);
        }
        
        printf("\n");
    }
    
}

int main(){
    int moveDirt,input;
    int row=0;
    scanf("%d",&moveDirt);
while((scanf("%d",&input))!=EOF){
    if(input>highDirt){
        highDirt=input;
    }
        dirtMap[row++][input]=1;
        numOfBox++;
}
showMap();

}