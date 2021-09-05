#include <stdio.h>
int clab_clab();
int main(){
	int TC;
	char people_clab[1002]={'\0',};
	scanf("%d",&TC);

	for (int i = 0; i < TC; ++i)
	{

		scanf("%s",people_clab);
		printf("#%d %d\n",i+1,clab_clab(people_clab));
		// printf("# %d\n",clab_clab(people_clab));
	}


	return 0;
}


int clab_clab(char *q){
	int need_people=0,now_people=0;
	int num=0;
	int total_need_people=0;
	while(q[num]!=0){
			if(num==0){
				now_people+=(q[num]-'0');
			}
			else{
				if((now_people+need_people)<num){
					need_people=(num-now_people);
					now_people+=(q[num]-'0');
					total_need_people=need_people;
				}
				else{
					now_people+=(q[num]-'0');
				}
			}



		num++;
	}

	return total_need_people;
}