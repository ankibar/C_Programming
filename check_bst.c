#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}Node;
Node* newNode(int x)
{
	Node* new = (Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->rchild = NULL;
	new->lchild = NULL;
}
int check(Node* root)
{
	if(root == NULL)
	{
		return 1;
	}
	if(root->data > (root->lchild)->data)
	{
		return 1;
	}
	else if(root->data < (root->rchild)->data)
	{
		return 1;
	}
	else return 0;
}

Node* create(Node* root, int x)
{
	if(root == NULL)
	{
		root = getnode(root);
		root->data = x;
	}
	else if(root->lchild)
	{
		Node* new = getnode(new);
		new->data = x;	
	}
	else if(root->rchild)
	{
		Node* new = getnode(new);
		new->data = x;
	}

	reuturn root;
}

int main()
{
	Node* root;
	int choice ;
	//creatng a binary tree to check

}