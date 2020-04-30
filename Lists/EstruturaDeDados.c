#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{

    int *itens;
    int tamanho, quantidade;

}Lista;

typedef struct Fila{

    int *itens;
    int inicio, fim, tamanho;

}Fila;

typedef struct Pilha{

    int *itens;
    int topo, tamanho;

}Pilha;

typedef struct Circular{

    int *itens;
    int start, end, tamanho;

}Circular;

/* Funções da Lista */
void criarLista(Lista *, int);
void inclusaoLista(Lista *, int);
int remocaoLista(Lista *, int);
void mostrarLista(Lista);
int listaCheia(Lista);
int listaVazia(Lista);

/* Funções da Fila */
void criarFila(Fila *, int);
void inclusaoFila(Fila *, int);
int remocaoFila(Fila *);
void mostrarFila(Fila);
int filaCheia(Fila);
int filaVazia(Fila);

/* Funções da Pilha */
void criarPilha(Pilha *, int);
void inclusaoPilha(Pilha *, int);
int remocaoPilha(Pilha *);
void mostrarPilha(Pilha);
int pilhaCheia(Pilha);
int pilhaVazia(Pilha);

/* Funções do Circular */
void criarCircular(Circular *, int);
void inclusaoCircular(Circular *, int);
int remocaoCircular(Circular *);
void mostrarCircular(Circular);

int main (){

    int quant, *tamanho, i, pos_ed, chave, removido;
    char **nome, op;
    Lista *l;
    Fila *f;
    Pilha *p;
    Circular *c;

    scanf("%d", &quant);

    nome = (char **) malloc(sizeof(char *)*quant);
    for(i=0; i<quant; i++){
        nome[i] = (char *) calloc(9,sizeof(char));
    }

    tamanho = (int *) malloc(sizeof(int)*quant);

    c = (Circular *) calloc(quant, sizeof(Circular));
    l = (Lista *) calloc(quant, sizeof(Lista));
    f = (Fila *) calloc(quant, sizeof(Fila));
    p = (Pilha *) calloc(quant, sizeof(Pilha));


    for(i=0; i<quant; i++){

        scanf("%s", nome[i]);
        scanf("%d", &tamanho[i]);

        if(strcmp(nome[i],"LES") == 0){
            criarLista(&l[i], tamanho[i]);
        }
        else if(strcmp(nome[i],"FILA") == 0){
            criarFila(&f[i], tamanho[i]);
        }
        else if(strcmp(nome[i],"PILHA") == 0){
            criarPilha(&p[i], tamanho[i]);
        }
        else if(strcmp(nome[i],"CIRCULAR") == 0){
            criarCircular(&c[i], tamanho[i]);
        }
    }

    while(scanf("%d", &pos_ed) != EOF){

        scanf("\n%c", &op);
        if(strcmp(nome[pos_ed],"LES") == 0){
            if(op != 'M'){
                scanf("%d", &chave);
                if(op == 'I'){
                    inclusaoLista(&l[pos_ed], chave);
                }
                else if(op == 'R'){
                    if(!listaVazia(l[pos_ed])){
                        removido = remocaoLista(&l[pos_ed], chave);
                        if(removido != 0){
                            printf("REMOVIDO: %d\n", removido);
                        }
                    }
                }
            }
            else{
                if(!listaVazia(l[pos_ed])){
                    mostrarLista(l[pos_ed]);
                }
            }
        }
        else if(strcmp(nome[pos_ed],"FILA") == 0){
            if(op == 'I'){
                scanf("%d", &chave);
                if(filaVazia(f[pos_ed])){
                    f[pos_ed].inicio = -1;
                    f[pos_ed].fim = -1;
                }
                inclusaoFila(&f[pos_ed], chave);
            }
            else if(op == 'R'){
                if(!filaVazia(f[pos_ed])){
                    printf("REMOVIDO: %d\n", remocaoFila(&f[pos_ed]));
                }
                else{
                    f[pos_ed].inicio = -1;
                    f[pos_ed].fim = -1;
                }
            }
            else if(op == 'M'){
                if(!filaVazia(f[pos_ed])){
                    mostrarFila(f[pos_ed]);
                }else{
                    f[pos_ed].inicio = -1;
                    f[pos_ed].fim = -1;
                }
            }
        }
        else if(strcmp(nome[pos_ed],"PILHA") == 0){
            if(op == 'I'){
                scanf("%d", &chave);
                inclusaoPilha(&p[pos_ed], chave);
            }
            else if(op == 'R'){
                if(!pilhaVazia(p[pos_ed])){
                    printf("REMOVIDO: %d\n", remocaoPilha(&p[pos_ed]));
                }
            }
            else if(op == 'M'){
                if(!pilhaVazia(p[pos_ed])){
                    mostrarPilha(p[pos_ed]);
                }
            }
        }
        else if(strcmp(nome[pos_ed],"CIRCULAR") == 0){
            if(op == 'I'){
                scanf("%d", &chave);
                inclusaoCircular(&c[pos_ed], chave);
            }
            else if(op == 'R'){
                if(c[pos_ed].start != c[pos_ed].end){
                    printf("REMOVIDO: %d\n", remocaoCircular(&c[pos_ed]));
                }
            }
            else if(op == 'M'){
                if(c[pos_ed].start != c[pos_ed].end){
                    mostrarCircular(c[pos_ed]);
                }
            }
        }
    }


    for(i=0; i<quant; i++){
        free(nome[i]);
    }
    free(nome);
    free(tamanho);
    free(l[pos_ed].itens);
    free(f[pos_ed].itens);
    free(p[pos_ed].itens);
    free(c[pos_ed].itens);
    free(l);
    free(f);
    free(p);
    free(c);

    return 0;
}

/* Funções da Lista */
void criarLista(Lista *l, int n){

    l->itens = (int *) malloc(sizeof(int) * n);
    l->tamanho = n;
    l->quantidade = 0;

}

void inclusaoLista(Lista *l, int chave){

    int achei=0, i=0, j;

    if(!listaCheia(*l)){

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
                for(j=l->quantidade; j != i; j--){
                    l->itens[j] = l->itens[j-1];
                }
            }
            l->itens[i] = chave;
            l->quantidade++;
        }

    }

}

int remocaoLista(Lista *l, int chave){

    int achei=0, i=0, j, removido;

    if(!listaVazia(*l)){

        while(i<l->quantidade && !achei && l->itens[i] <= chave){

            if(l->itens[i] == chave){
                achei=1;
            }
            else{
                i++;
            }

        }

        if(achei){
            removido = l->itens[i];
            for(j=i; j<l->quantidade; j++){
                l->itens[j] = l->itens[j+1];
            }
            l->quantidade--;
            return removido;
        }
        return 0;

    }

}

void mostrarLista(Lista l){

    int i;

    for(i=0; i<l.quantidade; i++){
        printf("%d%s", l.itens[i], i==l.quantidade-1?"\n":" ");
    }

}
int listaCheia(Lista l){
    return l.quantidade == l.tamanho;
}

int listaVazia(Lista l){
    return l.quantidade == 0;
}

/* Funções da Fila */
void criarFila(Fila *f, int n){

    f->itens = (int *) malloc(sizeof(int) * n);
    f->inicio = -1;
    f->fim = -1;
    f->tamanho = n;
}

void inclusaoFila(Fila *f, int chave){

    if(f->inicio == -1 && f->fim == -1){
        f->inicio++;
    }

    if(!filaCheia(*f)){
        f->fim++;
        f->itens[f->fim] = chave;
    }
}

int remocaoFila(Fila *f){

    int removido = f->itens[f->inicio];

    if(!filaVazia(*f)){
        f->inicio++;
        return removido;
    }
    else{
        f->inicio = -1;
        f->fim = -1;
    }

}

void mostrarFila(Fila f){

    int i;

    for(i=f.inicio; i<=f.fim;  i++){
        printf("%d%s", f.itens[i], i==f.fim?"\n":" ");
    }

}

int filaCheia(Fila f){
    return f.fim == f.tamanho-1;
}

int filaVazia(Fila f){
    return (f.fim+1 == f.inicio || (f.fim == -1 && f.inicio == -1));
}


/* Funções da Pilha */
void criarPilha(Pilha *p, int n){

    p->itens = (int *) malloc(sizeof(int) * n);
    p->topo = -1;
    p->tamanho = n;

}

void inclusaoPilha(Pilha *p, int chave){

    if(!pilhaCheia(*p)){
        p->topo++;
        p->itens[p->topo] = chave;
    }

}

int remocaoPilha(Pilha *p){

    int removido = p->itens[p->topo];
    p->topo--;
    return removido;

}

void mostrarPilha(Pilha p){

    int i;

    for(i=0; i<=p.topo; i++){
        printf("%d%s", p.itens[i], i == p.topo?"\n":" ");
    }

}

int pilhaCheia(Pilha p){
    return p.topo == p.tamanho-1;
}

int pilhaVazia(Pilha p){
    return p.topo == -1;
}

/* Funções do Circular */
void criarCircular(Circular *c, int n){

    c->itens = (int *) malloc(sizeof(int)*n);
    c->start = 0;
    c->end = 0;
    c->tamanho = n;

}

void inclusaoCircular(Circular *c, int chave){

    int novo_fim;

    novo_fim = (c->end+1)%c->tamanho;
    if(novo_fim != c->start){

        c->itens[c->end] = chave;
        c->end = novo_fim;

    }
}

int remocaoCircular(Circular *c){

    int removido;

    if(c->start != c->end){

        removido = c->itens[c->start];
        c->itens[c->start] = 0;
        c->start = (c->start+1)%c->tamanho;
        return removido;
    }

    return 0;

}

void mostrarCircular(Circular c){

    int i;

    for(i=c.start; i!=c.end; i=(i+1)%c.tamanho){
        printf("%d%s", c.itens[i], (i+1)%c.tamanho==c.end?"\n":" ");
    }

}
