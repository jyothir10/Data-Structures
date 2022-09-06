#include<stdio.h>
#define MAX_TERMS 100

typedef struct{
    int row,col,value;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];
term sum[MAX_TERMS];
int i,j,x=1,y=1;

void attach(int row,int column,int value){
    sum[x].row = row;
    sum[x].col = column;
    sum[x++].value = value;
}

void sparse(term z[MAX_TERMS]){
    int r,c,count=1;
    printf("Enter the no of rows of the %d'st matrix: ",y);
    scanf("%d",&r);
    printf("Enter the no of columns of the %d'st matrix: ",y);
    scanf("%d",&c);

    int matrix[r][c];
    printf("Enter the %d'st matrix row by row:",y);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    y++;
    z[0].row=r;
    z[0].col=c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(matrix[i][j]!=0){
                z[count].row=i;
                z[count].col=j;
                z[count++].value=matrix[i][j];
            }
        }
    }
    z[0].value=count-1;
}

void main(){
    sparse(a);
    sparse(b);

    printf("The first matrix in tuple form is: ");
    printf("\nRow  Column  Value\n");
    for(i=0;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }
    printf("The second matrix in tuple form is: ");
    printf("\nRow  Column  Value\n");
    for(i=0;i<=b[0].value;i++){
        printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
    }

    i=1,j=1;
    if(a[0].row == b[0].row && a[0].col == b[0].col){
        sum[0].row = a[0].row,sum[0].col = a[0].col;
        while(i<=a[0].value && j<=b[0].value){
                if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)){
                    attach(b[j].row,b[j].col,b[j].value);
                    j++;
                }
                else if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)){
                    attach(a[i].row,a[i].col,a[i].value);
                    i++;
                }
                else{
                    int val = a[i].value + b[j].value;
                    attach(a[i].row,a[i].col,val);
                    i++,j++;
                }
        }
        while(i<=a[0].value){
                attach(a[i].row,a[i].col,a[i].value);
                i++;
        }
        while(j<=b[0].value){
                attach(b[j].row,b[j].col,b[j].value);
                j++;
        }

        sum[0].value = x-1;
        printf("The sum of the matrix is: ");
        printf("\nRow  Column  Value\n");
        for(i=0;i<=sum[0].value;i++){
        printf("%d\t%d\t%d\n",sum[i].row,sum[i].col,sum[i].value);
        }
    }
    else {
        printf("The two matrix can't be added!");
    }
}
