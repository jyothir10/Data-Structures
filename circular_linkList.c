#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head = NULL;
struct node *ptr,*ptr1,*ptr2,*new;
int data,key,ch;
void main(){
    option();
}
void option(){
    printf("Enter your choice: ");
    while(1){
        printf("\n1-display 2-insert at front 3-insert at end 4-insert anywhere\n5-delete from front 6-delete from end 7-delete from anywhere 8-end the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: display();
                    break;
            case 2: insert_front();
                    break;
            case 3: insert_end();
                    break;
            case 4: insert_any();
                    break;
            case 5: delete_front();
                    break;
            case 6: delete_end();
                    break;
            case 7: delete_any();
                    break;
            case 8: exit(0);
            default: printf("Invalid choice!");
                        break;
        }
    }
}
void display(){
    if(head == NULL){
        printf("List is empty!");
        return;
    }
    printf("The contents of the list: ");
    ptr = head;
    if(ptr->link == head){
        printf("%d",ptr->data);
    }
    else{
        while(ptr->link!= head){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
        printf("%d",ptr->data);
    }
}
void insert_front(){
    new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Underflow : No Insertion");
        exit(0);
    }
    printf("Enter the data to be inserted: ");
    scanf("%d",&new->data);
    if(head==NULL){
        new->link = new;
    }
    else{
        new->link = head;
        ptr = head;
        while(ptr->link!=head){
            ptr = ptr->link;
        }
        ptr->link = new;
    }
    head = new;
    display();
}
void insert_end(){
    new = malloc(sizeof(struct node));
    if(new == NULL){
         printf("Memory Underflow : No Insertion");
         exit(0);
    }
    printf("Enter the data to be inserted: ");
    scanf("%d",&new->data);
    if(head == NULL){
        new->link = new;
        head = new;
    }
    else{
        ptr = head;
        while(ptr->link!=head){
            ptr = ptr->link;
            }
        ptr->link = new;
        new->link = head;
    }
    display();
}
void insert_any(){
    new = malloc(sizeof(struct node));
    if(new == NULL){
         printf("Memory Underflow : No Insertion");
         exit(0);
    }
    printf("Enter the element after which you have to insert: ");
    scanf("%d",&key);
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    ptr = head;
    while(ptr->data!=key & ptr->link!=head){
        ptr = ptr->link;
    }
    if(ptr->link == head){
        printf("key is not available!");
        return;
    }
    else{
        new->link = ptr->link;
        new->data = data;
        ptr->link = new;
        display();
    }
}
void delete_front(){
    ptr = head;
    if(ptr == NULL){
        printf("The list is empty: No Deletion");
        return;
    }
    ptr1 = head;
    while(ptr1->link!=head){
        ptr1 = ptr1->link;
    }
    if(head->link==head){
        head= NULL;
    }
    else{
        head = head->link;
    }
    ptr1->link = head;
    free(ptr);
    display();
}
void delete_end(){
    ptr = head;
    if(ptr == NULL){
        printf("The list is empty: No Deletion");
        return;
    }
    ptr1 = NULL;
    while(ptr->link!=head){
        ptr1 = ptr;
        ptr = ptr->link;
    }
    if(ptr1==NULL){
        head = NULL;
    }
    else{
         ptr1->link = head;
    }
    free(ptr);
    display();
}
void delete_any(){
    ptr = head;
    printf("Enter the element which you have to delete: ");
    scanf("%d",&key);
    while(ptr->data!=key & ptr->link!=head){
        ptr1 = ptr;
        ptr = ptr->link;
    }
    if(ptr->link == head){
        printf("Node with key doesnt exist: No deletion");
        return;
    }
    else{
        ptr1->link = ptr->link;
        free(ptr);
        display();
        return;
    }
}

