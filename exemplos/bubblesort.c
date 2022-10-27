#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6

void troca(int *x, int *y);
void bubble(int vet[]);
void bubble2(int vet[]);
void bubble3(int vet[]);
void preenche(int vet[], int max);
void imprime(int vet[]);

int main() {
  int vet[N]={39,59,03,05,02,11};

  //preenche(vet,N);
  imprime(vet);
  bubble3(vet);
  printf("\n\n");
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
  srand(time(NULL));
  for (i=0; i<N; i++) {
    vet[i] = (rand() % max)+1;
  }
}

void imprime(int vet[]) {
  int i;
  for (i=0; i<N; i++) {
    printf("[%d] ", vet[i]);
  }
  printf("\n");
}

void bubble(int vet[]) {
  int i, j, c=0,t=0;
  for (i=0; i<N; i++) {
        printf("Iteracao %d:\n",i+1);
    for(j=1; j<N; j++){
        c++;
      if (vet[j-1] > vet[j]) {
        troca(&vet[j], &vet[j-1]);
        t++;
      }
     imprime(vet);
    }
    printf("\n");
  }
  printf("Resumo:\n %d Comparacoes \n %d Trocas",c,t);
}

void bubble2(int vet[]) {
  int i, j,c=0,t=0;
  for (i=0; i<N-1; i++) {
      printf("Iteracao %d:\n",i+1);
    for(j=1; j<N-i; j++){
       c++;
      if (vet[j-1] > vet[j]) {
        t++;
        troca(&vet[j], &vet[j-1]);
      }
      imprime(vet);
    }
    printf("\n");
  }
  printf("Resumo:\n %d Comparacoes \n %d Trocas",c,t);
}

void bubble3(int vet[]) {
  int i, j, status = 1,c=0,t=0;
  for (i=0; i<N-1 && status; i++) {
    printf("Iteracao %d:\n",i+1);
    status = 0;
    for(j=1; j<N-i; j++){
        c++;
      if (vet[j-1] > vet[j]) {
        status = 1;
        troca(&vet[j], &vet[j-1]);
        t++;
      }
      imprime(vet);
    }
    printf("\n");
  }
  printf("Resumo:\n %d Comparacoes \n %d Trocas",c,t);
}
