#include<stdio.h>
void main(){
    int a[20],n;
    printf("Enter the no of terms in the array: ");
    scanf("%d",&n);
    input(a,n);
    insert(a,n);
    display(a,n);
}
void input(int arr[],int t){
    printf("Enter the terms in the array: ");
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
}
void insert(int arr[],int t){
    int item,pos;
    printf("Enter the index where you want to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element you want to insert: ");
    scanf("%d",&item);
    for(int i=(t-1);i>=pos;i--){
        arr[i+1] = arr[i];
    }
    arr[pos] = item;
}
void display(int arr[],int t){
    printf("The inserted array is: ");
    for(int i=0;i<=t;i++){
        printf("%d ", arr[i]);
    }
}
