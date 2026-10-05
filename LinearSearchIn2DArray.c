#include<stdio.h>
int main(){
	int r,c,target;
	printf("Enter dimensions of the array: ");
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("Enter element at coordinate %d,%d: ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nEnter target element: ");
	scanf("%d",&target);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(target==arr[i][j]){
				printf("Element found at %d,%d",i,j);
				break;
			}
		}
	}
	return 0;
}
