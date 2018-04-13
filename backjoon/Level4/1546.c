#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

	int N;
	float grade[1001];
	int i=0;
	int temp_grade,count=0;
	int max_grade_pointer=0,max_grade;;
	int sum=0;
	float avg=0;
	scanf("%d\n",&N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&temp_grade);
		grade[i]=temp_grade;
		if(grade[max_grade_pointer]>=temp_grade){
			continue;
		}
		else{
			max_grade_pointer=i;
			//printf("Max : %d\n",max_grade_pointer );
		}
	}
	max_grade=grade[max_grade_pointer];


	for (i=0; i < N; ++i)
	{
	
			
			grade[i]=(float)((int)((grade[i]/max_grade*100)*1000+5))/1000;
		//문제에서 새로 바뀐 점수도 소수점 2번째 자리 까지 반올림 하라는 문장은 없지만 그렇게 해줘야댐

		avg+=grade[i];
	}

	printf("%.2f\n",avg/N);
}