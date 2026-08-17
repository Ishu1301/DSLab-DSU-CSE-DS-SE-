#include<stdio.h>
int mostRepeatedNumber(int*,int);
int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Most repeated number is %d",mostRepeatedNumber(arr,n));
	return 0;
}
int mostRepeatedNumber(int* arr,int arrSize){
	int count=0,high=0,most;
	for(int i=0;i<arrSize;i++){
		count=0;
		for(int j=0;j<arrSize;j++){
			if(arr[i]==arr[j]){
				count++;
				if(count>high){
					high=count;
					most=arr[i];
				}
			}
		}
	}
	return most;
}
