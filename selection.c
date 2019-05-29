#include<stdio.h>
#include<stdlib.h>
void swap(int* arr[], int x, int y)
{
	int temp = *arr[x];
	*arr[x] = *arr[y];
	*arr[y] = temp;
}
int main()
{
	int n,i,temp;
	int *a = (int *)malloc(50 * sizeof(int));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d", a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(*a[i]>*a[j+1])
			{
				temp = j;
			}	
			
		}
		swap(&a,i,temp);
	}
	for(i=0;i<n;i++)
	{
		printf("The sorted array is %d ", *a[i]);
	}
	return 0;
}