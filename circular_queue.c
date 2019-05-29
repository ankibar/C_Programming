#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
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
	else if((r+1) % MAX == f)
	{
		printf("Queue full");
		exit(0);
	}
	else 
	{
		r = (r+1) % MAX;
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
		f = (f+1) % MAX;
	}
}
void display()
{
	if(isEmpty())
		printf("Nothing to display");
	else 
	{
		int count = (r+MAX-f)%MAX +1;
		for(int i = 0; i < count; i++)
		{
			int index = (f + i) % MAX;
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
	