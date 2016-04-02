#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *enqueue(Node *p,int n,int i)
{
    Node *q,*temp;
    int m;
    q = malloc(sizeof(Node));
    q->data = n;
    if(i == 1)
    {
        p = q;
        p->next = p;
    }
    else if(i == 2)
    {
        p->next = q;
        q->next = p;
        p = q;
    }else
    {
        temp = p->next;
        p->next = q;
        q->next = temp;
        p = q;
    }
    q = p;
    printf("Now the queue is:\n");
    for(m=0;m<i;m++)
    {
        q = q->next;
        printf("%4d",q->data);
    }
    printf("\n");
    return p;
}

Node *dequeue(Node *p,int i)
{
    Node *q;
    int m;
    if(i == 1)
    {
        q = p->next;
        p->next = p;
    }else if(i <= 0)
    {
        p = NULL;
        printf("NO NODE NOW!\n");
        return p;
    }
    else
    {
        q = p->next;
        p->next = q->next;
        p = q;
    }
    printf("Now the queue is:\n");
    for(m=0;m<i;m++)
    {
        q = q->next;
        printf("%4d",q->data);
    }
    printf("\n");
    return p;
}

int main()
{
    Node *p;
    int n,i=0;
    char s[8],c;
    p = NULL;
    while(1)
    {
        printf("enqueue or dequeue?\n");
        gets(s);
        if(!strcmp(s,"enqueue"))
        {
            i++;
            if(i<=0)i=1;
            printf("number:");
            scanf("%d",&n);
            fflush(stdin);
            p = enqueue(p,n,i);
        }
        if(!strcmp(s,"dequeue"))
        {
            i--;
            p = dequeue(p,i);
        }
        printf("continue?(Y/N):");
        scanf("%c",&c);
        fflush(stdin);
        if(c == 'N')
            break;
    }
    return 0;
}
