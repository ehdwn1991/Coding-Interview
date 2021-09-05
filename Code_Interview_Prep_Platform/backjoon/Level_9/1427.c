#include <stdio.h>
#include <string.h>

/* 
1234=>4321
9999=>9999
100000 => 100000
예를 들어 위의 수처럼 10의 배수는 그대로 출력 되어야 한다.

 */
int main(){

    char inputTemp;
    char map[10]={0,};
    int point=10;
    while((inputTemp=getchar())){
        if(inputTemp==10){
            break;
        }
        map[inputTemp-48]+=1;
    }

    while(point--!=0)
    {
        if(map[point]!=0 || point>=0){
        for (size_t j = 0; j < map[point]; j++)
        {
            printf("%d",point);
        }

        }
        
    }
}