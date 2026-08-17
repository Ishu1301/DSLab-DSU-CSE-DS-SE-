#include<stdio.h>
char firstRepeated(char*, int);
int main(){
	char str[100];
	printf("Enter string: ");
	gets(str);
	int n=0;
	while(str[n]!='\0'){
		n++;
	}
	printf("first repeated character is %c", firstRepeated(str,n));
}
char firstRepeated(char* str, int strSize){
	char check;
	for(int i=0;i<strSize-1;i++){
		check = str[i];
		for(int j=i+1; j<strSize;j++){
			if(check == str[j]){
				return check;
			}
		}
	}
}
