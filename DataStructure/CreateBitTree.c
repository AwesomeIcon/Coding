#include <stdio.h>
#include <stdlib.h>

typedef struct bitTree
{
    char value;
    struct bitTree *lchild;
    struct bitTree *rchild;
}bitTree;

bitTree *create()
{
    char a;
    bitTree *T;
    scanf("%c",&a);
    if(a == "") T = NULL;
    else{
        T = malloc(sizeof(bitTree));
        T->value = a;
        T->lchild = create(T->lchild);
        T->rchild = create(T->rchild);
    }
    return T;
}

void PreOrder(bitTree *T)
{
    if(T!= NULL)
    {
        printf("%4d",T->value);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

int main()
{
    bitTree *Ta;
    printf("Create a biTree...\n");
    Ta = create();
    printf("bitTree is:\n");
    PreOrder(Ta);
    return 0;
}
