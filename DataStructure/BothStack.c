#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 100
typedef struct BothStack
{
    int data[STACKSIZE];
    int top1;
    int top2;
}BothStack;

void InitBothStack(BothStack *S)
{
    S->top1 = -1;
    S->top2 = STACKSIZE;
}

void push(BothStack *S,int n,int m)
{
    if(S->top2 - S->top1 == 1)
    {
        printf("Stack is full!\n");
        return;
    }
    if(n == 1)
    {
        S->top1 += 1;
        S->data[S->top1] = m;
    }else if(n == 2)
    {
        S->top2 -= 1;
        S->data[S->top2] = m;
    }
}

void pop(BothStack *S,int n)
{
    if(n == 1)
    {
        if(S->top1 == -1)
        {
            printf("no more data for 1!\n");
            return;
        }
        printf("%d is pop!\n",S->data[S->top1]);
        S->data[S->top1] = 0;
        S->top1 -= 1;
    }else if(n == 2)
    {
        if(S->top2 == STACKSIZE)
        {
            printf("no more data for 2!\n");
            return;
        }
        printf("%d is pop!\n",S->data[S->top2]);
        S->data[S->top2] = 0;
        S->top2 += 1;
    }
}

int main()
{
    BothStack S,*p;
    p = &S;
    InitBothStack(p);
    int n,m;
    char s[4],c;
    while(1)
    {
        printf("1 or 2?\n");
        scanf("%d",&n);
        if(n != 1 && n != 2)
        {
            printf("Error for n!\n");
            continue;
        }
        fflush(stdin);
        printf("push or pop?\n");
        gets(s);
        if(!strcmp(s,"push"))
        {
            printf("the number you want to push:");
            scanf("%d",&m);
            push(p,n,m);
        }
        if(!strcmp(s,"pop"))
        {
            pop(p,n);
        }
        fflush(stdin);
        printf("continue?(Y/N)");
        scanf("%c",&c);
        if(c == 'N')
        {
            break;
        }
    }
    printf("goodbye!");
    return 0;
}
