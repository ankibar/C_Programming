ww#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}*Node;

typedef struct stack{
	int top;
	Node arr[];
}*stack;

Node getnode(int x){
	Node temp = (Node)malloc(sizeof(struct node));
	temp->lchild = NULL;
	temp->rchild = NULL;
	temp->data = x;
	return temp;
}

Node search(Node root, int x){
	if(root == NULL || root->data == x)
		return root;
	root->rchild = search(root->rchild, x);
	root->lchild = search(root->lchild, x);
}
void push(stack s, Node x){
	if(s->top == MAX-1){
		printf("Stack full");
		return;
	}
	else{
		s->arr[++(s->top)] = x;
	}
}
Node pop(stack s){
	if(s->top == -1){
		printf("Stack empty");
		return NULL;
	}
	else{
		return s->arr[(s->top)--];
	}
}

void iterative_inorder(Node root){
	stack s = (stack)malloc(sizeof(struct stack));
	s->top = -1;
	while(1){
		if(root != NULL){
			push(s, root);
			root = root->lchild;
		}
		else{
			if(s->top = -1)
				break;
			pop(s);
			printf("%d",root->data);
			root = root->rchild;
		}
	}
}	
void recursive_inorder(Node root){
	if(root == NULL)
		return;
	else{
		recursive_inorder(root->lchild);
		printf("%d ", root->data);
		recursive_inorder(root->rchild);
	}
}
Node inorder(Node root, int x){
	Node temp = getnode(0);
	Node succ = getnode(0);
	temp = search(root, x);
	if(root == NULL)
		return NULL;
	while(root != NULL){
		if(temp->data < root->data){
			succ = root;
			root = root->lchild;
		}
		else if(temp->data > root->data){
			root = root->rchild;
		}
		else
			break;
	}
	return succ;	
}
int main(){
	Node temp = getnode(0);
	Node root = getnode(10);	
	root->rchild = getnode(15);
	root->lchild = getnode(6);
	(root->lchild)->rchild = getnode(9);
	(root->lchild)->lchild = getnode(4);
	((root->lchild)->lchild)->rchild = getnode(5);
	(root->rchild)->lchild = getnode(12);
	(root->rchild)->rchild = getnode(17);
	recursive_inorder(root);
	printf("\n");
	iterative_inorder(root);
	temp = inorder(root, 9);
	printf("\n%d\n", temp->data);	
	return 0;
}