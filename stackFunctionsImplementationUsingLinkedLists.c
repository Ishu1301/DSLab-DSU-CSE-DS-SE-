#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int);
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
struct Node* createNode(int val){   // Creating New Elements for Linked List
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}
void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d\n", top->val);
    top = top->next;
    free(temp);
}
void peek() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("%d\n", top->val);
}
void display() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
void isEmpty(){
	if(top==NULL){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}
void isFull(){
	if(top!=NULL){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}
