#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

typedef struct RAISE
{
	char name[100];
	int money;
	struct RAISE *next;
}INFO;

typedef struct Prime
{
	int data;
	bool isprime;
	struct Prime *next;
	
}PRIME;



void challenge_1();
INFO *create_element();
int add_info();
void print_info();
void challenge_2();
PRIME *generate_number();
PRIME *create_num();
void prime_print();
void prime_number();



int main(){
	// challenge_1();
	challenge_2();

}

void challenge_2(){
	PRIME *head=NULL;
	int num=0;
	printf("Input number: ");
	scanf("%d",&num);

	head = generate_number(num);
	prime_number(&head,num);
	prime_print(head);

}

PRIME *generate_number(int num){
	PRIME *head=NULL;
	PRIME *temp=NULL;
	int root=0;


	for (int i = 2; i < num; ++i)
	{
		if(head==NULL){
			head = create_num();
			head->data=i;
			head->isprime=true;
			head->next=NULL;
			temp = head;			
		}
		else{
			temp->next=create_num();
			temp=temp->next;
			temp->data=i;
			temp->isprime=true;
			temp->next=NULL;
		}

	}

	return head;

}

PRIME *create_num(){
	PRIME *element = (PRIME*)malloc(sizeof(PRIME));
	element->next=NULL;
	return element;
}

void prime_number(PRIME **head,int num){
	PRIME *temp=*head;
	PRIME *now_point=NULL;
	int root=0;

	for (root = 2; (root*root) <= (num); ++root);
	


	for (int i = 2; i <= root; ++i)
	{

		if(temp->isprime==true){
			now_point=temp->next;
			if(now_point==NULL) return;
			// printf("==%d==%d\n",i,now_point->data );
			while(now_point!=NULL)
			{	
				if ((now_point->data)%temp->data==0&&now_point->isprime==true)
				{
				// printf("%d\n",now_point->data );
					now_point->isprime=false;
				}
				now_point=now_point->next;
			}
		}
		temp=temp->next;
	}

}

void prime_print(PRIME *node){
	PRIME *temp=node;
	int line=0;
	char not_prime='X';
	while(temp!=NULL){
		if(line%5==0){
			printf("\n");
		}
		if(temp->isprime==true){
		printf("%5d",temp->data );
		}
		else{
		printf("%5c",not_prime);
		}
		temp=temp->next;
		line++;
	}
	printf("\n");
}

void challenge_1(){
		INFO *head=NULL;

		while(add_info(&head));



}

	INFO *create_element(){
		INFO *element = (INFO*)malloc(sizeof(INFO));
		element->next=NULL;
		return element;
	}

	int add_info(INFO **node){
		static int count=0;
		static int sum_money=0;
		char name[100]={0,};
		int money=0;
		INFO *temp=NULL;
		INFO *creat_node=NULL;
		temp = *node;
		printf("name : ");
		scanf("%s",name);
		if(strcmp(name,"end")!=0){
			printf("raise : ");
			scanf("%d",&money);
		// scanf("%s",creat_node->name);
		// scanf("%d",&creat_node->money);

			creat_node=create_element();
			strcpy(creat_node->name,name);
			creat_node->money=money;
			if(*node==NULL){
				*node = creat_node;
			}
			else{
			// printf("asdasd\n");
				while(temp->next!=NULL){
					temp=temp->next;
				}

				temp->next=creat_node;
				creat_node->next=NULL;
			}
			sum_money+=creat_node->money;
			count++;
		}
		else{
			print_info(*node);
			printf("raise average: %d\n",sum_money/count);
			return 0;
		}
		return count;
	}

	void print_info(INFO *node){
		INFO *temp = node;
		for (int i = 1; temp!=NULL; ++i)
		{
			printf("%d. %3s  %3d\n",i,temp->name,temp->money);
			temp=temp->next;
		}

	}