#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

x,y
4,0
5,0
 */

void spreadDust();
void printMap();


int nowMap[51][51]={0,};
int sequenceMap[51][51]={0,};

int R=0,C=0;
// up down left right
int directionRow[4]={1,-1,0,0}; // up down
int directionCol[4]={0,0,-1,1}; // left right
int availableDirection[4]={0,}; // U D L R
int locCirculator[4]={0,};
int clockWise[4]={3,0,2,1};
int counterClockWise[4]={3,1,2,0};



int checkBlowWind(int i,int j){
    if (i>=0&&j >= 0 && i<=R&&j <=C)
    {
        if(sequenceMap[i][j]!=-1){
            return 1;
        }
    }
    
    return 0;
}
void blowWind(){
    int tmp=0;
    int r,c;

     //uppper aircleaner down
    r=0;
    while(r<locCirculator[0]){
        
        if(checkBlowWind(r+1,0)&&checkBlowWind(r,0)){
            nowMap[r+1][0]=sequenceMap[r][0];
        }
        r++;
    }

     //uppper aircleaner left
    c=C;
    while(c>0){
        
        if(checkBlowWind(0,c-1)&&checkBlowWind(0,c)){
            nowMap[0][c-1]=sequenceMap[0][c];
        }
        c--;
    }
    //uppper aircleaner up
    r=locCirculator[0];
    while(r>0){

        if(checkBlowWind(r-1,C-1)&&checkBlowWind(r,C-1)){
            nowMap[r-1][C-1]=sequenceMap[r][C-1];
        }
        r--;
    }



    c=0;
    //uppper aircleaner right
    while(c<C){
        
        if(checkBlowWind(locCirculator[0],c+1)&&checkBlowWind(locCirculator[0],c)){
            nowMap[locCirculator[0]][c+1]=sequenceMap[locCirculator[0]][c];
            
        }
        c++;

    }
    nowMap[locCirculator[0]][locCirculator[1]]=-1;
    nowMap[locCirculator[0]][locCirculator[1]+1]=0;



    //lower aircleaner up
    r=R;
    while(r>locCirculator[2]){
        if(checkBlowWind(r-1,0)&&checkBlowWind(r,0)){
            nowMap[r-1][0]=sequenceMap[r][0];
        }
        r--;
    }

     //lower aircleaner left
    c=C;
    while(c>0){
        
        if(checkBlowWind(R-1,c-1)&&checkBlowWind(R-1,c)){
            nowMap[R-1][c-1]=sequenceMap[R-1][c];
        }
        c--;
    }


    //lower aircleaner down
    r=locCirculator[2];
    while(r<R){
        
        if(checkBlowWind(r+1,C-1)&&checkBlowWind(r,C-1)){
            nowMap[r+1][C-1]=sequenceMap[r][C-1];
        }
        r++;
    }

    c=0;
    //lower aircleaner right
    while(c<C){
        
        if(checkBlowWind(locCirculator[2],c+1)&&checkBlowWind(locCirculator[2],c)){
            nowMap[locCirculator[2]][c+1]=sequenceMap[locCirculator[2]][c];
            
        }
        c++;

    }
    nowMap[locCirculator[2]][locCirculator[3]]=-1;
    nowMap[locCirculator[2]][locCirculator[3]+1]=0;
    
}





void dustFlowAction(){
    int i,j;
    memset(sequenceMap,0,sizeof(sequenceMap));
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if(nowMap[i][j]>0){
                spreadDust(i,j);
            }
        }

    }
}


void spreadDust(int i, int j){
   int spreadDustValue=0;
   int beforeDust=0;
   int afterDust=0;
   int spreadCnt=0;
   int k;
   beforeDust=nowMap[i][j];
   spreadDustValue= beforeDust/5;
    sequenceMap[i][j]+=beforeDust;
for (k = 0; k < 4; k++)
{

     if((i+directionRow[k])>=0&& (i+directionRow[k])< R && j+directionCol[k]>=0&& j+directionCol[k]<C){
            if(nowMap[(i+directionRow[k])][j+directionCol[k]]>=0)// up down left right
                {
                        sequenceMap[(i+directionRow[k])][(j+directionCol[k])]+=spreadDustValue;
                        sequenceMap[i][j]-=spreadDustValue;
                }
        }
}
    
    return;
}

int canDustSpread(int i,int j){
    int cnt=0;
    int d;
    for (d = 0; d < 4; d++)
    {
        if((i+directionRow[d])>=0&& (i+directionRow[d])< R && j+directionCol[d]>=0&& j+directionCol[d]<C){
            if(nowMap[(i+directionRow[d])][j+directionCol[d]]>=0)// up down left right
                {
                    availableDirection[d]=1;
                    cnt++;
                }
        }
            
    }
    return cnt;
}

int sol(int time){
    int i;
    for (i = 0; i < time; i++)
    {
        dustFlowAction();
        memset(nowMap,0,sizeof(nowMap));
        memcpy(nowMap,sequenceMap,sizeof(nowMap));
        nowMap[locCirculator[0]][locCirculator[1]]=-1;
        nowMap[locCirculator[2]][locCirculator[3]]=-1;
        blowWind();

    }

}



void printMap(){
    int sum=0;
    int i,j;
       for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if(nowMap[i][j]>0){
                sum+=nowMap[i][j];
            }
        }
    }
    printf("%d\n",sum);

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

    sol(T);
 printMap();

}