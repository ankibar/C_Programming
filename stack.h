#include<stdio.h>
#include<stdlib.h>
#define MAX 50
/*
typedef struct stack{
	int top;
	int arr[MAX];
}stack;

void push(stack s, int x){
	if(s.top == MAX){
		printf("stack overflow\n");
		return;
	}
	else
		s.arr[++(s.top)] = x;
}
int pop(stack s){
	if(s.top == -1){
		printf("stack underflow\n");
		return 0;
	}
	else
		return s.arr[(s.top)--];
}
void display(stack s){
	int i = s.top;
	while(i>=0){
		printf("%d", s.arr[i]);
		i--;
	}
}*/
int top = -1;
int arr[MAX];
void push(int x){
	if(top == MAX){
		printf("Stack Overflow");
		return;
	}
	else
		arr[++top] = x;
}
int pop(){
	if(top == -1){
		printf("Stack Underflow");
		return 0;
	}
	else
		return arr[top--];
}
void display(){
	if(top == -1){
		printf("Stack Empty\n");
	}
	else
		for(int i=0; i<=top; i++){
			printf("%d", arr[i]);
		}
}
bool isEmpty(){
	if(top == -1)
		return true;
	else 
		return false;
}