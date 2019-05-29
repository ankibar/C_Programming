#include"stack.h"
int main(){
	char s[];
	char *e;
	char temp;
	printf("Enter postfix expression");
	scanf("%s", s);
	e = s;
	while(*e == '\0'){
		if(*e == '(')
			push(*e);
		else if(*e == ')'){
			while(*e != '('){
				temp = pop();
				printf("%c", temp);
			}
			temp = pop();
		}
		else if(precedence(*e) > precedence(arr[top])){
			push(*e);
		}
		else if(precedence(*e)<precedence(arr[top])){
			while(precedence(*e)<precedence(arr[top])){
				temp = pop();
			}
		}

	}


}