#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char comp_alpha[26]="abcdefghijklmnopqrstuvwxyz";
	int comp_location[26]={0,};
	char buf[110]={'\0',};
	for(int i=0;i<26;i++){
	comp_location[i]=-1;
	}


	fgets(buf,sizeof(buf),stdin);

	for(int i=0;i<26;i++){
		for(int j=0;j<strlen(buf);j++){
			if(buf[j]==comp_alpha[i]){
				comp_location[i]=j;
				break;
			}
		}

	}

for(int i=0;i<26;i++){
printf("%d ",comp_location[i]);
}

puts("");


}
