#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void quick(int* vet, int tamanho)
{
    qsort (vet, tamanho, sizeof(int), compare);
}
