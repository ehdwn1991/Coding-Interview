#include <stdio.h>

int main(){
    char a[6]={'A','B','C','\0'};
    char b[6]={'\0',};
    for(int i=0;i<3;i++){
        b[i]=a[i];
        b[5-i]=a[i];
    }
    for(int q=0;q<6;q++){
        printf("%c: %x\t",b[q],&b[q]); 
    }
    printf("\n");
    puts(b);
    
}
