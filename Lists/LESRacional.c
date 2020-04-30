#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    float *Num, *Den;
    int quantidade, tamanho;

}Lista;

void criarLista(Lista *, int);
void inclusao(Lista *, float, float);
void remocao(Lista *, float, float);
int busca(Lista, float, float);
void mostrar(Lista);
int cheia(Lista);
int vazia(Lista);

int main(){

    int n;
    float chaveNum, chaveDen;
    char op;
    Lista l;

    scanf("%d", &n);
    criarLista(&l, n);

    while(scanf("\n%c", &op) != EOF){

        if(op != 'M'){
            scanf("%f %f", &chaveNum, &chaveDen);
        }
        if(op == 'I'){
            inclusao(&l, chaveNum, chaveDen);
        }
        else if(op == 'R'){
            remocao(&l, chaveNum, chaveDen);
        }
        else if(op == 'B'){
            printf("%s", busca(l, chaveNum, chaveDen)?"SIM\n":"NAO\n");
        }
        else if(op == 'M'){
            mostrar(l);
        }

    }
    free(l.Num);
    free(l.Den);

    return 0;
}

void criarLista(Lista *l, int n){

    l->Num = (float *) malloc(n*sizeof(float));
    l->Den = (float *) malloc(n*sizeof(float));
    l->quantidade = 0;
    l->tamanho = n;

}

void inclusao(Lista *l, float Num, float Den){

    if(!cheia(*l)){

        int i=0, achei=0, j;

        while(i<l->quantidade && !achei && !vazia(*l) && (l->Num[i]/l->Den[i]) != (Num/Den)){

            if((l->Num[i]/l->Den[i]) > (Num/Den)){
                achei=1;
            }
            else{
                i++;
            }

        }

        if(achei){
            for(j=l->quantidade; j>i; j--){

                l->Num[j] = l->Num[j-1];
                l->Den[j] = l->Den[j-1];

            }
        }

        if(vazia(*l) || (l->Num[i]/l->Den[i]) != (Num/Den)){

            l->Num[i] = Num;
            l->Den[i] = Den;
            l->quantidade++;

        }

    }
}

void remocao(Lista *l, float Num, float Den){

    if(!vazia(*l)){

        int i=0, achei=0, j;

        while(i<l->quantidade && !achei){

            if((l->Num[i]/l->Den[i]) == (Num/Den)){
                achei=1;
            }
            else{
                i++;
            }

        }

        if(achei){

            for(j=i; j<l->quantidade; j++){

                l->Num[j] = l->Num[j+1];
                l->Den[j] = l->Den[j+1];

            }

            l->quantidade--;

        }

    }

}

int busca(Lista l, float Num, float Den){

    int i=0;
    if(!vazia(l)){
        while(i<l.quantidade){

            if((l.Num[i]/l.Den[i]) == (Num/Den)){
                return 1;
            }
            else{
                i++;
            }

        }
    }

    return 0;

}
void mostrar(Lista l){

    int i;

    for(i=0; i<l.quantidade; i++){
        printf("%.0f/%.0f%s", l.Num[i], l.Den[i], (i == l.quantidade-1)?"\n":" ");
    }

}

int cheia(Lista l){
    return l.quantidade == l.tamanho;
}

int vazia(Lista l){
    return l.quantidade == 0;
}