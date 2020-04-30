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
Item * criaItem(int);
void inserir(Lista *,  Item *);
Lista * removeDuplicates(Lista *);
void mostrar(Lista *);

int main(){

    int i, quant, tamanho, j, chave;
    Lista *l;

    scanf("%d", &quant);

    for(i=0; i<quant; i++){
        scanf("%d", &tamanho);
        l = criarLista();

        if(tamanho != 0){

            for(j=0; j<tamanho; j++){

                scanf("%d", &chave);
                inserir(l, criaItem(chave));

            }

            l = removeDuplicates(l);
            mostrar(l);
        }
    }

    free(l);

    return 0;
}

Lista * criarLista(){

    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        l->inicio = NULL;
    }
    return l;

}

Item * criaItem(int chave){

    Item *it = (Item *) malloc(sizeof(Item));
    it->chave = chave;
    it->prox = NULL;
    return it;

}

void inserir(Lista *l, Item *novo){

    Item *anterior = NULL, *atual = l->inicio;

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
    novo->prox  = atual;

}

Lista * removeDuplicates(Lista *l){

    Item *atual = l->inicio, *anterior = NULL;
    Item *removido;

    while(atual != NULL){
        if(anterior != NULL && anterior->chave == atual->chave){
            anterior->prox = atual->prox;
            removido = atual;
            free(removido);

            atual = anterior->prox;
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }

    return l;

}

void mostrar(Lista *l){

    Item *atual = l->inicio;

    while(atual != NULL){

        printf("%d%s", atual->chave, atual->prox!=NULL?" ":"\n");
        atual = atual->prox;

    }

}