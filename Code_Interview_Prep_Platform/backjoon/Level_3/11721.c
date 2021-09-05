#include <stdio.h>
#include <string.h>

int main(){
	int N;
	char buf[1001];
	fgets(buf,sizeof(buf),stdin);

	for (int i = 1; i < strlen(buf); ++i)
	{
		printf("%c",buf[i-1] );
		
		if(i%10==0)
			printf("\n");
	}




}