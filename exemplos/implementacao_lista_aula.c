#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int info;
    struct No* prox;
} No;


typedef struct Lista {
    No* inicio;
} Lista;

//protótipos
Lista* criar_lista(void);
int lista_vazia(Lista *l);
No* criar_no(int v);
int info_no(No *n);
int tamanho_lista(Lista *l);
void mostrar_lista(Lista *l);
No* adicionar_inicio(Lista *l, int v);
No* adicionar_novo_no(No *n, int v);
int indice_no(Lista *l, int v);
No* retornar_no_pos(Lista *l, int pos);
No* adicionar_no_pos(Lista *l, int v, int pos);
int del_primeiro_no(Lista *l);
int del_no_lista(No *ant);
int del_no_pos(Lista *l, int pos);
int del_no_valor(Lista *l, int v);

//
void inserir_par_impar(Lista *l, int v);


int main(){
    Lista *l1 = criar_lista();
    Lista *l2 = criar_lista();
    Lista *l3 = criar_lista();


   //Lista l1 - Teste de inserção e remoção
    printf("Lista L1 - Operacoes basicas.\n\n");
    printf("Adicionando 10 no incio...\n");
    adicionar_inicio(l1,10);
    mostrar_lista(l1);
    printf("Adicionando 20 no incio...\n");
    adicionar_inicio(l1,20);
    mostrar_lista(l1);
    printf("Adicionando 30 no incio...\n");
    adicionar_inicio(l1,30);
    mostrar_lista(l1);
    printf("Adicionando 45 na pos 1...\n");
    adicionar_no_pos(l1,45,1);
    mostrar_lista(l1);
    printf("Adicionando 50 na pos 4...\n");
    adicionar_no_pos(l1,50,4);
    mostrar_lista(l1);
    printf("Removendo o primeiro elemento...%d\n",del_primeiro_no(l1));
    mostrar_lista(l1);
    printf("Removendo o segundo elemento...%d\n",del_no_pos(l1,1));
    mostrar_lista(l1);
    printf("Removendo o terceiro elemento...%d\n",del_no_pos(l1,2));
    mostrar_lista(l1);
    printf("Removendo o elemento 10... pos:%d\n",del_no_valor(l1,10));
    mostrar_lista(l1);

    printf("\nLista L2 - Teste da funcao de insercao de valores pares no inicio e impares no final.\n\n");
    //Lista 2 - Inserção de valores pares no início e ímpares no final
    printf("Adicionando 10... \n");
    inserir_par_impar(l2,10);
    mostrar_lista(l2);
    printf("Adicionando 11... \n");
    inserir_par_impar(l2,11);
    mostrar_lista(l2);
    printf("Adicionando 12... \n");
    inserir_par_impar(l2,12);
    mostrar_lista(l2);
    printf("Adicionando 15.. \n");
    inserir_par_impar(l2,15);
    mostrar_lista(l2);

    //Lista 3 - Para teste da função inserir_ordenado
    printf("\nLista L3 - Teste para funcao inserir ordenado:\n\n");
    printf("Adicionando 3.. \n");
    inserir_ordenado(l3,3);
    mostrar_lista(l3);
    printf("Adicionando 1.. \n");
    inserir_ordenado(l3,1);
    mostrar_lista(l3);
    printf("Adicionando 2.. \n");
    inserir_ordenado(l3,2);
    mostrar_lista(l3);
    printf("Adicionando 10.. \n");
    inserir_ordenado(l3,10);
    mostrar_lista(l3);


return -1;
}

Lista* criar_lista(){ //função para criação da lista
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int lista_vazia(Lista *l){
    return (l->inicio==NULL);
}

No* criar_no(int v){
    No *n = (No*)malloc(sizeof(No));
    n->info = v;
    n->prox = NULL;
    return n;
}

int info_no(No *n){
    return n->info;

}

int tamanho_lista(Lista *l){
    int tam = 0;
    No *aux = l->inicio;

    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }

    return tam;
}

void mostrar_lista(Lista *l){
    No* aux = l->inicio;
    if(lista_vazia(l))
        printf("Lista Vazia\n\n");
    else
        printf("Lista(%d): \n",tamanho_lista(l));
    while(aux!=NULL){
        printf("%d, ",info_no(aux));
        aux = aux->prox;
    }
    printf("\n");
}

No* adicionar_inicio(Lista *l, int v){
    No *novo = criar_no(v);
    novo->prox = l->inicio;
    l->inicio = novo;
    return novo;
}

No* adicionar_novo_no(No *n, int v){
    No *novo = criar_no(v);
    novo->prox = n->prox;
    n->prox = novo;
    return novo;
}

int indice_no(Lista *l, int v){
    int pos = 0;
    No *aux = l->inicio;
    while(aux!=NULL){
        if(aux->info == v){
            return pos;
        }
        pos++;
        aux = aux->prox;
    }
    return -1;
}

No* retornar_no_pos(Lista *l, int pos){
    int i;
    No *aux = l->inicio;
    if(pos < 0 || pos >= tamanho_lista(l)){
        return NULL;
    }
    for(i=0;i<pos;i++){
        aux=aux->prox;
    }
    return aux;
}

No* adicionar_no_pos(Lista *l, int v, int pos){
    if(pos==0){
        adicionar_inicio(l,v);
    }else{
        No* n = retornar_no_pos(l,pos-1);
        if(n!=NULL){
            n = adicionar_novo_no(n,v);
        }
        return n;
    }
}

int del_primeiro_no(Lista *l){
    int aux;
    No* no = l->inicio;
    if(lista_vazia(l)){
        printf("Erro: Lista vazia\n");
        return -1;
    }
    l->inicio = no->prox;
    aux = info_no(no);
    free(no);
    return aux;
}

int del_no_lista(No *ant){
    int aux;
    No *no = ant->prox;
    if(no==NULL){
        printf("O no a ser excluido nao existe!!\n");
        return -1;
    }
    ant->prox = no->prox;
    aux = info_no(no);
    free(no);
    return aux;
}

int del_no_pos(Lista *l, int pos){
    if(pos==0){
        return del_primeiro_no(l);
    }
    else{
        if(pos < 1 || pos >=tamanho_lista(l)){
            printf("Posição inválida\n");
            return -1;
        }
        No *n = retornar_no_pos(l,pos-1);
        return del_no_lista(n);
    }
}
int del_no_valor(Lista *l, int v){
    int pos = indice_no(l,v);
    if(pos==0){
        del_primeiro_no(l);
    }else if(pos > 0){
        del_no_pos(l,pos);
    }
    return pos;
}

void inserir_par_impar(Lista *l, int v){
    if(v%2==0){
        adicionar_inicio(l,v);
    }else{

        adicionar_no_pos(l,v,tamanho_lista(l));
    }
}

void inserir_ordenado(Lista *l, int v){
    No* ant = NULL;
    No* p = l->inicio;

    while(p!=NULL && p->info < v){
        ant = p;
        p=p->prox;
    }

    No *novo = criar_no(v);
    if(ant==NULL){
        novo->prox = l->inicio;
        l->inicio = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}
