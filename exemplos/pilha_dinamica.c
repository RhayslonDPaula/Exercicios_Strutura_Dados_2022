#include<stdio.h>
#include<stdlib.h>
#define N 3 //número máximo de elementos


typedef struct No{
  int info;
  struct No* prox;
}No;

typedef struct Pilha{
    No* topo;
}Pilha;

/*Operações básicas com pilhas*/
Pilha* criar_pilha();
No* criar_no(int v);
void pilha_push (Pilha*, int);
int pilha_vazia(Pilha*);
void pilha_push(Pilha*, int);
int pilha_pop(Pilha*);
int mostrar_topo(Pilha*);
void imprimir_pilha(Pilha*);

int main()
{
    Pilha *p;
    p = criar_pilha();
    pilha_push(p,15);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    system("pause");
    pilha_push(p,20);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    system("pause");
    pilha_push(p,25);
    printf("Pilha topo: %d\n",mostrar_topo(p));
    system("pause");
    imprimir_pilha(p);
    system("pause");
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    system("pause");
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    system("pause");
    printf("Retirando %d ....\n",pilha_pop(p));
    imprimir_pilha(p);
    system("pause");
    printf("Retirando %d ....\n",pilha_pop(p));
    return -1;
}

Pilha* criar_pilha()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

No* criar_no(int v){
  No *n = (No*) malloc(sizeof(No));
  n->info = v;
  n->prox = NULL;
  return n;
}


int pilha_vazia(Pilha *p)
{
    return (p->topo==NULL);
}


void pilha_push(Pilha *p, int v){
    No* novo = criar_no(v);
    novo->prox = p->topo;
    p->topo = novo;
}

int mostrar_topo(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("A pilha esta vazia.\n");
        return -1;
    }
    return p->topo->info;
}

int pilha_pop(Pilha *p){
    No* aux;
    int val;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return -1;
    }
    aux = p->topo;
    val = aux->info;
    p->topo = aux->prox;
    free(aux);
    return val;
}

void imprimir_pilha(Pilha *p){//Apenas para debug da pilha. Não faz parte das operações.
 No* aux = p->topo;
 while(aux){
    printf("[%d]  ",aux->info);
    aux = aux->prox;
 }
 printf("\n");
}
