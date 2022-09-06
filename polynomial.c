#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100

typedef struct{
    float coeff;
    int exp;
}polynomial;

polynomial terms[MAX_TERMS];
int avail=0;

void attach(float coefficient, int exponent){
    if(avail>MAX_TERMS){
        printf("Too many terms in the polynomial");
        exit;
    }
    terms[avail].coeff=coefficient;
    terms[avail++].exp=exponent;
}

void main(){
    int startA,finishA,startB,finishB,startD,finishD,n,i,exponent;
    float coefficient;
    startA=0;
    printf("Enter the no of terms in the first polynomial: ");
    scanf("%d",&startB);
    printf("Enter the no of terms in the second polynomial: ");
    scanf("%d",&n);
    finishA=startB-1;
    finishB=startB+n-1;
    for(i=0;i<=finishA;i++){
        printf("Enter the coefficient and exponent of the term %d of the first polynomial : ",(i+1));
        scanf("%f %d",&coefficient,&exponent);
        attach(coefficient,exponent);
    }
    for(i=1;i<=n;i++){
        printf("Enter the coefficient and exponent of the term %d pf the second polynomial : ",i);
        scanf("%f %d",&coefficient,&exponent);
        attach(coefficient,exponent);
    }
    printf("Polynomial 1 = ");
    for(i=startA;i<=finishA;i++){
        printf("%f x^%d",terms[i].coeff,terms[i].exp);
        if(i!=finishA){
            printf(" + ");
        }
    }
    printf("\nPolynomial 2 = ");
    for(i=startB;i<=finishB;i++){
        printf("%f x^%d",terms[i].coeff,terms[i].exp);
        if(i!=finishB){
            printf(" + ");
        }
    }
    startD = avail;
    while(startA <= finishA && startB <= finishB){
        if(terms[startA].exp > terms[startB].exp){
            attach(terms[startA].coeff,terms[startA].exp);
            startA++;
        }
        else if(terms[startA].exp < terms[startB].exp){
            attach(terms[startB].coeff,terms[startB].exp);
            startB++;
        }
        else{
            coefficient=terms[startA].coeff + terms[startB].coeff;
            if(coefficient!=0){
                attach(coefficient,terms[startA].exp);
            }
            startA++;
            startB++;
        }
    }
    while(startA <= finishA){
        attach(terms[startA].coeff,terms[startA].exp);
        startA++;
    }
    while(startB <= finishB){
        attach(terms[startB].coeff,terms[startB].exp);
        startB++;
    }
    finishD=avail-1;

    printf("\nSum of the polynomial = ");
    for(i=startD;i<=finishD;i++){
        printf("%f x^%d",terms[i].coeff,terms[i].exp);
        if(i!=finishD){
            printf(" + ");
        }
    }
}
