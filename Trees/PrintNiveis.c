#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{

    int *itens;
    int inicio, fim, tamanho;

}Fila;

typedef struct No{

    int valor;
    struct No *esq, *dir;

}No;

typedef No* Arvore;

void criarFila(Fila *, int);
void inclusaoFila(Fila *, Arvore *);
void exclusaoFila(Fila *);
int vazia(Fila);
Arvore * cria_Arvore();
void libera_Arvore(Arvore *);
void libera_NO(No *);
void insere(Arvore *, int);
void percursoNivel(Arvore *, Fila *);
No * preOrdem(Arvore *, Fila *);

int main(){

    int n, i, nivel, valor;

    Arvore *raiz = cria_Arvore();
    Fila f;

    scanf("%d", &n);

    criarFila(&f, n);

    for(i=0; i<n; i++){
        scanf("%d", &valor);
        insere(raiz, valor);
    }

    percursoNivel(raiz, &f);

}

Arvore * cria_Arvore(){
    Arvore *raiz = (Arvore *) malloc(sizeof(Arvore));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void libera_Arvore(Arvore *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

void libera_NO(No *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void insere(Arvore *raiz, int valor){
    if(raiz == NULL){
        return;
    }

    No *novo, *atual, *ant;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        return;
    }

    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL){
        *raiz = novo;
    }
    else{
        atual = *raiz;
        ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == ant->valor){
                free(novo);
                return;
            }
            else if(valor > ant->valor){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(valor > ant->valor){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
}

void inclusaoFila(Fila *f, Arvore *raiz){
    if(f->inicio == -1 && f->fim == -1){
        f->inicio++;
    }
    f->fim++;
    f->itens[f->fim] = (*raiz)->valor;
}

void criarFila(Fila *f, int n){

    f->itens = (int *) malloc(n*sizeof(int));
    f->inicio = -1;
    f->fim = -1;
    f->tamanho = n;

}

void exclusaoFila(Fila *f){
    if(!vazia(*f)){
        f->inicio++;
    }
}


void percursoNivel(Arvore *raiz, Fila *f){
    if(raiz == NULL || *raiz == NULL){
        return;
    }

    No *atual = *raiz;
    inclusaoFila(f, raiz);

    while(!vazia(*f)){
        printf("%d\n", atual->valor);
        if((*raiz)->esq != NULL){
            inclusaoFila(f,(&(*raiz)->esq));
        }
        if((*raiz)->dir != NULL){
            inclusaoFila(f,(&(*raiz)->dir));
        }
        exclusaoFila(f);
        atual = preOrdem(raiz, f);
        printf("teste");
    }

}

No * preOrdem(Arvore *raiz, Fila *f){
    if(raiz == NULL){
        return 0;
    }
    No *atual;
    if(*raiz != NULL){
        if((*raiz)->valor == f->itens[f->inicio]){
            atual = *raiz;
            return (&(*atual));
        }
        preOrdem(&(*raiz)->esq, f);
        preOrdem(&(*raiz)->dir, f);
        return 0;
    }
}

int vazia(Fila f){
    return (f.fim+1 == f.inicio || (f.fim == -1 && f.inicio == -1));
}