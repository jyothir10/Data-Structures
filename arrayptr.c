#include<stdio.h>
void main(){
    int a[10],n,i,*ptr;
    printf("enter the no of elements: \n");
    scanf("%d",&n);
    ptr = a;
    printf("enter the elements: \n");
    for(i = 0;i<n;i++)
    {
        scanf("%d",(ptr+i));
    }
    printf("The array elements are: \n");
    for(i = 0;i<n;i++)
    {
        printf("%d \n",*(ptr + i));
    }
}
