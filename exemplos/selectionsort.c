#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6

void troca(int *x, int *y);
void selection(int vet[]);
void preenche(int vet[], int max);
void imprime(int vet[]);

int main() {
  int vet[N] = {39,59,03,05,02,11};
  //preenche(vet,N);
  imprime(vet);
  selection(vet);
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

void selection(int vet[]) {
  int i, j, min,t=0,c=0;

  for (i=0; i<N-1; i++) {
    printf("Iteracao %d:\n",i+1);
    min = i;
    for (j=i+1; j<N; j++) {
      c++;
      if (vet[j] < vet[min]) {
        min = j;
      }
    }
    troca(&vet[min], &vet[i]);
    t++;
    imprime(vet);
    printf("\n");
  }
  printf("Resumo:\n %d Comparacoes \n %d Trocas\n",c,t);
}

