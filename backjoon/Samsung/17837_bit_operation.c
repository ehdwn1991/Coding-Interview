#include <stdio.h>




int main(){
    int i,j;
    int *a;
    int val;
    int *b;
    int *temp;
    int val1=0x5;
    val=0x9345;
    a=&val;
    b=&val1;
    // b= a;

    for ( i = 0; i < 4; i++)
    {

    // find
    if(*a&*b<<((i+1)*4)){
        //n 번 위로 클리어

    //clear
    printf("%0.8x\n",*a^*b<<((i+1)*4));
    temp=a;
            *temp=*temp>>(i+1)*4;
    printf("be temp[%0.8x]\n",*temp);

            *temp=*temp<<(i+1)*4;
    printf("af temp[%0.8x]\n",*temp);

    *temp=*a^*temp;
    printf("stack [] clear [%0.8x]\n",*temp);    
    }


    }
    
/*     
    0001 1
    0010 2
    0100 3
    1000 4
    1001 5 
    1010 6
    1100 7
    1101 8
    1110 9
    1111 10
    */
}