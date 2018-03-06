#include <stdio.h>
int main(){
	int i,run_time,is_weirednum=0;
	int a;
	int sum_of_weirdnum;
	scanf("%d",&is_weirednum);

	for(a=1;a<=is_weirednum;a++){
		if(is_weirednum!=a&&is_weirednum%a==0)
			sum_of_weirdnum+=a;

	}
	printf("sum : %d\n",sum_of_weirdnum );
	if(sum_of_weirdnum>is_weirednum)
		puts("weird");
	else
		puts("not weird");


}