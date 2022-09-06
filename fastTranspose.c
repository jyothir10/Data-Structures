#include<stdio.h>
#define MAX_TERMS 100

typedef struct{
    int row,col,value;
}term;

void main(){
    term a[MAX_TERMS];
    term b[MAX_TERMS];
    int numCols,numTerms,i,j,r,c,count=1;
    int rowTerms[10];
    int startPosition[10];
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

    numCols = a[0].col,numTerms = a[0].value;
    b[0].row = numCols,b[0].col = a[0].row,b[0].value = numTerms;

    if(numTerms>0){
        for(i=0;i<=(numCols-1);i++){
            rowTerms[i] = 0;
        }
        for(i=1;i<=numTerms;i++){
            rowTerms[a[i].col]++;
        }
        startPosition[0] = 1;
        for(i=1;i<=(numCols-1);i++){
            startPosition[i] = startPosition[i-1] + rowTerms[i-1];
        }
        for(i=1;i<=numTerms;i++){
            j=startPosition[a[i].col]++;
            b[j].row = a[i].col,b[j].col = a[i].row,b[j].value = a[i].value;
        }
    }
    printf("The Transposed matrix in tuple form is :   ");
    printf("\nRow  Column  Value\n");
    for(i=0;i<=b[0].value;i++){
        printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
    }
}
