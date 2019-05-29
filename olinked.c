#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
}*NODE;
NODE get_node(NODE temp)
{
	temp = (int*)malloc(sizeof(struct node));
	return temp;
}
void insert_front(NODE head, int x)
{
	NODE new = get_node(new);
	new->data = x;
 	new->link = NULL;
 	
}
void insert_rear
{
			
}
int main()
{
	int choice
	do
	{
		printf("Enter choice:\n1.\n2");
		scanf("%d",choice);	
	}while(choice != 4)
	
}