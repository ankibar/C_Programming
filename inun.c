#include<stdio.h>
#include<stdlib.h>
#include"singlecircle.h"
Node intersection(Node head1, Node head2){
	Node temp1 = getnode(0);
	Node temp2 = getnode(0);
	Node temp3 = getnode(0);
	Node head3 = getnode(0);
	temp1 = head1->link;
	temp2 = head2->link;
	temp3 = head3->link;
	int i=0,j=0;
	while(temp1->link != head1){
		while(temp2->link != head2){
			if(temp1->data == temp2->data){
				temp3->data = temp1->data;
				temp3 = temp3->link;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
	temp3->link = head3;
	return head3;
}
Node unions(Node head1, Node head2){
	Node temp1 = getnode(0);
	Node temp2 = getnode(0);
	Node temp3 = getnode(0);
	Node head3 = getnode(0);
	temp1 = head1->link;
	temp2 = head2->link;
	temp3 = head3->link;
	int i=0,j=0;
	while(temp1->link != head1){
		while(temp2->link != head2){
			if(temp1->data == temp2->data){
				temp3->data = temp1->data;
				temp3 = temp3->link;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
	temp3->link = head3;
	return head3;	
}
int main(){
	Node head1, head2;
	int choice, ele;
	printf("Choose:\n");
	printf("1. Insert1\n2. Insert2\n3. Delete1\n4. Delete2\n5. Display1\n6. Display2\n6. Display2");
	do{
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element");
					scanf("%d", &ele);
					insertr(head1, ele);
					break;
			case 2: printf("Enter element");
					scanf("%d", &ele);
					insertr(head2, ele);
					break;
			case 3: deleter(head1);
					break;
			case 4: deleter(head2);
					break;
			case 5: display(head1);
					break;
			case 6: display(head2);
					break;
		}
	}while(choice != 6);
	return 0;
}