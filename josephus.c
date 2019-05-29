//josephus circle problem
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
}*NODE;

NODE getnode(NODE x)
{
	x = (NODE)malloc(sizeof(struct node));
	x->data = 0;
	x->link = NULL;
	return x; 
}
int survive(int n, int m)
{
	//Construct a circular linked list such that each node's data is position and 
	//use n,m accordingly after
	int count = 1,check = 1,pos_final = 0;
	
	NODE head;
	head = getnode(head);
	NODE temp;
	temp = getnode(temp);
	NODE temp2;
	temp2 = getnode(temp2);
	
	temp = head->link;

	while(count != n)
	{
		temp->data = count;
		temp = temp->link;
		count++;
	}
	temp = temp->link;
	temp->data = n;
	temp->link = head->link;

	//done creating circular linked list
	temp2 = head->link;
	while((head->link)->link != NULL)
	{
		temp2 = temp2->link;
		if(check == m-1)
		{
			//temp2->link is the mth peron after the 1st person
			temp2->link = (temp2->link)->link;	
		}
		
		check++;
		temp2 = temp2->link;
	} 

	pos_final = (head->link)->data;
	return pos_final;
}
int main()
{
	int n,m,x;
	printf("Enter no. of people in the circle: ");
	scanf("%d", &n);
	printf("Enter which person gets killed in each step: ");
	scanf("%d", &m);
	x = survive(n,m);
	printf("To survive stand at position %d from the start", x);
	return 0;
}