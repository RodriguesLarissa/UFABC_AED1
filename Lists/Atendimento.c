#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{

    char *nome;
    int RA;

}Aluno;

typedef struct Fila{

    Aluno *alunos;
    int inicio, fim, tamanho, quantidade;

}Fila;

void criarFila(Fila *, int);
void criarAluno(Fila *);
void inclusao(Fila *);
void exclusao(Fila *);
void mostrar(Fila);
void mostrarInverso(Fila);
int cheia(Fila);
int vazia(Fila);

int main (){

    int n;
    char op;
    Fila f;
    Aluno alunos;

    scanf("%d", &n);

    criarFila(&f, n);

    while(scanf("\n%c", &op) != EOF){

        if(op == 'I'){

            criarAluno(&f);
            if(vazia(f)){
                f.inicio = -1;
                f.fim = -1;
            }

            inclusao(&f);
        }
        else if(op == 'A'){
            if(vazia(f)){
                f.inicio = -1;
                f.fim = -1;
            }
            else{
                exclusao(&f);
            }
        }
        else if(op == 'M'){
            mostrar(f);
        }
        else if(op == 'R'){
            mostrarInverso(f);
        }
        else if(op == 'Q'){
            printf("Quantidade: %d\n", f.quantidade);
        }

    }
    free(f.alunos->nome);
    free(f.alunos);

    return 0;
}

void criarFila(Fila *f, int n){

    f->alunos = malloc (sizeof(Aluno)*n);
    f->inicio = -1;
    f->fim = -1;
    f->tamanho = n;
    f->quantidade = 0;

}

void criarAluno(Fila *f){

    int i;

    if(!cheia(*f)){
        f->alunos[f->fim+1].nome = malloc (sizeof(char)*100);
    }
}

void inclusao(Fila *f){

    if(!cheia(*f)){
        if(vazia(*f)){
            f->inicio++;
        }
        f->fim++;
        scanf("%d", &f->alunos[f->fim].RA);
        scanf("%s", f->alunos[f->fim].nome);
        f->quantidade++;

    }
}

void exclusao(Fila *f){

    if(!vazia(*f)){
        printf("[%d] %s\n", f->alunos[f->inicio].RA, f->alunos[f->inicio].nome);

        f->inicio++;
        f->quantidade--;
    }

}

void mostrar(Fila f){

    int i;

    if(!vazia(f)){
        for(i=f.inicio; i<=f.fim; i++){
            printf("[%d] %s\n", f.alunos[i].RA, f.alunos[i].nome);
        }
    }
}

void mostrarInverso(Fila f){

    int i;

    if(!vazia(f)){
        for(i=f.fim; i>=f.inicio; i--){
            printf("[%d] %s\n", f.alunos[i].RA, f.alunos[i].nome);
        }
    }
}

int cheia(Fila f){
    return (f.fim+1 == f.tamanho);
}
int vazia(Fila f){
    return(f.fim == f.inicio-1 || (f.fim == -1 && f.inicio == -1));
}