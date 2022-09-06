#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *Llink;
    struct node *Rlink;
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
    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->Rlink;
    }
}
void insert_front(){
    new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Underflow : No Insertion");
        exit(0);
    }
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    new->Rlink = head;
    new->Llink = NULL;
    new->data = data;
    if(head!=NULL){
        head->Llink = new;
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
    scanf("%d",&data);
    new->data = data;
    new->Rlink = NULL;
    if(head == NULL){
        head = new;
        new->Llink = NULL;
    }
    else{
        ptr = head;
        while(ptr->Rlink!=NULL){
            ptr = ptr->Rlink;
            }
        ptr->Rlink = new;
        new->Llink = ptr;
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
    while(ptr->data!=key & ptr->Rlink!=NULL){
        ptr = ptr->Rlink;
    }
    if(ptr->data == key){
         ptr1 = ptr->Rlink;
        new->Rlink = ptr1;
        new->Llink = ptr;
        new->data = data;
        ptr->Rlink = new;
        ptr1->Llink = new;
        display();
    }
    else{
        printf("Specified data is not in the list!");
        return;
    }
}
void delete_front(){
    ptr = head;
    if(ptr == NULL){
        printf("The list is empty: No Deletion");
        return;
    }
    if(ptr->Rlink == NULL){
        head = NULL;
    }
    else{
        ptr1 = ptr->Rlink;
        ptr1->Llink = NULL;
        head = ptr1;
    }
    free(ptr);
    display();
}
void delete_end(){
     if(head == NULL){
        printf("The list is empty: No Deletion");
        return;
    }
    ptr = head;
    if(ptr->Rlink == NULL){
        head = NULL;
    }
    else{
        while(ptr->Rlink!=NULL){
            ptr = ptr->Rlink;
        }
    ptr1 = ptr->Llink;
    ptr1->Rlink = NULL;
    }
    free(ptr);
    display();
}
void delete_any(){
    ptr = head;
    printf("Enter the element which you have to delete: ");
    scanf("%d",&key);
    while(ptr->data!=key & ptr->Rlink!=NULL){
        ptr = ptr->Rlink;
    }
    if(ptr->data == key){
        ptr1 = ptr->Llink;
        ptr2 = ptr->Rlink;
        ptr1->Rlink = ptr2;
        ptr2->Llink = ptr1;
        free(ptr);
        display();
    }
    else{
        printf("Node to be deleted : Not Found");
    }
}
