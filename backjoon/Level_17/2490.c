#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int bae,deung;
	int one,two,three,four;
	char buf[10];
	int status_zero=0,status_one=0;
	for(int i = 0; i < 3; ++i){
		fgets(buf,sizeof(buf),stdin);
		for (int j = 0; j < strlen(buf); ++j)
		{
			if(buf[j]=='0')
				status_zero++;
			else if(buf[j]=='1')
				status_one++;
			else
				continue;
		}

		if(status_zero>0){
			switch(status_zero){
				case 1:
				printf("A\n");
				break;
				case 2:
				printf("B\n");
				break;


				case 3:
				printf("C\n");
				break;
				case 4:
				printf("D\n");
				break;

			}
		}
		else
			printf("E\n");
	status_one=0;
	status_zero=0;
	}
}