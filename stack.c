#include<stdio.h>
#include<stdlib.h>
int top = -1;
void main(){
    int c,n,z=1;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    int a[n];
    printf("1-push elements \n2-pop elements \n3-display elements \n4-check whether stack is empty \n5-return the topmost element of the stack \n6-Exit from the loop");
    while(z>0){
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    switch(c){      //switch statement
        case 1: push(a,n);
                break;
        case 2: pop(a);
                break;
        case 3: display(a);
                break;
        case 4: isEmpty();
                break;
        case 5: Top(a);
                break;
        case 6: exit(0);
        }
    }
}
void push(int arr[],int t){     //function to push elements into the stack
    int item;
    if(top >=t){
        printf("Stack overflow!");
        exit(0);
    }
    printf("Enter the term: ");
    scanf("%d",&item);
    top++;
    arr[top] = item;
}
void pop(int arr[]){    //function to pop elements out of stack
    int item;
    if(top<0){
        printf("Stack underflow!");
        exit(0);
    }
    item = arr[top--];
    printf("%d", item);
    }
void display(int arr[]){    //function to display the stack
    if(top<0){
        printf("Stack is empty!");
        exit(0);
    }
    for(int i=top;i>-1;i--){
        printf("%d ",arr[i]);
    }
}
void isEmpty(){     //function to check whether stack is empty
    if(top == -1){
        printf("stack is empty!");
    }
    else printf("Stack is not empty");
}
void Top(int arr[]){    //function to return the topmost element in the stack
    printf("The topmost element is: ");
    printf("%d",arr[top]);
}
