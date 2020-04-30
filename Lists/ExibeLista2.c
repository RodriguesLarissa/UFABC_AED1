#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int chave;
    struct Item *prox;

}Item;

typedef struct Lista{

    Item *inicio;

}Lista;

Lista * criarLista();
Item * criarItem(int);
void inserir(Lista *, Item *);
void printReverseList(Lista *);

int main (){

    int i, j, quant, n, chave;

    scanf("%d", &quant);

    for(i=0; i<quant; i++){

        Lista *l = criarLista();

        scanf("%d", &n);

        for(j=0; j<n; j++){
            scanf("%d", &chave);
            inserir(l, criarItem(chave));
        }

        printReverseList(l);

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

Item * criarItem(int chave){

    Item *it = (Item *) malloc(sizeof(Item));
    if(it != NULL){
        it->chave = chave;
        it->prox = NULL;
    }
    return it;

}

void inserir(Lista *l, Item *novo){

    Item *atual = l->inicio, *anterior = NULL;

    while(atual != NULL){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior != NULL){
        anterior->prox = novo;
    }
    else{
        l->inicio = novo;
    }
    novo->prox = atual;

}

void printReverseList(Lista *l){

    Item *atual=l->inicio;
    int tamanho=0, i;

    while(atual != NULL){
        atual = atual->prox;
        tamanho++;
    }

    int *vetor = (int *) malloc(sizeof(int)*tamanho);

    atual = l->inicio;
    for(i=tamanho-1; i>=0; i--){
        vetor[i] = atual->chave;
        atual = atual->prox;
    }

    for(i=0; i<tamanho;i++){
        printf("%d\n", vetor[i]);
    }

}