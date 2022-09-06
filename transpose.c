#include<stdio.h>
#define MAX_TERMS 100

typedef struct{
    int row,col,value;
}term;

void main(){
    term a[MAX_TERMS];
    term b[MAX_TERMS];
    int currentB,i,j,r,c,count=1;
    printf("Enter the no of rows: ");
    scanf("%d",&r);
    printf("Enter the no of columns: ");
    scanf("%d",&c);

    int matrix[r][c];
    printf("Enter the matrix row by row:");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    a[0].row=r;
    a[0].col=c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(matrix[i][j]!=0){
                a[count].row=i;
                a[count].col=j;
                a[count].value=matrix[i][j];
                count++;
            }
        }
    }

    a[0].value=count-1;
    printf("The matrix in tuple form is :   ");
    printf("\nRow  Column  Value\n");
    for(i=0;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }

    int t = a[0].value;
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    b[0].value=a[0].value;
    if(t>0){
         currentB=1;
        for(i=0;i<=(a[0].col-1);i++){
            for(j=1;j<=t;j++){
                if(a[j].col==i){
                    b[currentB].col=a[j].row;
                    b[currentB].row=a[j].col;
                    b[currentB].value=a[j].value;
                    currentB++;
                }
            }
        }
    }

    printf("Transpose of the matrix in tuple form is :   ");
    printf("\nRow  Column  Value\n");
    for(i=0;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
    }
}
