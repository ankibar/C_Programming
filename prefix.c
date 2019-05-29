#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

/*void reverse(char a[])
{
    int i =0;
    int count = 0;
    while(a[i] != '\0')
    {
      count++;           
    }
    for(int i =0; i<=count; i++)
    {
        char temp = a[i];
        a[i] = a[count - i];
        a[count-i] = temp; 
    }
    for(int i =0; i<=count; i++)
    {
        if(a[i] == ')')
            a[i] = '(';
        else if(a[i] == '(')
            a[i] = ')';   
    }
    
}*/

int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    strrev(exp);
    e = exp;
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i] == '(')
            exp[i] = ')';
        else if(exp[i] == ')')
            exp[i] = '(';
    }
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}