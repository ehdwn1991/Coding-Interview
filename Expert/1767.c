#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int pick(int (*arr)[12],int input);
int search(int (*arr)[12],int input,int row,int col);
void clear();
void fill_path(int (*arr)[12],int input,int vec,int row,int col);
void showall(int (*arr)[12],int input);
int main(){
	int Tc=0;
	int input=0;
	int temp;
	int row=0,col=0;
	int arr[12][12]={0,};
	char buf[1024];
	clock_t startTime, endTime;
	double nProcessExcuteTime;
  startTime = clock(); /*현재 시각을 구한다.*/
	scanf("%d",&Tc);
	for (int i = 1; i <= Tc; ++i)
	{
		scanf("%d",&input);
		clear();
		for (int k = 0; k <input; ++k)
		{
			fgets(buf,1024,stdin);
			// printf("i:%d row %d %s\n",i,row,buf );
			for(int j=0; j<strlen(buf);j++){
				if(buf[j]==10)
					break;

				if(buf[j]>='0'&&buf[j]<='9'){
					arr[row][col]=buf[j]-'0';
					// printf("hit[%d][%d]:%d\n",row,col,arr[row][col] );
					col++;
				}
			}
			col=0;
			row++;
			// puts(buf);
			// memset(buf,0,strlen(buf));
		}
		row=0;
		printf("#%d %d\n",i,pick(arr,input));
	// memset(arr,0,sizeof(arr)/sizeof(int));
			// clear();
	// showall(arr,input);
	}
	// puts("");


	endTime = clock(); /*현재 시각을 구한다.*/
  
  nProcessExcuteTime = ( (double)(endTime - startTime) ) / CLOCKS_PER_SEC;
  
  printf("Excute time: %f\n", nProcessExcuteTime);
}



int pick(int (*arr)[12],int input){
	int count_core=0, count_path=0;
	int row=input,col=input;
	int temp;
	int left_i=0,left_j=0,right_i=input-1,right_j=input-1;
	// 	for (int i = 0; i < row; ++i)
	// 	{	
	// 		if(count_core==input)
	// 			break;
	// 		for (int j = 0; j < col; ++j)
	// 		{	
	// 				// printf("arr[%d][%d] : %d\n",i,j,arr[i][j] );
	// 			if((i==0 || j==0 || i==input-1 || j==input-1) && (arr[i][j]==1))
	// 			{
	// 			// printf("\n%d %d \n",i,j);
	// 			count_core++;
	// 			}	
	// 			else{
	// 			if(arr[i][j]==1){
	// 				if((temp=search(arr,input,i,j,core_status))>0 ){
	// 				printf("aaarr[%d][%d]=>%d\n",i,j,temp);
	// 				count_path+=temp;
	// 				count_core++;
	// 				}
	// 			}

	// 			}
	// 		}
	// }


	while(left_i!=right_i){

		for (int i = left_i; i < right_i; ++i)
		{
				// 열 고정
			if(left_j==0)
				break;
			if(arr[i][left_j]==1){
				if((temp=search(arr,input,i,left_j))>0){
					// printf("left down row: %d  col: %d\n",i,left_j );
					count_core++;
					count_path+=temp;
				}
			}

		}

		for (int i = left_j+1; i <right_j ; ++i)
		{
				// 행 고정
			if(left_i==0)
				break;
			if(arr[left_i][i]==1){
				if((temp=search(arr,input,left_i,i))>0){
					// printf("left right move row: %d  col: %d\n",left_i,i );
					count_core++;
					count_path+=temp;
				}
			}

		}
		for (int i = right_i; i>0; --i)
		{
				// 열 고정
			if(right_j==input-1)
				break;
			if(arr[i][right_j]==1){
				if((temp=search(arr,input,i,right_j))>0){
					// printf("right up row: %d  col: %d\n",i,right_j );
					count_core++;
					count_path+=temp;
				}
			}

		}

		for (int i = right_j-1; i >0; --i)
		{
				// 행 고정
			if(right_i==input-1)
				break;
			if(arr[right_i][i]==1){
				if((temp=search(arr,input,right_i,i))>0){
					// printf("right left move row: %d  col: %d\n",right_i,i );
					count_core++;
					count_path+=temp;
				}
			}

		}


			left_i++; //row
			left_j++; //col
			right_i--;
			right_j--;
		}
		return count_path;
	}

	void fill_path(int (*arr)[12],int input,int vec,int row,int col){
			//0=left 1=right 2=up 3=down
		// printf("fill vec: %d  row: %d  col: %d\n",vec,row,col );
		if(vec==0){
			for (int i = 0; i < col; ++i)
			{
				arr[row][i]=2;
			}		
		}
		else if(vec==1){
			for (int i = col+1; i < input; ++i)
			{
				arr[row][i]=2;
			}

		}
		else if(vec==2){
			for (int i = 0; i < row; ++i)
			{
				arr[i][col]=2;
			}	

		}
		else{
			for (int i = row+1; i < input; ++i)
			{
				arr[i][col]=2;
			}

		}
	}

	int search(int (*arr)[12],int input,int row,int col){
		int r=0,c=0;
	int weight[4]={0,}; //0=left 1=right 2=up 3=down
	int min_path=0,min_vec=0;;
// printf("search row: %d  col: %d\n",row,col );
	// left
	for (int i = 0; i < col; ++i)
	{	
		if(arr[row][i]<1){
			weight[0]+=1;
		}
		else{
			weight[0]=0;
			break;
		}
	}


	// right
	for (int i = col+1; i < input; ++i)
	{	
		if(arr[row][i]<1){
			weight[1]+=1;
		}
		else{
			weight[1]=0;
			break;
		}
	}


	// up
	for (int i = 0; i < row; ++i)
	{	
		if(arr[i][col]<1){
			weight[2]+=1;
		}
		else{
			weight[2]=0;
			break;
		}
	}


	// down
	for (int i = row+1; i < input; ++i)
	{	
		if(arr[i][col]<1){
			weight[3]+=1;
		}
		else{
			weight[3]=0;
			break;
		}
	}

	min_path=input;

	for (int i = 0; i <= 3; ++i)
	{
		if(min_path>weight[i]&&weight[i]>0){
			min_path=weight[i];
		}
	}


	if(min_path==input)
		min_path=-1;

	else{
		for (int i = 0; i < 4; ++i)
		{
			//0=left 1=right 2=up 3=down
			if(min_path==weight[i]){
	// printf("l : %d r: %d u: %d  d: %d\n",weight[0],weight[1],weight[2],weight[3] );
	// printf("arr[%d][%d]=>%d   min:%d => %d\n",row,col,arr[row][col],i,min_path);
				fill_path(arr,input,i,row,col);
				// showall(arr,input);
				break;
			}
		}
	}

	// printf("min_path: %d\n",min_path );
	return min_path;
}

void clear(){
	while(getchar()!=10);
}

void showall(int (*arr)[12],int input){
	for (int i = 0; i < input; ++i)
	{
		for (int j = 0; j < input; ++j)
		{
			printf("%d ",arr[i][j] );
		}
		printf("\n");
	}

}

