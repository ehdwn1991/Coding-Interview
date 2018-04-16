#include <stdio.h>

// int main(){
// 	// char asteric_module[3][5]={{' ',' ','*',' ',' '},
// 	// 							{' ','*',' ','*',' '},
// 	// 							{'*','*','*','*','*'}};

// 	char asteric_module[][5]={"  *  "," * * ","*****"};
// 	int N=0,center;
// 	char a[1000][2000]={' ',};	
// 	// for (int i = 0; i < 3; ++i)
// 	// {
// 	// 	printf("%s\n",asteric_module[i]);
// 	// }

// 	scanf("%d",&N);
// 	a[0][N]='*';
// 	for (int i = 1; i < N; ++i)
// 	{
// 		a[i][0]='*';
// 		a[i][i]='*';
// 	}

// 	printf("###%c###\n",a[0][3]);
// 	printf("%s\n",a[0] );
// 	//puts(a[0]);
	
// }
int n, a[3072][6146];
int main() {
    scanf("%d", &n);
    a[0][n - 1] = a[1][n - 2] = a[1][n] = a[2][n - 3] = a[2][n - 2] = a[2][n - 1] = a[2][n] = a[2][n + 1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            if (i > 2) a[i][j] = (j>2 && a[i - 3][j - 3]) ^ a[i - 3][j + 3];
            putchar(" *"[a[i][j]]);
        }
        puts("");
    }
    return 0;
}