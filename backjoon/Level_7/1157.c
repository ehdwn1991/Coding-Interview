#include <stdio.h>
#include <string.h>
int main(){
	int alpha[26]={0,};
//	정수형 배열을 쓰는 이유는 단어의 길이가 1000000이기 때문에 반복된
//	알파벳의 횟수가 127번을 넘어가면 CHAR형의 범위를 넘어버린다.

	char temp;
	int Max_comp=0;
	int comp2=0;
	int comp1=0;	


	while((temp=getchar())!=10){
		if(temp>64&&temp<91){
		//대문자 일때
			alpha[temp-65]+=1;
		}
		else{
	//		소문자 일때
			alpha[temp-97]+=1;
		}
	}

//	for(int i=0;i<26;i++){
//		printf("%d ",alpha[i]);

//		}
//puts("");	
	for(int i=0;i<26;i++){
		if(alpha[i]!=0){
			Max_comp=(Max_comp>alpha[i]?Max_comp:alpha[i]);
//			printf("###%d###\n",Max_comp);	
	}
	}
	for(int j=0;j<26;j++){
		if(Max_comp==alpha[j]){
			comp1=j;
			comp2++;	
		}
	}


	if(comp2>1){
	printf("?\n");}
	else
	printf("%c\n",comp1+65);



}
