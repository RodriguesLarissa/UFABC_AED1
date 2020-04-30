#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{

    int *itens;
    int inicio, fim, tamanho;

}Fila;

void criarFila(Fila *, int);
void inclusao(Fila *, int);
int exclusao(Fila *);
int cheia(Fila);
int vazia(Fila);

int main (){

    int n, chave;
    Fila f;
    char op;

    scanf("%d", &n);
    criarFila(&f, n);

    while(scanf("\n%c", &op) != EOF){

        if(op == 'E'){

            scanf("%d", &chave);

            if(vazia(f)){
                f.inicio = -1;
                f.fim = -1;
            }

            inclusao(&f, chave);
        }
        else if(op == 'D'){
            if(!vazia(f)){
                printf("%d\n", exclusao(&f));
            }
            else{
                f.inicio = -1;
                f.fim = -1;
            }
        }

    }
    free(f.itens);

}

void criarFila(Fila *f, int n){

    f->itens = (int *) malloc(n*sizeof(int));
    f->inicio = -1;
    f->fim = -1;
    f->tamanho = n;

}

void inclusao(Fila *f, int chave){


    if(f->inicio == -1 && f->fim == -1){
        f->inicio++;
    }

    if(!cheia(*f)){
        f->fim++;
        f->itens[f->fim] = chave;
    }
}

int exclusao(Fila *f){


    if(!vazia(*f)){
        f->inicio++;
        return f->itens[f->inicio-1];
    }
    return 0;
}

int cheia(Fila f){
    return f.fim+1 == f.tamanho;
}

int vazia(Fila f){
    return (f.fim+1 == f.inicio || (f.fim == -1 && f.inicio == -1));
}