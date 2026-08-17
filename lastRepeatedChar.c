#include<stdio.h>
char lastRepeated(char*, int);
int main(){
	char str[100];
	printf("Enter string: ");
	gets(str);
	int n=0;
	while(str[n]!='\0'){
		n++;
	}
	printf("last repeated character is %c", lastRepeated(str,n));
	return 0;
}
char lastRepeated(char* str, int strSize){
	char check;
	for(int i=strSize-1;i>0;i--){
		check = str[i];
		for(int j=i-1;j>0;j--){
			if(check == str[j]){
				return check;
			}
		}
	}
}
