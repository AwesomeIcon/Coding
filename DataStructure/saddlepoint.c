#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 5

typedef struct Node
{
    int a;
    int b;
    int value;
}Node;

int main()
{
    int a[M][N]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    int i,j,m,n,temp;
    Node p[M],q[N];
    for(i=0;i<M;i++)
    {
        temp = 10000;
        for(j=0;j<N;j++)
        {
            if(a[i][j] < temp)
            {
                temp = a[i][j];
                m = i;
                n = j;
            }
        }
        q[i].a = m;
        q[i].b = n;
        q[i].value = temp;
    }
    for(j=0;j<N;j++)
    {
        temp = -1000;
        for(i=0;i<M;i++)
        {
            if(a[i][j] > temp)
            {
                temp = a[i][j];
                m = i;
                n = j;
            }
        }
        p[j].a = m;
        p[j].b = n;
        p[j].value = temp;
    }
    printf("saddle point are:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(q[i].a == p[j].a && q[i].b == p[j].b)
            {
                printf("%4d",q[i].value);
            }
        }
    }
    return 0;
}
