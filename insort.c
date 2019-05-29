#include<stdio.h>
void insert(int a[], int n){
	int i=0,j=1;
	int temp =0;
	for(i=1;i<n;i++){
		j = i-1;
		temp = a[i];
		while(j>=0 && a[j]>temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
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
	insert(a,n);
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;	
}