#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
    struct LinkList *next;
    int             value;
} LinkList;

struct LinkList *create(int n)
{
    int i,a;
    LinkList *head,*p,*q;
    head = NULL;
    printf("Input the integers:\n");
    for(i=n;i>0;i--)
    {
        p = malloc(sizeof(LinkList));
        scanf("%d",&a);
        p->value = a;
        if(head == NULL)
        {
            head = p;
            q = p;
        }else
        {
            q->next = p;
            q = p;
        }
    }
    q->next = NULL;
    return head;
};

void ReverseLinkList(LinkList *L)
{
    LinkList *p,*q;
    p = L;
    L = L->next;
    q = L->next;
    p->next =NULL;
    while(L)
    {
        if(L->next == NULL)
        {
            L->next = p;
            break;
        }
        L->next = p;
        p = L;
        L = q;
        q = q->next;
    }
    while(L)
    {
        printf("%4d",L->value);
        L = L->next;
    }
}

int main()
{
    int n;
    printf("Input the Length of List:");
    scanf("%d",&n);
    LinkList *node;
    node = create(n);
    printf("The reversed result is:\n");
    ReverseLinkList(node);
    return 0;
}
