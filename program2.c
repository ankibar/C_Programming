// construct binary tree from postfix expression and also evaluate it

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxsize 50
struct node
{
    char data ;
    struct node * left ;
    struct node * right ;
};

typedef struct node * Node ;

typedef struct
{
    Node numlist[maxsize];
    int tos ;
}stk ;

void push(stk * ptr ,Node element)
{
    if(ptr->tos!=maxsize-1)
    {
        (ptr->tos)++ ;
        ptr->numlist[ptr->tos]=element ;
    }
}

Node pop(stk * ptr)
{
    if(ptr->tos!=-1)
    {
        Node element = ptr->numlist[ptr->tos];
        (ptr->tos)-- ;
        return element ;
    }
}

Node construct(char exp[maxsize])
{
    int i ;
    int length=strlen(exp);
    Node newnode ;
    stk s1 ;
    stk * ptr = &s1 ;
    s1.tos = -1 ;
    for(i=0;i<=length-1;i++)
    {

        if(isdigit(exp[i])>0)
        {

            newnode=(Node)malloc(sizeof(struct node));
            newnode->data = exp[i];
            newnode->left=NULL ;
            newnode->right=NULL ;
            push(ptr,newnode);
        }
        else
        {
            newnode = (Node)malloc(sizeof(struct node));
            newnode->data = exp[i];
            Node right = pop(ptr);
            Node left  = pop(ptr);
            newnode->right=right ;
            newnode->left = left;
            push(ptr,newnode);

        }
    }
    Node root = pop(ptr);
    return root ;


}

void inorder(Node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }

}

int evaluate(Node root)
{
    if(root==NULL)
    {
        return 0 ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return ((int)(root->data)-48);
    }
    int lval = evaluate(root->left);
    int rval = evaluate(root->right);

    if(root->data=='+')
    {
        return lval+rval ;
    }
    if(root->data=='-')
    {
        return lval-rval ;
    }
    if(root->data=='*')
    {
        return lval*rval ;
    }
    if(root->data=='/')
    {
        return lval/rval ;
    }
}
int main()
{
    char exp[maxsize];
    printf("Enter the postfix expression");
    scanf("%s",exp);
    int length = strlen(exp);
    Node root = construct(exp);
    printf("Expression tree in inorder:\n");
    inorder(root);
    printf("Value:%d\n",evaluate(root));
    return 0 ;


}


