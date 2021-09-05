#include <stdio.h>

int main(){
	char input_alpha;
	scanf("%c",&input_alpha);
	if(input_alpha>='a'&&input_alpha<='z')
		printf("Input_Alphabet: %c order number : %d\n",input_alpha,input_alpha-'a'+1);
	else if(input_alpha>='A'&&input_alpha<='Z')
	printf("Input_Alphabet: %c order number : %d\n",input_alpha,input_alpha-'A'+1);
	else
	printf("Invalid Value!!\n");

}
