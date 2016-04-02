#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k=0;
    int *p,*q,*r;
    r = NULL;
    printf("Input array A's length:");
    scanf("%d",&n);
    p = malloc(sizeof(int)*n);
    printf("Input data:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Input array B's length:");
    scanf("%d",&m);
    q = malloc(sizeof(int)*m);
    printf("Input data:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&q[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[j] == q[i])
            {
                if(r == NULL)
                {
                    r = malloc(sizeof(int));
                    r[k] = q[i];
                    k++;
                }else
                {
                    r = realloc(r,sizeof(int));
                    r[k] = q[i];
                    k++;
                }
            }
        }
    }
    printf("The array C is:\n");
    for(i=0;i<k;i++)
    {
        printf("%4d",r[i]);
        if( (i+1)%5 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}
