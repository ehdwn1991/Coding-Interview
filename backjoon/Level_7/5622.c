#include <stdio.h>
#include <string.h>
int main(){
	char buf[16]={'\0',};
	int result=0;
	scanf("%s",buf);

	for(int i=0;i<strlen(buf);i++){
		if(buf[i]>=65&&buf[i]<=67)
			result+=3;	
		
		else if(buf[i]>=68&&buf[i]<=70)
			result+=4;

		else if(buf[i]>=71&&buf[i]<=73)
			result+=5;

		else if(buf[i]>=74&&buf[i]<=76)
			result+=6;
		
		else if(buf[i]>=77&&buf[i]<=79)
			result+=7;
		
		else if(buf[i]>=80&&buf[i]<=83)
			result+=8;

		else if(buf[i]>=84&&buf[i]<=86)
			result+=9;

		else	
		result+=10;

	}
	printf("%d\n",result);

}
