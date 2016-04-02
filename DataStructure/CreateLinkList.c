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

int main()
{
    int n;
    printf("Input the Length of List:");
    scanf("%d",&n);
    LinkList *node;
    node = create(n);
    printf("The result is:\n");
    while(node)
    {
        printf("%4d",node->value);
        node = node->next;
    }
    return 0;
}
