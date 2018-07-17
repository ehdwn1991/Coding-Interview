#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
typedef struct link
{
	int data;
	struct link *left;
	struct link *right;

}Node;

void Deletion();
void node_remove();
void print2DUtil();
void print2D();
int height();
int Insertion();
int isEmpty();
Node *add();
Node *find_node();
void printInorder();
void printpostorder();
void printPreorder();
int main(){
	Node *temp;
	Node *root=NULL;
	int arr[11]={35,18,68,3,7,26,12,22,30,23,99};
	for (int i = 0; i < 11; ++i)
	{
		Insertion(&root,arr[i]);
	}

	print2D(root);
	puts("");
	puts("");
	printf("전위 순회");
	printPreorder(root);
	printf("\n");
	printf("후위 순회");
	printpostorder(root);
	printf("\n");
	printf("중위 순회");
	printInorder(root);
	printf("\n");
	print2D(root);
	Deletion(&root,7);
	print2D(root);
	Deletion(&root,12);
	print2D(root);
	Deletion(&root,18);
	print2D(root);	
	Deletion(&root,35);
	print2D(root);
}


int isEmpty(Node **head){
	if(*head==NULL){
		printf("in isEmpty\n");
		return 0;
	}
	else
		return 1;
}

Node *add(int data){
	Node *add_element =(Node*)malloc(sizeof(Node));
	add_element->data = data;
	add_element->left = NULL;
	add_element->right = NULL;
	return add_element;
}

void node_remove(Node *node){
	printf("Delete : %d\n",node->data);
	free(node);
}


void Deletion(Node **node, int data){
	Node *loc = *node;
	Node *parent_node =NULL;
	Node *right_node=NULL;
	Node *right_sub =NULL;
	Node *child=NULL;
	Node *left_most=NULL;
	while(loc!=NULL){
			if(loc->data == data){
				break;
			}
			if(loc->data > data){
				parent_node = loc;
				loc= loc->left;
			}
			else{
				parent_node = loc;
				loc= loc->right;
			}

		}

	// 단일 노드 삭제
	if((loc->left)==NULL && (loc->right)==NULL){

		if(parent_node->data >loc ->data){
			parent_node -> left =NULL;
		}
		else{
			parent_node->right=NULL;
		}

		node_remove(loc);
	}
	// 두개의 서브트리 존재
	else if((loc->left)!=NULL && (loc->right)!=NULL){
		right_sub = loc->right;
		while(right_sub->left!=NULL){
			left_most = right_sub;
			right_sub = right_sub->left;
		}

		if(right_sub->right!=NULL){
			loc -> data= right_sub->data;
			right_node = right_sub->right;
			right_sub->data = right_node->data;
			right_sub->right = NULL;
			node_remove(right_node);

			left_most->left=right_sub->right;
		}
		else{
			loc->data = right_sub->data;
			node_remove(right_sub);
		}
	}
	// 한개의 서브트리 존재
	else{
		if(loc->left!=NULL){
			child = loc->left;
		}
		else{
			child = loc->right;
		}


		if(parent_node->data >loc->data){

			parent_node->left = child;

		}
		else{
			parent_node->right = child;
		}
		node_remove(loc);

	}

}

int Insertion(Node **element,int data){
	if(isEmpty(element)==0){
		//add head
		printf("isEmpty\n");
		*element= add(data);
	}

	else{
		Node *loc =find_node(*element,data);

		if(loc->data > data){
			loc->left = add(data);
		}
		else{
			loc->right = add(data);
		}

	}
	return 0;
}

// Node
Node *find_node(Node *list, int data){
	Node *point=list;
	Node *prev_node=NULL;
	while(point!=NULL){
		if(point->data > data){
			prev_node = point;
			point= point->left;
		}
		else{
			prev_node = point;
			point= point->right;
		}
		
	}
	return prev_node;
}

void printInorder(Node* node)
{
	if (node == NULL) return;
	printInorder(node->left);
	printf("%d ",node->data );
	printInorder(node->right);
}
void printPreorder(Node* node)
{
	if (node == NULL) return;
	printf("%d ",node->data );
	printInorder(node->left);
	printInorder(node->right);
}
void printpostorder(Node* node)
{
	if (node == NULL) return;
	printInorder(node->left);
	printInorder(node->right);
	printf("%d ",node->data );
}


int height(Node* node)
{
	if (node==NULL)
		return 0;
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return(lheight+1);
		else return(rheight+1);
	}
}




void print2DUtil(Node *root, int space)
{
    // Base case
	if (root == NULL)
		return;

    // Increase distance between levels
	space += COUNT;

    // Process right child first
	print2DUtil(root->right, space);

    // Print current node after space
    // count
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

    // Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
   // Pass initial space count as 0
	print2DUtil(root, 0);
}