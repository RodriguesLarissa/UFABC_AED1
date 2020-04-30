#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    float *itens;
    int quantidade, tamanho;

}Lista;

void criaLista(Lista *, int);
void inclusao(Lista *, float);
void remocao(Lista *, float);
int busca(Lista, float);
void mostrar(Lista);
int cheia(Lista);
int vazia(Lista);

int main(){

    int n;
    float chave;
    char op;
    Lista l;

    scanf("%d", &n);

    criaLista(&l, n);

    while(scanf("\n%c", &op) != EOF){

        if(op != 'M'){
            scanf("%f", &chave);
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

    l->itens = (float*) malloc(n*sizeof(float));
    l->tamanho = n;
    l->quantidade = 0;

}

void inclusao(Lista *l, float chave){

    int i=0, achei=0, j, igual=0;

    if(!cheia(*l)){
        while(i<l->quantidade && !achei && !igual){
            if(chave == l->itens[i]){
                igual=1;
            }
            else if(chave<l->itens[i]){
                achei=1;
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

        if(!igual){
            l->itens[i] = chave;
            l->quantidade++;
        }
    }
}

void remocao(Lista *l, float chave){

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
        for(j=i; j<l->quantidade; j++){
            l->itens[j] = l->itens[j+1];
        }
        l->quantidade--;
    }
}
int busca(Lista l, float chave){

    int i;

    for(i=0; i<l.quantidade; i++){
        if(l.itens[i] == chave){
            return 1;
        }
    }
    return 0;

}
void mostrar(Lista l){

    int i, integral_part;
    float decimal_part;

    for(i=0; i<l.quantidade; i++){

        integral_part = (int) l.itens[i];
        decimal_part = (float) l.itens[i] - integral_part;
        if(decimal_part == 0.0){
            printf("%.0f%s", l.itens[i], i!=l.quantidade-1?" ":"\n");
        }
        else{
            printf("%.1f%s", l.itens[i], i!=l.quantidade-1?" ":"\n");
        }
    }

}

int cheia(Lista l){

    return l.quantidade == l.tamanho;

}

int vazia(Lista l){

    return l.quantidade == 0;
}