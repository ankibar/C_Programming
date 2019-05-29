#include<stdbool.h>
#include "stack.h"
void balanced(char a[]){
	int n;
	int temp;
	n = sizeof(*a)/ sizeof(char);
	int i;
	for(i=0;i<n;i++){
		if(a[i] == '(')
			push(1);
		else if(a[i] == ')')
			temp = pop();
	}
}
int main()
{
	char x[20];
	printf("Enter expression");
	scanf("%s",x);
	balanced(x);
	if(isEmpty){
		printf("balanced");
	}
	else
		printf("not");
	return 0;
}