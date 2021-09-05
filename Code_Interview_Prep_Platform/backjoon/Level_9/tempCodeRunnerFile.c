#include <stdio.h>
#include <string.h>

int main(){

    char inputTemp;
    char map[10]={0,};
    int point=0;
    while((inputTemp=getchar())){
        if(inputTemp==10){
            break;
        }
        map[inputTemp-48]+=1;
    }

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < map[i]; j++)
        {
            printf("%d",i);
        }
        
    }

}