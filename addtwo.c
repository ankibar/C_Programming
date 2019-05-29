#include<stdio.h>
#include<stdlib.h>
Node add(Node h1, Node h2){
	Node h3 = getnode(0);
	Node temp1 = getnode(0);
	Node temp2 = getnode(0);
	Node temp3 = getnode(0);
	int sum = 0, carry = 0;
	temp1 = head1->link;
	temp2 = head2->link;
	while(temp1->link != NULL & temp2->link != NULL){
		sum = temp1->data + temp2->data + carry;
		carry = sum/10;
		sum = sum % 10;
		temp1 = temp1->link;
		temp2 = temp1->link;
		insert_front(head3, sum);
	}
	while(temp1->link != NULL){
		insert_front(head3, temp1->data);
	}
	while(temp2->link != NULL){
		insert_front(head3, temp2->data);
	}
	return head3;	
}
void reverse(Node head){
	Node prev = getnode(0);
	Node cur = getnode(0);
	if(head != NULL){
		prev = head;
		cur = head->next;
		head = head->next;
		prev->next = NULL;
		while(head != NULL){
			head = head->next;
			cur->next = prev;
			prev = cur;
			cur = head;
		}
		head = prev;
	}
}
void display(Node head){
	Node temp = getnode(0);	
	temp = head3->link;
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->link;
	}
}
int main(){
	char num1[50], num2[50];
	Node h1 = getnode(0);
	Node h2 = getnode(0);
	Node h3 = getnode(0);
	printf("Enter first number");
	scanf("%s", num1);
	printf("Enter second number");
	scanf("%s", num2);
	for(int i = 0;i<strlen(num1);i++){
		insert_front(h1,num1[i]-'0');
	}
	for(int i = 0;i<strlen(num2);i++){
		insert_front(h2,num1[i]-'0');
	}
	head3 = add(h1,h2);
	reverse(h3);
	display(h3);
}