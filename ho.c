#include<stdio.h>
void main(){
char name[10] = "hello";
char *ptr;
ptr = name;
printf("%c",*(ptr +1));
printf("%c",*ptr+1);
}
