
#include <stdio.h>

typedef struct dice{
    /*
     base clock wise
    n e s w u d
    1 2 3 4 5 6
    1(Down) 2(West) 3(North) 4(South) 5(East) 6(Up)
    020 
    313
    050
    060
    */
    // int direct[6]={0,};
    int HV; // default =0 H 1 vertical 2
    int position;

}Dice;

int horizontalRoll[4]={1,4,6,3};  //Roll East(Left Shift), Roll West(Right Shift)
int verticalRoll[4]={1,2,6,5};   //Roll Notrh(Right Shift), Roll South(Left Shift)
int xDirection[4]={0,0,-1,1}; 
int yDirection[4]={1,-1,0,0}; 

int rollingDice[7]={0,};
int nMap[21][21]={0,};
int command[1001]={0,};
int N,M,X,Y,K;
int diceBottom;
Dice diceinfo;
int findBottomPosition(){
    int i,pos;
    if(diceinfo.HV==1){
        for (i = 0; i < 4; i++)
        {
           if(horizontalRoll[i]==diceinfo.position){
               pos=i;
           }
        }
    } else{
        for (i = 0; i < 4; i++)
        {
           if(verticalRoll[i]==diceinfo.position){
               pos=i;
           }
        }
    }
    return pos;
}
int isValidRolling(int path){
    // rolling direction  East 1, West 2, North 3, South 4
    // printf("X[%d], X+d[%d]  Y[%d]   Y+d[%d]\n",X,X+xDirection[path-1],Y,Y+yDirection[path-1]);
    if(X+xDirection[path-1]>=0 && X+xDirection[path-1]<N &&Y+yDirection[path-1]>=0 && Y+yDirection[path-1]<M){
        return 1;
    }
    return 0;

}

void southRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[0]];
   
     for(i=3;i>0;i--){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i+1]];
    }
    rollingDice[verticalRoll[3]]=tmp;
   
   tmp=findBottomPosition();
   diceinfo.position = tmp  < 1 ? verticalRoll[3] : verticalRoll[--tmp];

printf("tmp [%d] pos[%d] verticalRoll[%d]\n",tmp,diceinfo.position,verticalRoll[tmp]);


}



void northRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[verticalRoll[3]];
    for(i=0;i<3;i++){
        rollingDice[verticalRoll[i]]=rollingDice[verticalRoll[i-1]];
    }
    rollingDice[verticalRoll[0]]=tmp;
    // if(nMap[X][Y]!=0){
    //     rollingDice[verticalRoll[1]]=nMap[X][Y];
    //     nMap[X][Y]=0;
    // }else
    // {
    //    nMap[X][Y]= rollingDice[diceBottom];
    // }
    // printf("%d\n",rollingDice[verticalRoll[3]]);
   tmp=findBottomPosition();
diceinfo.position = tmp > 2 ? verticalRoll[0] : verticalRoll[++tmp];



}
void eastRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[0]];
    for(i=3;i>0;i--){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i+1]];
    }
    rollingDice[horizontalRoll[3]]=tmp;
    // if(nMap[X][Y]!=0){
    //     rollingDice[horizontalRoll[3]]=nMap[X][Y];
    //     nMap[X][Y]=0;
    // }else
    // {
    //    nMap[X][Y]= rollingDice[diceBottom];
    // }
    
    // printf("%d\n",rollingDice[horizontalRoll[1]]);
       tmp=findBottomPosition();
diceinfo.position = tmp  < 1 ? horizontalRoll[3] : horizontalRoll[--tmp];


}

void westRolling( ){
    int i;
    int tmp;
    tmp = rollingDice[horizontalRoll[3]];
    
     for(i=0;i<3;i++){
        rollingDice[horizontalRoll[i]]=rollingDice[horizontalRoll[i-1]];
    }
    rollingDice[horizontalRoll[0]]=tmp;
    // if(nMap[X][Y]!=0){
    //     rollingDice[horizontalRoll[1]]=nMap[X][Y];
    //     nMap[X][Y]=0;
    // }else
    // {
    //    nMap[X][Y]= rollingDice[diceBottom];
    // }
    // printf("%d\n",rollingDice[horizontalRoll[3]]);
   tmp=findBottomPosition();

diceinfo.position = tmp > 2 ? horizontalRoll[0] : horizontalRoll[++tmp];
}




void showDice(){
    int i;
    // printf("X[%d] Y[%d]\n",X,Y);
    //     puts("Show Command");
    // for(i=0;i<K;i++){
    //     printf("%d ",command[i]);
    // }
    puts("");
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
    diceBottom=1;
    diceinfo.HV=0;
    diceinfo.position=1;
}


int sol(){
    int i=0;
    initDice();
    showDice();
    for(i=0;i<K;i++){
        //   printf("Codex asdasd %d\n",command[i]);
            printf("Command[%d]:%d\n",i,command[i]);
        if(isValidRolling(command[i])){
            switch(command[i]){
    case 1 :  //East
                Y++;
                diceinfo.HV=1;
                eastRolling();
        break;
    case 2 :  //West
                Y--;
                diceinfo.HV=1;
                westRolling();
        break;
    case 3 :  //North
                X--;
                diceinfo.HV=2;
                northRolling();
        break;

    case 4 :  //South
                X++;
                diceinfo.HV=2;
                southRolling();
        break;  
}
        printf("dicepositions : %d \n",diceinfo.position);
    if(nMap[X][Y]!=0){
        rollingDice[diceinfo.position]=nMap[X][Y];
        nMap[X][Y]=0;
    }else
    {
       nMap[X][Y]= rollingDice[diceinfo.position];
    }
    // printf("%d\n",rollingDice[7-diceinfo.position]);

        showDice();
            // printf("X[%d] Y[%d]\n",X,Y);

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
    sol();
    

}