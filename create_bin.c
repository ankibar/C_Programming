#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}Node;

Node* getNode(Node* new)
{
	new = (Node*)malloc(sizeof(Node));
	new->data = 0;
	new->rchild = NULL;
	new->lchild = NULL;
	return new;
}

Node* create_bin(Node* root)
{
	int x,y,z;
	printf("Enter number");
	scanf("%d",&x);
	root->data = x;
	
	printf("Enter lchild");
	scanf("%d", &y);
	if(y == -1)
		return NULL;
	else
		(root->lchild)->data = y;
		root->rchild = create_bin(root->lchild);
	
	printf("Enter rchild");
	scanf("%d", &((root->rchild)->data));
	if(z == -1)
		return NULL;
		else
			(root->rchild)->data = z;
			root->lchild = create_bin(root->rchild);
	
	return root;
}
void inorder(Node* root)
{
	if(root)
	{
		inorder(root->lchild);
		printf("%d  ", root->data);
		inorder(root->rchild);
	}
}
int main()
{
	Node* root = getNode(root);	
	create_bin(root);
	inorder(root);
	return 0;
}