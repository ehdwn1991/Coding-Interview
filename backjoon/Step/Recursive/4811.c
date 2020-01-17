#include <stdio.h>

/*
pill N
1 or 0.5

1 -> W
0.5 -> H
ex
3
www
pick w send w remain hww stack w
pick w send w remain hhw stack ww
pick w send w remain hhh stack www
pick h send h remain hww stack wwwh
pick h send h remain hww stack wwwhh
pick h send h remain hww stack wwwhhh

BaseCase W==0 M(W,H)==1
M(W,H) = M(W-1,H+1) W>0 && H<1
M(W,H) = M(W-1,H+1)+M(W,H-1) otherwise
 */

int count=0;
long long map[31][31]={0,};
int pillMsg(int W,int H){
    printf("N : %d phlls: %c\n",N,pills);
    if(W==0){
        return 1;
    }
    
}
int main(){
    int N;
scanf("%d",&N);
pillMsg(N,0);
printf("count : %d test: %d\n",count,test);
}
