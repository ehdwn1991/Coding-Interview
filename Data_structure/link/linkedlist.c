#include <stdio.h>
#include <stdlib.h>


typedef struct link
{
	int data;
	struct link *next;
}Node;

void showall();
int append();
int isEmpty();
Node *add();
Node *traversing();
Node *find_node();
void delete_node();
void insert_node();
int main(){
	Node *temp;
	Node *head=NULL;

	append(&head);
	append(&head);
	append(&head);
	showall(head);
	// insert_node(&head);
	// showall(head);
	// append(&head);
	// showall(head);
	delete_node(&head);
	showall(head);
}




int isEmpty(Node **head){
	if(*head==NULL){
		printf("in isEmpty\n");
		return 0;
	}
	else
		return 1;
}



Node *add(){
	Node *add_element =(Node*)malloc(sizeof(Node));
	printf("Add element : ");
	scanf("%d",&add_element->data);
	add_element->next = NULL;
	return add_element;
}



void insert_node(Node **head){
	int loc=0,data=0;
	Node *node_loc=*head;
	Node *prev_node=NULL;
	Node *temp_node = NULL;
	printf("insert location :");
	scanf("%d",&loc);
	if(loc==0){
		temp_node=add();
		temp_node ->next = node_loc;
		*head = temp_node;
	}

	else{
		for (int i = 0; i < loc; ++i)
		{
			prev_node = node_loc;
			if(i==loc-1){
				temp_node = add();
				temp_node ->next = prev_node->next;
				prev_node->next = temp_node;
				break;
			}
		// printf("i[%d]:%d\n",i,node_loc->data );
			node_loc = node_loc->next;
		}
	}

}

int append(Node **element){
	Node *add_element =(Node*)malloc(sizeof(Node));
	printf("Add element : ");
	scanf("%d",&add_element->data);
	add_element->next = NULL;

	if(isEmpty(element)==0){
		//add head
		printf("isEmpty\n");
		*element= add_element;

	}
	else{
		Node *loc =traversing(*element);
		loc->next = add_element;
	}
	return 0;
}


Node *traversing(Node *list){
	Node *point=list;
	while(point!=NULL){
		if(point->next ==NULL)
			return point;
		point= point->next;
	}
	return point;
}

void delete_node(Node **list){
	int data=0;
	Node *point=*list;
	Node *prev_node=NULL;
	printf("Delete element: ");
	scanf("%d",&data);	

	if (point->data==data)
	{
		*list = point->next;
		free(point);
	}
	else{
		while(point!=NULL){
			prev_node = point;
			point= point->next;
			if(point->data ==data){
				prev_node->next = point->next;
				free(point);
				break;

			}
		}
	}

}

Node *find_node(Node *list, int data){
	Node *point=list;
	while(point!=NULL){
		if(point->data ==data)
			return point;
		point= point->next;
	}

	return NULL;
}


void showall(Node *list){
	Node *point=list;
	printf("================\n");
	while(point!=NULL){
		printf("%d\n",point->data );
		point= point->next;
	}

}