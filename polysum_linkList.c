#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo;
    float coeff;
    struct node *link;
}*pptr = NULL,*qptr = NULL,*rptr = NULL,*new,*ptr;
void attach(float coeffi,int expon,struct node **head){
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
    float coef;
    while(pptr!=NULL && qptr!=NULL){
        if(pptr->expo > qptr->expo){
            attach(pptr->coeff,pptr->expo,&rptr);
            pptr = pptr->link;
        }
        else if(pptr->expo < qptr->expo){
            attach(qptr->coeff,qptr->expo,&rptr);
            qptr = qptr->link;
        }
        else{
            coef = pptr->coeff + qptr->coeff;
            if(coef!=0){
                attach(coef,pptr->expo,&rptr);
            }
            pptr = pptr->link;
            qptr = qptr->link;
        }
    }
    while(pptr!=NULL){
        attach(pptr->coeff,pptr->expo,&rptr);
        pptr = pptr->link;
    }
    while(qptr!=NULL){
        attach(qptr->coeff,qptr->expo,&rptr);
        qptr = qptr->link;
    }
    printf("Sum polynomial : ");
    display(&rptr);
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
}

