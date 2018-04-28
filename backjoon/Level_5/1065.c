#include <stdio.h>

int main(){
	int N;
	int place_value[3]={'\0',};
	int Hansu=0;
	scanf("%d",&N);

	for (int i = 1; i <= N; ++i)
	{
		if(i<100){
			Hansu++;
			// printf("11's : %d  \n",i );
		}
		else if(i==1000){
			break;
		}
		else if(99<i){
			place_value[0]= i/100;
			place_value[1]=(i-place_value[0]*100)/10;
			place_value[2]=((i-place_value[0]*100)-(place_value[1]*10));
			if(place_value[0]-place_value[1]==place_value[1]-place_value[2]){
				Hansu++;
			}
			else{
			// printf("two's com : %d  0:%d 1:%d 2:%d\n",i ,place_value[0],place_value[1],place_value[2]);
			printf("%d\n",i );
			}



		}
	
	}
	printf("%d\n",Hansu );

}