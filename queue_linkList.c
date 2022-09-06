#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*front = NULL,*rear = NULL;
struct node *ptr,*new;
void main(){
    option();
}
void option(){
    while(1){
        int ch;
        printf("\nEnter your choice: 1-insert element 2-delete element 3-display 4-end the program: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!");
                    break;
        }
    }
}
void display(){
    if(front == NULL){
        printf("List is empty!");
        return;
    }
    printf("The contents of the list: ");
    ptr = front;
    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}
void enqueue(){
    new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Underflow : No Insertion");
        exit(0);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&new->data);
    new->link = NULL;
    if(front == NULL){
        front = new;
        rear =new;
    }
    else{
        rear->link = new;
        rear = new;
    }
    display();
}
void dequeue(){
    ptr = front;
    if(ptr == NULL){
        printf("Queue is empty: No Deletion");
        return;
    }
    if(front == rear){
        front = NULL;
        rear = NULL;
    }
    else{
        front = ptr->link;
        free(ptr);
    }
    display();
}
