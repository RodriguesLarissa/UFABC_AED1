#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int valor;
    struct No *esq, *dir;

}No;

typedef No* Arvore;

Arvore * cria_Arvore();
void libera_Arvore(Arvore *);
void libera_NO(No *);
void insere(Arvore *, int);
void mostraNivel(Arvore *, int, int);
int altura(Arvore *);

int main(){

    int n, i, nivel, valor, alt;

    Arvore *raiz = cria_Arvore();

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &valor);
        insere(raiz, valor);
    }

    alt = altura(raiz);

    for(i=0; i<alt; i++){
        mostraNivel(raiz, i, 0);
    }

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

void mostraNivel(Arvore *raiz, int nivel, int k){
    if(raiz == NULL || (*raiz) == NULL){
        return;
    }
        if(nivel == k){
            printf("%d\n", (*raiz)->valor);
            mostraNivel(&(*raiz)->esq, nivel, k+1);
            mostraNivel(&(*raiz)->dir, nivel, k+1);
        }
        else{
            mostraNivel(&(*raiz)->esq, nivel, k+1);
            mostraNivel(&(*raiz)->dir, nivel, k+1);
        }
}

int altura(Arvore *raiz){
    if(raiz == NULL || *raiz == NULL){
        return 0;
    }
    int alt_esq = altura(&(*raiz)->esq);
    int alt_dir = altura(&(*raiz)->dir);
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }
    else{
        return(alt_dir + 1);
    }
}