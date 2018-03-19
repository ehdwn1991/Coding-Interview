#include <stdio.h>

int n_addition(int n);
int main(){
	int input_num,result;
	printf("Input your number : ");
	scanf("%d",&input_num);
	printf("sum of 1 to %d = %d\n",input_num,n_addition(input_num));
	
}
int n_addition(int n){
	if(n<1)
		return 0;
	return n+n_addition(n-1);


}
