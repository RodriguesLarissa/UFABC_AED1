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
Lista * mergeLists(Lista *, Lista *);
void mostrar(Lista *);

int main(){

    int i, j, quant, n1, n2, chave;

    scanf("%d", &quant);

    for(i=0; i<quant; i++){

        Lista *l1 = criarLista(), *l2 = criarLista();
        scanf("%d", &n1);

        for(j=0; j<n1; j++){
            scanf("%d", &chave);
            inserir(l1, criarItem(chave));
        }

        scanf("%d", &n2);

        for(j=0; j<n2; j++){
            scanf("%d", &chave);
            inserir(l2, criarItem(chave));
        }

        if(n1 == 0){
            l1 = l2;
        }
        else if(n2 == 0){
            l1 = l1;
        }
        else{
            l1 = mergeLists(l1, l2);
        }

        mostrar(l1);
    }
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

Lista * mergeLists(Lista *l1, Lista *l2){

    Item *atual1 = l1->inicio, *atual2 = l2->inicio, *anterior1 = NULL, *aux = NULL;

    while(atual2 != NULL && atual1 != NULL){

        if(atual1->chave <= atual2->chave){
            if(anterior1 != NULL){
                anterior1->prox = atual1;
            }
            else{
                l1->inicio = atual1;
            }
            anterior1 = atual1;
            atual1 = atual1->prox;
        }
        else{
            if(anterior1 != NULL){
                anterior1->prox = atual2;
            }
            else{
                l1->inicio = atual2;
            }
            aux = atual2->prox;
            atual2->prox = atual1;
            anterior1 = atual2;
            atual2 = aux;
        }
    }

    while(atual2 != NULL){
        anterior1->prox = atual2;
        anterior1 = atual2;
        atual2 = atual2->prox;
    }

    while(atual1 != NULL){
        anterior1->prox = atual1;
        anterior1 = atual1;
        atual1 = atual1->prox;
    }

    return l1;

}

void mostrar(Lista *l){

    Item *atual = l->inicio;

    while(atual != NULL){

        printf("%d%s", atual->chave, atual->prox==NULL?"\n":" ");
        atual = atual->prox;

    }

}