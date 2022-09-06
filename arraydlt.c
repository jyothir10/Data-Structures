#include<stdio.h>
void main(){
    int a[20],n;
    printf("Enter the no of terms in the array: ");
    scanf("%d",&n);
    input(a,n);
    delete(a,n);
    display(a,n);
}
void input(int arr[],int t){
    printf("Enter the terms in the array: ");
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
}
void delete(int arr[],int t){
    int pos;
    printf("Enter the index position which you want to delete: ");
    scanf("%d", &pos);
    for(int i=pos;i<t;i++){
        arr[i] = arr[i+1];
    }
}
void display(int arr[],int t){
    printf("The modified array is: ");
    for(int i=0;i<(t-1);i++){
        printf("%d ", arr[i]);
    }
}
