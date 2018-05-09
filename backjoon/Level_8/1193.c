#include <stdio.h>

int main(){
	int N=0;
	int count=1;
	int row=0,col=0;
	int i,j;
	scanf("%d",&N);
	while(1){
		if(count==N)
			break;
		if(row==0){
			col++;
			count++;
			for(int i=col;0<i;i--){
				if(count==N)
					break;
				row++;
				col--;
				count++;
			}
		}
		else{

			row++;
			count++;
			for(int j=row;0<j;j--){
				if(count==N)
					break;
				row--;
				col++;
				count++;
			}

		}

		// printf("count:%d\n",count );
	}
	printf("%d/%d\n",row+1,col+1);
	// col=3;
	// for(int i=col;0<i;i--){
	// 	col--;
	// 	printf("###%d %d\n",i,col);
	// }
}