/*
1-)  Utilizando o método bolha, quantas trocas são necessárias para que a sequência [66,  84,  4,  
21,  71,  40] seja ordenada de modo crescente?

2-) Utilizando o método bolha, quantas trocas são necessárias para que a sequência [0  52  86  34  
82  7  5] seja ordenada de modo decrescente?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define N 6

void ex1 (int b[]);
void ex2 (int o);
void troca (int *x,int *y);
void imprime(int vet[]);
int main(int argc, char const *argv[])
{
  
  int v[] = {66,84,4,21,71,40};
  imprime(v);
  ex1(v);
  imprime(v);
  int t[] = {0,52,86,34,82,7,5};
 
  exe2(t);
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
void ex2 (int o){
  int i,j,u=0;
  for ( i = 0; i < N; i++)
  {
    for ( j = 1; j < N; j++)
    {
      if (o[j-1] < o[j])
      {
        troca(&o[j],&o[j-1]);
        u++;
      }
      
    }
    
  }
  printf("numero de trocas%d",u);
}
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
  
