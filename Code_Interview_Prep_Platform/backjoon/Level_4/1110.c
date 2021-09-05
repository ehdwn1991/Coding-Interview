#include <stdio.h>
int circle();
int tokken_units();
int token_tens();
int main(){
	
	int N,temp_N;
	int result;
	scanf("%d",&N);

	printf("%d\n",circle(N));

}

int circle(int N){
	int count=1;
	int init_state[3];
	int next_state[3];
	int arg_first,arg_second,arg_result;
	init_state[0]=token_tens(N);
	init_state[1]=tokken_units(N);
	init_state[2]=init_state[0]+init_state[1];
	next_state[0]=init_state[0];
	next_state[1]=init_state[1];
	next_state[2]=init_state[2];

	while(1){

		if(next_state[2]<10){
		next_state[0]=next_state[1];
		next_state[1]=next_state[2];
		next_state[2]=next_state[0]+next_state[1];
		}
		else{
		next_state[0]=next_state[1];
		next_state[1]=tokken_units(next_state[2]);
		next_state[2]=next_state[0]+next_state[1];

		}
		if(next_state[0]==init_state[0]&&next_state[1]==init_state[1]&&next_state[2]==init_state[2]){
			break;
		}

		count++;

	}
			return count;
}

int tokken_units(int N){
	int units;//units 일의 자리
	units= N-(N/10)*10;

	return units;
}

int token_tens(N){

int tens;//units 일의 자리
tens= N/10;

return tens;

}