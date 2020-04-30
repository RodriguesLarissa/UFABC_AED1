#include <stdio.h>
#include <stdlib.h>

typedef struct Lista1{

    int *itens, quantidade, tamanho;

}Lista1;

typedef struct Lista2{

   int *itens, quantidade, tamanho;

}Lista2;

void criarLista1(Lista1 *, int);
void criarLista2(Lista2 *, int);
void inclusaoL1(Lista1 *, int);
void remocaoL1(Lista1 *, int);
void inclusaoL2(Lista2 *, int);
void remocaoL2(Lista2 *, int);
int cheia1(Lista1);
int vazia1(Lista1);
int cheia2(Lista2);
int vazia2(Lista2);
int analise(Lista1, Lista2);

int main (){

    Lista1 l1;
    Lista2 l2;
    int n1, n2, i=0, chave;
    char op;

    scanf("%d %d", &n1, &n2);

    criarLista1(&l1, n1);
    criarLista2(&l2, n2);

    for(i=0; i<n1; i++){

        scanf("\n%c", &op);
        scanf("%d", &chave);

        if(op == 'I'){
            inclusaoL1(&l1, chave);
        }
        else if(op == 'E'){
            remocaoL1(&l1, chave);
        }
    }

    for(i=0; i<n2; i++){

        scanf("\n%c", &op);
        scanf("%d", &chave);

        if(op == 'I'){
            inclusaoL2(&l2, chave);
        }
        else if(op == 'E'){
            remocaoL2(&l2, chave);
        }
    }

    printf("%s\n", analise(l1, l2)?"SIM":"NAO");

    free(l1.itens);
    free(l2.itens);

    return 0;
}

void criarLista1(Lista1 *l1, int n1){

    l1->itens = (int *) malloc(sizeof(int) * n1);
    l1->quantidade = 0;
    l1->tamanho = n1;

}

void criarLista2(Lista2 *l2, int n2){

    l2->itens = (int *) malloc(sizeof(int) * n2);
    l2->quantidade = 0;
    l2->tamanho = n2;

}

void inclusaoL1(Lista1 *l1, int chave){

    int achei=0, i=0, j;

    if(!cheia1(*l1)){

        while(i<l1->quantidade && !achei){

            if(l1->itens[i] >= chave){
                achei=1;
            }
            else{
                i++;
            }

        }

        if(l1->itens[i] != chave){

            if(achei){
                for(j=l1->quantidade; j != i; j--){
                    l1->itens[j] = l1->itens[j-1];
                }
            }
            l1->itens[i] = chave;
            l1->quantidade++;
        }
    }
}

void remocaoL1(Lista1 *l1, int chave){

    int achei=0, i=0, j;

    if(!vazia1(*l1)){

        while(i<l1->quantidade && !achei && l1->itens[i] <= chave){

            if(l1->itens[i] == chave){
                achei = 1;
            }
            else{
                i++;
            }

        }

        if(achei){
            for(j=i; j<l1->quantidade; j++){
                l1->itens[j] = l1->itens[j+1];
            }
            l1->quantidade--;
        }

    }

}

void inclusaoL2(Lista2 *l2, int chave){

    int achei=0, i=0, j;

    if(!cheia2(*l2)){

        while(i<l2->quantidade && !achei){

            if(l2->itens[i] >= chave){
                achei=1;
            }
            else{
                i++;
            }

        }

        if(l2->itens[i] != chave){

            if(achei){
                for(j=l2->quantidade; j != i; j--){
                    l2->itens[j] = l2->itens[j-1];
                }
            }
            l2->itens[i] = chave;
            l2->quantidade++;
        }
    }

}

void remocaoL2(Lista2 *l2, int chave){

    int achei=0, i=0, j;

    if(!vazia2(*l2)){

        while(i<l2->quantidade && !achei && l2->itens[i] <= chave){

            if(l2->itens[i] == chave){
                achei =1;
            }
            else{
                i++;
            }

        }

        if(achei){

            for(j=i; j<l2->quantidade; j++){
                l2->itens[j] = l2->itens[j+1];
            }
            l2->quantidade--;
        }

    }

}

int cheia1(Lista1 l1){
    return l1.quantidade == l1.tamanho;
}

int vazia1(Lista1 l1){
    return l1.quantidade == 0;
}

int cheia2(Lista2 l2){
    return l2.quantidade == l2.tamanho;
}

int vazia2(Lista2 l2){
    return l2.quantidade == 0;
}

int analise(Lista1 l1, Lista2 l2){

    int i, j=0;

    if(l1.quantidade > l2.quantidade){
        return 0;
    }
    else{
        for(i=0; i<l2.quantidade; i++){
            if(l2.itens[i] == l1.itens[j]){
                j++;
            }
        }
    }

    if(j == l1.quantidade){
        return 1;
    }
    return 0;
}