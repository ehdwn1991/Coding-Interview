
#include <stdio.h>



int horizontalRoll[4]={1,2,6,5};  //Roll East(Left Shift), Roll West(Right Shift)
int verticalRoll[4]={1,3,6,4};   //Roll Notrh(Right Shift), Roll South(Left Shift)
int xDirection[4]={0,0,-1,1}; 
int yDirection[4]={1,-1,0,0};
int rollingDice[7]={0,};
int nMap[21][21]={0,};
int command[1001]={0,};
int N,M,X,Y,K;
    // dice[1]='D';
    // dice[2]='W';
    // dice[3]='N';
    // dice[4]='S';
    // dice[5]='E';
    // dice[6]='U';
char seq[7]={'X','D','W','N','S','E','U'};

int isValidRolling(int path){
    if(X+xDirection[path-1]>=0 && X+xDirection[path-1]<N &&Y+yDirection[path-1]>=0 && Y+yDirection[path-1]<M){
        return 1;
    }
    return 0;

}

void southRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[0]];
   
     for(i=0;i<3;i++){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i+1]];
    }
    rollingDice[verticalRoll[3]]=tmp;
   


}



void northRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[3]];
    for(i=3;i>=1;i--){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i-1]];
    }
    rollingDice[verticalRoll[0]]=tmp;
}
void eastRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[0]];
    for(i=0;i<3;i++){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i+1]];
    }
    rollingDice[horizontalRoll[3]]=tmp;


}

void westRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[3]];
    
      for(i=3;i>=1;i--){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i-1]];
    }
    rollingDice[horizontalRoll[0]]=tmp;

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
void showDice(){
    puts("DiceMap");

    for (size_t i = 1; i <= 6; i++)
    {
        printf("[%d]=%d (%c)\n",i,rollingDice[i],seq[i]);
    }
    puts("");
}

int sol(){
    int i=0;
    initDice();
    for(i=0;i<K;i++){
        if(isValidRolling(command[i])){
            switch(command[i]){
    case 1 :  //East
                Y++;
                eastRolling();
        break;
    case 2 :  //West
                Y--;
                westRolling();
        break;
    case 3 :  //North
                X--;
                northRolling();
        break;

    case 4 :  //South
                X++;
                southRolling();
        break;  
}
    if(nMap[X][Y]!=0){
        rollingDice[1]=nMap[X][Y];
        nMap[X][Y]=0;
    }else
    {
       nMap[X][Y]= rollingDice[1];
    }
    printf("%d\n",rollingDice[6]);
// showDice();

        }
    }





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
    sol();
    

}