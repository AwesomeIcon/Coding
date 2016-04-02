#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,temp,N;
    int *array;
    printf("Please input array's length N:");
    scanf("%d",&N);
    array = malloc(N*sizeof(int));
    if( array != NULL)
    {
        for(i=0;i<N;i++)
        {
            printf("array[%d] = ",i);
            scanf("%d",&array[i]);
        }
    }else
    {
        printf("Out of memory!\n");
        exit(1);
    }
    for(i=0;i<N/2;i++)
    {
        temp         = array[i];
        array[i]     = array[N-i-1];
        array[N-i-1] = temp;
    }
    printf("Reverse into:\n");
    for(i=0;i<N;i++)
    {
        printf("array[%d] = %d\n",i,array[i]);
    }
    free( array );
    return 0;
}
