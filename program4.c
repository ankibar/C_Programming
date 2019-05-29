//program to print ancestors of a given node in a binary tree

#include<stdio.h>
struct node
{
    int data ;
    struct node * left ;
    struct node * right ;
};

typedef struct node * Node ;

Node create()
{
    Node x ;
    int value ;
    printf("Enter -1 to quit or Enter other value\n");
    scanf("%d",&value);
    if(value==-1)
    {
        return NULL;
    }
    x= (Node)malloc(sizeof(struct node));
    x->data=value;
    printf("Enter left child of %d\n",x->data);
    x->left = create();
    printf("Enter right child of %d\n",x->data);
    x->right = create();
    return x;
}

int ancestor(Node root,int value)
{
    if(root==NULL)
    {
        return 0 ;
    }
    if(root->data==value)
    {
        return 1 ;
    }
    if(ancestor(root->left,value)==1||ancestor(root->right,value)==1)
    {
        printf("%d ",root->data);
        return 1 ;
    }
    return 0 ;
}

int main()
{
    Node root = create();
    int value ;
    printf("Enter value to print ancestors of\n");
    scanf("%d",&value);
    ancestor(root,value);
    return 0;
}
