#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top = -1;
int stack[MAX];

void push(int x)
{
	if(top == MAX - 1)
		printf("Stack Overflow");
	else 
		top++;
		stack[top] = x;
}

void pop()
{
	if(top == -1)
		printf("Stack Underflow");
	else
	printf("Popped element is %d", stack[top]);
	top--;
}

void display()
{
	if(top == -1)
		printf("Stack empty");
	else
		for(int i = top; i>= 0; i--)
			printf("%d",stack[i]);
}
	
int main()
{
	int choice,m;
	printf("Enter one of the following chocies:");
	printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit\n");
	do
	{
		printf("\nEnter choice:");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1 : {
				 printf("Enter element to be pushed :");
				 scanf("%d",&m);
				 push(m);
				 break;
				}
				
		
		case 2 : {pop();
				break;}
		
		case 3 : {display();
				 break;}
		
		case 4 : {exit(0);
					break;}
		
		default: printf("Wrong choice");
		
	}
	}while(choice != 4);
	return 0;
}