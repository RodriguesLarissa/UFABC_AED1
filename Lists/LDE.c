#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int chave;
    struct Item *proximo;

}Item;

typedef struct Lista{

    Item *inicio;

}Lista;

Lista * criarLista();
Item * criaItem(int);
void inserir(Lista *, Item *);
Item * remover(Lista *, int);
int busca(Lista *, int);
void mostrar(Lista *);

int main(){

    Lista *l = criarLista();
    Item *removido;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF){

        if(op != 'L'){
            scanf("%d", &chave);

            if(op == 'I'){
                inserir(l, criaItem(chave));
            }
            else if(op == 'R'){
                removido = remover(l, chave);
                if(removido != NULL){
                    free(removido);
                }
            }
            else if(op == 'B'){
                printf("%s\n", busca(l, chave)?"SIM":"NAO");
            }
        }
        else if(op == 'L'){
            mostrar(l);
        }

    }

    return 0;
}

Lista * criarLista(){

    Lista *l = (Lista *) malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

Item * criaItem(int chave){

    Item *it = (Item *) malloc(sizeof(Item));
    it->chave = chave;
    it->proximo = NULL;

    return it;

}

void inserir(Lista *l, Item *novo){

    Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave < novo->chave){

        anterior = atual;
        atual = atual->proximo;

    }

    if(atual == NULL || atual->chave != novo->chave){
        if(anterior != NULL){
            anterior->proximo = novo;
        }
        else{
            l->inicio = novo;
        }
        novo->proximo = atual;
    }
}

Item * remover(Lista *l, int chave){

    Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave != chave){

        anterior = atual;
        atual = atual->proximo;

    }

    if(atual != NULL){
        if(anterior == NULL){
            l->inicio = atual->proximo;
        }
        else{
            anterior->proximo = atual->proximo;
        }
    }

    return atual;

}

int busca(Lista *l, int chave){

    Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave != chave){

        anterior = atual;
        atual = atual->proximo;

    }

    if(atual != NULL){
        return 1;
    }
    else{
        return 0;
    }

}
void mostrar(Lista *l){

    Item *atual = l->inicio;

    while(atual != NULL){

        printf("%d%s", atual->chave, atual->proximo!=NULL?" ":"\n");
        atual = atual->proximo;

    }

}