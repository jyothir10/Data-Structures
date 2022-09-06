#define size 15
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//array variables
int a[size],b[15],s[15],u[15];
int c = 0;

//Heap sort

void HeapSort(){
    initialise();
    length();
    int temp;
    BuildMaxHeap();
    for(int i = c;i>=2;i--){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        MaxHeapify(1,(i-1));
    }
    display();
}
void initialise(){
    int root;
    for(int i=1;i<size;i++){
        a[i] = 0;
    }
    printf("Enter the root element: ");
    scanf("%d",&root);
    create(1,root);
}
void create(int i,int item){
    int option,itemLeft,itemRight;
    if(i!=0){
        a[i] = item;
        printf("Node %d has a left subtree? 1-Yes,2-No ",i);
        scanf("%d",&option);
        if(option==1){
            printf("Enter the data to be inserted: ");
            scanf("%d",&itemLeft);
            create(2*i,itemLeft);
        }
        else{
            create(0,0);
        }
        printf("Node %d has a right subtree? 1-Yes,2-No ",i);
        scanf("%d",&option);
        if(option==1){
            printf("Enter the data to be inserted: ");
            scanf("%d",&itemRight);
            create(2*i+1,itemRight);
        }
        else{
            create(0,0);
        }
    }
}
void length(){
    for(int i=1;i<size;i++){
        if(a[i]!=0){
            c++;
        }
    }
}
void BuildMaxHeap(){
    for(int i=floor(c/2);i>=1;i--){
        MaxHeapify(i,c);
    }
}
void MaxHeapify(int i,int n){
    int l,r,largest,temp;
    l = 2*i;
    r = 2*i+1;
    if(l<=n && a[l]>a[i])
        largest = l;
    else
        largest = i;
    if(r<=n && a[r]>a[largest])
        largest = r;
    if(largest!=i){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(largest,n);
    }
}
void display(){
    for(int i=1;i<=c;i++){
        printf("%d ",a[i]);
    }
}

//merge sort

void Merge(){
    int n;
    n = input(b);
    mergeSort(0,n-1);
    display1(s,n);
}
int input(int inp[]){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i =0;i<n;i++){
        scanf("%d",&inp[i]);
    }
    return n;
}
void mergeSort(int l,int r){
    int mid;
    if(l<r){
        mid = (l+r)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,mid,r);
    }
}
void merge(int l,int mid,int r){
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(b[i]<=b[j]){
            s[k] = b[i];
            k++;i++;
        }
        else{
            s[k] = b[j];
            k++;j++;
        }
    }
    if(i>mid){
        while(j<=r){
            s[k] = b[j];
            k++;j++;
        }
    }
    else{
        while(i<=mid){
            s[k] = b[i];
            k++;i++;
        }
    }
    for(k= 0;k<=r;k++){
        b[k] = s[k];
    }
}
void display1(int dis[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",dis[i]);
    }
}

//quick sort

void quick(){
    int n;
    n = input(u);
    quickSort(0,n-1);
    display1(u,n);
}
void quickSort(int p,int r){
    int q;
    if(p<r){
        q = partition(p,r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}
int partition(int p,int r){
    int pivot,i,j,temp;
    pivot = p;i=p;j=r;
    while(i<j){
        while(u[i]<=u[pivot]&&i<r){
            i++;
        }
        while(u[j]>u[pivot]){
            j--;
        }
        if(i<j){
            temp = u[i];
            u[i] = u[j];
            u[j] = temp;
        }
    }
    temp = u[pivot];
    u[pivot] = u[j];
    u[j] = temp;
    return j;
}

void option(){
    int ch;
    while(ch){
    printf("\nEnter your choice: 1-Quick sort 2-Heap sort 3-Merge sort 4-exit the program ");
    scanf("%d",&ch);
    switch(ch){
    case 1: quick();
            break;
    case 2: HeapSort();
            break;
    case 3: Merge();
            break;
    case 4: exit(0);
    default: printf("Invalid choice!");
            break;

        }
    }
}
void main(){
    option();
}
