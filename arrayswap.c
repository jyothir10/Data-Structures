#include<stdio.h>
void swap(int *x,int *y){
    int temp;
    printf("\nBefore swapping a = %d and b = %d \n",*x,*y);
    temp = *x;
    *x = *y;
    *y = temp;
    printf("After swapping a = %d and b = %d",*x,*y);
}
void main(){
    int a,b,*p,*q,sum = 0;
    p = &a;
    q = &b;
    printf("Enter the 2 numbers: \n");
    scanf("%d %d",p,q);
    sum = *p+*q;
    printf("The sum of the numbers is: %d",sum);
    swap(&a,&b);
}

