#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int arr[MAX];
int r,f = -1;
void enq(int x){
	if(r == -1 && f == -1){
		arr[++r] = x;
		f++;
	}
	else{
		arr[++r] = x;
	}
}
int deq(){
	if(r == -1 && f == -1){
		printf("Queue empty");
		return 0;
	}
	else
		return arr[f++];
}
void display(){
	for(int i =f+2; i<=r; i++){
		printf("%d", arr[i]);
	}
}