#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int l, int m, int r){
	int i = 0,j = 0,k = 0;
	int n1 = m-l+1;
	int n2 = r-m;
	int* L = (int*)malloc(n1*sizeof(int)); 
	int* R = (int*)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
		L[i] = a[l+i];
	for(j=0;j<n2;j++)
		R[j] = a[m+1+j];

	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}k++;
	}

	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergesort(int a[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
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
	mergesort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf(" ");
	}
	return 0;	
}	