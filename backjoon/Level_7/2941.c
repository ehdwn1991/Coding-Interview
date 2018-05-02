#include <stdio.h>
#include <string.h>
int main(){
	char buf[101]={'\0',};
	int croatia=0;
	scanf("%s",buf);
	for(int i=0;i<strlen(buf);i++){
		if(buf[i]=='c'&&(buf[i+1]=='='||buf[i+1]=='-')){
			croatia++;
			i+=1;
		
		}
		else if(buf[i]=='d'){
			if(buf[i+1]=='z'&&buf[i+2]=='='){
				croatia++;
				i+=2;
			}
			else if(buf[i+1]=='-'){
				croatia++;
				i+=1;
			}
			else{
			croatia++;
			}
		}
		else if(buf[i]=='l'&&buf[i+1]=='j'){
			croatia++;
			i+=1;
		}		

		else if(buf[i]=='n'&&buf[i+1]=='j'){
			croatia++;
			i+=1;
		}		
		else if(buf[i]=='s'&&buf[i+1]==61){
			croatia++;
			i+=1;
		}

		else if(buf[i]=='z'&&buf[i+1]=='='){
			croatia++;
			i+=1;
		}
		else{
			croatia++;
		}


	}

printf("%d\n",croatia);

}
