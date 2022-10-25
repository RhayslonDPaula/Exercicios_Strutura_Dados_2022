#include <stdio.h>
#include<stdlib.h>
#define N 3

typedef struct No{
    int info;
    struct No* prox;
} No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;

//protótipos
No* criar_no(int v);
Fila* criar_fila();
int fila_vazia(Fila *f);
void enfileirar_fila(Fila *f, int v);
int desenfileirar_fila(Fila *f);
void imprimir_fila(Fila *f);

int main(){
    Fila *f = criar_fila();
    enfileirar_fila(f,10);
    imprimir_fila(f);

    enfileirar_fila(f,20);
    imprimir_fila(f);

    enfileirar_fila(f,30);
    imprimir_fila(f);

    desenfileirar_fila(f);
    imprimir_fila(f);

    desenfileirar_fila(f);
    imprimir_fila(f);

    desenfileirar_fila(f);
    imprimir_fila(f);

    desenfileirar_fila(f);
    imprimir_fila(f);

    return -1;
}

Fila* criar_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

No* criar_no(int v){
 No* n = (No*)malloc(sizeof(No));
 n->info = v;
 n->prox = NULL;
 return n;
}

int fila_vazia(Fila *f){
    return (f->inicio==NULL);
}

void enfileirar_fila(Fila *f, int v){
    No* novo = criar_no(v);
    if(fila_vazia(f)){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int desenfileirar_fila(Fila *f){
    int val;
    No *aux;
    if(fila_vazia(f)){
        printf("Erro: Fila vazia\n");
        return -1;
    }
    else{
        aux=f->inicio;
        val = aux->info;
        f->inicio = aux->prox;
        if(f->inicio==NULL){
            f->fim = NULL;
        }
        free(aux);
        return val;
    }
}

void imprimir_fila(Fila *f){
    No *aux = f->inicio;
    printf("Fila:\n");
    while(aux!=NULL){
        printf("%d, ",aux->info);
        aux= aux->prox;
    }
    printf("\n");
}
