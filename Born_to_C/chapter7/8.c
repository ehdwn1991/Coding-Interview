#include <stdio.h>
int main(){
	int num1,num2=0,count=0;
	while(1){
		printf("addition  num : ");
		scanf("%d",&num1);
		num2+=num1;
		if(num1==0){
			printf("add %d times and addition result : %d \n",count,num2);
			break;
		}

		count++;
		}

}
