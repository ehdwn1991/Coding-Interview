#include <stdio.h>
#include <stdlib.h>
int main(){
	int input_num;
	double q,w,e,r;
	printf("3 digit decimal : ");
	scanf("%d",&input_num);
	q= (double)input_num/100;
	w=(double)(q-(int)q)*10;
	e=(double)(w-(int)w)*10;
	if((int)q%2==0) printf("%d->Even number\t",(int)q);
	else printf("%d->odd number\t",(int)q);
	if((int)w%2==0) printf("%d->Even number\t",(int)w);
	else printf("%d->odd number\t",(int)w);
	if((int)e%2==0) printf("%d->Even number\t",(int)e);
	else printf("%d->odd number\t",(int)e);

	printf("\n");
}
