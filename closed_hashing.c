#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int H = 11;
int h[10];
int hashDivision(int k){
    int index = k%H +1;
    return index;
}
int closed(int k,int insert){
    int i,index,m=3;
    index = hashDivision(k);
    bool flag = false;
    if(k == h[index]){
        return index;
    }
    else{
        if(insert==1 && h[index] <=0){
            h[index] = k;
            return;
        }
        i = (index+m)%H +1;
        while(i!=index && flag==false){
                if(h[i]<=0){
                    if(insert){
                        h[i] = k;
                        flag = true;
                        return;
                    }
                }
                else{
                    if(h[i] == k){
                        flag = true;
                        return i;
                    }
                    else
                        i = (i+m)%H + 1;
                    }
                }
        if(flag == false && i == index)
            printf("Table overflow");
    }
}
void hash(){
    int ch = 1,n,i,key,index;
    while(ch){
        printf("\nEnter your choice: 1-Insert to hash table 2-Search key 3-display 4-end program ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the no of key values you want to insert: ");
            scanf("%d",&n);
            for(i=1;i<=n;i++){
                printf("Enter the %dst key value : ",i);
                scanf("%d",&key);
                closed(key,1);
            }
        }
        else if(ch==2){
            printf("Enter the value to be searched: ");
            scanf("%d",&key);
            index = closed(key,0);
            if(index!=0)
                printf("Key found at index %d",index);
            else
                printf("Key not found!");
        }
        else if(ch==3){
            printf("Hash Table: \n index\tvalue\n");
            for(i=1;i<=10;i++){
                printf("%d\t%d\n",i,h[i]);
            }
        }
        else if(ch==4)
            exit(0);
    }
}
void main(){
    hash();
}

