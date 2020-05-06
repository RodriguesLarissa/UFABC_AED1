#include <stdio.h>
#include <stdlib.h>

void ordena(int *, int);

int main (){

    int i, tam;

    scanf("%d", &tam);

    int *v = (int *) malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        scanf("%d", &v[i]);
    }

    ordena(v, tam);

    free(v);

    return 0;
}

void ordena(int *v, int tam){

    int i, j, aux, cont=0;

    for(i=1; i<tam; i++){
        aux=v[i];
        for(j=i; (j>0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
            cont++;
        };
        v[j] = aux;
    }

    printf("%d\n", cont);
}