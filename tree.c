#include<stdio.h>
#include<stdlib.h>
typdef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}Node;
/*
Node* getnode(Node* temp)
{
	temp = (Node*)malloc(sizeof(Node));
	temp->data = 0;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}
*/
Node* newNode(int x)
{
	Node* new = (Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->rchild = NULL;
	new->lchild = NULL;
}

void create(Node* root, int x)
{
	if(root == NULL)
	{
		qnewNode(x);
	}
	else if(root->lchild)
	{
		
	}
	else if(root->rchild)
	{
		Node* new = getnode(new);
		new->data = x;
	}
}
int main()
{
	int choice,x,y,z;
	Node* root = getnode(root);
	printf("Enter root value");
	scanf("%d", &x);
	root->data = x;
	do
	{
		printf("Enter 1 for entering left tree, 2 for right tree, 3 to exit");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
			printf("Enter left child of %d", &(root->data));
			root = root->lchild;
			scanf("%d",&y);
			if(y == -1)
			{
				break;
			}
			create(root, y);
			break;

			case 2: 
			printf("Enter right child of %d", &(root->data));
			root = root->rchild;
			scanf("%d",&z);
			if(z == -1)
			{
				break;
			}
			create(root, z);
			break;
				
		}
		
	}while(choice != 3);
	return 0;

}