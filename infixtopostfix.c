#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int n,top1= -1,top2= -1,top3 =-1,index1=0,index2=0,w=0,eval[20];
char stack[20],out[20];
void input(char arr[]){
    printf("Enter the arithmetic expression with ) at the end: ");
    scanf("%s",arr);
    n = strlen(arr);
}

int ISP(char x){
    if(x=='+'||x=='-'){
        return 2;
        }
    else if(x=='*'||x=='/'){
        return 4;
        }
    else if(x=='^'){
        return 5;
        }
    else if(x=='('){
        return 0;
        }
}

int ICP(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 6;
    }
    else if(x=='('){
        return 9;
    }
    else if(x==')'){
        return 0;
    }
}

char readSymbol(char arr[],int *index){
    int v = strlen(arr);
    if((*index)<v){
        return arr[((*index)++)];
    }
}

void push(char ar[],char item,int *top){
    int v = strlen(ar);
    if((*top)>=v){
        printf("Stack Overflow");
        exit(0);
    }
    ar[++(*top)] = item;
}

char pop(char ar[],int *top){
    if((*top)<0){
        printf("Stack underflow");
        exit(0);
    }
    char item = ar[(*top)--];
    return item;
}

void output(char d){
    if(d!=')'&&d!='('){
        push(out,d,&top2);
        printf("%c",d);
    }
}

void postfix(char arr[]){
    top1 = -1;
    push(stack,'(',&top1);
    while(top1>-1){
        char item = readSymbol(arr,&index1);
        char x= pop(stack,&top1);
        if(isalnum(item)){
            push(stack,x,&top1);
            output(item);
        }
        else if(item == ')'){
            while(x !='('){
                output(x);
                x = pop(stack,&top1);
            }
        }
        else if(ISP(x)>= ICP(item)){
            while(ISP(x)>= ICP(item)){
                output(x);
                x = pop(stack,&top1);
            }
            push(stack,x,&top1);
            push(stack,item,&top1);
        }
        else if (ICP(item)>ISP(x)){
            push(stack,x,&top1);
            push(stack,item,&top1);
        }
        else printf("Invalid expression!");
    }
}

float calc(float y,float x,char op){
    float sum,diff,quo,prod,expo;
    switch(op){
        case '+': sum = x+y;
                    return sum;
                    break;
        case '-': diff = x-y;
                    return diff;
                    break;
        case '/': quo = x/y;
                    return quo;
                    break;
        case '*': prod = x*y;
                    return prod;
                    break;
        case '^': expo = pow(x,y);
                    return expo;
                    break;
        default: printf("Invalid!");
    }
}

void pushf(float item){
    int k = strlen(eval);
    if(top3>k){
        printf("\nStack Overflow");
        exit(0);
    }
    eval[(++top3)] = item;
}

char popf(){
    if(top3<0){
        printf("Stack underflow");
        exit(0);
    }
    char item = eval[top3--];
    return item;
}

void EvalPostfix(char arr[]){
    int g = strlen(out);
    out[g] = '#';
    float x,y,t,val,l;
    char item = readSymbol(out,&index2);
    while(item !='#'){
        if(isalnum(item)){
            l = atof(&item);
            pushf(l);
        }
        else{
            char op = item;
            y = popf();
            x = popf();
            t = calc(y,x,op);
            pushf(t);
        }
        item = readSymbol(out,&index2);
    }
    val = popf();
    printf("\nValue : %f",val);
}

void main(){
    char a[20];
    input(a);
    printf("postfix : ");
    postfix(a);
    EvalPostfix(out);
}
