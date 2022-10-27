#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void troca(int *x, int *y);
void insertion(int vet[]);
void preenche(int vet[], int max);
void imprime(int vet[]);

int main() {
  int vet[N]={7,6,5,4,3,2,1};

  //preenche(vet,N);
  imprime(vet);
  insertion(vet);
  imprime(vet);
}

void troca(int *x, int *y) {
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}

void preenche(int vet[], int max) {
  int i;
  //srand(time(NULL));
  for (i=0; i<N; i++) {
    vet[i] = (rand() % max)+1;
  }
}


void imprime(int vet[]) {
  int i;
  for (i=0; i<N; i++) {
    printf("[%d]", vet[i]);
  }
  printf("\n");
}

void insertion(int vet[]) {
  int i, j,flag=0, trocas=0;
  for (i=1; i<N; i++) {
    printf("Iteracao %d:\n",i);
    flag=0;
    for (j=i; j>0 && vet[j] < vet[j-1]; j--) {
      troca(&vet[j-1], &vet[j]);
      trocas++;
      imprime(vet);
      flag=1;
    }
    if(flag==0){
    imprime(vet);
    }
    printf("\n");
  }
  printf("Trocas:%d\n",trocas);
}
