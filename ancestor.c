#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* newnode(int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;	
}
Node* getNode(Node* new)
{
	new = (Node*)malloc(sizeof(Node));
	new->data = 0;
	new->right = NULL;
	new->left = NULL;
	return new;
}

bool ancestors(Node* root, int key)
{
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;
	if(ancestors(root->left, key) || ancestors(root->right, key))
	{	
		printf("%d",root->data);
		return true;
	}
	return false;
}
void inorder(Node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}
int main()
{	
	Node* root = newnode(1); 
	root->left        = newnode(2); 
	root->right       = newnode(3); 
	root->left->left  = newnode(4); 
	root->left->right = newnode(5); 
	root->left->left->left  = newnode(7); 
 	ancestors(root,7);
	//inorder(root);
	return 0;
}