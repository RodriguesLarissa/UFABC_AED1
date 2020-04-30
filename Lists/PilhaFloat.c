#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{

    float *itens;
    int topo, tamanho;

}Pilha;

void criarPilha(Pilha *, int);
void inclusao(Pilha *, float);
void exclusao(Pilha *);
void topo(Pilha);
void mostrar(Pilha);
void mostrarInverso(Pilha);
int cheia(Pilha);
int vazia(Pilha);

int main (){

    int n;
    char op;
    float valor;
    Pilha p;

    scanf("%d", &n);

    criarPilha(&p, n);

    while(scanf("\n%c", &op) != EOF){

        if(op == 'E'){
            scanf("%f", &valor);
            inclusao(&p, valor);
        }
        else if(op == 'D'){
            exclusao(&p);
        }
        else if(op == 'T'){
            topo(p);
        }
        else if(op == 'X'){
            mostrar(p);
        }
        else if(op == 'B'){
            mostrarInverso(p);
        }

    }

    return 0;
}

void criarPilha(Pilha *p, int n){

    p->itens = (float *) malloc(sizeof(float)*n);
    p->topo = -1;
    p->tamanho = n;

}

void inclusao(Pilha *p, float valor){

    if(!cheia(*p)){
        p->topo++;
        p->itens[p->topo] = valor;
    }

}

void exclusao(Pilha *p){

    if(!vazia(*p)){
        p->itens[p->topo] = 0;
        p->topo--;
    }

}

void topo(Pilha p){

    int integral_part;
    float decimal_part;

    if(!vazia(p)){
        integral_part = (int) p.itens[p.topo];
        decimal_part = (float) p.itens[p.topo] - integral_part;

        if (decimal_part == 0.0){
            printf("%.0f\n", p.itens[p.topo]);
        }else{
            printf("%.1f\n", p.itens[p.topo]);
        }
    }
}

void mostrar(Pilha p){

    int i, integral_part;
    float decimal_part;

    if(!vazia(p)){

        for(i=p.topo; i>=0;i--){

            integral_part = (int) p.itens[i];
            decimal_part = (float) p.itens[i] - integral_part;

            if(decimal_part == 0.0){
                printf("%.0f%s", p.itens[i], (i==0)?"\n":" ");
            }else{
                printf("%.1f%s", p.itens[i], (i==0)?"\n":" ");
            }
        }
    }

}
void mostrarInverso(Pilha p){

    int i, integral_part;
    float decimal_part;

    if(!vazia(p)){
        for(i=0; i<=p.topo; i++){

            integral_part = (int) p.itens[i];
            decimal_part = (float) p.itens[i] - integral_part;

            if(decimal_part == 0.0){
                printf("%.0f%s", p.itens[i], (i==p.topo)?"\n":" ");
            }else{
                printf("%.1f%s", p.itens[i], (i==p.topo)?"\n":" ");
            }
        }
    }

}

int cheia(Pilha p){
    return p.topo == p.tamanho-1;
}

int vazia(Pilha p){
    return p.topo == -1;
}