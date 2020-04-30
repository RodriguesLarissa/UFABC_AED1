#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int chave;
    struct Item *prox, *ant;

}Item;

typedef struct Lista{

    Item *inicio, *final;
    int quantidade;

}Lista;

Lista * criaLista();
Item * criaItem(int);
void inclusao(Lista *, Item *);
Item * remocao(Lista *, int);
void mostrar(Lista *);
void mostrarInverso(Lista *);

int main (){

    Lista *l = criaLista();
    Item *removido;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF){

        if(op == 'I'){
            scanf("%d", &chave);
            inclusao(l, criaItem(chave));
        }
        else if(op == 'E'){
            scanf("%d", &chave);
            removido = remocao(l, chave);
            if(removido != NULL){
                free(removido);
            }
        }
        else if(op == 'M'){
            mostrar(l);
        }
        else if(op == 'R'){
            mostrarInverso(l);
        }
    }

    free(l);

    return 0;
}

Lista * criaLista(){

    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        l->inicio = NULL;
        l->final = NULL;
        l->quantidade = 0;
    }
    return l;

}

Item * criaItem(int chave){

    Item *it = (Item *) malloc(sizeof(Item));
    if(it != NULL){

        it->chave = chave;
        it->prox = NULL;
        it->ant = NULL;

    }
    return it;
}

void inclusao(Lista *l, Item *novo){

    Item *atual = l->inicio, *anterior = NULL;

    novo->prox = NULL;
    novo->ant = NULL;
    if(l->quantidade == 0){
        l->inicio = novo;
        l->final = novo;
        l->quantidade++;
    }
    else{
        while(atual != NULL && atual->chave < novo->chave){
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == NULL || atual->chave != novo->chave){
            if(anterior == NULL){ //inicio
                l->inicio = novo;
                atual->ant = novo;
            }
            else if(atual != NULL){//meio
                atual->ant = novo;
                anterior->prox = novo;
            }
            else{//final
                l->final = novo;
                anterior->prox = novo;
            }
            novo->prox = atual;
            novo->ant = anterior;
            l->quantidade++;
        }
    }
}

Item * remocao(Lista *l, int chave){

    Item *atual = l->inicio, *anterior = NULL;

    if(l->quantidade != 0) {
        while(atual != NULL && atual->chave != chave){
            anterior = atual;
            atual = atual->prox;
        }

        if(atual != NULL){
            if(anterior == NULL){ //Primeiro da Lista
                if(atual->prox != NULL){
                    l->inicio = atual->prox;
                    (atual->prox)->ant = atual->ant;
                }
                else{
                    l->inicio = NULL;
                    l->final  = NULL;
                }
            }
            else if(atual->prox == NULL){ //final
                anterior->prox = atual->prox;
                l->final = anterior;
            }
            else{ //meio
                anterior->prox = atual->prox;
                (atual->prox)->ant = atual->ant;
            }
            l->quantidade--;
            return atual;
        }
        return 0;
    }
    return 0;
}

void mostrar(Lista *l){

    Item *atual = l->inicio;

    while(atual != NULL){
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

void mostrarInverso(Lista *l){

    Item *atual = l->final;

    while(atual != NULL){
        printf("%d ", atual->chave);
        atual = atual->ant;
    }
    printf("\n");

}