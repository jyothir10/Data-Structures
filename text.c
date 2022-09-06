#include<stdio.h>
void main(){

FILE *fp;
char a;
int ch=0,w=0,l=0;
fp = fopen("word.txt","w");
printf("Enter the text: \n");
while((a=getchar())!=EOF)
{
    putc(a,fp);
}
fclose(fp);

fp = fopen("word.txt","r");
while((a = getc(fp))!= EOF)
{
    if(a==' ')
    {
        w++;
    }
    else if(a=='.')
    {
        l++;
    }
    else
    {
        ch++;
    }
}
 printf("No of characters is: %d\n",ch);
 printf("No of words is: %d\n",(w+1));
 printf("No of lines is: %d\n",l);

 fp = fopen("result.txt","w");
 putw(ch,fp);
 putw((w+1),fp);
 putw(l,fp);
 fclose(fp);

}

