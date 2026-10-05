#include<stdio.h>
#define size 10
int stack[size];
int top = -1;

void push(int);
void pop();
void peek();
void display();
void isEmpty();
void isFull();

int main(){
	int func = 10;
	printf("Enter a number to perform function: 1 = Push\n2 = Pop\n3 = Peek\n4 = Display\n5 = isEmpty\n6 = isFull\n0 = terminate\n");
	while(func!=0){
		scanf("%d",&func);
		if(func==1){
			printf("Enter Value to Push: ");
			int val = 0;
			scanf("%d",&val);
			push(val);
		}
		else if(func==2){
			pop();
		}
		else if(func==3){
			peek();
		}
		else if(func==4){
			display();
		}
		else if(func==5){
			isEmpty();
		}
		else if(func==6){
			isFull();
		}
		else if(func==0){
			printf("Terminating");
		}
		else{
			printf("Invalid Input\n");
		}
	}
	return 0;	
}

void push(int val){
	if(top==size-1){
		printf("Stack Overflow\n");
	}
	else{
		stack[++top] = val;
	}
}
void pop(){
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		printf("%d\n",stack[top--]);
	}
}
void peek(){
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		printf("%d\n",stack[top]);
	}
}
void display(){
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		for(int i=0;i<top+1;i++){
			printf("%d\t",stack[i]);
		}
	}
}
void isEmpty(){
	if(top==-1){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}
void isFull(){
	if(top==size-1){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}
