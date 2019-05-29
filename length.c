#include<stdio.h>
int length(char a[],static int i)
{
	i=0;
	static int count = 0;
	if(a[i] = '\0')
		return 0;
	else
		count++;
	
	return length(a[i],i+1);

}
int main()
{
	char a[50],n;
	printf("Enter the string you want to findd the length of");
	scanf("%s", &a);
	length(a,0);
}