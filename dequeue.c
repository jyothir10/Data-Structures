#include<stdio.h>
#include<stdlib.h>
int size =5;
int a[5];
int front= -1,rear = -1;
void main(){
    option();
}
void option(){
    int ch;
    while(1){
        printf("\nEnter your choice:\n1-insert element at the rear\t2-insert element at the front\n3-delete element from the rear\t4-delete element from the front\n5-end the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: inject();
                    break;
            case 2: push();
                    break;
            case 3: eject();
                    break;
            case 4: pop();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice!");
                    break;
        }
    }
}

void inject(){
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
            printf("deque is full!");
        }
    }
}
void eject(){
    int item;
    if(front == -1){
        printf("Deque is empty!");
        exit(0);
    }
    else{
        if(front == rear){
            item = a[rear];
            front = rear = -1;
        }
        else{
            if(rear == 0){
                item = a[rear];
                rear = (size-1);
            }
            else if(rear == (size-1)){
                item = a[rear];
                rear = 0;
            }
            else{
                item = a[rear];
                rear = (rear-1);
            }
        }
        display();
    }
}
void pop(){
    int item;
    if(front == -1){
        printf("Deque is empty");
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
void push(){
    int ahead,item;
    if(front == 0){
        ahead = (size-1);
    }
    else{
        if(front == -1){
            ahead = 0;
        }
        else{
            ahead = (front-1);
        }
    }
    if(ahead == rear){
        printf("Deque is full!");
        exit(0);
    }
    else{
        printf("Enter the element to be inserted: ");
        scanf("%d",&item);
        front = ahead;
        a[front] = item;
        display();
    }
}
void display(){
    int i;
     if(front == -1){
        printf("Queue is empty!");
        exit(0);
    }
    printf("The elements of the queue is: ");
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

