#include <stdio.h>

int ppang();
int main(){
	int TC=0;
	int a,b,c;
	scanf("%d",&TC);	

	for (int i = 1; i <= TC; ++i)
		{	a=0;
			b=0;
			c=0;
			scanf("%d %d %d",&a,&b,&c);
			printf("#%d %d\n",i,ppang(a,b,c));

		}
	}

	int ppang(int bread1,int bread2, int money){
		int bread1_count=0,bread2_count=0;
		int max_bread=0;
		int temp=0;
			bread1_count=money/bread1;
			max_bread = bread1_count;
			while((bread1_count*bread1+bread2_count*bread2<=money)){
				temp = bread1_count+bread2_count;
				if(max_bread<temp){
					max_bread=temp;
				}
				if(bread1_count>0)
				bread1_count--;

				bread2_count++;
			// printf("bread_1:%d bread_2:%d max:%d\n",bread1_count,bread2_count,max_bread );
			}



		return max_bread;
	}



