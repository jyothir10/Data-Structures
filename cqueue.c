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
    int item,next;
    printf("Enter the element to be inserted: ");
    scanf("%d",&item);
    if(front == -1){
        front = rear = 0;
        a[rear] = item;
        display();
    }
    else{
        next = (rear+1)%size;
        if(next!=front){
            rear = next;
            a[rear] = item;
            display();
        }
        else{
            printf("Cqueue is full!");
        }
    }
}
void dequeue(){
    int item;
    if(front == -1){
        printf("Cqueue is empty");
        exit(0);
    }
    else{
        item = a[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
    }
    display();
}
void display(){
    int i;
     if(front == -1){
        printf("Cqueue is empty!");
        exit(0);
    }
    printf("The elements of the Cqueue is: ");
    if(front<=rear){
        for(i = front;i<=rear;i++){
        printf("%d ",a[i]);
        }
    }
    else{
        for(i = 0;i<=rear;i++){
             printf("%d ",a[i]);
        }
         for(i = front;i<size;i++){
            printf("%d ",a[i]);
        }
    }
}
