#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{

    char *itens;
    int topo, tamanho;

}Pilha;

void criarPilha(Pilha *, int);
void inclusao(Pilha *, char);
void exclusao(Pilha *);
void topo(Pilha);
void mostrar(Pilha);
void mostrarInverso(Pilha);
int cheia(Pilha);
int vazia(Pilha);

int main (){

    int n;
    char op, valor;
    Pilha p;

    scanf("%d", &n);

    criarPilha(&p, n);

    while(scanf("\n%c", &op) != EOF){

        if(op == 'E'){
            scanf("\n%c", &valor);
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

    p->itens = (char *) malloc(sizeof(char)*n);
    p->topo = -1;
    p->tamanho = n;

}

void inclusao(Pilha *p, char valor){

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

    if(!vazia(p)){
        printf("%c\n", p.itens[p.topo]);
    }
}

void mostrar(Pilha p){

    int i;

    if(!vazia(p)){
        for(i=p.topo; i>=0;i--){
            printf("%c%s", p.itens[i], (i==0)?"\n":" ");
        }
    }

}
void mostrarInverso(Pilha p){

    int i;

    if(!vazia(p)){
        for(i=0; i<=p.topo; i++){
            printf("%c%s", p.itens[i], (i==p.topo)?"\n":" ");
        }
    }

}

int cheia(Pilha p){
    return p.topo == p.tamanho-1;
}

int vazia(Pilha p){
    return p.topo == -1;
}