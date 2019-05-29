//finding the depth, height and number of leaf nodes in a tree
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

int present(Node* root, int x)
{
	/*
	if(root->data == x)
		return 1;
	else
		return 0;
	return(present(root->right,x)+present(root->left,x));
	
	static int sum = 0;
	if(root->data == x)
		return 1 + root(right);
	
	
	if(present(root->right,x))
		sum = sum + 1;
		return sum;
	else if(present(root->right,x))
		sum = sum + 1;
		return sum;

	return sum;
	*/
	if(present(root->right))
	return 1;
}

int depth(Node* root, int x)
{
	Node* temp = getNode(temp);
	if(root == NULL || present(root, x) == 0)
		return 0;
	if(present(root, x) > 0)
		return 1;
	//return((root->left)->data == x + (root->right)->data == x)
	return depth(root->right, x) + depth(root->left, x);
}

int main()
{	
	Node* root = newnode(1); 
	root->left        = newnode(2); 
	root->right       = newnode(3); 
	root->right->left = newnode(9); 
	root->left->left  = newnode(4); 
	root->left->right = newnode(5); 
	root->left->left->left  = newnode(7);
	printf("%d",present(root,9));
	return 0;

}
