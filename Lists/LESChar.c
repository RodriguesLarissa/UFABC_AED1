#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    char *itens;
    int tamanho, quantidade;

}Lista;

void criaLista(Lista *, int);
void inclusao(Lista *, char);
void remocao(Lista *, char);
int busca(Lista, char);
void mostrar(Lista);

int main(){

    int n;
    char op, chave;
    Lista l;

    scanf("%d", &n);

    criaLista(&l, n);

    while(scanf("\n%c", &op) != EOF){

        if(op != 'M'){
            scanf("\n%c", &chave);
        }
        if(op == 'I'){
            inclusao(&l, chave);
        }
        else if(op == 'R'){
            remocao(&l, chave);
        }
        else if(op == 'B'){
            printf("%s\n", busca(l, chave)?"SIM":"NAO");
        }
        else if(op == 'M'){
            mostrar(l);
        }

    }
    free(l.itens);
    return 0;
}

void criaLista(Lista *l, int n){

    l->itens = (char *) malloc(n*sizeof(char));
    l->quantidade = 0;
    l->tamanho = n;

}

void inclusao(Lista *l, char chave){

    int i=0, achei=0, j;

    while(i<l->quantidade && !achei && l->itens[i] != chave){

        if(l->itens[i] > chave){
            achei = 1;
        }
        else{
            i++;
        }
    }

    if(achei && l->quantidade<l->tamanho){
        for(j=l->quantidade; j>i; j--){
            l->itens[j] = l->itens[j-1];
        }
    }

    if(l->itens[i] != chave && l->quantidade+1<=l->tamanho){
        l->itens[i] = chave;
        l->quantidade++;
    }
}

void remocao(Lista *l, char chave){

    int i=0, achei=0, j;

    while(i<l->quantidade && !achei){

        if(l->itens[i] == chave){
            achei = 1;
        }
        else{
            i++;
        }
    }

    if(achei){

       for(j=i+1; j<l->quantidade; j++, i++){
           l->itens[i] = l->itens[j];
       }
       l->itens[i] = 0;
       l->quantidade--;

    }
}

int busca(Lista l, char chave){

    int meio, esq = 0, dir = l.quantidade-1;

    while(esq <= dir){

        meio = (esq+dir)/2;

        if(l.itens[meio] == chave){
            return 1;
        }
        else if(l.itens[meio] > chave){
            dir = meio-1;
        }
        else{
            esq = meio+1;
        }

    }

    return 0;

}

void mostrar(Lista l){

    int i;

    for(i=0; i<l.quantidade; i++){

        printf("%c%s", l.itens[i], i == l.quantidade-1?"\n":" ");

    }

}

