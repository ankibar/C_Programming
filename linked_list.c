#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void insert_front(struct Node** head,int stuff)
{
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	if(*head = NULL)
	{
		*head = new;
	}
	new->data = stuff;
	new->next = *head;
	*head = new; 
}
/*void delete_front(struct Node** head)
{
	*head = 
	*head = *head->link;
}
void delete_rear(struct Node** head)
{
	temp = *head;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	while((temp->next) != NULL)
	{
		temp = temp->next;
	}
	temp = NULL;
}*/
void insert_rear(struct Node** head, int x)
{
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = *head;
	if(*head = NULL)
	{
		*head = new;
	}
	while((temp->next) != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->next =  NULL;	
}

void print(struct Node** head)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = *head;
	while(temp != NULL)
	{
		printf("%d",temp->data);
	}
	temp = temp->next;
}
int main()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head = NULL;
	int choice;
	printf("1.insert_rear \n2.insert_front \n3.delete_rear \n4.delete_front \n5.print \n6.exit");
	do
	{
		int x,y;
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter number to be inserted");
					scanf("%d", &x);
					insert_rear(&head, x);
					break;
			case 2: printf("Enter number to be inserted	");
					scanf("%d", &y);
					insert_front(&head, y);
					break;
			/*case 3: delete_rear(&head);
					break;
			case 4: delete_front(&head);
					break;*/
			case 5: print(&head);

		}
	}while(choice != 5);
return 0;
}