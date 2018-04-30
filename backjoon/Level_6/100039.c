#include <stdio.h>

int main(){
	int a;
	int temp[5]={0,};
	int total=0;
	for(int i=0;i<5;i++){
		scanf("%d",&temp[i]);
		if(temp[i]<40)
			temp[i]=40;

		total+=temp[i];
	}
	printf("%d\n",total/5);




	}
