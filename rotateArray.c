#include<stdio.h>
void flipArray(int*,int,int);
int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array: ");
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Original array: \n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	int pos;
	printf("\nEnter the number of positions to flip the array by: ");
	scanf("%d",&pos);
	pos = pos-1;
	flipArray(arr,n,pos);
	
	printf("\nRotated array: \n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
void flipArray(int* arr,int arrSize,int pos){
	int l=0, r=pos;
	while(l<r){
		int temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		l++;
		r--;
	}
}
