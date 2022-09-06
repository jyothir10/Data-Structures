#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
     int data;
     struct node *left;
     struct node *right;
}*lchild,*rchild,*root;
void create(){
    int ch = 1;
    while(ch){
        insertion();
        printf("Do you want to insert more (1-yes/0-no)");
        scanf("%d",&ch);
    }
}
void insertion(){
    struct node *ptr,*ptr1,*new;
    bool flag = false;
    int item;
    printf("Enter the data to be inserted: ");
    scanf("%d",&item);
    ptr = root;
    while(ptr!=NULL && flag == false){
        if(item < ptr->data){
            ptr1 = ptr;
            ptr = ptr->left;
        }
        else if(item > ptr->data){
            ptr1 = ptr;
            ptr = ptr->right;
        }
        else if(ptr->data == item){
            flag = true;
            printf("Item already exist!");
            return;
        }
    }
    if(ptr == NULL){
        new = malloc(sizeof(struct node));
        new->data = item;
        new->left = NULL;
        new->right = NULL;
        if(ptr1->data < item){
            ptr1->right = new;
        }
        else{
            ptr1->left = new;
        }
    }
}
struct node * successor(struct node *ptr){
    struct node *ptr1;
    ptr1 = ptr->right;
    if(ptr1!=NULL){
        while(ptr1->left!=NULL){
            ptr1 = ptr1->left;
        }
    }
    return ptr1;
}
void deletion(int item){
    struct node *ptr,*ptr1,*parent;
    bool flag = false;
    ptr = root;
    int item1,c;
    while(ptr!=NULL && flag == false){
        if(item < ptr->data){
            parent = ptr;
            ptr = ptr->left;
        }
        else if(item > ptr->data){
            parent = ptr;
            ptr = ptr->right;
        }
        else if(ptr->data == item){
            flag = true;
        }
    }
    if(flag == false){
        printf("Item doen not exists!No deletion");
        return;
    }
    if(ptr->left == NULL && ptr->right == NULL){
        c = 1;
    }
    else if(ptr->left!=NULL && ptr->right!=NULL){
        c = 2;
    }
    else{
        c = 3;
    }
    if(c == 1){
        if(parent->left == ptr){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
        free(ptr);
    }
    else if(c == 2){
        if(parent->left == ptr){
            if(ptr->left = NULL){
                parent->left = ptr->right;
            }
            else{
                parent->left = ptr->left;
            }
        }
        else{
            if(parent->right == ptr){
                if(ptr->left = NULL){
                    parent->right = ptr->right;
                }
                else{
                    parent->right = ptr->left;
                }
            }
        }
        free(ptr);
    }
    else if(c == 3){
        ptr1 = successor(ptr);
        item1 = ptr->data;
        deletion(item1);
        ptr->data = item1;
    }
    inorder(root);
}
void preorder(struct node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(struct node *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}
void postorder(struct node *ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->data);
    }
}
void option(){
    int ch,item;
    printf("Enter your choice");
    while(1){
        printf("\n1-Create a BT 2-Insert a node 3-delete a node 4-inorder traversal 5-preoder 6 -postorder 7-stop the program ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create();
                        break;
            case 2: insertion();
                        break;
            case 3: printf("Enter the data to be deleted: ");
                    scanf("%d",&item);
                    deletion(item);
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
    int data;
    printf("Enter the root element: ");
    scanf("%d",&data);
    root = malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    option();
}
