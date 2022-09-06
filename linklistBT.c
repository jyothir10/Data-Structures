#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *left;
     struct node *right;
}*lchild,*rchild,*root;
void create(struct node *ptr,int item){
    int option,itemLeft,itemRight;
    if(ptr!=NULL){
        ptr->data = item;
        printf("Node with data %d has a left subtree? (1-Yes,2-No) ",ptr->data);
        scanf("%d",&option);
        if(option==1){
            printf("Enter the data to be inserted: ");
            scanf("%d",&itemLeft);
            lchild = malloc(sizeof(struct node));
            ptr->left = lchild;
            create(lchild,itemLeft);
        }
        else{
            ptr->left = NULL;
            create(NULL,0);
        }
        printf("Node with data %d has a right subtree? (1-Yes,2-No) ",ptr->data);
        scanf("%d",&option);
        if(option==1){
            printf("Enter the data to be inserted: ");
            scanf("%d",&itemRight);
            rchild = malloc(sizeof(struct node));
            ptr->right = rchild;
            create(rchild,itemRight);
        }
        else{
            ptr->right = NULL;
            create(NULL,0);
        }
    }
}
struct node * searchLink(struct node *temp,int key){
    struct node *t;
    if(temp->data!=key){
        if(temp->left!=NULL){
            t = searchLink(temp->left,key);
            if(t!=NULL){
                return t;
            }
        }
        else{
            return(NULL);
        }
        if(temp->right!=NULL){
            t = searchLink(temp->right,key);
            if(t!=NULL){
                return t;
            }
        }
        else{
            return(NULL);
        }
    }
    else{
        return temp;
    }
}
void insertion(struct node *base){
    struct node *temp,*ptr;
    int option,key,insert;
    printf("Enter the element after which you have to insert : ");
    scanf("%d",&insert);
    temp = searchLink(base,insert);
    if(temp == NULL){
        printf("Unsuccessful Search! No insertion");
        return;
    }
    if(temp->left!=NULL && temp->right!=NULL){
        printf("Insertion not possible : Nodes present");
    }
    else{
        if(temp->left==NULL && temp->right == NULL){
            printf("Insert node as left or right? (1-left,0-right) ");
            scanf("%d",&option);
        }
        ptr = malloc(sizeof(struct node));
        printf("Enter the data to be inserted ");
        scanf("%d",&key);
        ptr->data = key;
        ptr->left = NULL;
        ptr->right = NULL;
        if(option == 1 || temp->right!=NULL){
            temp->left = ptr;
        }
        else if(option == 0 || temp->left!=NULL){
            temp->right = ptr;
        }
        preorder(root);
    }
}
struct node * searchParent(struct node *ptr,int item,struct node *pred){
    struct node *parent = NULL,*t;
    if(ptr == NULL){
        return NULL;
    }
    if(ptr->data == item){
        parent = pred;
        return pred;
    }
    else{
        t = searchParent(ptr->left,item,ptr);
        if(t!=NULL){
                return t;
            }
        t = searchParent(ptr->right,item,ptr);
        if(t!=NULL){
                return t;
            }
        return parent;
    }
}
void deletion(struct node *ptr){
    struct node *parent,*ptr1,*ptr2;
    int delete;
    if(ptr == NULL){
        printf("Tree is empty! NO deletion");
        return;
    }
    printf("Enter the element which you have to delete : ");
    scanf("%d",&delete);
    parent = searchParent(ptr,delete,NULL);
    if(parent!=NULL){
        ptr1 = parent->left;
        ptr2 = parent->right;
        if(ptr1!=NULL && ptr1->data == delete){
            if(ptr1->left!=NULL || ptr1->right!=NULL){
                printf("Not a leaf node : No deletion");
                return;
            }
            parent->left = NULL;
            free(ptr1);
        }
        else if(ptr2!=NULL && ptr2->data == delete){
            if(ptr2->left!=NULL || ptr2->right!=NULL){
                printf("Not a leaf node : No deletion");
                return;
            }
            parent->right = NULL;
            free(ptr2);
        }
        preorder(root);
    }
    else{
        printf("Unsuccessfull search! ");
    }
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
void option(struct node *root,int data){
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
    int data;
    printf("Enter the root element: ");
    scanf("%d",&data);
    root = malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    option(root,data);
}
