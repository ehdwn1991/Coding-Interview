#include <stdio.h>
#include <string.h>
/*  
0 30 7
0 10 0
0  0 9


0 18 13(7+6)
0 16(10+6) 0
0  0 9

0 19(18+1) 11||(5||(7-(7/5)*2)+6)
0 16(10+6) 1
0  0 9

0 19(18+1) 11||(6+5(||7-(7/5)*2))
0 10||(6+4||(10-(10/5)*3)) 1
0  0 20

0 19(18+1) 11||(6+5(||7-(7/5)*2))
0 10||(6+4||(10-(10/5)*3)) 1
0  0 20


Ar,c (-1 ≤ Ar,c ≤ 1,000)
 */



int nowMap[2501][2501]={0,};
int sequenceMap[2501][2501]={0,};

int R=0,C=0;
// up down left right
int directionRow[4]={1,-1,0,0}; // up down
int directionCol[4]={0,0,-1,1}; // left right
int availableDirection[4]={0,};
int locCirculator[4]={0,};
int sol(int time){
    for (size_t i = 0; i < time; i++)
    {
        dustFlowAction();
        memset(nowMap,0,sizeof(nowMap));
        memcopy(nowMap,sequenceMap,sizeof(nowMap));
        memset(sequenceMap,0,sizeof(sequenceMap));
        airFlowAction();
    }
    
}

void horizonWind(int i, int j,int direction){
    int templ;
    
    while(){

    }

}

void verticalWind(){

}


void airCirculate(){

    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {

        }
        
    }
    


}


void airFlowAction(){
    int upRowTemp,downRowTemp;
       for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            if(nowMap[i][j]==-1){
                availableDirection[0]=i;
                availableDirection[1]=j;
                availableDirection[2]=i+1;
                availableDirection[3]=j;
                airCirculate();
                memset(availableDirection,-1,sizeof(availableDirection));
                i=i+1;
            }
        }
        
    }
    
}

void dustFlowAction(){

    memset(sequenceMap,-1,sizeof(sequenceMap));
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            spreadDust(i,j);
        }
        
    }
}

int canAirFlow(int i, int j, int d){ // d is direction  up down left right 0 1 2 3
    if((i+directionRow[d])>=0&& (i+directionRow[d])<= R &&j+directionCol[d]>=0&&j+directionCol[d]<=C){

    }else{

    }

}

void spreadDust(int i, int j){
   int spreadDustValue=0;
   int beforeDust=0;
   int afterDust=0;
   int spreadCnt=0;
   beforeDust=nowMap[i][j];
   spreadDustValue= beforeDust/5;
   spreadCnt=canDustSpread(i,j);
   afterDust=(beforeDust-(beforeDust/5)*spreadCnt);
for (size_t k = 0; k < 4; k++)
{
    if(availableDirection[k])
      sequenceMap[(i+directionRow[k])][(i+directionCol[k])]+=spreadDustValue;

}
    sequenceMap[i][j]+=afterDust;


    memset(availableDirection,0,sizeof(availableDirection));
}

int canDustSpread(int i,int j){
    int cnt;
    for (size_t d = 0; d < 4; d++)
    {
        if((i+directionRow[d])>=0&& (i+directionRow[d])<= R &&j+directionCol[d]>=0&&j+directionCol[d]<=C)
            if(nowMap[(i+directionRow[d])][j+directionCol[d]]>=0)// up down left right
                availableDirection[d]=1;
        cnt++; 
    }
    return cnt;
}   





int main(){
    int T; // 6<=R<=50
    int insert;
    int row=0,col=0;
    int loc=0;
    scanf("%d %d %d",&R,&C,&T);
   
    while(scanf("%d",&insert)!=EOF){
        if(R==row){
            break;
        }
        if(col==C){
            col=0;
            row++;
        }
        if (insert ==-1)
        {
            locCirculator[loc++]=row;
            locCirculator[loc++]=col;

        }
        
        nowMap[row][col]=insert;
        col++;
    };


    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            printf("%d",nowMap[i][j]);
        }
        puts("");
    }  

    puts("");


}