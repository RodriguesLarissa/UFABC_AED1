#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{

    int chave;
    struct Item *prox, *ant;

}Item;

typedef struct Lista{

    Item *inicio;

}Lista;

typedef struct Fila{

    Item *inicio;
    Item *final;

}Fila;

typedef struct Pilha{

    Item *topo, *inicio;

}Pilha;

Lista * criarLista();
Fila * criarFila();
Pilha * criarPilha();
Item * criarItem(int);
void inclusaoLista(Lista *, Item *);
Item * remocaoLista(Lista *, int);
void mostrarLista(Lista *);
void inclusaoFila(Fila *, Item *);
Item * remocaoFila(Fila *);
void mostrarFila(Fila *);
void inclusaoPilha(Pilha *, Item *);
Item * remocaoPilha(Pilha *);
void mostrarPilha(Pilha *);

int main(){

    int pos_ed, quant, i, chave;
    Item *removido;
    char **nome, op;
    Lista **l;
    Fila **f;
    Pilha **p;

    scanf("%d", &quant);

    l = (Lista **) calloc(quant, sizeof(Lista *));
    f = (Fila **) calloc(quant, sizeof(Fila *));
    p = (Pilha **) calloc(quant, sizeof(Pilha *));

    nome = (char **) malloc(sizeof(char *)*quant);
    for(i=0; i<quant; i++){
        nome[i] = (char *) calloc(5, sizeof(char));
    }

    for(i=0; i<quant; i++){

        scanf("%s",  nome[i]);

        if(strcmp(nome[i],"LDE") == 0){
            l[i] = criarLista();
        }
        else if(strcmp(nome[i],"FILA") == 0){
            f[i] = criarFila();
        }
        else if(strcmp(nome[i],"PILHA") == 0){
            p[i] = criarPilha();
        }
    }

    while(scanf("%d", &pos_ed) != EOF){

        scanf("\n%c", &op);
        if(strcmp(nome[pos_ed],"LDE") == 0){
            if(op != 'M'){
                scanf("%d", &chave);
                if(op == 'I'){
                    inclusaoLista(l[pos_ed], criarItem(chave));
                }
                else if(op == 'R'){
                    removido = remocaoLista(l[pos_ed], chave);
                    if(removido != NULL){
                        printf("REMOVIDO: %d\n", removido->chave);
                        free(removido);
                    }
                }
            }
            else{
                if(l != NULL){
                    mostrarLista(l[pos_ed]);
                }
            }
        }
        else if(strcmp(nome[pos_ed],"FILA") == 0){
            if(op == 'I'){
                scanf("%d", &chave);
                inclusaoFila(f[pos_ed], criarItem(chave));
            }
            else if(op == 'R'){
                removido = remocaoFila(f[pos_ed]);
                if(removido != NULL){
                    printf("REMOVIDO: %d\n", removido->chave);
                    free(removido);
                }
            }
            else if(op == 'M'){
                if(f != NULL){
                    mostrarFila(f[pos_ed]);
                }
            }
        }
        else if(strcmp(nome[pos_ed],"PILHA") == 0){
            if(op == 'I'){
                scanf("%d", &chave);
                inclusaoPilha(p[pos_ed], criarItem(chave));
            }
            else if(op == 'R'){
                removido = remocaoPilha(p[pos_ed]);
                if(removido != NULL){
                    printf("REMOVIDO: %d\n", removido->chave);
                    free(removido);
                }
            }
            else if(op == 'M'){
                if(p != NULL){
                    mostrarPilha(p[pos_ed]);
                }
            }
        }
    }

    return 0;

}

Lista * criarLista(){

    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        l->inicio = NULL;
    }
    return l;

}

Fila * criarFila(){

    Fila *f = (Fila *) malloc(sizeof(Fila));
    if(f != NULL){

        f->inicio = f->final = NULL;

    }
    return f;

}

Pilha * criarPilha(){

    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p != NULL){
        p->topo = NULL;
    }
    return p;

}

Item * criarItem(int chave){

    Item *it = (Item *) malloc(sizeof(Item));
    if(it != NULL){
        it->chave = chave;
        it->prox = NULL;
        it->ant = NULL;
    }
    return it;

}

void inclusaoLista(Lista *l, Item *novo){
    Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave < novo->chave)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL || atual->chave != novo->chave){
        if(anterior != NULL)
        {
            anterior->prox = novo;
        }
        else
        {
            l->inicio = novo;
        }
        novo->prox = atual;
    }
}

Item * remocaoLista(Lista *l, int chave){

    Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave != chave)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual != NULL)
    {
        if(anterior == NULL)
        {
            l->inicio = atual->prox;
        }
        else
        {
            anterior->prox = atual->prox;
        }
    }
    return atual;

}

void mostrarLista(Lista *l){


    Item *atual = l->inicio;
    while(atual != NULL)
    {
        printf("%d%s", atual->chave, atual->prox!=NULL?" ":"\n");
        atual = atual->prox;
    }

}

void inclusaoFila(Fila *f, Item *novo){

    if(f->inicio==NULL && f->final == NULL){
        f->inicio = novo;
    }
    else
    {
        f->final->prox = novo;
    }
    f->final = novo;

}

Item * remocaoFila(Fila *f){

    Item *removido = f->inicio;

    if(f->inicio != NULL && f->final != NULL){
        f->inicio = f->inicio->prox;
        if(f->inicio == NULL)
        {
            f->final = NULL;
        }
    }
    return removido;

}

void mostrarFila(Fila *f){

    Item *atual = f->inicio;
    while(atual != NULL)
    {
        printf("%d%s", atual->chave, atual->prox!=NULL?" ":"\n");
        atual = atual->prox;
    }

}

void inclusaoPilha(Pilha *p, Item *novo){

    if(p->inicio==NULL && p->topo == NULL){
        p->inicio = novo;
    }
    else
    {
        p->topo->prox = novo;
        novo->ant = p->topo;
    }
    p->topo = novo;
}

Item * remocaoPilha(Pilha *p){

    Item *atual = p->topo;

    if(p->topo != NULL && p->topo->ant != NULL)
    {
        p->topo = p->topo->ant;
        p->topo->prox = NULL;
    }else{
        p->topo = NULL;
        p->inicio = NULL;
    }
    return atual;

}

void mostrarPilha(Pilha *p){

    Item *atual = p->inicio;
    while(atual != NULL)
    {
        printf("%d%s", atual->chave, atual->prox!=NULL?" ":"\n");
        atual = atual->prox;
    }

}