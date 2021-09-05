#include <stdio.h>
#include <string.h>

void challenge_1();
void challenge_2();
void challenge_3();
int main(){
	// challenge_1();
	// challenge_2();
	challenge_3();

}

void challenge_1(){
	char input;
	int max=0,now=0;
	int word_count=0;
	while((input=getchar())!=EOF){
		if(input==10){
			if(word_count>max){
				max=word_count;
			}
			word_count=0;
		}
		else{
			word_count++;
		}
	}
	printf("max Length : %d\n",max);
}

void challenge_2(){
	char input;

	while((input=getchar())!=10){
		if(input>='A' && input<'Z'){
			printf("%c",input+32);
		}
		else if(input>='a' && input<'z'){
			printf("%c",input-32);
		}

		else{
			printf("%c",input);
		}
	}
	printf("\n");
}

void challenge_3(){
	char input;
	char arr[10]={0,};
	int i=0,result=0,nth_digit=1;
	while((input=getchar())!=10){
		arr[i]=input;
		nth_digit*=10;
		i++;
	}
	nth_digit/=10;
	for (int i = 0; i < strlen(arr); ++i)
	{
		result+=(arr[i]-'0')*nth_digit;
		nth_digit/=10;
	}
	printf("%d\n",result+10);

}