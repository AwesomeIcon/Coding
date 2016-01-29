#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k;
    int *p,*q,*r;
    r = NULL;
    printf("Input array A's length:");
    scanf("%d",&n);
    p = malloc(sizeof(int)*n);
    k = n;
    r = malloc(sizeof(int)*k);
    printf("Input data:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        r[i] = p[i];
    }
    printf("Input array B's length:");
    scanf("%d",&m);
    q = malloc(sizeof(int)*m);
    printf("Input data:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&q[i]);
    }
    int flag = 1;
    for(i=0;i<m;i++)
    {
        flag = 1;
        for(j=0;j<n;j++)
        {
            if(q[i] == p[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            k++;
            r = realloc(r,sizeof(int)*k);
            r[k-1] = q[i];
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%4d",r[i]);
        if((i+1)%5==0)
        {
            printf("\n");
        }
    }
    return 0;
}
