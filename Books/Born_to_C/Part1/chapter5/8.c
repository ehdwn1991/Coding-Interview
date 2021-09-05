#include <stdio.h>

int main(){
	int hour,min,sec,now_total_time;
	printf("hour : ");
	scanf("%d",&hour);
    printf("min : ");
    scanf("%d",&min);
	printf("sec : ");
    scanf("%d",&sec);
	now_total_time = (hour*60*60)+(min*60)+(sec);
	printf("elapse time convert to sec : %ds\n",now_total_time);
}
