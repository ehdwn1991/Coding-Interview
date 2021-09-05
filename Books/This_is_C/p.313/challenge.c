#include <stdio.h>


void challenge_1();
void challenge_2();
int check_lotto();
void draw_score();
int main(){
	challenge_1();
	challenge_2();


}

void challenge_1(){
	int score[5]={72,88,94,64,100};
	draw_score(score,sizeof(score)/sizeof(int));

}

void draw_score(int *p,int size){
	int temp;
	for (int i = 0; i < size; ++i)
	{
		temp = p[i]/5;
		printf("(%d)  ",p[i] );
		for (int i = 0; i < temp; ++i)
		{
			printf("*");
		}
		printf("\n");

	}

}

void challenge_2(){
	int lotto[6]={4,10,25,30,41,45};
	int my_num[6]={1,4,7,22,41,43};

	printf("%d\n",check_lotto(lotto,my_num));
}

int check_lotto(int *lotto,int *my){
	int hit=0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (lotto[i]==my[j])
			{
				hit++;
			}
		}

	}
	return hit;

}