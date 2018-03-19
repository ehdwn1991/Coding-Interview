#include <stdio.h>

int main(){
	int input,grade;
	printf("Insert score : ");
	scanf("%d",&input);
	grade = input/10;
	switch(grade){
	case 10 :
		printf("A\n"); 
		break;
	case 9 :
		printf("A\n");
		break;
	case 8 :
		printf("B\n");
	break;
	default :
		printf("F\n");
		break;
}	


}
