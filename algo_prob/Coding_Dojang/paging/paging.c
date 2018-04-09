#include <stdio.h>

int main(int argc,char **argv){
    int m,n,paging;
    FILE *fp;
    fp=fopen(argv[1],"rt");

    char input;
    
    
    scanf("%d %d",&m,&n);

    if(m<=n){
        paging=n;
        printf("%d %d %d",m,n,paging);
    }
    else{//m>n
        if(m%n==0){
            paging=m/n; 
            printf("m\tn\tpaging\n");
            printf("%d\t%3d\t%3d\n",m,n,paging);
        }
        else{
            paging=m/n;
            printf("m\tn\tpaging\n");
            printf("%d\t%3d\t%3d\n",m,n,paging+1);
        
        }
        }

    }
