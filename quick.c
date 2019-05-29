#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l-1;
	for(int j = l; j<= r; j++){
		if(a[j] <= pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[r]);
	return (i+1);
}
void quick(int a[], int l, int r){
	if(l<r){
		int pi = partition(a,l,r);
		quick(a,l,pi-1);
		quick(a,pi+1,r);
	}
}
int main(){
	int n,i;
	int a[20];
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The sorted array is");
	quick(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf(" ");
	}
	return 0;	
}	