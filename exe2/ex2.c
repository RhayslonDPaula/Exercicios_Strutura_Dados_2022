/*1.    Implemente um programa que solicite os dados de nome, idade e e-mail de
uma pessoa e armazene os dados em uma estrutura.

(a)   Crie uma função para imprimir os dados na tela.



2. Crie uma estrutura representando os alunos de um determinado curso. A
estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota
da segunda prova e nota da terceira prova.

(a) Permita ao usuário entrar com os dados de 5 alunos.

(b) Para cada aluno, calcule a média final e diga se ele foi aprovado ou
reprovado, considerando o valor 6 para aprovação.

(c) Para calcular a média crie uma função.*/
#include <stdio.h>

typedef struct {
  char nome[50];
  int idade;
  char email[50];
} pessoa;

typedef struct {
  char nome[50];
  int maluno;
  int notap1;
  int notap2;
  int notap3;
} matricula;

void ex1();

void ex2();

int media(matricula a);

void imprime(pessoa p);

int main(void) {
  ex1();
  ex2();
}

void ex1() {

  pessoa p1;

  printf("Digite o nome da pessoa   :");

  scanf("%s", p1.nome);

  printf("\nDigite a idade da pessoa  :");

  scanf("%d", &p1.idade);

  printf("\nDigite o E-mail da pessoa :");
  scanf("%s", p1.email);

  imprime(p1);
}
void imprime(pessoa p) {
  printf("%s \nTem %d anos de vida \nE seu E-mail é %s", p.nome, p.idade,
         p.email);
}
void ex2() {
  matricula aluno[5];
  int i = 0;
  do{
    
    printf("Digite a matricula do aluno     :");
    scanf("%d", &aluno[i].maluno);
    printf("\nDigite o nome do aluno          :");
    scanf("%s", aluno[i].nome);
    printf("\nDigite a nota da primeira prova :");
    scanf("%d", &aluno[i].notap1);
    printf("\nDigite a nota da segunda prova  :");
    scanf("%d", &aluno[i].notap2);
    printf("\nDigite a nota da terceira prova :");
    scanf("%d", &aluno[i].notap3);

    if (media(aluno[i]) >= 6) {
      printf("\nAluno %s foi aprovado!", aluno[i].nome);
    } else {
      printf("\nAluno %s foi reprovado!", aluno[i].nome);
    }
    printf("\n");
    printf("\n");
  i++;
 } while (i<5);
}

int media(matricula a) {
  int media;
  media = ((a.notap1 + a.notap2 + a.notap3) / 3);
  return media;
}