#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
int r = -1;
int f = -1;	
int q[MAX];
bool isEmpty()
{
	if(f == -1 && r == -1)
		return true;
	else 
		return false;
}
int enqueue(int x)
{
	if(isEmpty())
	{
		f=0;
		r=0;
		q[r] = x;
	}
	else if(r == MAX - 1)
	{
		printf("Queue full");
		exit(0);
	}
	else 
	{
		r++;
		q[r] = x;
	}	
}

void dequeue()
{
	if(f == -1)
	{
		printf("Queue empty");
	}
	else if(f == r)
	{
		f=-1;
		r=-1;
	}
	else
	{
		f++;
	}
}
void display()
{
	if(isEmpty())
		printf("Nothing to display");
	else 
	{
		for(int i = f; i <= r; i++)
		{
			printf("%d", q[i]);
		}
	}
}
int main()
{
	int choice,x;
	printf(" 1. Queue \n 2.Dequeue \n 3.Display \n 4.Exit");
	do
	{
		printf("Enter your choice");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter number to enqueue");
					scanf("%d",&x);
					enqueue(x);
					break;
			case 2: dequeue();
					break;
			case 3:display();
					break;
		}

	}while(choice != 4);
	return 0;

}
	