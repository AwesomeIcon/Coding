#include <stdio.h>
#include <stdlib.h>

typedef struct Jonse
{
    struct Jonse *next;
    int           code;
} Jonse;

Jonse *create(int n)
{
    int i,a;
    Jonse *head,*p,*q;
    head = NULL;
    printf("Input the integers:\n");
    for(i=n;i>0;i--)
    {
        p = malloc(sizeof(Jonse));
        scanf("%d",&a);
        p->code = a;
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
    q->next = head;
    return head;
};

void ShowList(Jonse *L)
{
    printf("The number join this game:\n");
    int origin;
    origin = L->code;
    printf("%4d",L->code);
    L = L->next;
    while(L->code != origin)
    {
        printf("%4d",L->code);
        L = L->next;
    }
    printf("\n");
}

Jonse* JonseOut(Jonse* L,int m,int n)
{
    int a,b;
    Jonse *p;
    printf("Game begin!\n");
    for(a = 1;a < n;a++)
    {
        for(b = 0;b < m-2;b++)
        {
            L = L->next;
        }
        p = L->next;
        L->next = p->next;
        L = L->next;
        printf("%d died!\n",p->code);
        free(p);
    }
    printf("%d alive!\n",L->code);
    L->next = NULL;
}

int main()
{
    Jonse *L;
    int m,n;
    printf("The number of people:");
    scanf("%d",&n);
    printf("The Loop:");
    scanf("%d",&m);
    L = create(n);
    ShowList(L);
    JonseOut(L,m,n);
    return 0;
}
