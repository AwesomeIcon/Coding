#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100
typedef struct Node
{
    int top;
    int data[STACKSIZE];
}Node;

void changeradix(Node *p,int n,int m)
{
    while(n != 0)
    {
        p->top += 1;
        p->data[p->top] = n%m;
        n = n/m;
    }
    while(p->top != -1)
    {
        printf("%d",p->data[p->top]);
        p->top -= 1;
    }
}

int main()
{
    int n,m;
    Node S,*p;
    p = &S;
    S.top = -1;
    printf("input a decimal number:");
    scanf("%d",&n);
    printf("which radix to change:(2-9)");
    scanf("%d",&m);
    changeradix(p,n,m);
    return 0;
}
