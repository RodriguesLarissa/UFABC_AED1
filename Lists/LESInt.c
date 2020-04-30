#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    int *itens, quantidade, tamanho;

}Lista;

void criarLista(Lista *, int);
void inclusao(Lista *, int);
void remocao(Lista *, int);
int busca(Lista, int);
void mostrar(Lista);
int vazia(Lista);
int cheia(Lista);

int main (){

    int n, chave;
    Lista l;
    char op;

    scanf("%d", &n);

    criarLista(&l, n);

    while(scanf("\n%c", &op) != EOF){

        if(op != 'M'){
            scanf("%d", &chave);

            if(op == 'I'){
                inclusao(&l, chave);
            }
            else if(op == 'R'){
                remocao(&l, chave);
            }
            else if(op == 'B'){
                printf("%s\n", busca(l, chave)?"SIM":"NAO");
            }
        }
        else if(op == 'M'){
            mostrar(l);
        }

    }

    free(l.itens);

    return 0;
}

void criarLista(Lista *l, int n){

    l->itens = (int *) malloc(n*sizeof(int));
    l->quantidade = 0;
    l->tamanho = n;

}


void inclusao(Lista *l, int chave){

    int achei = 0, i=0, j;

    if(!cheia(*l)){

        while(i<l->quantidade && !achei){

            if(l->itens[i] >= chave){
                achei = 1;
            }
            else{
                i++;
            }

        }

        if(l->itens[i] != chave){
            if(achei){

                for(j = l->quantidade; j != i; j--){

                    l->itens[j] = l->itens[j-1];

                }
            }

            l->itens[i] = chave;
            l->quantidade++;
        }
    }
}

void remocao(Lista *l, int chave){

    int achei = 0, i=0, j;

    if(!vazia(*l)){

        while(i<l->quantidade && !achei && l->itens[i] <= chave){

            if(l->itens[i] == chave){
                achei = 1;
            }
            else{
                i++;
            }

        }

        if(achei){

            for(j=i; j<l->quantidade; j++){
                l->itens[j] = l->itens[j+1];
            }
            l->quantidade--;

        }

    }

}

int busca(Lista l, int chave){

    int dir = l.quantidade-1, esq = 0, meio = 0;

    while(dir >= esq){

        meio = (dir+esq)/2;

        if(l.itens[meio] > chave){
            dir = meio-1;
        }
        else if(l.itens[meio] < chave){
            esq = meio+1;
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
        printf("%d%s", l.itens[i], i==l.quantidade-1?"\n":" ");
    }

}

int vazia(Lista l){
    return l.quantidade == 0;
}
int cheia(Lista l){
    return l.quantidade == l.tamanho;
}