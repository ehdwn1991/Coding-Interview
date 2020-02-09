#include <stdio.h>
#include <string.h>
#define MAX 51

typedef struct queue{
    int x;
    int y;

}Queue;



int vMap[MAX][MAX]={0,};
Queue qu[MAX]={0,};

int front=-1;
int rear=-1;
int N,M;
int isEmpty(void){
    if(front==rear) 
        return 1;
    else
        return 0;
}
int isFull(void){
    int tmp=(rear+1)%MAX; 
    if(tmp==front) 
        return 1;
    else
        return 0;
}
void push(int x,int y){
    if(isFull())
        printf("Full.\n");
    else{
         qu[rear].x=x;
         qu[rear].y=y;
        //  printf(" %x x: %d y:%d\n",&qu[rear],qu[rear].x,qu[rear].y);
         rear = (rear+1)%MAX;

        }
}
Queue *pop(){
    Queue *tempQ=malloc(sizeof(Queue));
    if(isEmpty())
        printf("Empty.\n");
    else{
        tempQ = &qu[front];
        front = (front+1)%MAX;
        // printf("%x %d, %d \n",tempQ,tempQ->x,tempQ->y);
        return tempQ;
    }
}


void testQ(){
    Queue *qTemp;
    qTemp = (pop());
    // printf("%x %d %d\n",qTemp,(qTemp)->x,(*qTemp).y);
}

int sol(){

}

void showQ(){
    for ( i = 0; i < 51; i++)
    {
        printf("x: %d y:%d",qu[i].x,qu[i].y);
        puts("");
    }
   
}
void showMap(){
   for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
        printf("%d ",vMap[i][j]);
        }
        puts("");
    }
}

int main(){
    int i=0,j=0;
    int row=0,col=0;
   
    scanf("%d %d",&N,&M);
    while((scanf("%d",&vMap[row][col++]))!=EOF){
        if(col==N){
            col=0;
            row++;
        }
    }

 


testQ();

}