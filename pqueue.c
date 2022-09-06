#include<stdio.h>
#include<stdlib.h>
struct{
    int val;
    int p;
}a[5],temp;
int front=-1,rear=-1,size=5;
void main(){
    option();
}
void option(){
    int ch;
    while(1){
        printf("\nEnter your choice: 1-insert element 2-delete element 3-end the program");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice");
                    break;
        }
    }
}
void enqueue(){
    int item,prior;
    if(rear == (size-1)){
        printf("Queue is full");
        exit(0);
    }
    printf("Enter the element to be inserted and its priority: ");
    scanf("%d %d",&item,&prior);
    if(front == -1 && rear == -1){
        front = 0;
    }
    rear = rear+1;
    a[rear].val = item;
    a[rear].p = prior;
    if(front!= rear){
            sort();
    }
    display();
}
void sort(){
    int larg;
    for(int i =front;i<rear;i++){
        larg = i;
        for(int j =(i+1);j<=rear;j++){
            if(a[j].p>a[larg].p){
                larg = j;
            }
        }
        if(larg!=i){
            temp = a[i];
            a[i] = a[larg];
            a[larg] = temp;
        }
    }
}
void dequeue(){
    int item;
    if(front == -1){
        printf("Queue is empty");
        exit(0);
    }
    temp = a[front];
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
