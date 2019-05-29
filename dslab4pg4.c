#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int arr[],int *top,int c)
{
    if((*top)<99)
    {
        (*top)++;
        arr[*top]=c;

    }

}
void pop(int *top)
{

    if((*top)!=-1)
    {


        (*top)--;
    }

}
int main()
{
    int n ;
    int stack[100];
    int i ;
    int top=-1;
    int ele ;
    int k ;
    int pos ;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&ele);
        push(stack,&top,ele);

    }
    printf("elements to be deleted ?\n");
    scanf("%d",&k);
    while(k>0)
    {
        for(i=0;i<=n-2;i++)
        {
            if(stack[i]<stack[i+1])
            {
                pos = i;
                break ;

            }
        }
        for(i=pos;i<=n-1;i++)
        {
            pop(&top);


        }
        for(i=pos+1;i<=n-1;i++)
        {
            push(stack,&top,stack[i]);
        }
        k--;
        n--;
    }
    printf("Array after deleting elements :\n");
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    return 0 ;

}
