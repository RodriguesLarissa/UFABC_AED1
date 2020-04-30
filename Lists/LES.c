#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    int *itens;
    int quantidade, tamanho;

} Lista;

void criaLista(Lista *, int);
void inclusao(Lista *, int);
void exclusao(Lista *, int);

int main(){

    int n, i, chave;
    char op;
    Lista l;

    scanf("%d", &n);

    criaLista(&l, n);

    for(i=0; i<n; i++){
        scanf("\n%c %d", &op, &chave);

        if(op == 'I'){
            inclusao(&l, chave);
        }
        else if(op == 'E'){
            exclusao(&l, chave);
        }
    }

    for(i=0; i<l.quantidade; i++){
        printf("%d\n", l.itens[i]);
    }

    return 0;
}

void criaLista(Lista *l, int n){

    l->itens = (int*) malloc(n*sizeof(int));
    l->tamanho = n;
    l->quantidade = 0;

}

void inclusao(Lista *l, int chave){

    int i=0, achei=0, j;

    while(i<l->quantidade && !achei && l->itens[i] != chave){

        if(l->itens[i] > chave){
            achei = 1;
        }
        else{
            i++;
        }

    }

    if(achei){

        for(j=l->quantidade; j>i; j--){

            l->itens[j] = l->itens[j-1];

        }
    }

    if(l->itens[i] != chave){
        l->itens[i] = chave;
        l->quantidade++;
    }
}

void exclusao(Lista *l, int chave){

    int i=0, achei=0, j=0;

    while(i<l->quantidade && !achei){

        if(l->itens[i] == chave){
            achei=1;
        }
        else{
            i++;
        }

    }

    if(achei){

        for(j=i+1; j<l->quantidade; j++){
            l->itens[i] = l->itens[j];
            i++;
        }
        l->quantidade--;

    }

}

