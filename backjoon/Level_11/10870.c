#include <stdio.h>
#include <string.h>
/* 
1,1,2,3,5,8,13,21,34,55
1~10 natural number sumation == Nth 피보나치의 값
 */
int map[1000]={0,};
int main(){
int N;
scanf("%d",&N);
/* for (size_t i = 1; i < 11; i++)
{
    printf("%d recursive[%d]\n",i,recursive(i));
} */

// printf("recursive: %d\n",recursive(N));
printf("improve: %d\n",improve(N));
memset(map,0,sizeof(map));
// printf("Basic : %d\n",basicfibo(N));
// printf("simple : %d\n",simpleSumation(N));
}

/* 
fibo = 0 => if n is 0
     = 1 => if n is 1
     = fibo(n-1)+fibo(n-2) => Otherwise
*/
int recursive(int n){
    return n>=2 ? recursive(n-1)+recursive(n-2) : n;

}

int improve(int N){
    if(N<2){
        map[N]=N;
        return N;
    }
    if(map[N]!=0){
        // printf("Has %d // %d\n",N,map[N]);
        return map[N];
    }
    map[N]= improve(N-1)+improve(N-2);
    
return improve(N);
}
int basicfibo(int n){
    if(n==0 || n==1){
        return n;
    }

    return basicfibo(n-1)+basicfibo(n-2);
}

int simpleSumation(int N){
   return ((N+1)*N)/2;
    
}