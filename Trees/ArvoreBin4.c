#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{

    char chave[50];
    struct No *esq, *dir;

}No;

typedef No* Arvore;

Arvore * cria_Arvore();
void libera_Arvore(Arvore *);
void libera_NO(No *);
void insere(Arvore *, char [50]);
void remover(Arvore *, char [50]);
int valorCalculado(char [50]);
No * remove_No(No *);
void preOrdem(Arvore *);
void emOrdem(Arvore *);
void posOrdem(Arvore *);
int arvoreVazia(Arvore *);

int main (){

    char operacao[10];
    char chave[50];

    Arvore *raiz = cria_Arvore();

    while(scanf("%s", operacao) != EOF){
        if(strcmp(operacao, "insert") == 0 || strcmp(operacao, "delete") == 0){
            scanf("%s", chave);
            if(strcmp(operacao, "insert") == 0){
                insere(raiz, chave);
            }
            else{
                remover(raiz, chave);
            }
        }
        else if(strcmp(operacao, "pre-order") == 0){
            if(arvoreVazia(raiz) != 1){
                preOrdem(raiz);
                printf("\n");
            }
        }
        else if(strcmp(operacao, "in-order") == 0){
            if(arvoreVazia(raiz) != 1){
                emOrdem(raiz);
                printf("\n");

            }
        }
        else if(strcmp(operacao, "post-order") == 0){
            if(arvoreVazia(raiz) != 1){
                posOrdem(raiz);
                printf("\n");
            }
        }
    }

    libera_Arvore(raiz);
    return 0;
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

int valorCalculado(char chave[50]){
    int i, valor=0;

    for(i=0; i<strlen(chave); i++){
        valor += chave[i];
    }
    return valor;
}

void insere(Arvore *raiz, char chave[50]){
    if(raiz == NULL){
        return;
    }

    No *novo, *atual, *ant;

    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        return;
    }

    strcpy(novo->chave, chave);
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
            if(valorCalculado(chave) >= valorCalculado(ant->chave)){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(valorCalculado(chave) >= valorCalculado(ant->chave)){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
}

void remover(Arvore *raiz, char chave[50]){
    if(raiz == NULL){
        return;
    }

    No *ant, *atual;
    ant = NULL;
    atual = *raiz;

    while(atual != NULL){
        if(valorCalculado(chave) == valorCalculado(atual->chave)){
            if(atual == *raiz){
                *raiz = remove_No(atual);
            }
            else{
                if(ant->dir == atual){
                    ant->dir = remove_No(atual);
                }
                else{
                    ant->esq = remove_No(atual);
                }
            }
            return;
        }
        ant = atual;
        if(valorCalculado(chave) > valorCalculado(atual->chave)){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
}

No * remove_No(No *atual){
    No *no1, *no2;
    if(atual->dir == NULL){
        no2 = atual->esq;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->dir;
    while(no2->esq != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    if(no1 != atual){
        no1->esq = no2->dir;
        no2->dir = atual->dir;
    }
    no2->esq = atual->esq;
    free(atual);
    return no2;
}

void preOrdem(Arvore *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("[%d]:%s\n", valorCalculado((*raiz)->chave), (*raiz)->chave);
        preOrdem(&(*raiz)->esq);
        preOrdem(&(*raiz)->dir);
    }
}

void emOrdem(Arvore *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem(&(*raiz)->esq);
        printf("[%d]:%s\n", valorCalculado((*raiz)->chave), (*raiz)->chave);
        emOrdem(&(*raiz)->dir);
    }
}

void posOrdem(Arvore *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem(&(*raiz)->esq);
        posOrdem(&(*raiz)->dir);
        printf("[%d]:%s\n", valorCalculado((*raiz)->chave), (*raiz)->chave);
    }
}

int arvoreVazia(Arvore *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}