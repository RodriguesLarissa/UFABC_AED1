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
int insere(Arvore *, int);
int altura(Arvore *);

int main(){

    int n, i, valor;

    Arvore *raiz = cria_Arvore();

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &valor);
        insere(raiz, valor);
    }

    printf("%d\n", altura(raiz)-1);

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

int insere(Arvore *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    No *novo, *atual, *ant;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        return 0;
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
                return 0;
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
    return 1;
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