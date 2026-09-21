#include<stdio.h>
#include<stdlib.h>
struct node* createNode(int);
struct node* insertNode(struct node*,int,int);
struct node* deleteNode(struct node*,int);
void traverseDoubleCircularLinkedList(struct node*);
int searchingDoubleCircularLinkedList(struct node*,int);
struct node{
	struct node* prev;
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
	second->prev = head;
	second->next = third;
	third->prev = second;
	third->next = fourth;
	fourth->prev = third;
    fourth->next = head;
    head->prev = fourth;

    printf("\nOriginal Double Circular Linked List: ");
	traverseDoubleCircularLinkedList(head);
	
	int newn,index;
	printf("\nEnter new node value and index: ");
	scanf("%d%d",&newn,&index);
	head = insertNode(head,index,newn);
	printf("\nDouble Circular Linked List after insertion: ");
	traverseDoubleCircularLinkedList(head);

    printf("\nEnter index of node to be deleted: ");
	scanf("%d",&index);
	head = deleteNode(head,index);
	traverseDoubleCircularLinkedList(head);

    int find;
	printf("Enter value to be found: ");
	scanf("%d",&find);
	int out = searchingDoubleCircularLinkedList(head,find);
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
	
	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	
	return newNode;
}
struct node* insertNode(struct node* head,int position,int val){
	struct node* newNode = createNode(val);
	struct node* temp = head;
	if(position==1){
		newNode->next = temp;
		temp->prev = newNode;
        struct node* last = head;
        do{
            last = last->next;
        }
        while(last!=head);
        last->next = newNode;
        newNode->prev = last;
		return newNode;
	}
	else{
		while(position!=2){
			temp = temp->next;
			position--;
		}
		struct node* tempNext = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = tempNext;
		tempNext->prev = newNode;
		return head;
	}
}
struct node* deleteNode(struct node* head,int position){
	struct node* temp=head;
	if(position==1){
		head = head->next;      
        struct node* last = head;
        do{
            last = last->next;
        }
        while(last!=head);
        head->prev = last;
		free(temp);
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
		tempPrev->prev = temp->prev;
		free(temp);
		return head;
	}
}
int searchingDoubleCircularLinkedList(struct node* head, int val){
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
void traverseDoubleCircularLinkedList(struct node* head){
	struct node* current = head;
	do{
		printf("%d\t",current->data);
		current = current->next;
	}
    while(current!=head);
	printf("\n");
}