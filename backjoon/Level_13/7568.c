#include <stdio.h>
#include <stdlib.h>

typedef struct mess{
    int Weight;
    int Height;
    int score;
    struct mess *next;
}Mess;

typedef struct top{
    int Weight;
    int Height;
    int score;
}TOP;

int H[51]={0,};
int W[51]={0,};
int main(){
    TOP *topVal;
    int count;
    scanf("%d",&count);
    topVal->score=count;
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d %d",H[i],W[i]);
        if(topVal->Height<H[i] && topVal->Weight<W[i]){
            topVal->Height=H[i];
            topVal->Weight=W[i];
            topVal->score--;
        }
    }
    
printf("%d\n",topVal->score);
}



Mess *newValue(int W,int H){
    Mess *add_element=(Mess*) malloc(sizeof(Mess));
return add_element;
}

