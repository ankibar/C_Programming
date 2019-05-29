#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
int main()
{
	struct node *n1;
	n1 = (struct node*)malloc(sizeof(struct node));
	n1->data = 1;
	struct node *n2;
	n1->link = (struct node*)malloc(sizeof(struct node));
	printf("%p\n",n2);
	printf("%p\n",&n2);
	n1->link = n2;
	printf("%p\n",(n1->link));
}
