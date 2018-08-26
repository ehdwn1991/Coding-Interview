#include <stdio.h>
#include <string.h>

void challenge_1();
void challenge_2();
void challenge_3();
char *my_token();
void input_data();
void swap();
void print_data();
void show_time();
void set_time();
void move_time();
int a,b;
int hour, min;
int main(){
	// challenge_1();
	// challenge_2();
	challenge_3();


}


void challenge_1(){

	input_data(&a,&b);
	swap();
	print_data(a,b);

}



void input_data(int *a,int *b){
	scanf("%d %d",a,b);
}

void swap(void){
	int temp;
	temp = a;
	a=b;
	b=a;

}

void print_data(int a,int b){
	printf("%d %d\n",a,b);
}

void challenge_2(){
	// printf("%.2d시 %.2d분\n",h,m);
	set_time();
	show_time();
	move_time();
	show_time();
}


void set_time(){
	printf("최초 설정 시간: ");
	scanf("%d %d",&hour,&min);
}

void show_time(){
	printf("%.2d시 %.2d분\n",hour,min);

}

void move_time(){
	int temp,h_temp,m_temp;
	printf("경과 시간 : ");
	scanf("%d",&temp);
	// printf("hour: %.2d min: %.2d\n",hour,min );
	// printf("min : %d   %d\n",min,temp );
	min+=temp;
	if(min>=60){
		h_temp = min/60;
		m_temp = min%60;
		// printf("h_temp: %d m_temp: %d\n",h_temp,m_temp );
		hour+=h_temp;
		min=m_temp;
		// printf("hour: %d min: %d\n",hour,min );
		if(hour>24){
			hour=hour-25;
		}

	}



}

void challenge_3(){
	char str[80]={0,};
	char *p;
	int i=0;
	char *tok=" ";
	printf("문장 입력: ");
	fgets(str,1024,stdin);

	while(str[i]!=10){
		i++;
	}
	str[i]='\0';

	while((p=my_token(str," ,"))!=NULL){
		if(*p!='\0')
		printf("%s\n",p );
	}

}

char *my_token(char  *p, const char *tok){
	static char *ps_loc=NULL;
	char *now_point=NULL;
	char *start_point=NULL;
	int tok_count=0;


	if (ps_loc==NULL&&start_point==NULL){
		ps_loc=p;
		start_point=p;
	}
	
	else{
		start_point = ps_loc;
	}


	if (*ps_loc=='\0')
	{
		return NULL;
	}

	while(*ps_loc!='\0'){
		for(int i=0;tok[i]!='\0';i++){
			if(*ps_loc==tok[i]){
				*ps_loc='\0';
				ps_loc++;
				return start_point;
			}
		}
		ps_loc++;

	}

	return start_point;
}