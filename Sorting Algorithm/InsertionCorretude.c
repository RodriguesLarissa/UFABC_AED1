#include <stdio.h>
#include <stdlib.h>

void ordenaInsertion(int *, int *, int);
void mostrar(int *, int *, int, int, int);

int main (){

    int i, tam;

    scanf("%d", &tam);

    int *vetorInicial = (int *) malloc(sizeof(int)*tam);
    int *vetorFinal = (int *) malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        scanf("%d", &vetorInicial[i]);
    }

    ordenaInsertion(vetorInicial, vetorFinal, tam);

    free(vetorInicial);
    free(vetorFinal);

    return 0;
}

void ordenaInsertion(int *v1, int *v2, int tam){

    int i, j, aux;
    int tam1 = tam, tam2 = 0, n=0;

    v2[0] = v1[0];
    tam2++;
    n++;
    mostrar(v1, v2, tam1, tam2, n);

    for(i=1; i<tam; i++){
        aux = v1[i];
        for(j=i; (j>0) && (aux<v2[j-1]); j--){
            v2[j] = v2[j-1];
        }
        v2[j] = aux;
        tam2++;
        n++;
        mostrar(v1, v2, tam1, tam2, n);
    }

}

void mostrar(int *v1, int *v2, int tam1, int tam2, int n){

    int i;

    printf("Sublista Ordenada: ");
    for(i=0; i<tam2; i++){
        printf("%d%s", v2[i], i==tam2-1?"\n":" ");
    }
    printf("Sublista Desordenada:%s", n==tam1?"\n":" ");
    for(i=n; i<tam1; i++){
        printf("%d%s", v1[i], i==tam1-1?"\n":" ");
    }
}