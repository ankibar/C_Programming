#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node* link;
}*Node;
Node getnode(int x){
	Node temp = (Node)malloc(sizeof(struct node));
	temp->link = NULL;
}
Node insertr(Node head, int x){
	Node new = getnode(x);
	Node temp = getnode(0);
	temp = head->link;
	if(head->link == NULL){
		head->link = new;
		new->link = head;
	}
	else{
		while(temp->link != head){
			temp = temp->link;
		}
		temp->link = new;
		new->link = head;
	}
}
Node insertf(Node head, int x){
	Node new = getnode(x);
	Node temp = getnode(0);
	temp = head->link;
	if(head->link == NULL){
		head->link = new;
		new->link = head;
	}
	else{
		new->link = head->link;
		head->link = new;
	}
}
Node deletef(Node head){
	Node temp = getnode(0);
	temp = head->link;
	if(head->link == NULL){
		printf("Already empty");
		return NULL;
	}
	else{
		temp = head->link;
		head->link = (head->link)->link;
		free(temp);
	}
}
Node deleter(Node head){
	Node temp = getnode(0);
	temp = head->link;
	if(head->link == NULL){
		printf("Already empty");
		return NULL;
	}
	else{
		while((temp->link)->link != head){
			temp = temp->link;
		}
		temp->link = head;
	}
}
Node display(Node head){
	Node temp = getnode(0);
	temp = head->link;
	while(temp->link != head){
		printf("%d", (temp->data));
	}
}