#include <stdio.h>

int main(){
	int N;
	int count_path=1;
	scanf("%d",&N);
// 	for(int i=2;i<=N;){
		
// 		if(N>=i&&(6*count_path)+i>N){
// 			break;
// 		}
// 		else{
// 			i+=6*count_path;
// 			count_path++;
// 		}
// 		}


// if(N==1)
// printf("1\n");
// else
// printf("%d\n",count_path+1);

	for(int i=0;i<1000000000/18;i++){
		if(N<=(3*i*(i+1)+1)){
			count_path=i+1;
			break;
		}

	}
printf("%d\n",count_path);

}