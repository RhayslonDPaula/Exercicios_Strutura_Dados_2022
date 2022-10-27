/*
1-)  Utilizando o método bolha, quantas trocas são necessárias para que a sequência [66,  84,  4,  
21,  71,  40] seja ordenada de modo crescente?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define N 6

void ex1 (int b[]);
void troca (int *x,int *y);
void imprime(int vet[]);
int main(int argc, char const *argv[])
{
  
  int v[] = {66,84,4,21,71,40};
  imprime(v);
  ex1(v);
  imprime(v);
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
  
