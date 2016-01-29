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

void CombineLinkList(LinkList *L1,LinkList *L2,int a)
{
    LinkList *L,*head,*p;
    head = NULL;
    int i;
    for(i=0;i<a;i++)
    {
        L = malloc(sizeof(LinkList));
        if(L1&&L2)
        {
            if((L1->value) < (L2->value))
            {
                L->value = L1->value;
                L1 = L1->next;
                if(head == NULL)
                {
                    head = L;
                    p = L;
                }else
                {
                    p->next = L;
                    p = L;
                }
            }else
            {
                L->value = L2->value;
                L2 = L2->next;
                if(head == NULL)
                {
                    head = L;
                    p = L;
                }else
                {
                    p->next = L;
                    p = L;
                }
            }
        }else if(L1 && !L2)
        {
            L->value = L1->value;
            L1 = L1->next;
            p->next = L;
            p = L;
        }else if(L2 && !L1)
        {
            L->value = L2->value;
            L2 = L2->next;
            p->next = L;
            p = L;
        }
    }
    p->next = NULL;
    while(head)
    {
        printf("%4d",head->value);
        head = head->next;
    }
}

int main()
{
    int n,m;
    LinkList *L1,*L2;
    printf("Input the Length of L1:");
    scanf("%d",&n);
    L1 = create(n);
    printf("Input the Length of L2:");
    scanf("%d",&m);
    L2 = create(m);
    printf("The combined result is:\n");
    CombineLinkList(L1,L2,m+n);
    return 0;
}
