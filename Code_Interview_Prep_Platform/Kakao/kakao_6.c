#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void check_4by4();
void fill_blank();
void re_align();
int find_blank();
int check_hit();
int print_state();
int main(){
	int n=0,m=0; //m 높이 n 폭  n X m
	int count=0;
	int TC=0;
	int **for_free;
	scanf("%d",&TC);
	for (int t = 0; t < TC; ++t)
	{
		scanf("%d %d",&m,&n);
		char **kaka=(char**)malloc(sizeof(char*)*m);
	
		for (int i = 0; i < m; ++i)
		{
			kaka[i]=(char*)malloc(sizeof(char)*n);
			scanf("%s",kaka[i]);
		}

		check_4by4(kaka,m,n);
		printf("%d\n",print_state(kaka,m,n));
		
		for (int k = 0; k < m; ++k)
		{
			free(kaka[k]);
		}
	}	

	// object cannot be allocated, the old object is not deallocated and its value is unchanged.
	// c99-§7.20.3.4
}




// searching removable block
int check_hit(char **kaka_block,int m,int n){
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if((kaka_block[i][j]!=0)&&(i+1<n)&&(j+1<m)&&
				(kaka_block[i][j]==kaka_block[i][j+1])&&
				(kaka_block[i][j]==kaka_block[i+1][j])&&
				(kaka_block[i][j]==kaka_block[i+1][j+1])){
				 // removalble word at least one
				return 1;
			}
		}
	}
	return -1;
}


// until can't remove any block
void check_4by4(char **kaka_block,int m,int n){
	char **blank_block=(char**)malloc(sizeof(char*)*m);
	int remove_blank=0;
	for (int i = 0; i < m; ++i)
	{
		blank_block[i]=(char*)malloc(sizeof(char)*n);
	}

	while(1)
	{
		//check any removable block
		if(check_hit(kaka_block,m,n)<0)
			break;

		else{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					// check 2by2 matching block
					if((kaka_block[i][j]!=0)&&(i+1<m)&&(j+1<n)&&(kaka_block[i][j]==kaka_block[i][j+1])&&(kaka_block[i][j]==kaka_block[i+1][j])&&(kaka_block[i][j]==kaka_block[i+1][j+1])){
						blank_block[i][j]='X';
						blank_block[i][j+1]='X';
						blank_block[i+1][j]='X';
						blank_block[i+1][j+1]='X';
						// remember 2by2 matching block position at another array
					}
				}
			}
			//fill blank block
			fill_blank(kaka_block,blank_block,m,n);
			//realigned kaka_block
			re_align(kaka_block,m,n);

		}
	}



} 

// compare origin pad and blank pad and if matching blocks replacing 0
void fill_blank(char **kaka_block,char **blank_block,int m,int n){
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(blank_block[i][j]=='X'){
				kaka_block[i][j]=0;
				blank_block[i][j]=0;
			}
		}
	}

}

// 
void re_align(char **kaka_block,int m,int n){
	int point=0;
	char temp;
	for (int i = 0; i < m; ++i)
	{
		for (int j = i; j < n; ++j)
		{	
			
			for (int k = m-1; k>0; --k)
			{
				if(kaka_block[k][i]==0&&kaka_block[k-1][i]!=0){
					temp= kaka_block[k][i];
					kaka_block[k][i]=kaka_block[k-1][i];
					kaka_block[k-1][i]=temp;
				}
			}

		}

	}

}

int print_state(char **kaka_block,int m,int n){
	int count=0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(kaka_block[i][j]==0){
				printf("'");
				count++;
			}
			else
				printf("%c",kaka_block[i][j]);
		}
		printf("\n");
	}
	return count;
}