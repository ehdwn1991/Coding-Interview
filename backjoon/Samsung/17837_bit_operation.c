#include <stdio.h>


int main(){
    int i;
    int a=0x00000345;
    int b=0x3;
    // b= a;
    printf("%0.8x\n",a&(b));

    for ( i = 1; i < 8; i++)
    {
    if(a&b<<(i*4)){
    printf("%0.8x\n",b<<(i*4));

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