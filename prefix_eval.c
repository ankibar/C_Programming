#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<libm.a>
#define MAX 30
typedef struct stack
{
	int data[MAX];
	int top;
}stack;
int evaluate(char x,int op1, int op2)
{
	if(x == '+')
		return (op1+op2);
	if(x == '-')
		return (op1-op2);
	if(x == '/')
		return (op1/op2);
	if(x == '*')
		return (op1*op2);
	if(x == '^')
		return (pow(op1,op2));
	if(x == '%')
		return (op1%op2);
}
void push(stack *s,int x)
{
	s->top++;
	s->data[s->top] = x; 
}
int pop(stack *s)
{
	int item = s->data[s->top];
	s->top--;
	return item;
}
int main()
{
	stack s1;
	s1.top = -1;
	char exp[MAX];
	int res;
	int i,length,val1,val2;
	printf("Enter expression to be evaluated");
	scanf("%s", exp);
	length = strlen(exp);
	for(i = length-1;i>0;i++)
	{
		if(isdigit(exp[i]) > 0)
			push(&s1, (int)(exp[i] - '0'));
		else
		{
			val1 = pop(&s1);
			val2 = pop(&s1);
			res = evaluate(exp[i], val1, val2);
			push(&s1, res); 
		}
	}
	printf("The result is %d", pop(&s1));
	return 0;
}
