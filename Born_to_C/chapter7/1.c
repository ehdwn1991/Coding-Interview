#include <stdio.h>

int main(){
	int in_num,n=1,count=1;

	printf("positive num : ");
	scanf("%d",&in_num);
	printf("%d's multiple :",in_num);
	while(1){
		n=in_num*count;
		if(n>100){
		count--;
		break;}	
		printf(" %d ",n);
		count++;

	}
	
	printf("\nCount of %d's multiple : %d \n",in_num,count);

}
