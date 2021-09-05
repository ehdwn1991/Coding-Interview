#include <stdio.h>
void challenge_1();
void challenge_2();
void challenge_3();

void rotate();
void func();
void line_up();
void swap();
int main(){
	// challenge_1();
	// challenge_2();
	challenge_3();

}

void challenge_1(){
	int mod,rem;
	func(&mod,&rem);
	printf("portion: %d remainder: %d\n",mod,rem );


}

void func(int *a,int *b){
	int temp;
	scanf("%d",&temp);
	*a=temp/4;
	*b=temp%4;
}

void challenge_2(){
	double max,mid,min;
	printf("Input three numbers: ");
	scanf("%lf %lf %lf",&max,&mid,&min);
	line_up(&max,&mid,&min);
	printf("max : %.1lf mid: %.1lf  min:%.1lf\n",max,mid,min );

}


void line_up(double *a,double *b,double *c){
	double arr[3];
		arr[0]=*a;
		arr[1]=*b;
		arr[2]=*c;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 3-1; j > i; --j)
		{
			if(arr[i]<arr[j])
				swap(&arr[i],&arr[j]);

		}
	}

	*a=arr[0];
	*b=arr[1];
	*c=arr[2];



}

void swap(double *a,double *b){
	double temp;
	temp = *a;
	*a= *b;
	*b=temp;
}


void challenge_3(){
	int a=1,b=2,c=3;
	char q;
	while((q=getchar())){
		if(q!=10)
			break;
		rotate(&a,&b,&c);
		printf("%d:%d:%d",a,b,c );

	}

}

void rotate(int *a,int *b,int *c){
	int temp;
	temp = *a;
	*a=*b;
	*b=*c;
	*c=temp;
}