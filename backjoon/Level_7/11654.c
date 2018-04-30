#include <stdio.h>

int main(){
	char a;


	while((a=getchar())!=EOF){
		if(a!=10)
			printf("%d\n",a);


	}

}
