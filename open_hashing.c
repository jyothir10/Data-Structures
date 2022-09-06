#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int H = 10;
struct node{
    int data;
    struct node *link;
}*h[10];
struct node *ptr,*ptr1,*new;

void initialise(){
    for(int i=0;i<10;i++)
        h[i] = NULL;
}
int hashDivision(int k){
    int index = k%H;
    return index;
}
void insertEnd(int key,int index){
    ptr = h[index];
    new = malloc(sizeof(struct node));
    new->link = NULL;
    new->data = key;
    if(ptr == NULL)
        h[index] = new;
    else{
        while(ptr!=NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
    ptr1->link = new;
    }
}
void open(int key){
    int index,i,ch;
    bool flag = false;
    index = hashDivision(key);
    ptr = h[index];
    while(ptr!=NULL && flag == false){
        if(ptr->data == key){
            flag = true;
            printf("Item found at index %d\n",index);
        }
        else{
            ptr = ptr->link;
        }
    }
    if(flag == false){
        printf("Key value does not exists!");
        printf("\nDo you want to insert the key: 1-yes,0-no ");
        scanf("%d",&ch);
        if(ch)
            insertEnd(key,index);
    }
}
void main(){
    int key,ch = 1;
    initialise();
    while(ch){
        printf("Enter the key value: ");
        scanf("%d",&key);
        open(key);
        printf("Do you want to insert more keys? 1-yes,0-no ");
        scanf("%d",&ch);
    }
}
