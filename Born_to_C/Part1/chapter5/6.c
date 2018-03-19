#include <stdio.h>

int main()
{	double cigar,year;
	double max_age;
	//printf("your age : ");
	//scanf("%lf",&now_age);
			
	printf("how many smoking cigar for day : ");
	scanf("%lf",&cigar);

	printf("how long somking : ");		
	scanf("%lf",&year);
	max_age =100-((cigar*2*365*year)/60/24/356);
	printf("approximately age : %lf \n",max_age);



}
