#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int           num;
    float       price;
} Node;

int main()
{
    Node *p,*q,*head;
    int num;
    char c;
    float price;
    head = NULL;
    while(1)
    {
        printf("Input the price of TV:");
        scanf("%f",&price);
        printf("Input the num of this TV:");
        scanf("%d",&num);
        fflush(stdin);
        if(head == NULL)
        {
            p = malloc(sizeof(Node));
            p->num = num;
            p->price = price;
            head = p;
            head->next = NULL;
        }else{
            int flag = 0;
            q = head;
            while(q)
            {
                if(q->price == price)
                {
                    q->num += num;
                    flag = 1;
                }
                if(q->next)
                {
                    q = q->next;
                }else{
                    break;
                }
            }
            if(flag == 0)
            {
                p = malloc(sizeof(Node));
                p->num = num;
                p->price = price;
                q->next = p;
                q = p;
                q->next = NULL;
            }
        }
        printf("Continue or not?(Y/N):");
        scanf("%c",&c);
        if(c == 'N')
        {
            break;
        }
    }
    while(head)
    {
        printf("price:%.2f,number:%2d\n",head->price,head->num);
        head = head->next;
    }
    return 0;
}
