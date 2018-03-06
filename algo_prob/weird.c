#include <stdio.h>
int main(){
	int i,run_time,is_weirednum;
	int a;
	int sum_of_weirdnum;
	scanf("&d",is_weirednum);

	for(a=1;a<=is_weirednum;a++){
		if(is_weirednum%a==0)
			sum_of_weirdnum+=a;

	}
	if(sum_of_weirdnum>is_weirednum)
		puts("weird");
	else
		puts("not weird");


}