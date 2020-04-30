#include <stdio.h>
#include <stdlib.h>

typedef struct Circular{

    int *itens;
    int inicio, fim, tamanho;

}Circular;

void iniciaCircular(Circular *, int);
void inclusao(Circular *, int);
int remocao(Circular *);

int main (){

    Circular c;
    int n, chave, i;
    char op;

    scanf("%d", &n);

    iniciaCircular(&c, n);

    while(scanf("\n%c", &op) != EOF){

        if(op == 'E'){
            scanf("%d", &chave);
            inclusao(&c, chave);
        }
        else if(op == 'D'){
            if(c.inicio != c.fim){
                printf("%d\n", remocao(&c));
            }
        }

    }

    free(c.itens);
    return 0;
}

void iniciaCircular(Circular *c, int n){

    c->itens = (int *) malloc(sizeof(int)*n);
    c->inicio = 0;
    c->fim = 0;
    c->tamanho = n;

}

void inclusao(Circular *c, int chave){

    int novo_fim;

    novo_fim = (c->fim+1)%c->tamanho;

    if(novo_fim != c->inicio){

        c->itens[c->fim] = chave;
        c->fim = novo_fim;

    }

}

int remocao(Circular *c){

    int removido;

    if(c->inicio != c->fim){

        removido = c->itens[c->inicio];
        c->itens[c->inicio] = 0;
        c->inicio = (c->inicio+1)%c->tamanho;

    }

    return removido;
}