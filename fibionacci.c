//fibionacci series
#include<stdio.h>
int fib(int n)
{
	if(n==1)
		return 1;
	if(n==0)
		return 0;
	printf("%d",n);
	return(fib(n-1) + fib(n-2));
	
}

int main()
{
	int k;
	printf("Enter the number of fibionacci nos you want");
	scanf("%d", &k);
	printf("The series is %d", fib(k));
}