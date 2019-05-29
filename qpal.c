#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct q
{
	int arr[MAX];
	int r;
	int f;
}*Q;
void enqueue(Q q1, int x)
{
	q1 = malloc(sizeof(struct q));
	if(q1->r = MAX - 1)
	{
		  printf("Queue full");
		  return;
	}
	else
		q1->arr[++(q1->r)] = x;
} 
int dequeue(Q q1)
{
	int temp;
	q1 = malloc(sizeof(struct q));
	if(q1->r == -1)
	{
		printf("Queue empty");
		return 0;
	}
	else
		temp = q1->f;
		(q1->f)++;
		return temp;
}
void display(Q q1)
{
	int i;
	q1 = malloc(sizeof(struct q));
	for(i=q1->r;i>=q1->f;i--)
	{
		printf("%d",q1->arr[i]);
		printf(" ");
	}

}
int main()
{
	Q q1;
	q1 = malloc(sizeof(struct q));
	q1->r = -1;
	q1->f = -1;
	int choice,x,y;
	printf("Chooose :\n1.Enqueue\n2.Dequeue\n3.Dislay\n4.Exit");
	do
	{
		printf("Enter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			printf("Enter number to enqqueue");
			scanf("%d",&x);
			enqueue(q1, x);
			break;
			
			case 2: 
			y = dequeue(q1);
			printf("Popped element is %d",y);
			break;
			
			case 3: 
			display(q1);
		}
	}while(choice != 4);

	return 0;

}