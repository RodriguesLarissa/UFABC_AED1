#include <stdio.h>
#include <stdlib.h>

void ordena(int *, int);
void mostrar(int *, int);

int main (){

    int tam, i;

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

    int aux, i, j;

    for(i=1; i<tam; i++){
        aux = v[i];
        for(j=i; (j>0) && (aux<v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
        mostrar(v, tam);
    }

}

void mostrar(int *v, int tam){

    int i;

    for(i=0; i<tam; i++){
        printf("%d%s", v[i], tam-1==i?"\n":" ");
    }

}