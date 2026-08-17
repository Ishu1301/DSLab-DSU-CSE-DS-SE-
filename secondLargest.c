#include<stdio.h>
int secondLargest(int*,int);
int main(){
	int n;
	printf("Enter number of elements in an array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements of the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Second largest element is = %d",secondLargest(arr,n));
}
int secondLargest(int* arr, int arrSize){
	int first, second;
	first = arr[0];
	second = arr[1];
	if(second>first){
		int temp = first;
		first = second;
		second = temp;
	}
	for(int i=2;i<arrSize;i++){
		if(arr[i]>=first){
			second = first;
			first = arr[i];
		}
		if(arr[i]>=second && arr[i]<first){
			second = arr[i];
		}
	}
	return second;
}
