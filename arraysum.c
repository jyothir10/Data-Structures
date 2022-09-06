port#include<stdio.h>
int a[10],i,n,*ptr,s = 0;
void sum(int m){
    for(i=0;i<m;i++){
        s = s + *(ptr+i);
    }
    printf("The sum of array elements is: %d",s);
}
void main(){
    printf("Enter the no of elements: \n");
    scanf("%d",&n);
    ptr = a;
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    sum(n);
}
