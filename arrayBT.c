#define size 10
#include<stdio.h>
#include<stdlib.h>
int a[size];
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
void insertion(){
    int temp,option,key,insert;
    printf("Enter the element after which you have to insert : ");
    scanf("%d",&insert);
    temp = searchIndex(insert);
    if(temp == 0){
        printf("Unsuccessful Search!");
        return;
    }
    if(a[2*temp]!=0 && a[2*temp+1]!= 0){
        printf("Insertion not possible : Nodes present");
    }
    else{
        if(a[2*temp] == 0 && a[2*temp+1] == 0){
            printf("Insert node as left or right? (1-left,2-right) ");
            scanf("%d",&option);
        }
        printf("Enter the data to be inserted: ");
        scanf("%d",&key);
        if(option == 1 || a[2*temp+1]!=0){
            a[2*temp] = key;
        }
        else if(option == 2 || a[2*temp]!=0){
            a[2*temp+1] = key;
        }
        preorder(1);
    }
}
int searchIndex(int item){
    for(int i=0;i<=size;i++){
        if(a[i]==item){
            return i;
        }
    }
}
void deletion(){
    int delete,i;
    printf("Enter the element which you have to delete : ");
    scanf("%d",&delete);
    i = searchIndex(delete);
    if(a[2*i]!=0 || a[2*i+1]!=0){
        printf("Not a leaf node : No deletion");
        return;
    }
    a[i] = 0;
    preorder(1);
}
void preorder(int i){
    if(a[i]!=0){
        printf("%d ",a[i]);
        preorder(2*i);
        preorder(2*i+1);
    }
}
void inorder(int i){
    if(a[i]!=0){
        inorder(2*i);
        printf("%d ",a[i]);
        inorder(2*i+1);
    }
}
void postorder(int i){
    if(a[i]!=0){
        postorder(2*i);
        postorder(2*i+1);
        printf("%d ",a[i]);
    }
}
void option(int root,int data){
    int ch;
    printf("Enter your choice");
    while(1){
        printf("\n1-Create a BT 2-Insert a leaf node 3-delete a leaf node 4-inorder traversal 5-preoder 6 -postorder 7-stop the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(root,data);
                        break;
            case 2: insertion(root);
                        break;
            case 3: deletion(root);
                        break;
            case 4: inorder(root);
                        break;
            case 5: preorder(root);
                        break;
            case 6: postorder(root);
                        break;
            case 7: exit(0);
            default: printf("Invalid Choice!");
                        break;
        }
    }
}
void main(){
    int root;
    printf("Enter the root element: ");
    scanf("%d",&root);
    option(1,root);
}
