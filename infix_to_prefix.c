#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
typedef struct
{
	int data[MAX];
	int top;
}stack;
void push(stack *s,char x)
{
	s->top++;
	s->data[s->top] = x; 
}
char pop(stack *s)
{
	int item = s->data[s->top];
	s->top--;
	return item;
}
void reverse(char s1[], char s2[])
{
	int i,l;
	l = strlen(s1);
	for(i = 0;i<l;i++)
	{
		if(s1[l-i-2] = '(')
			s2[i] = ')';
		
		else if(s1[l-i-1] = ')')
			s2[i] = '(';

		else
			s2[i] = s1[l-i-1]; 
	}

}
int weight(char x)
{
	switch(x)
	{
		case '(': return -1;
					break;
		case '-': return 0;
					break;
		case '+': return 0;
					break;
		case '/': return 1;
					break;
		case '*': return 1;
					break;
		case '^': return 2;
					break;
	}
}
void display(stack *s)
{
	int i;
	printf("The o/p is:");
	for(i = s->top;i>=0;i++)
	{
		printf("%c",s->data[i]);
	}
}
int main()
{
	char exp[MAX],exp1[MAX],x,y,a;
	int i ;
	stack o,s;
	o.top = -1;
	s.top = -1;
	printf("Enter the expression:\n");
	scanf("%s", exp);
	reverse(exp,exp1);
	for(i=0;i<strlen(exp1);i++)
	{
		x = exp1[i];
		if(isalpha(x) != 0)
			push(&o,x);
		else if(x == '(')
			push(&s,x);
		else if(x == ')')
		{
			y = pop(&s);
			while(y != '(')
			{
				push(&o,y);
				y = pop(&s);
			}
		}
		else 
		{
			if(s.top != -1)
			{
				y = pop(&s);
				if(weight(x)>= weight(y))
				{
					push(&s, y);
					push(&s, x);
				}
				else
				{
					while(weight(x)<weight(y))
					{
						push(&o, y);
						y = pop(&s);
					}
					push(&s,y);
					push(&s,x);
				}
			}
			else
				push(&s,x);
		}
	}
	while(s.top != -1)
	{
		y = pop(&s);
		push(&o,y);
	}
	display(&o);
	return 0; 

}
