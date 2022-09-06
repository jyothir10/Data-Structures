#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo;
    float coeff;
    struct node *link;
}*pptr = NULL,*qptr = NULL,*rptr = NULL;
void attach(float coeffi,int expon,struct node **head){
    struct node *ptr,*new;
    new = malloc(sizeof(struct node));
    if(new == NULL){
         printf("Memory Underflow : No Insertion");
         return;
    }
    new->expo = expon;
    new->coeff = coeffi;
    if(*head == NULL){
        *head = new;
    }
    else{
        ptr = *head;
        while(ptr->link!=NULL){
            ptr = ptr->link;
            }
        ptr->link = new;
    }
    new->link = NULL;
}
void display(struct node **head){
    struct node *ptr;
    if(*head == NULL){
        printf("List is empty!");
        return;
    }
    ptr = *head;
    while(ptr!= NULL){
        printf("%f x^%d",ptr->coeff,ptr->expo);
        if(ptr->link!=NULL){
             printf(" + ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}
void calc(){
    struct node *ptr;
    int exp;
    float coef;
    while(pptr!=NULL){
        ptr = qptr;
        while(ptr!=NULL){
            coef = pptr->coeff*ptr->coeff;
            exp = pptr->expo + ptr->expo;
            prod(exp,coef);
            ptr = ptr->link;
        }
        pptr = pptr->link;
    }
}
void prod(int expon,double coeffi){
    struct node *ptr1;
    ptr1 = rptr;
    if(ptr1 == NULL){
        attach(coeffi,expon,&rptr);
    }
    else{
        while(ptr1->expo != expon && ptr1->link != NULL){
            ptr1 = ptr1->link;
        }
        if(ptr1->expo == expon){
            ptr1->coeff = ptr1->coeff + coeffi;
        }
        else{
             attach(coeffi,expon,&rptr);
        }
        sort();
    }
}
void sort(){
    struct node *ptr,*ptr2,*ptr3,*temp;
    ptr2 = rptr;
    int larg;
    temp = malloc(sizeof(struct node));
    while(ptr2!=NULL){
        larg = ptr2->expo;
        ptr3 = ptr2->link;
        while(ptr3!=NULL){
            if(ptr3->expo > larg){
                ptr = ptr3;
                larg = ptr3->expo;
            }
            ptr3 = ptr3->link;
        }
        if(larg!=ptr2->expo){
            temp->expo = ptr2->expo;
            temp->coeff = ptr2->coeff;
            ptr2->expo = ptr->expo;
            ptr2->coeff = ptr->coeff;
            ptr->expo = temp->expo;
            ptr->coeff = temp->coeff;
        }
        ptr2 = ptr2->link;
    }
}
void main(){
    int n1,n2,exponent;
    float coefficient;
    printf("Enter the no of terms in the first polynomial: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter the coefficient and exponent of the term %d of first polynomial: ",(i+1));
        scanf("%f %d",&coefficient,&exponent);
        attach(coefficient,exponent,&pptr);
    }
    printf("Enter the no of terms in the second polynomial: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter the coefficient and exponent of the term %d of second polynomial: ",(i+1));
        scanf("%f %d",&coefficient,&exponent);
        attach(coefficient,exponent,&qptr);
    }
    printf("Polynomial 1: ");
    display(&pptr);
    printf("Polynomial 2: ");
    display(&qptr);
    calc();
    printf("Product polynomial: ");
    display(&rptr);
}
