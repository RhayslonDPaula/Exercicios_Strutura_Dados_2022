/*
1-)  Utilizando o método bolha, quantas trocas são necessárias para que a sequência [66,  84,  4,  
21,  71,  40] seja ordenada de modo crescente?

2-) Utilizando o método bolha, quantas trocas são necessárias para que a sequência [0  52  86  34  
82  7  5] seja ordenada de modo decrescente?

3-)  Utilizando  o  método  de  inserção,  quantas  trocas  serão  realizadas  para  ordenar  em  ordem 
crescente o vetor [7,  6,  5,  4,  3,  2,  1]? 

4-) Utilizando o método de ordenação por seleção, qual será a ordem do vetor [72,  83,  17,  75,  
31,  30] após o algoritmo realizar 3 trocas (ordenação crescente)?

5-)  Aplicando  o  método  quicksort  no  vetor  [7,  11,  14,  6,  9,  4,  3,  12].  Considerando  que  o  pivô 
selecionado é o primeiro elemento, qual será sua posição no vetor após a primeira iteração?

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define N 6,NE 7
# define NE 7

void ex1 (int b[]);
void ex2 (int o[]);
void ex3 (int h[]);
void t();
void ex4 (int a[]);
void ex5 (int b1[]);
void troca (int *x,int *y);
void imprime(int vet[]);

int main(int argc, char const *argv[])
{
  
  //int v[] = {66,84,4,21,71,40};
  //imprime(v);
  //ex1(v);
  //imprime(v);

  //int t[] = {0,52,86,34,82,7,5};
  //ex2(t);

  //int p[] = {7,  6,  5,  4,  3,  2,  1};

  //ex3(p);

  //int f[] = {72,83,17,75,31,30};

  //ex4(f);

  int v1[] = {7,  11,  14,  6,  9,  4,  3,  12}
  
  return 0;
}

void ex1(int b[]){
  int i,j;
for ( i = 0; i < N; i++)
{
  for ( j = 1; j < N; j++)
  {
    if (b[j-1] < b[j])
    {
      troca (&b[j],&b[j-1]);
    }
    
   
  }
  
}
}

void ex2(int o[]){
  int i,j,u=0;
  for ( i = 0; i < NE; i++)
  {
    for ( j = 1; j < NE; j++)
    {
      if (o[j-1] < o[j])
      {
        troca(&o[j],&o[j-1]);
        u++;
      }
      
    }
    
  }
  printf("numero de trocas %d",u);
}

void troca (int *x,int *y){
  int aux;
  aux= *x;
  *x = *y;
  *y =aux;

}

void imprime(int vet[]) {
  int i;
  for (i=0; i<N; i++) {
    printf("[%d] ", vet[i]);
  }
  printf("\n");
}

void ex3(int h[]){
  int i,j,flag = 0,trocas = 0;
  for (i = 1; i < NE; i++)
  {
    printf ("interacao %d:\n",i);
    flag = 0;
    for ( j=i ; j>0 && h[j] < h[j-1]; j--)
    {
      troca (&h[j-1],&h[j]);
      trocas++;
      imprime(h);
      flag = 1;
    }
    if (flag == 0)
      imprime(h);
    {
      printf("\n");
    }
    printf("Trocas:%d\n",trocas);
  }
  
}

void ex4 (int a[]){

  int i,j,mi,t = 0,c = 0;

  for ( i = 0; i < N-1; i++)
  {
    if (i <= 2)
    {
      printf ("Interacao %d:\n",i+1);
    }
    mi = i;
    for ( j=i+1; j < N; j++)
    {
      c++;
      if (a[j]< a[mi])
      {
        mi = j;
      }
      
    }
    troca(&a[mi],&a[i]);
    t++;
    if (i <= 2)
    {
    imprime(a);
    printf("\n");
    }
  }
  printf("Resumo: \n %d Comparacoes \n %d Trocas\n",c,t);
}

void ex5 (int b1[]){

}