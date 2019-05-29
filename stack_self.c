#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
char item;
#define MAX 50
char arr[MAX];

void push(char x)
{
	if(top == MAX - 1)
	{
		printf("Stack overflow");
		exit(0);
	}

	arr[top] = x;
	top++; 
}

char pop()
{
	if(top < -1)
	{
		printf("Stack underflow");
		exit(0);
	}
	if(arr[top] == '(' || arr[top] == ')')
	{
		item = arr[top-1];
		
	}
	else
		{item = arr[top];} 
	top--;
	return item;
}

void display()
{
	for(int i=top;i>=0;i--)
	{
		printf("%d", arr[i]);
	}
}

int isOperand(char a)
{
	if((a <= 'z' & a >= 'a') || (a <= 'Z' & a >= 'A'))
	{
		return 1;
	}
	else return 0;
}
int isOperator(char symbol)
{
	if(symbol == '^' || symbol == '+' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	else
		return 0;
}

int precedence(char a)
{
	
	if(a == '^')
	{
		return 3;
	}

	if(a == '*' || a == '/')
	{
		return 2;
	}

	{
		return 1;
	}
	
	if(a == '+' || a == '-')
	{
		return 1;
	}
}
int isBracket(char a)
{
	if(a == '(')
	{
		return 1;
	}
	if(a == ')')
	{
		return 0;
	}
}

int main()
{
	int n=0,j=0,i=0;
	char infix[MAX];
	char postfix[MAX];
	do
	{
		for(int i=0;;i++)
		{
			scanf("%s", infix[i]);
			n++;

		}
	
	
	}while(*infix[i] != '\n');

	for(i=0;i<n;i++)
	{
		switch(isOperand(infix[i]))
		{
			case 1: postfix[j] = infix[i];
					j++;
					break;
			case 0: continue;

		}
		switch(isOperator(infix[i]))
		{
			case 1:
					while(precedence(infix[i]) < precedence(arr[top]))
					{
						pop();
					} 
					push(infix[i]);
					break;
			case 0: continue;
		}
		switch(isBracket(infix[i]))
		{
			case 1: push(infix[i]);
					break;
			case 0: 
					while(arr[top] != '(')
					{
						pop();	
					}
					break;
		}

	}
	
	for(i=0;i<n;i++)
	{
		printf("%d", postfix[i]);
		while(top>-1)
		{
			pop();
		}	
	}
	

}