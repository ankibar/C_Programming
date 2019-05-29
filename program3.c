// program to find inorder successor of a given node in bst

#include<stdio.h>
#define maxsize 50
struct node
{
    int data ;
    struct node * left ;
    struct node * right ;
};

typedef struct node * Node ;
int value ;
int flag = 0 ;
int successor ;
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

void inorder(Node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        if(flag==1)
        {
            successor=root->data ;
            flag = 0 ;

        }
        if(root->data==value)
        {
            flag=1 ;
        }
        inorder(root->right);

    }
}
int main()
{
    Node root = create();

    int i ;
    printf("Enter value to print inorder successor\n");
    scanf("%d",&value);
    inorder(root);
    printf("%d",successor);


    return 0 ;

}
