#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*avail = NULL;
struct node *ptr,*ptr1,*new;

struct node1{
    int size;
    int data;
    struct node *link;
}*avail1 = NULL;
struct node1 *pt,*pt1,*ptr2,*new1;

void create(){      //fixed block creation
    int n,i;
    printf("Enter the no of free fixed memory blocks you want to create: ");
    scanf("%d",&n);
    for(i= 0;i<n;i++){
        new = malloc(sizeof(struct node));
        new->link = NULL;
        if(avail == NULL)
            avail = new;
        else{
            ptr1->link = new;
        }
        ptr1 = new;
    }
}

struct node* getNode(){     //fixed block
    if(avail == NULL){
        printf("Memory is Insufficient!No creation");
        return NULL;
    }
    else{
        ptr = avail;
        avail = avail->link;
        printf("Allocated fixed block memory\n");
        return ptr;
    }
}
void returnNode(struct node* ptr){      //fixed block
    ptr1 = avail;
    while(ptr1->link != NULL)
        ptr1 = ptr1->link;
    ptr1->link = ptr;
    ptr->link = NULL;
    printf("Returned fixed block memory\n");
    free(ptr);
}

void fixedBlock(){
    create();
    new = getNode();
    printf("Enter the data to be added: ");
    scanf("%d",&new->data);
    printf("%d\n",new->data);
    returnNode(new);
}

void create1(){       //variable block creation
    int n,i;
    printf("Enter the no of free variable memory blocks you want to create: ");
    scanf("%d",&n);
    for(i= 0;i<n;i++){
        new1 = malloc(sizeof(struct node1));
        new1->link = NULL;
        printf("Enter the size of the %d memory block in ascending order: ",(i+1));
        scanf("%d",&new1->size);
        if(avail1 == NULL)
            avail1 = new1;
        else{
            pt->link = new1;
        }
        pt = new1;
    }
}

struct node1* firstFit(){        //variable block
    int s;
    if(avail1 == NULL){
        printf("Memory is Insufficient!No creation");
        return NULL;
    }
    else{
        pt = avail1;
        printf("Enter the memory size required: ");
        scanf("%d",&s);
        while(pt->link!=NULL && pt->size<s){
            pt1 = pt;
            pt = pt->link;
        }
        if(pt->link == NULL && pt->size<s){
            printf("Memory request is too large to serve!");
            exit(0);
        }
        else{
            pt1->link = pt->link;
            printf("Allocated variable block memory\n");
            return(pt);
        }
    }
}

struct node1* bestFit(){        //variable block
    int s;
    if(avail1 == NULL){
        printf("Memory is Insufficient!No creation");
        return NULL;
    }
    else{
        pt = avail1;
        printf("Enter the memory size required: ");
        scanf("%d",&s);
        while(pt->link!=NULL && pt->size<s){
            pt1 = pt;
            pt = pt->link;
        }
        if(pt->link == NULL && pt->size<s){
            printf("Memory request is too large to serve!");
            exit(0);
        }
        else{
            pt1->link = pt->link;
            printf("Allocated variable block memory\n");
            return(pt);
        }
    }
}
struct node1* worstFit(){
    int s;
    if(avail1 == NULL){
        printf("Memory is Insufficient!No creation");
        return NULL;
    }
    else{
        pt = avail1;
        printf("Enter the memory size required: ");
        scanf("%d",&s);
        while(pt->link!=NULL){
            pt1 = pt;
            pt = pt->link;
        }
        if(pt->size<s){
            printf("Memory request is too large to serve!");
            exit(0);
        }
        else{
            pt1->link = NULL;
            printf("Allocated variable block memory\n");
            return(pt);
        }
    }
}
void returnnode(struct node1* pt){      //variable block
    pt1 = avail1;
    while(pt1->link!=NULL && pt1->size<pt->size){
        ptr2 = pt1;
        pt1 = pt1->link;
    }
    if(pt1->size>pt->size){
        ptr2->link = pt;
        pt->link = pt1;
    }
    else{
        pt1->link = pt;
        pt->link = NULL;
    }
    printf("Returned variable block memory");
    free(pt);
}

void variableBlock(){
    int ch;
    create1();
    printf("Enter the strategy you need: 1-first fit,2-best fit,3-worst fit ");
    scanf("%d",&ch);
    switch(ch){
        case 1: new1 = firstFit();
                break;
        case 2: new1 = bestFit();
                break;
        case 3: new1 = worstFit();
                break;
        case 4: printf("Invalid choice!");
                break;
    }
    printf("Enter the data to be added: ");
    scanf("%d",&new1->data);
    printf("%d\n",new1->data);
    returnnode(new1);
}
void option(){
    int ch = 1;
    while(ch){
        printf("Enter the memory block choice: 1-fixed,2-variable,3-end the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: fixedBlock();
                    break;
            case 2: variableBlock();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice!");
                    break;
        }
    }
}

void main(){
    option();
}

