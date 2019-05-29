#include<stdio.h>
#include<stdlib.h>

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

void printLeft(Node* root)
{
	if(root == NULL)
		return;
	printLeft(root->left);
	printf("%d", root->data);
}
void printRight(Node* root)
{
	if(root == NULL)
		return;
	printf("%d", root->data);
	printRight(root->right);
}

int main()
{	
	Node* root = newnode(1); 
	root->left        = newnode(2); 
	root->right       = newnode(3); 
	root->right->left = newnode(9); 
	root->left->left  = newnode(4); 
	root->left->right = newnode(5); 
	root->left->left->left  = newnode(7);q 
 	printLeft(root);
 	printRight(root->right);
	//inorder(root);
	return 0;
}