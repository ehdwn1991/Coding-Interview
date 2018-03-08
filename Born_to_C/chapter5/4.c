#include <stdio.h>

int main(){
	int a,b,c,comp1,comp2,result;
	printf("input a :");
	scanf("%d",&a);
	printf("input b :");
	scanf("%d",&b);
	printf("input c :");
	scanf("%d",&c);

	//a==b? printf("%d\n",a): a>b?(a>c?a:(b>c?:));
	comp1 = a>b?a:b;	
	comp2 = b>c?b:c;
	//result = comp1>comp2?comp1:comp2;
	result = a>=b&&a>=c?a:b>=a&&b>=c?b:c>=a&&c>=b?c:c; //이렇게 해도 결과는 동일!! 왜냐면 결국에 전부 false면 c랑 같은 값이 거나 c가 가장 큰값임	
	printf("result : %d\n",result);
}
