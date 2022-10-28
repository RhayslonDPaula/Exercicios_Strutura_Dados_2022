#include<stdio.h>
#define N 8

void troca(int *x, int *y);
void quicksort(int vet[], int left, int right);
int partition(int vet[], int left, int right);
void imprime(int vet[]);
int buscaBinaria(int vet[],int key,int left, int right);
int buscaBinariaIterativo(int vet[],int key,int left, int right);

int main()
{
    int vet[N]= {5,25,10,6,8,4,3,9},val;
    imprime(vet);
    quicksort(vet,0,N-1);
    printf("\n\n");
    imprime(vet);
    val = buscaBinariaIterativo(vet,10,0,N-1);
    if(val < 0)
        printf("Valor nao encontrado!\n");
    else
        printf("valor encontrado na posicao %d. \n",val+1);
    return 0;
}

int buscaBinaria(int vet[],int key,int left, int right)
{
    int mid;
    if(left>right)
        return -1;
    mid = (left+right)/2;
    if(key == vet[mid])
        return mid;
    else if(key < vet[mid])
        return buscaBinaria(vet, key,left, mid-1);
    else
        return buscaBinaria(vet,key,mid+1,right);

}

int buscaBinariaIterativo(int vet[],int key,int left, int right)
{
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(key == vet[mid])
            return mid;
        else if(key < vet[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}


void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void imprime(int vet[])
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

void quicksort(int vet[], int left, int right)
{
    int pivot;
    if (left >= right)
    {
        return;
    }
    pivot = partition(vet, left, right);
    quicksort(vet, left, pivot-1);
    quicksort(vet, pivot+1, right);
}

int partition(int vet[], int left, int right)
{
    int i = left + 1, j = right;

    while(i<=j)
    {
        while (vet[i] <= vet[left] && i <= right) i++;
        while (vet[j] > vet[left] && j > left) j--;

        if (i < j) troca(&vet[i], &vet[j]);
    }
    troca(&vet[j], &vet[left]);

    return j;
}
