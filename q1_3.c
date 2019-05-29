#include <stdio.h>
#include <stdlib.h>
#include "q.h"
// typedef struct bst
// {
// 	int data;
// 	struct bst *left;
// 	struct bst *right;
// }bst;
bst *createroot()
{
	bst *temp=(bst*)malloc(sizeof(bst));
	temp->left=temp->right=NULL;
	temp->data=-100;
}
bst* minVal(bst *root)
{
	bst* temp=root;
	while(temp->left)
		temp=temp->left;
	return temp;
}
bst* delete(bst* root, int item)
{
	if(root==NULL)
		return root;
	if(item<root->data)
		root->left=delete(root->left,item);
	else if(item>root->data)
		root->right=delete(root->right,item);
	else
	{
		if(root->left==NULL)
		{
			bst* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			bst* temp=root->right;
			free(root);
			return temp;
		}
		bst* temp=minVal(root->right);
		root->data=temp->data;
		// root->temp->data;
		root->right=delete(root->right,temp->data);
	}
	return root;
}
void LevelOrder(bst *root)
{
	bst* temp;
	queue q;
	init(&q);
	if(!root)
		return;
	enq(&q,root);
	while(!emptyqueue(&q))
	{
		temp=deq(&q);
		printf("%d\t",temp->data);

		if(temp->left)
			enq(&q,temp->left);
		if (temp->right)
			enq(&q,temp->right);
	}
}

bst* insert(bst *root,int x)
{
	if(root == NULL)
	{
		bst *temp=createroot();
		temp->data=x;
		root=temp;
		return temp;
	}

	if(x>root->data)
		root->right=insert(root->right,x);
	else if(x<root->data)
		root->left=insert(root->left,x);

	else
		printf("value repeated\n");
	
	return root;
    
}
bst *search_successor(bst *root,int ele)
{
	if(root->data==ele)
		return root;
	else if(ele<root->data)
		return search_successor(root->left,ele);
	else
		return search_successor(root->right,ele);
}
int insuc_post(bst *root)
{
	if(root && root->left)
	{	
		return insuc_post(root->left);
	}
	return root->data;
}
void InOrderR(bst *root)
{
	if(root)
	{
		InOrderR(root->left);
		printf("%d\t",root->data );
		InOrderR(root->right);
	}
	return;
}
int main()
{
	bst *tree=NULL;
	int choice=-1,n;

	while(1)
	{
		printf("enter ur choice\n1)Instert 2)delete 3)display(Level Order) 4)Inorder successor");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
					scanf("%d",&n);
					tree=insert(tree,n);
					break;
			case 2: scanf("%d",&n);
					delete(tree,n);
					break;
			case 3: LevelOrder(tree);
					break;
			case 4: scanf("%d",&n);
					bst *root=search_successor(tree,n);
					printf("%d",insuc_post(root->right));
					break;
			default : exit(0);

		}
	}
}