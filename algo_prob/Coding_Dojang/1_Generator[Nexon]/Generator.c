#include <stdio.h>
int generate();
int main(){

    int start_range,end_range;
    int n_digits=10;
    scanf("%d %d",&start_range,&end_range);
    int sum_of_generator;
    int sum_of_all,sum_of_self;
    int check_generator[5000]={0,};
    int generate_state;
    for(int i=start_range;i<=end_range;i++){
        if(i%10==0){
            n_digits*=10;
        }

            generate_state=generate(i,n_digits);
        if(check_generator[generate_state]==0){
            check_generator[generate_state-1]=1;
        
        }

    }
    printf("qwe");
    for(int q=0;q<5000;q++){
        if(check_generator[q]==0){
            printf("%d ",(q+1));
            sum_of_self+=(q+1);
        }
        
    
        }
    printf("sum_of_generator :%d \n",sum_of_self);



}


int generate(int n_times,int n_digits){
    int now_decimal=n_times,sum_of_generator;
    int digits=n_times,run=0;
    while(digits>=1){
       digits/=10;
        
       run++;
    }
    digits=1;
    while(run>0){
        
        sum_of_generator+=(now_decimal/digits);
        
        printf("n:%d\n",now_decimal/digits);
        now_decimal=now_decimal-((now_decimal/digits)*digits);
         printf("%d\n",now_decimal);   
        //printf("sum :%d n_digits :%d \n",now_decimal,digits);
        digits*=10;
        run--;
    }
    
    return sum_of_generator+=n_times;

}
