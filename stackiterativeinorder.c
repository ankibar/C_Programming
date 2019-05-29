#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
	//stack s = (stack)malloc(sizeof(struct stack));
	stack s;
	s->top = -1;
	while(true){
		if(root != NULL){
			push(s, root);
			root = root->lchild;
		}
		else{
			if(s->top = -1)
				break;
			root = pop(s);
			printf("%d",(root->data));
			root = root->rchild;
		}
	}
}
int main(){
	Node root = getnode(10);
	root->rchild = getnode(15);
	root->lchild = getnode(6);
	(root->lchild)->rchild = getnode(9);
	(root->lchild)->lchild = getnode(4);
	((root->lchild)->lchild)->rchild = getnode(5);
	(root->rchild)->lchild = getnode(12);
	(root->rchild)->rchild = getnode(17);
	iterative_inorder(root);	
	return 0;
}