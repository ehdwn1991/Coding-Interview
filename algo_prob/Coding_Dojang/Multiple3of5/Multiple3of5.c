#include <stdio.h>
#define Max_num 1000

int mutiple_addition();
int main(){
   int result;
   result=  mutiple_addition(3,5);
   printf("result : %d\n",result);
    
    

}

int mutiple_addition(int N1,int N2){
    int i=0;
    int add_num=0;
    while(++i<1000){
        if(i%N1==0||i%N2==0)
            add_num+=i;
    printf("%d\n",i);
    }
    return add_num;
}

