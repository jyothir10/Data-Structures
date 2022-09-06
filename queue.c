#include<stdio.h>
#include<stdlib.h>
int size =5;
int a[5];
int front=-1,rear=-1;
void main(){
    option();
}
void option(){
    while(1){
        int ch;
        printf("\nEnter your choice: 1-insert element 2-delete element 3-end the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice!");
                    break;
        }
    }
}

void enqueue(){
    int item;
    if(rear == (size-1)){
        printf("Queue is full");
        exit(0);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&item);
    if(front == -1 && rear == -1){
        front = 0;
    }
    rear = rear+1;
    a[rear] = item;
    display();
}
void dequeue(){
    int item;
    if(front == -1){
        printf("Queue is empty");
        exit(0);
    }
    item = a[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = front +1;
    }
    if(front!=-1){
        display();
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty!");
        exit(0);
    }
    printf("The elements of the queue is: ");
    for(int i = front;i<=rear;i++){
        printf("%d ",a[i]);
    }
}
