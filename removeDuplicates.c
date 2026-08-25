#include<stdio.h>

int removeDuplicates(int*,int);
void main(){
    int n=0;
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int size=0;
    size = removeDuplicates(arr,n);

    printf("Array without duplicates:\t");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}
int removeDuplicates(int*arr,int arrSize){
    int size=0;
    for(int i=0;i<arrSize;i++){
        int flag=0;
        for(int j=0;j<size;j++){
            if(arr[j]==arr[i]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            arr[size]=arr[i];
            size++;
        }
    }
    return size;
}