#include<stdio.h>
int main(){
	int r,c,h,target;
	printf("Enter dimensions of the array: ");
	scanf("%d%d%d",&r,&c,&h);
	int arr[r][c][h];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<h;k++){
				printf("Enter element at coordinate %d,%d,%d: ",i,j,k);
				scanf("%d",&arr[i][j][k]);
			}
		}
	}
	printf("\nEnter target element: ");
	scanf("%d",&target);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<h;k++){
				if(target==arr[i][j][k]){
					printf("Element found at %d,%d,%d",i,j,k);
					break;
				}
			}
		}
	}
	return 0;
}
