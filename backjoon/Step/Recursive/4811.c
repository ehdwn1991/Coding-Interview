#include <stdio.h>
#include <string.h>
/*
pill N
1 or 0.5

1 -> W
0.5 -> H

BaseCase W==0 M(W,H)==1
M(W,H) = M(W-1,H+1) W>0 && H<1
M(W,H) = M(W-1,H+1)+M(W,H-1) otherwise
 */

int count=0;
long long map[31][31]={0,};
long long pillMsg(int W,int H){
    if(map[W][H]){
        // printf("map[%d][%d]:%d\n",W,H,map[W][H]);
        return map[W][H];
    }
    if(W==0){
        return 1;
    }
    
    map[W][H]=pillMsg(W-1,H+1);
    if(H>0)
        map[W][H] += pillMsg(W,H-1);
    
    return map[W][H];

}
int main(){
    int N;

while(scanf("%ld",&N)){
    if (N==0){
        break;
    }
printf("%ld\n",pillMsg(N,0));
memset(map,0,sizeof(map));

}
}
