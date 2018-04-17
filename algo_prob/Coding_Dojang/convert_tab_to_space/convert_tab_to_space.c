#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_buf 1024
int main(int argc,char* argv[]){
    int i=0;
    char *input;
   // char buf[Max_buf];
    char *tok;
    FILE *fp;
    int temp;
    int buf[Max_buf];
    fp=fopen(argv[1],"rt");
    if(argc==1){
        fputs("error\n",stderr);
    }
//현재는 foef로 다른 배열에 저장후 쓰지만 다음번엔 fread를 통해서 바로 해결해보자
    else{
    int i=0;
    int buf_size=0;
        while(!feof(fp)){
            temp=fgetc(fp);
            if(temp<0)
                break;
            buf[i]=temp;
            buf_size=i;
            i++;
            }
    i=0;
    while(i<=buf_size){
        if((*(buf+i))=='\\'&&(*(buf+(i+1)))=='t'){
        printf("    ");
        i++;
        }
        else
            putchar(*(buf+i));
        
        i++;
        }

    }
    
}
