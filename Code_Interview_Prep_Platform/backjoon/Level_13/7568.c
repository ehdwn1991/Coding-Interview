#include <stdio.h>
#include <stdlib.h>


typedef struct top{
    int Weight;
    int Height;
    int score;
}TOP;

int main(){
    TOP *topVal;
    int count;
    scanf("%d",&count);
    TOP *topList = (TOP*)malloc(sizeof(TOP)*count);
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d %d",&topList[i].Height,&topList[i].Weight);

    }

     for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
            if(topList[i].Height>topList[j].Height&&topList[i].Weight>topList[j].Weight)
                topList[j].score++;
        }
     }


    for (size_t i = 0; i < count; i++)
    {
        // printf("%d %d %d \n",topList[i].Height,topList[i].Weight,(topList[i].score)+1);
        printf("%d ",(topList[i].score)+1);
    }
}

