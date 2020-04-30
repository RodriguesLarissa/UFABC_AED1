#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{

    int *itens;
    int inicio, fim, tamanho;

}Fila;

void criarFila(Fila *, int);
void inclusao(Fila *, int);
int exclusao(Fila *);
int vazia(Fila);
int cheia(Fila);

int main (){

    int n, chave;
    char op;
    Fila f;
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
            if(vazia(f)){
                f.inicio = -1;
                f.fim = -1;
                printf("Runtime Error: Fila Vazia.\n");
            }
            else{
                printf("%d\n", exclusao(&f));
            }
        }


    }


    return 0;
}

void criarFila(Fila *f, int n){

    f->itens = (int *) malloc(n*sizeof(int));
    f->tamanho = n;
    f->inicio = -1;
    f->fim = -1;

}

void inclusao(Fila *f, int chave){

    if(!cheia(*f)){
        if(vazia(*f)){
            f->inicio++;
        }
        f->fim++;
        f->itens[f->fim] = chave;
    }
    else{
        printf("Runtime Error: Fila Cheia.\n");
    }
}

int exclusao(Fila *f){

    if(!vazia(*f)){
        f->inicio++;
        return (f->itens[f->inicio-1]);
    }
    else{
        return 0;
    }

}

int vazia(Fila f){
    return(f.fim+1 == f.inicio || (f.fim == -1 && f.inicio == -1));
}

int cheia(Fila f){
    return(f.fim == f.tamanho-1);
}