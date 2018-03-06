#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int targetnumber = 0;
	int nownum;
	struct timeval tv1,tv2;


	gettimeofday(&tv1, NULL);

	scanf("%d", &targetnumber);

	for (nownum = 1; nownum <= targetnumber; nownum++)
		if (targetnumber % nownum == 0)
			printf("%d는 %d의 약수. \n", nownum, targetnumber);


	printf("Complete\n");

	gettimeofday(&tv2, NULL);



//경과시간
		double nElapsed = difftime(tv2.tv_sec , tv1.tv_sec);
		double milisec = tv2.tv_usec - tv1.tv_usec;
		milisec/= (double)1000000;
		nElapsed += milisec;

		printf("nElapsed : %f \n",nElapsed );
		return 0;
	}









//~~~~~~~~~~~~~~~~~







