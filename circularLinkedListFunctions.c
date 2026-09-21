#include<stdio.h>
#include<stdlib.h>
struct node* createNode(int);
struct node* insertNode(struct node*,int,int);
struct node* deleteNode(struct node*,int);
void traverseCircularLinkedList(struct node*);
int searchingCircularLinkedList(struct node*,int);
struct node{
	int data;
	struct node* next;
};
int main(){
	int n1,n2,n3,n4;
	printf("Enter the value of linked list: ");
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	
	struct node* head = createNode(n1);
	struct node* second = createNode(n2);
	struct node* third = createNode(n3);
	struct node* fourth = createNode(n4);
	
	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = head;
	
	printf("\nOriginal Circular Linked List: ");
	traverseCircularLinkedList(head);
	
	int newn,index;
	printf("\nEnter new node value and index: ");
	scanf("%d%d",&newn,&index);
	head = insertNode(head,index,newn);
	printf("\nCircular Linked List after insertion: ");
	traverseCircularLinkedList(head);
	
	printf("\nEnter index of node to be deleted: ");
	scanf("%d",&index);
	head = deleteNode(head,index);
	traverseCircularLinkedList(head);
	
	int find;
	printf("Enter value to be found: ");
	scanf("%d",&find);
	int out = searchingCircularLinkedList(head,find);
	if(out==-1){
		printf("Element not found!");
	}
	else{
		printf("Element found at index %d",out);
	}
	return 0;
}
struct node* createNode(int val){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = val;
	newNode->next = NULL;
	
	return newNode;
}
struct node* insertNode(struct node* head,int position,int val){
	struct node* newNode = createNode(val);
	struct node* temp = head;
	if(position==1){
		newNode->next = temp;
        struct node* last = head;
        do{
            last = last->next;
        }
        while(last!=head);
        last->next = newNode;
		return newNode;
	}
	else{
		while(position!=2){
			temp = temp->next;
			position--;
		}
		struct node* tempNext = temp->next;
		temp->next = newNode;
		newNode->next = tempNext;
		return head;
	}
}
struct node* deleteNode(struct node* head,int position){
	struct node* temp=head;
	if(position==1){
        struct node* last = head;
        do{
            last = last->next;
        }
        while(last!=head);

		head = head->next;
		free(temp);
        last->next = head;
		return head;
	}
	else{
		while(position!=1){
			temp = temp->next;
			position--;
			
		}
		struct node* tempPrev = head;
		while(tempPrev->next!=temp){
			tempPrev = tempPrev->next;
		}
		tempPrev->next = temp->next;
		tempPrev = tempPrev->next;
		free(temp);
		return head;
	}
}
int searchingCircularLinkedList(struct node* head, int val){
	int index=1;
	struct node* temp = head;
	int found = 0;
	do{
		if(temp->data==val){
			found=1;
			break;
		}
		index++;
		temp = temp->next;
	}
    while(temp!=head);
	if(found==1)
	return index;
	else
	return -1;
}
void traverseCircularLinkedList(struct node* head){
	struct node* current = head;
	do{
		printf("%d\t",current->data);
		current = current->next;
	}
    while(current!=head);
	printf("\n");
}