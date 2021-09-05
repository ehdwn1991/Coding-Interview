#include <stdio.h>

// Max combination 40320

int stack[40321]={0,};

int numPad[8]={0,};
int visit[9]={0};
int N,M;
int top=-1;

void push(int value);
int pop();
int combination(int pick){
        
    
    if(pick==M){
        for (size_t i = 0; i < M; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
        
        return 0;
    }

    for (size_t i = 1; i <= N; i++)
    {

        if(visit[i]==0){
        visit[i]=1;
        // printf("%d ",i);
        push(i);
        combination(pick+1);    
        visit[i]=0;
      
        pop();
        }

    }
    
    
}
int IsEmpty(){
    if(top<0)
        return 1;
    else
        return 0;
    }
int IsFull(){
    if(top>=40320)
        return 1;
    else
        return 0;
}
 

void push(int value){
    if(IsFull()==1)
        printf("Full!!\n");
    else
        stack[++top]=value; 
}
int pop(){
    if(IsEmpty()==1)
        printf("Empty!\n");
    else 
        return stack[top--];
}

int main(){
    scanf("%d %d",&N,&M);
combination(0);

        /* code */
    
}