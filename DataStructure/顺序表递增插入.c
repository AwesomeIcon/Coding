#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,i,j,N;
    printf("Please input array's length:");
    scanf("%d",&N);
    int *array = malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        printf("array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    printf("Please input a random number:");
    scanf("%d",&num);
    for (i=0;(num > array[i])&&(i < N);i++);
    N++;
    array = realloc(array,N*sizeof(int));
    for(j=N-1;j>i;j--)
    {
        array[j] = array[j-1];
    }
    array[i] = num;
    for(i=0;i<N;i++)
    {
        printf("array[%d] = %d\n",i,array[i]);
    }
    free(array);
    return 0;
}
