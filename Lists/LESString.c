#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Lista{

    char **itens;
    int quantidade, tamanho;

}Lista;

void criaLista(Lista *, int);
void inclusao(Lista *, char[]);
void remocao(Lista *, char[]);
int busca(Lista, char[]);
void mostrar(Lista);
int cheia(Lista);
int vazia(Lista);

int main(){

    int n;
    char op, chave[50];
    Lista l;

    scanf("%d", &n);

    criaLista(&l, n);

    while(scanf("\n%c", &op) != EOF){

        if(op != 'M'){
            scanf("\n%s", chave);
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

    int i;
    l->itens = (char **) malloc(n*sizeof(char *));
    for(i=0; i < n; i++){
        l->itens[i] = (char *) calloc(50, sizeof(char));
    }

    l->quantidade = 0;
    l->tamanho = n;

}

void inclusao(Lista *l, char chave[]){

    int i=0, j=0, achei=0;

    if(!cheia(*l)){
        while(i<l->quantidade && !achei && strcmp(chave, l->itens[i]) != 0){
            if(strcmp(chave, l->itens[i]) < 0){
                achei = 1;
            }
            else{
                i++;
            }
        }

        if(achei){

            for(j=l->quantidade; j>i; j--){
                strcpy(l->itens[j], l->itens[j-1]);
            }

        }

        if(strcmp(chave, l->itens[i]) != 0 || vazia(*l)){
            strcpy(l->itens[i], chave);
            l->quantidade++;
        }
    }

}


void remocao(Lista *l, char chave[]){

    int i=0, achei=0, j=0;

    if(!vazia(*l)){

        while(i<l->quantidade && !achei){

            if(strcmp(chave, l->itens[i]) == 0){
                achei = 1;
            }
            else{
                i++;
            }

        }

        if(achei){

            for(j=i; j<l->quantidade-1; j++){
                strcpy(l->itens[j], l->itens[j+1]);
            }

            l->quantidade--;

        }

    }

}

int busca(Lista l, char chave[]){

    int meio=0, esq=0, dir=l.quantidade-1;

    while(esq<=dir){

        meio = (esq+dir)/2;

        if(strcmp(l.itens[meio], chave) < 0){
            esq=meio+1;
        }
        else if(strcmp(l.itens[meio], chave) > 0){
            dir=meio-1;
        }
        else{
            return 1;
        }

    }

    return 0;

}

void mostrar(Lista l){

    int i;

    for(i=0; i<l.quantidade; i++){
        printf("%s%s", l.itens[i], i == l.quantidade-1?"\n":" ");
    }

}

int cheia(Lista l){

    return l.quantidade == l.tamanho;

}

int vazia(Lista l){

    return l.quantidade == 0;

}