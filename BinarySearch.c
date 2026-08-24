#include<stdio.h>
int binarySearch(int*,int,int);
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter Sorted array(ascending): ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i>=1){
			if(arr[i]<arr[i-1]){
				printf("array is not sorted; terminating");
				return 0;
			}
		}	
	}
	printf("\nGiven array: ");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	int target=0;
	printf("\nEnter element to be found: ");
	scanf("%d",&target);
	int ans;
	ans = binarySearch(arr,n,target);
	if(ans==-1){
		printf("\nElement not found in array");
	}
	else{
		printf("\nElement is present at index: %d",ans);
	}
	
}
int binarySearch(int*arr,int arrSize,int target){
	int l=0,r=arrSize-1;
	while(l<r){
		int mid = (l+r)/2;
		if(target==arr[mid]){
			return mid;
		}
		else if(target<arr[mid]){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	return -1;
}
