#include<stdio.h>
void main(){
FILE *fp;
int n;

printf("Enter the data: \n");
scanf("%d",&n);
fp = fopen("a.txt", "w");
fprintf(fp,"%d",n);
fclose(fp);

fp = fopen("a.txt","r");
fscanf(fp,"%d",&n);
printf("The data read from the file is : %d",n);
fclose(fp);

fp = fopen("a.txt", "a");
printf("\nEnter the new data: \n");
scanf("%d",&n);
fprintf(fp,"%d",n);
fclose(fp);

fp = fopen("a.txt","r");
fscanf(fp,"%d",&n);
printf("The data read from the file is : %d",n);
fclose(fp);
}
