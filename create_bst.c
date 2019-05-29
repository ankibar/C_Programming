#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}Node;

Node* getNode(Node* new, int x)
{
	new = (Node*)malloc(sizeof(Node));
	new->data = x;
	new->rchild = NULL;
	new->lchild = NULL;
	return new;
}

Node* create(Node* root, int data)	
{
	if(root == NULL)
		{
			root = getNode(root,data);
			return root;
		}

	if(root->data<data)
		root->rchild = create(root->rchild, data);
	else if(root->data>data)
		root->lchild = create(root->lchild, data);
}

void inorder(Node* root)
{
	if(root	)
	{
		inorder(root->lchild);
		printf("%d  ", root->data);
		inorder(root->rchild);
	}
}
int main()
{
	Node* root;
	root = create(root,5);
	root = create(root,6);
	root = create(root,4);
	root = create(root,9);
	root = create(root,8);
	root = create(root,1);
	root = create(root,13);
	inorder(root);
	return 0;

}