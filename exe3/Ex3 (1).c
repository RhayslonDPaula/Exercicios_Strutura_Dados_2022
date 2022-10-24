

#include <stdio.h>
# define bt 10
/*
1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para
inteiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de
cada variável usando os ponteiros. Imprima os valores das variáveis antes e após a
modificação.
*/
void ex1();
/*
2. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2
variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B
terá o valor de A.
*/
void ex2();
/*
3. Crie um programa que contenha uma função que permita passar por referência dois
números inteiros A e B. A função deverá calcular a soma entre estes dois números e
armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas
deverá modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função
principal.
*/
void ex3();
/*
4. Faça um programa que receba do usuário dois vetores, A e B, com 10 números inteiros
cada. Crie um novo vetor denominado C calculando C = A- B. Mostre na tela os dados do
vetor C.
a. Faça por meio de ponteiros e alocação dinâmica.
b. Crie uma função receba como argumento os vetores A e B e retorne o vetor C.
*/
void ex4();

void troca (int *a,int *b);
void soma ();
void imprime (int d);
int * calcula (int *a,int *b);

int main(void) {
  //ex1();
  //ex2();
  //ex3();
  ex4();
  return 0;
}
void ex1(){
  int a = 0,*x = &a;
  char b = 'a',*y = &b;
  float c = 0,*z = &c;

  printf("a = %d\nb = %c\nc = %.1f\n",a,b,c);
  *x = 1;
  *y = 'b';
  *z = 1.3;
  
  printf("a = %d\nb = %c\nc = %.1f\n",a,b,c);
  
}
void ex2(){
  int r ,t;
  r = 9;
  t = 7;
  
  
  imprime(r);
  imprime(t);
  troca(&r,&t);
  imprime(r);
  imprime(t);
  
}
void troca (int *a,int *b){
  
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  
}
void ex3(){
  int a = 8, b = 6;
  imprime(a);
  imprime(b);
  soma(&a,&b);
  imprime(a);
  imprime(b);
  
}
void ex4(){
  int *a, *b;
  
  
  for(int i =0; i < 9; i++){
  printf("Digite 10 numeros");
  scanf("%d",&a[i]);
  }
   for(int i =0; i < 9; i++){
  printf("Digite 10 numeros");
  scanf("%d",&b[i]);
  }
   calcula (a,b);
}

int * calcula (int *a,int *b){
  
}

void imprime ( int d) {
  printf("\n%d\n",d);
}
void soma (int * x, int *y){
  *x+= *y;
}