#include <stdio.h>
int rabit();
int main(){
	
	int a=1;
//	a=rabit(12);
//	printf("\n%d\n",a);
	for(int i=1;i<=12;i++)
	{	printf("%d ",rabit(i));

}
printf("\n");
}

int rabit(int bunny){
	int result;	
	if(bunny<=1)
		return bunny;
	else{
		result=rabit(bunny-1)+rabit(bunny-2);
		return result;
		}
}
