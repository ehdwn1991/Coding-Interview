#include <stdio.h>
#include <math.h>
int is_prime();
int main(){
	int N,input,count=0,prime=1; 
	scanf("%d",&N);

	for (int i = 1; i <= N; ++i)
	{
		// input=i;
		scanf("%d",&input);
		if(is_prime(input)==1)
			count++;
		
	}
	printf("%d\n",count);

}

int is_prime(int num){
	
	if(num==1)
		return 0;

	for (int j = 2; j <= sqrt(num); ++j)
	{
		if(num%j==0){
			return 0;
		}
	}

	return 1;
}

