#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{

    char valor;
    struct No *esq, *dir;

}No;

typedef No* Arvore;

Arvore * cria_Arvore();
void libera_Arvore(Arvore *);
void libera_NO(No *);
int insere(Arvore *, char);
int remover(Arvore *, char);
No * remove_No(No *);
void preOrdem(Arvore *);
void emOrdem(Arvore *);
void posOrdem(Arvore *);
int arvoreVazia(Arvore *);

int main (){

    char operacao[10];
    char valor;


    Arvore *raiz = cria_Arvore();

    while(scanf("%s", operacao) != EOF){
        if(strcmp(operacao, "insert") == 0 || strcmp(operacao, "delete") == 0){
            scanf("\n%c", &valor);
            if(strcmp(operacao, "insert") == 0){
                insere(raiz, valor);
            }
            else{
                remover(raiz, valor);
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

int insere(Arvore *raiz, char valor){
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
            if(valor >= ant->valor){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(valor >= ant->valor){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
    return 1;
}

int remover(Arvore *raiz, char valor){
    if(raiz == NULL){
        return 0;
    }

    No *ant, *atual;
    ant = NULL;
    atual = *raiz;
    while(atual != NULL){
        if(valor == atual->valor){
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
            return 1;
        }
        ant = atual;
        if(valor > atual->valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
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
        printf("%c ", (*raiz)->valor);
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
        printf("%c ", (*raiz)->valor);
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
        printf("%c ", (*raiz)->valor);
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