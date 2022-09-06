#include<stdio.h>
#include<stdlib.h>

//graph structures
struct node1{
    int data;
    struct node1 *next;
}*visit = NULL;
struct node{
    int data;
    struct node *link;
    struct node1 *alink;
}*gptr = NULL;

//stack variables and functions
int top = -1;
int stak[10];
void push(int item){
    if(top==10){
        printf("Stack full");
        exit(0);
    }
    stak[++top] = item;
}
int pop(){
    if(top == -1){
        printf("Stack empty");
        return -1;
    }
    return(stak[top--]);
}

//queue variables and functions
int front =-1, rear = -1;
int q[10];
void enqueue(int item){
    if(rear == 10){
        printf("Queue full!");
        exit(0);
    }
    if(front == -1){
        front = rear = 0;
        q[rear] = item;
    }
    else
        q[++rear] = item;

}
int dequeue(){
    if(front == -1){
        printf("Queue is empty");
        return -1;
    }
    int x = q[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else front++;
    return x;
}

int SearchVisit(int ver){
    struct node1 *p = visit;
    if(p == NULL){
        return 0;
    }
    else{
        while((p!=NULL) && (p->data != ver)){
            p = p->next;
        }
    }
    if(p!=NULL)return 1;
    else return 0;
}

void addVisit(int ver){
    struct node1 *p,*new;
    p = visit;
    if(p == NULL){
        new = malloc(sizeof(struct node1));
        new->data = ver;
        new->next = NULL;
        visit = new;
    }
    else{
        while(p->next!=NULL)
            p = p->next;
        new = malloc(sizeof(struct node1));
        new->data = ver;
        new->next = NULL;
        p->next = new;
    }
}
void input(){
                                   //entering the graph
    struct node *temp,*temp1;
    struct node1 *ptr,*ptr1,*ptr2;
    int v,o,op;
    printf("Enter the no of vertices: ");
    scanf("%d",&v);
    for(int i =0;i<v;i++){

        temp = malloc(sizeof(struct node));
        printf("Enter the vertex value: ");
        scanf("%d",&temp->data);
        if(gptr == NULL){
            gptr = temp;
            temp1 = temp;
        }
        else{
            temp1->link = temp;
            temp1 = temp;
        }
        temp->link = NULL;
        printf("Does the node have any adjacent vertex? 1-yes,2-no ");
        scanf("%d",&o);
        if(o == 1){
            ptr1 = NULL;
            do{
                ptr = malloc(sizeof(struct node1));
                printf("Enter the value of the adjacent vertex: ");
                scanf("%d",&ptr->data);
                if(ptr1 == NULL){
                    ptr1 = ptr;
                    ptr2 = ptr;
                }
                else{
                    ptr2->next = ptr;
                    ptr2 = ptr;
                }
                printf("Any more adjacent nodes ? 1-yes,0 -no ");
                scanf("%d",&op);
            }
            while(op == 1);
                ptr2->next = NULL;
            temp->alink = ptr1;
        }
        else
            temp->alink = NULL;
    }
    display();
}
void display(){
    int v;
    printf("Enter the vertex where traversal starts: ");
    scanf("%d",&v);
    printf("depth First Search: ");
    depthFirstSearch(gptr,v);
    printf("\nBreadth First Search: ");
    breadthFirstSearch(gptr,v);
}
void depthFirstSearch(struct node *gptr,int v){
    struct node *ptr;
    struct node1 *ptr1;
    int u = v;
    push(u);
    while(top != -1){
        u = pop();
        if(SearchVisit(u)==0){
            printf("%2d",u);
            addVisit(u);
            ptr = gptr;
            while((ptr!=NULL) && (ptr->data!=u))
                ptr = ptr->link;
            ptr1 = ptr->alink;
            while(ptr1!=NULL){
                push(ptr1->data);
                ptr1 = ptr1->next;
            }
        }
    }
    visit = NULL;
}
void breadthFirstSearch(struct node *gptr,int v){
    struct node *ptr;
    struct node1 *ptr1;
    int u = v;
    enqueue(u);
    while(front != -1){
        u = dequeue();
        if(SearchVisit(u)==0){
            printf("%2d",u);
            addVisit(u);
            ptr = gptr;
            while((ptr!=NULL) && (ptr->data!=u))
                ptr = ptr->link;
            ptr1 = ptr->alink;
            while(ptr1!=NULL){
                enqueue(ptr1->data);
                ptr1 = ptr1->next;
            }
        }
    }
}
void main(){
    input();
}
