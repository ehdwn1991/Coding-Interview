
#include <stdio.h>

typedef struct dice{
    /*
    bottom base clock wise
    n e s w u d
    1 2 3 4 5 6
    1(Down) 2(West) 3(North) 4(South) 5(East) 6(Up)
    030 
    215
    040
    060
    */
    // int direct[6]={0,};

}Dice;

int horizontalRoll[4]={1,2,6,5};  //Roll East(Left Shift), Roll West(Right Shift)
int verticalRoll[4]={1,3,6,4};   //Roll Notrh(Right Shift), Roll South(Left Shift)
int xDirection[4]={1,-1,0,0}; //Right Left
int yDirection[4]={0,0,1,-1}; // Up Down

int rollingDice[7]={0,};
int nMap[21][21]={0,};
int command[1001]={0,};
int N,M,X,Y,K;

int isValidRolling(int path){
    // rolling direction  East 1, West 2, North 3, South 4

    if(X+xDirection[path-1]>0 && X+xDirection[path-1]<M &&Y+yDirection[path-1]>0 && Y+yDirection[path-1]<N){
        return 1;
    }
    return 0;

}

void southRolling(int bottom){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[0]];
    for(i=0;i<3;i++){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i+1]];
    }
    rollingDice[verticalRoll[3]]=tmp;
    printf("%d\n",rollingDice[verticalRoll[1]]);

}

void northRolling(){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[3]];
    for(i=3;i>0;i--){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i-1]];
    }
    rollingDice[verticalRoll[0]]=tmp;
    printf("%d\n",rollingDice[verticalRoll[3]]);
}

void eastRolling(){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[0]];
    for(i=0;i<3;i++){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i+1]];
    }
    rollingDice[horizontalRoll[3]]=tmp;
    printf("%d\n",rollingDice[horizontalRoll[1]]);
}

void westRolling(){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[3]];
    for(i=3;i>0;i--){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i-1]];
    }
    rollingDice[horizontalRoll[0]]=tmp;
    printf("%d\n",rollingDice[horizontalRoll[3]]);
}




void showDice(){
    int i;
    for(i=1;i<=6;i++){
        printf("[%d]%d\n",i,rollingDice[i]);
    }
}
void showMap(){
    int i=0,j=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%d ",nMap[i][j]);
        }
        puts("");
    }
    puts("Show Command");
    for(i=0;i<K;i++){
        printf("%d ",command[i]);
    }
    puts("");
}
void initDice(){
    // dice[1]='D';
    // dice[2]='W';
    // dice[3]='N';
    // dice[4]='S';
    // dice[5]='E';
    // dice[6]='U';
    int i=0;
    for(i=0;i<7;i++){
        rollingDice[i]=0;
    }
}


int sol(){
    int i=0;
    initDice();
    showDice();
    for(i=0;i<K;i++){
        if(isValidRolling(command[i])){

        }
    }


    // printf("Rolling East\n\n");
    // eastRolling();
    // showDice();
    // printf("Rolling West\n\n");
    // westRolling();
    // showDice();
    // printf("Rolling North \n\n");
    // northRolling();
    // showDice();
    // printf("Rolling South\n\n");
    // southRolling();
    // showDice();


}
int main(){
    int row=0,col=0;
    int i;
    scanf("%d %d %d %d %d",&N,&M,&X,&Y,&K);
    while((scanf("%d",&nMap[row][col++]))!=EOF){
        if(col==M){
            col=0;
            row++;
        }
        if(row==N){
            break;
        }
    }

    for(i=0;i<K;i++){
        scanf("%d",&command[i]);
    }
    showMap();
    

}